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
   
   // mask is to make sure rt still has it's data
   Word mask = ~(((4 - offset) << 8) - 1);

   mRegisters->genReg[imm.rt] = 
      (mRegisters->genReg[imm.rt] & mask ) | (mMemController->GetWord(alignedAddr) >> (offset << 3));
}

void InstructionHelper::LWL(const InstructionSetImmediateType& imm) 
{
   // Unaligned address
   Word addr = mRegisters->genReg[imm.rs] + imm.immediate;

   // Align address(ex. 0x156 -> 0x154)
   Word alignedAddr = (addr & ~3);
   Word offset = (addr & 3);

   // mask is to make sure rt still has it's data
   Word mask = (1 << ((3 ^ offset) << 3)) - 1;

   mRegisters->genReg[imm.rt] =
      (mRegisters->genReg[imm.rt] & mask ) | mMemController->GetWord(alignedAddr) << ((3 ^ offset) << 3);
}

void InstructionHelper::SB(const InstructionSetImmediateType& imm) 
{

}

void InstructionHelper::SH(const InstructionSetImmediateType& imm) 
{

}

void InstructionHelper::SW(const InstructionSetImmediateType& imm) 
{
   mMemController->StoreWord(mRegisters->genReg[imm.rs] + imm.immediate,
                             mRegisters->genReg[imm.rt]);
}

void InstructionHelper::SWL(const InstructionSetImmediateType& imm) 
{

}

void InstructionHelper::SWR(const InstructionSetImmediateType& imm) 
{

}


void InstructionHelper::LUI(const InstructionSetImmediateType& imm) 
{
   mRegisters->genReg[imm.rt] = (imm.immediate << 16);
}

void InstructionHelper::ORI(const InstructionSetImmediateType& imm) 
{
   mRegisters->genReg[imm.rt] = mRegisters->genReg[imm.rs] | imm.immediate;
}
