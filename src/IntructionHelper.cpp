#include "InstructionHelper.h"

using namespace PSEmu;

void InstructionHelper::LUI(const InstructionSetImmediateType& imm,
         RegisterType& registers) 
{
   registers.genReg[imm.rt] = (imm.immediate << 16);
}