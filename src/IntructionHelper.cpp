#include "InstructionHelper.h"
#include "MemoryController.h"

using namespace PSEmu;

#define SIGNED_BYTE(x) ((x << 24) >> 24)
#define SIGNED_HALFWORD(x) ((x << 16) >> 16)

InstructionHelper::InstructionHelper(MemoryController* memControl, RegisterType* reg) :
   mMemController(memControl),
   mRegisters(reg)
{
}

InstructionHelper::~InstructionHelper() { }

void InstructionHelper::LB(const InstructionSetImmediateType& imm) 
{
   Word addr = mRegisters->genReg[imm.rs] + imm.immediate;

   mRegisters->genReg[imm.rt] = SIGNED_BYTE(mMemController->GetByte(addr));
}

void InstructionHelper::LBU(const InstructionSetImmediateType& imm) 
{
   Word addr = mRegisters->genReg[imm.rs] + imm.immediate;
   mRegisters->genReg[imm.rt] = mMemController->GetByte(addr);
}

void InstructionHelper::LH(const InstructionSetImmediateType& imm) 
{
   Word addr = mRegisters->genReg[imm.rs] + imm.immediate;

   mRegisters->genReg[imm.rt] = SIGNED_HALFWORD(mMemController->GetHalfWord(addr));
}

void InstructionHelper::LHU(const InstructionSetImmediateType& imm) 
{
   Word addr = mRegisters->genReg[imm.rs] + imm.immediate;
   mRegisters->genReg[imm.rt] = mMemController->GetHalfWord(addr);
}

void InstructionHelper::LW(const InstructionSetImmediateType& imm) 
{
   Word addr = mRegisters->genReg[imm.rs] + imm.immediate;
   mRegisters->genReg[imm.rt] = mMemController->GetWord(addr);
}

void InstructionHelper::LWR(const InstructionSetImmediateType& imm) 
{
   // Unaligned address
   Word addr = mRegisters->genReg[imm.rs] + imm.immediate;
   // Align address(ex. 0x153 -> 0x150)
   Word alignedAddr = (addr & ~3);
   Word offset = (addr & 3);
   Word shift = offset<<3;

   // Make sure to get the original data from rt, only masking what is necessary
   Word origData = mRegisters->genReg[imm.rt] & ~(0xffffffff>>shift);

   mRegisters->genReg[imm.rt] = origData | (mMemController->GetWord(alignedAddr) >> shift);
}

void InstructionHelper::LWL(const InstructionSetImmediateType& imm) 
{
   // Unaligned address
   Word addr = mRegisters->genReg[imm.rs] + imm.immediate;

   // Align address(ex. 0x156 -> 0x154)
   Word alignedAddr = (addr & ~3);
   Word offset = (addr & 3);
   Word shift = (3 ^ offset) << 3;

   // Make sure to get the original data from rt, only masking what is necessary
   Word origData = mRegisters->genReg[imm.rt] & (1 << shift) - 1;

   mRegisters->genReg[imm.rt] = origData | (mMemController->GetWord(alignedAddr) << shift);
}

void InstructionHelper::SB(const InstructionSetImmediateType& imm) 
{
   mMemController->StoreByte(mRegisters->genReg[imm.rs] + imm.immediate,
                             mRegisters->genReg[imm.rt]);
}

void InstructionHelper::SH(const InstructionSetImmediateType& imm) 
{
   mMemController->StoreHalfWord(mRegisters->genReg[imm.rs] + imm.immediate,
                                 mRegisters->genReg[imm.rt]);
}

void InstructionHelper::SW(const InstructionSetImmediateType& imm) 
{
   mMemController->StoreWord(mRegisters->genReg[imm.rs] + imm.immediate,
                             mRegisters->genReg[imm.rt]);
}

void InstructionHelper::SWR(const InstructionSetImmediateType& imm) 
{
   // Unaligned address
   Word addr = mRegisters->genReg[imm.rs] + imm.immediate;

   // Align address(ex. 0x156 -> 0x154)
   Word alignedAddr = (addr & ~3);
   Word offset = (addr & 3);
   Word shift = offset<<3;

   Word origData = mMemController->GetWord(alignedAddr) & ~(0xffffffff<<(shift));

   mMemController->StoreWord(alignedAddr, origData | (mRegisters->genReg[imm.rt] << shift));
}

void InstructionHelper::SWL(const InstructionSetImmediateType& imm) 
{
   // Unaligned address
   Word addr = mRegisters->genReg[imm.rs] + imm.immediate;

   // Align address(ex. 0x156 -> 0x154)
   Word alignedAddr = (addr & ~3);
   Word offset =  (addr & 3);
   Word shift = ((~offset) & 3) << 3;

   Word origData = mMemController->GetWord(alignedAddr) & ~(0xffffffff >> (shift));
   mMemController->StoreWord(alignedAddr, origData | (mRegisters->genReg[imm.rt] >> shift));
}

void InstructionHelper::LUI(const InstructionSetImmediateType& imm) 
{
   mRegisters->genReg[imm.rt] = (imm.immediate << 16);
}

void InstructionHelper::ORI(const InstructionSetImmediateType& imm) 
{
   mRegisters->genReg[imm.rt] = mRegisters->genReg[imm.rs] | imm.immediate;
}
