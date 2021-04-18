#pragma once
#include "CommonTypes.h"

namespace PSEmu
{
   class InstructExecHelper
   {
   public:

   // Load Upper Immediate
   static void LUI(const InstructionSetImmediateType& imm,
                   RegisterType& registers);


   };
   
   
}