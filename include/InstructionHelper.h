#pragma once
#include "CommonTypes.h"

namespace PSEmu
{
   class MemoryController;

   class InstructionHelper
   {
   public:
      InstructionHelper(MemoryController* memControl, RegisterType* reg);
      ~InstructionHelper();
      /**
       * LB - Load Byte
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Sign-extend contents of addressed byte and load into rt.
       * 
       * @param[in] imm        - The immediate instruction
       */
      void LB(const InstructionSetImmediateType& imm);

      /**
       * LBU - Load Byte Unsigned
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Zero-extend contents of addressed byte and load into rt.
       * 
       * @param[in] imm        - The immediate instruction
       */
      void LBU(const InstructionSetImmediateType& imm);

      /**
       * LUI - Load Upper Immediate
       * Shift 16-bit immediate left 16 bits. Set least significant 16 bits of word to zeroes.
       * Store result in register rt.
       * 
       * @param[in] imm        - The immediate instruction
       */
      void LUI(const InstructionSetImmediateType& imm);

      /**
       * ORI OR Immediate
       * Zero-extend 16-bit immediate, OR with contents of register rs and place result in
       * register rt.
       * 
       * @param imm        - The immediate instruction
       */
      void ORI(const InstructionSetImmediateType& imm);

      /**
       * SW Store Word
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Store least significant word of register rt at addressed location.
       * 
       * @param imm        - The immediate instruction
       */
      void SW(const InstructionSetImmediateType& imm);

   private:
      MemoryController* mMemController;
      RegisterType* mRegisters;
   };
   
}