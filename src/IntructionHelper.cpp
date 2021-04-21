#include "InstructionHelper.h"
#include "MemoryController.h"

using namespace PSEmu;

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
                           MemoryController* mmu) 
{
   mmu->StoreWord(registers.genReg[imm.rs] + imm.immediate,
                  registers.genReg[imm.rt]);
}