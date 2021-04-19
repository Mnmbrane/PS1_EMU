#include "InstructExecHelper.h"

using namespace PSEmu;

   void InstructExecHelper::LUI(const InstructionSetImmediateType& imm,
                                RegisterType& registers) 
   {
      registers.genReg[imm.rt] = (imm.immediate << 16);
   }