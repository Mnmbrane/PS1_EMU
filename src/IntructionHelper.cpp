#include "InstructionHelper.h"
#include "MemoryController.h"

using namespace PSEmu;

void InstructionHelper::LB(const InstructionSetImmediateType& imm,
                           RegisterType& registers) 
{
   Word val = 0;
   Word addr = imm.rs + imm.immediate;
   
}

void InstructionHelper::LUI(const InstructionSetImmediateType& imm,
                            RegisterType& registers) 
{
   registers.genReg[imm.rt] = (imm.immediate << 16);
}

void InstructionHelper::ORI(const InstructionSetImmediateType& imm,
                            RegisterType& registers) 
{
   registers.genReg[imm.rt] = registers.genReg[imm.rs] | imm.immediate;
}

void InstructionHelper::SW(const InstructionSetImmediateType& imm,
                           RegisterType& registers,
                           MemoryController* memControl) 
{
   memControl->StoreWord(registers.genReg[imm.rs] + imm.immediate,
                         registers.genReg[imm.rt]);
}