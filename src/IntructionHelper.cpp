#include "InstructionHelper.h"
#include "MemoryController.h"

using namespace PSEmu;

InstructionHelper::InstructionHelper(MemoryController* memControl, RegisterType* reg) :
   mMemController(memControl),
   mRegisters(reg)
{
}

InstructionHelper::~InstructionHelper() { }

void InstructionHelper::LB(const InstructionSetImmediateType& imm) 
{
   Word addr = imm.rs + imm.immediate;
   
}

void InstructionHelper::LUI(const InstructionSetImmediateType& imm) 
{
   mRegisters->genReg[imm.rt] = (imm.immediate << 16);
}

void InstructionHelper::ORI(const InstructionSetImmediateType& imm) 
{
   mRegisters->genReg[imm.rt] = mRegisters->genReg[imm.rs] | imm.immediate;
}

void InstructionHelper::SW(const InstructionSetImmediateType& imm) 
{
   mMemController->StoreWord(mRegisters->genReg[imm.rs] + imm.immediate,
                             mRegisters->genReg[imm.rt]);
}