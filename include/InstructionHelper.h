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
       * LH - Load Halfword
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Sign-extend contents of addressed byte and load into rt.
       * 
       * @param[in] imm        - The immediate instruction
       */
      void LH(const InstructionSetImmediateType& imm);

      /**
       * LHU - Load Halfword Unsigned
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Zero-extend contents of addressed byte and load into rt.
       * 
       * @param[in] imm        - The immediate instruction
       */
      void LHU(const InstructionSetImmediateType& imm);

      /**
       * LW - Load Word
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Load contents of addressed word into register rt.
       * 
       * @param[in] imm        - The immediate instruction
       */
      void LW(const InstructionSetImmediateType& imm);

      /**
       * LWL - Load Word Left
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Shift addressed word left so that addressed byte is leftmost byte of a word.
       * Merge bytes from memory with contents of register rt and load result into register
       * rt.
       * 
       * @param[in] imm        - The immediate instruction
       */
      void LWL(const InstructionSetImmediateType& imm);

      /**
       * LWR - Load Word Right
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Shift addressed word right so that addressed byte is rightmost byte of a word.
       * Merge bytes from memory with contents of register rt and load result into register
       * rt.
       * 
       * @param[in] imm        - The immediate instruction
       */
      void LWR(const InstructionSetImmediateType& imm);

      /**
       * SB - Store Byte
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Store least significant byte of register rt at addressed location.
       * 
       * @param[in] imm        - The immediate instruction
       */
      void SB(const InstructionSetImmediateType& imm);

      /**
       * SH - Store Halfword
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Store least significant halfword of register rt at addressed location.
       * 
       * @param[in] imm        - The immediate instruction
       */
      void SH(const InstructionSetImmediateType& imm);

      /**
       * SW - Store Word
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Store least significant word of register rt at addressed location.
       * 
       * @param imm        - The immediate instruction
       */
      void SW(const InstructionSetImmediateType& imm);

      /**
       * SWL - Store Word Left
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Shift contents of register rt right so that leftmost byte of the word is in position of
       * addressed byte. Store bytes containing original data into corresponding bytes at
       * addressed byte.
       * @param imm        - The immediate instruction
       */
      void SWL(const InstructionSetImmediateType& imm);

      /**
       * SWR - Store Word Right
       * Sign-extend 16-bit offset and add to contents of register base to form address.
       * Shift contents of register rt left so that rightmost byte of the word is in position of
       * addressed byte. Store bytes containing original data into corresponding bytes at
       * addressed byte.
       * @param imm        - The immediate instruction
       */
      void SWR(const InstructionSetImmediateType& imm);

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


   private:
      MemoryController* mMemController;
      RegisterType* mRegisters;
   };
}