#include "InstructionHelper.h"
#include "MemoryController.h"

#include <exception>

using namespace PSEmu;

#define SIGNED_BYTE(x) ((x << 24) >> 24)
#define SIGNED_HALFWORD(x) ((x << 16) >> 16)
#define SIGNED_IMM(x) SIGNED_HALFWORD(x)

InstructionHelper::InstructionHelper(MemoryController* memControl, RegisterType* reg) :
   mMemController(memControl),
   mRegisters(reg)
{
}

InstructionHelper::~InstructionHelper() { }

void InstructionHelper::LB(const InstructionSetImmediateType& imm) 
{
   Word addr = mRegisters->genReg[imm.rs] + SIGNED_IMM(imm.immediate);

   mRegisters->genReg[imm.rt] = SIGNED_BYTE(mMemController->GetByte(addr));
}

void InstructionHelper::LBU(const InstructionSetImmediateType& imm) 
{
   Word addr = mRegisters->genReg[imm.rs] + SIGNED_IMM(imm.immediate);
   mRegisters->genReg[imm.rt] = mMemController->GetByte(addr);
}

void InstructionHelper::LH(const InstructionSetImmediateType& imm) 
{
   Word addr = mRegisters->genReg[imm.rs] + SIGNED_IMM(imm.immediate);

   mRegisters->genReg[imm.rt] = SIGNED_HALFWORD(mMemController->GetHalfWord(addr));
}

void InstructionHelper::LHU(const InstructionSetImmediateType& imm) 
{
   Word addr = mRegisters->genReg[imm.rs] + SIGNED_IMM(imm.immediate);
   mRegisters->genReg[imm.rt] = mMemController->GetHalfWord(addr);
}

void InstructionHelper::LW(const InstructionSetImmediateType& imm) 
{
   Word addr = mRegisters->genReg[imm.rs] + SIGNED_IMM(imm.immediate);
   mRegisters->genReg[imm.rt] = mMemController->GetWord(addr);
}

void InstructionHelper::LWR(const InstructionSetImmediateType& imm) 
{
   // Unaligned address
   Word addr = mRegisters->genReg[imm.rs] + SIGNED_IMM(imm.immediate);
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
   Word addr = mRegisters->genReg[imm.rs] + SIGNED_IMM(imm.immediate);

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
   mMemController->StoreByte(mRegisters->genReg[imm.rs] + SIGNED_IMM(imm.immediate),
                             mRegisters->genReg[imm.rt]);
}

void InstructionHelper::SH(const InstructionSetImmediateType& imm) 
{
   mMemController->StoreHalfWord(mRegisters->genReg[imm.rs] + SIGNED_IMM(imm.immediate),
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

void InstructionHelper::ADDI(const InstructionSetImmediateType& imm) 
{
   Word regVal = mRegisters->genReg[imm.rs];
   int sImm = ((int)SIGNED_IMM(imm.immediate));

   if(CheckAddOverflow(sImm, regVal))
   {
      // overflow
      throw std::exception();
   }
   else
   {
      Word addVal = (int)regVal + sImm;
      mRegisters->genReg[imm.rt] = addVal;
   }
}

void InstructionHelper::ADDIU(const InstructionSetImmediateType& imm) 
{
   mRegisters->genReg[imm.rt] = mRegisters->genReg[imm.rs] + SIGNED_IMM(imm.immediate);
}

void InstructionHelper::SLTI(const InstructionSetImmediateType& imm) 
{
   mRegisters->genReg[imm.rt] = (int)mRegisters->genReg[imm.rs] < (int)SIGNED_IMM(imm.immediate);
}

void InstructionHelper::SLTIU(const InstructionSetImmediateType& imm) 
{
   mRegisters->genReg[imm.rt] = mRegisters->genReg[imm.rs] < SIGNED_IMM(imm.immediate);
}

void InstructionHelper::ANDI(const InstructionSetImmediateType& imm) 
{
   mRegisters->genReg[imm.rt] = mRegisters->genReg[imm.rs] & imm.immediate;
}

void InstructionHelper::ORI(const InstructionSetImmediateType& imm) 
{
   mRegisters->genReg[imm.rt] = mRegisters->genReg[imm.rs] | imm.immediate;
}

void InstructionHelper::XORI(const InstructionSetImmediateType& imm) 
{
    mRegisters->genReg[imm.rt] = mRegisters->genReg[imm.rs] ^ imm.immediate;
}

void InstructionHelper::LUI(const InstructionSetImmediateType& imm) 
{
   mRegisters->genReg[imm.rt] = (imm.immediate << 16);
}

void InstructionHelper::ADD(const InstructionSetRegisterType& reg) 
{
   int s = mRegisters->genReg[reg.rs];
   int t = mRegisters->genReg[reg.rt];

   if(CheckAddOverflow(s, t))
   {
      throw std::exception();
   }
   else
   {
      mRegisters->genReg[reg.rd] = mRegisters->genReg[reg.rs] + mRegisters->genReg[reg.rt];
   }
}

void InstructionHelper::ADDU(const InstructionSetRegisterType& reg)
{
   mRegisters->genReg[reg.rd] = mRegisters->genReg[reg.rs] + mRegisters->genReg[reg.rt];
}

void InstructionHelper::SUB(const InstructionSetRegisterType& reg) 
{
   int s = mRegisters->genReg[reg.rs];
   int t = mRegisters->genReg[reg.rt];

   if(CheckSubOverflow(s, t))
   {
      throw std::exception();
   }
   else
   {
      mRegisters->genReg[reg.rd] = mRegisters->genReg[reg.rs] - mRegisters->genReg[reg.rt];
   }
}

void InstructionHelper::SUBU(const InstructionSetRegisterType& reg) 
{
   mRegisters->genReg[reg.rd] = mRegisters->genReg[reg.rs] - mRegisters->genReg[reg.rt];
}

void InstructionHelper::SLT(const InstructionSetRegisterType& reg) 
{
   mRegisters->genReg[reg.rd] = (int)mRegisters->genReg[reg.rs] < (int)mRegisters->genReg[reg.rt];
}

void InstructionHelper::SLTU(const InstructionSetRegisterType& reg) 
{
   mRegisters->genReg[reg.rd] = mRegisters->genReg[reg.rs] < mRegisters->genReg[reg.rt];
}

void InstructionHelper::AND(const InstructionSetRegisterType& reg) 
{
   mRegisters->genReg[reg.rd] = mRegisters->genReg[reg.rs] & mRegisters->genReg[reg.rt];
}

void InstructionHelper::OR(const InstructionSetRegisterType& reg) 
{
   mRegisters->genReg[reg.rd] = mRegisters->genReg[reg.rs] | mRegisters->genReg[reg.rt];
}

void InstructionHelper::XOR(const InstructionSetRegisterType& reg) 
{
   mRegisters->genReg[reg.rd] = mRegisters->genReg[reg.rs] ^ mRegisters->genReg[reg.rt];
}

void InstructionHelper::NOR(const InstructionSetRegisterType& reg) 
{
   mRegisters->genReg[reg.rd] = ~(mRegisters->genReg[reg.rs] | mRegisters->genReg[reg.rt]);
}

bool InstructionHelper::CheckAddOverflow(const SWord& num1, const SWord& num2) 
{
   int temp;
   return __builtin_add_overflow(num1, num2, &temp);
}

bool InstructionHelper::CheckSubOverflow(const SWord& num1, const SWord& num2) 
{
   int temp;
   return __builtin_sub_overflow(num1, num2, &temp);
}