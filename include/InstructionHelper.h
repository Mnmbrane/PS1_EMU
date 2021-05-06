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
       * ADDI - ADD Immediate
       * Add 16-bit sign-extended immediate to register rs and place 32-bit result in
       * register rt . Trap on two’s complement overflow.
       * 
       * @param imm        - The immediate instruction
       */
      void ADDI(const InstructionSetImmediateType& imm);

      /**
       * ADDIU - ADD Immediate Unsigned
       * Add 16-bit sign-extended immediate to register rs and place 32-bit result in
       * register rt . Do not trap on overflow.
       * 
       * @param imm        - The immediate instruction
       */
      void ADDIU(const InstructionSetImmediateType& imm);

      /**
       * SLTI - Set on Less Than Immediate
       * Compare 16-bit sign-extended immediate with register rs as signed 32-bit
       * integers. Result = 1 if rs is less than immediate; otherwise result = 0.
       * Place result in register rt.
       * 
       * @param imm        - The immediate instruction
       */
      void SLTI(const InstructionSetImmediateType& imm);

      /**
       * SLTIU - Set on Less Than Unsigned Immediate
       * Compare 16-bit sign-extended immediate with register rs as unsigned 32-bit
       * integers. Result = 1 if rs is less than immediate; otherwise result = 0. Place
       * result in register rt. Do not trap on overflow.
       *
       * @param imm        - The immediate instruction
       */
      void SLTIU(const InstructionSetImmediateType& imm);

      /**
       * ANDI - AND Immediate
       * Zero-extend 16-bit immediate, AND with contents of register rs and place result
       * in register rt.
       *
       * @param imm        - The immediate instruction
       */
      void ANDI(const InstructionSetImmediateType& imm);

      /**
       * ORI - OR Immediate
       * Zero-extend 16-bit immediate, OR with contents of register rs and place result in
       * register rt.
       * 
       * @param imm        - The immediate instruction
       */
      void ORI(const InstructionSetImmediateType& imm);

      /**
       * XORI - Exclusive OR Immediate
       * Zero-extend 16-bit immediate, exclusive OR with contents of register rs and
       * place result in register rt.
       * 
       * @param imm        - The immediate instruction
       */
      void XORI(const InstructionSetImmediateType& imm);

      /**
       * LUI - Load Upper Immediate
       * Shift 16-bit immediate left 16 bits. Set least significant 16 bits of word to zeroes.
       * Store result in register rt.
       * 
       * @param[in] imm        - The immediate instruction
       */
      void LUI(const InstructionSetImmediateType& imm);

      /**
       * ADD - Add
       * Add contents of registers rs and rt and place 32-bit result in register rd. Trap on
       * two’s complement overflow.
       *
       * @param[in] reg         - The register instruction
       */
      void ADD(const InstructionSetRegisterType& reg);

      /**
       * ADDU - Add Unsigned
       * Add contents of registers rs and rt and place 32-bit result in register rd. Do not
       * trap on overflow.
       * 
       * @param[in] reg         - The register instruction
       */
      void ADDU(const InstructionSetRegisterType& reg);

      /**
       * SUB - Subtract
       * Subtract contents of registers rt and rs and place 32-bit result in register rd. Trap
       * on two’s complement overflow.
       *
       * @param[in] reg         - The register instruction
       */
      void SUB(const InstructionSetRegisterType& reg);

      /**
       * SUBU - Subtract Unsigned
       * Subtract contents of registers rt and rs and place 32-bit result in register rd. Do
       * not trap on overflow.
       *
       * @param[in] reg         - The register instruction
       */
      void SUBU(const InstructionSetRegisterType& reg);

      /**
       * SLT - Set on Less Than
       * Compare contents of register rt to register rs (as signed 32-bit integers).
       * If register rs is less than rt, result = 1; otherwise, result = 0.
       *
       * @param[in] reg         - The register instruction
       */
      void SLT(const InstructionSetRegisterType& reg);

      /**
       * SLTU - Set on Less Than Unsigned
       * Compare contents of register rt to register rs (as unsigned 32-bit integers). If
       * register rs is less than rt, result = 1; otherwise, result = 0.
       *
       * @param[in] reg         - The register instruction
       */
      void SLTU(const InstructionSetRegisterType& reg);

      /**
       * AND - And
       * Bit-wise AND contents of registers rs and rt and place result in register rd.
       *
       * @param[in] reg         - The register instruction
       */
      void AND(const InstructionSetRegisterType& reg);

      /**
       * OR - Or
       * Bit-wise OR contents of registers rs and rt and place result in register rd.
       *
       * @param[in] reg         - The register instruction
       */
      void OR(const InstructionSetRegisterType& reg);

      /**
       * XOR - Exclusive Or
       * Bit-wise Exclusive OR contents of registers rs and rt and place result in register
       * rd.
       *
       * @param[in] reg         - The register instruction
       */
      void XOR(const InstructionSetRegisterType& reg);

      /**
       * NOR - Load Upper Immediate
       * Bit-wise NOR contents of registers rs and rt and place result in register rd.
       *
       * @param[in] reg         - The register instruction
       */

      void NOR(const InstructionSetRegisterType& reg);

   private:
      static bool CheckAddOverflow(const SWord& num1, const SWord& num2);
      static bool CheckSubOverflow(const SWord& num1, const SWord& num2);
      MemoryController* mMemController;
      RegisterType* mRegisters;
   };
}