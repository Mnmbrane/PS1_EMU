#pragma once
#include "CommonTypes.h"

namespace PSEmu
{
   class MemoryController;

   class InstructionHelper
   {
   public:
      /**
       * LUI - Load Byte
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Sign-extend contents of addressed byte and load into rt.
       * 
       * @param[in] imm        - The immediate instruction
       * @param[out] registers  - Reference to the register arrays
       */
      static void LB(const InstructionSetImmediateType& imm,
                     RegisterType& registers);
      /**
       * LUI - Load Upper Immediate
       * Shift 16-bit immediate left 16 bits. Set least significant 16 bits of word to zeroes.
       * Store result in register rt.
       * 
       * @param[in] imm        - The immediate instruction
       * @param[out] registers  - Reference to the register arrays
       */
      static void LUI(const InstructionSetImmediateType& imm,
                      RegisterType& registers);

      /**
       * ORI OR Immediate
       * Zero-extend 16-bit immediate, OR with contents of register rs and place result in
       * register rt.
       * 
       * @param imm        - The immediate instruction
       * @param registers  - Reference to the register arrays
       */
      static void ORI(const InstructionSetImmediateType& imm,
                      RegisterType& registers);

      /**
       * SW Store Word
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Store least significant word of register rt at addressed location.
       * 
       * @param imm        - The immediate instruction
       * @param registers  - Reference to the register arrays
       */
      static void SW(const InstructionSetImmediateType& imm,
                     RegisterType& registers,
                     MemoryController* mmu);
   };

}