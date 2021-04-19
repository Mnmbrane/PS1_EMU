#pragma once
#include "CommonTypes.h"

namespace PSEmu
{
   class InstructExecHelper
   {
   public:

   // Load instructions

   // LUI Load Upper Immediate
   // Shift 16-bit immediate left 16 bits. Set least significant 16 bits of word to zeroes.
   // Store result in register rt.
   static void LUI(const InstructionSetImmediateType& imm,
                   RegisterType& registers);


   };
   
   
}