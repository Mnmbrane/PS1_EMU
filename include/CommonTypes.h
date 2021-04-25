#pragma once

#include "CommonVal.h"

namespace PSEmu
{
   class I_Memory;

   using Word = unsigned int;
   using HalfWord = unsigned short;
   using Byte = unsigned char;

   using Instruction = Word;

   typedef enum : Word
   {
      ZR,                              // Constant 0
      AT,                              // Reserved for the assembler
      V0, V1,                          // Values for results and expression evaluation
      A0, A2, A3,                      // Arguments
      T0, T1, T2, T3, T4, T5, T6, T7,  // Temporaries (not preserved across call)
      S0, S1, S2, S3, S4, S5, S6, S7,  // Saved (preserved across call)
      T8, T9,                          // More temporaries (not preserved across call)
      K0, K1,                          // Reserved for OS Kernel
      GP,                              // Global Pointer
      SP,                              // Stack Pointer
      FP,                              // Frame Pointer
      RA,                              // Return address (set by function call)

      MAX_GEN_REG_NUM
   } GeneralRegisterType;

   typedef enum : Word
   {
      HI,                              // Multiplication 64 bit high result or division remainder
      LO,                              // Multiplication 64 bit low result or division quotient
      PC,                              // Program Counter

      MAX_SPEC_REG_NUM
   } SpecialRegisterType; 

   typedef struct
   {
      Word genReg[MAX_GEN_REG_NUM];
      Word specReg[MAX_SPEC_REG_NUM];
   } RegisterType;

   typedef struct
   {
      unsigned int immediate  : IMM_SIZE;
      unsigned int rt         : RT_SIZE;
      unsigned int rs         : RS_SIZE;
      unsigned int op         : OP_SIZE;

   } InstructionSetImmediateType;

   typedef struct
   {
      unsigned int target  : TARGET_SIZE;
      unsigned int op      : OP_SIZE;

   } InstructionSetJumpType;

   typedef struct
   {
      unsigned int funct   : FUNCT_SIZE;
      unsigned int shamt   : SHAMT_SIZE;
      unsigned int rd      : RD_SIZE;
      unsigned int rt      : RT_SIZE;
      unsigned int rs      : RS_SIZE;
      unsigned int op      : OP_SIZE;

   } InstructionSetRegisterType;

   typedef union 
   {
      Instruction ins;
      InstructionSetImmediateType immType;
      InstructionSetJumpType      jumpType;
      InstructionSetRegisterType  regType;
   } InstructionDecodeType;

   typedef enum
   {
      E_INSTRUCTION_INVALID,
      E_INSTRUCTION_IMM,
      E_INSTRUCTION_JUMP,
      E_INSTRUCTION_REG
   } InsSelectType;

   enum OpcodeType
   {
      OP_SPECIAL,
      OP_BCOND,
      OP_J,
      OP_JAL,
      OP_BEQ,
      OP_BNE,
      OP_BLEZ,
      OP_BGTZ,
      OP_ADDI,
      OP_ADDIU,
      OP_SLTI,
      OP_SLTIU,
      OP_ANDI,
      OP_ORI, // OR Immediate
      OP_XORI,
      OP_LUI, // Load Upper Immediate
      OP_COP0,
      OP_COP1,
      OP_COP2,
      OP_COP3,
      OP_LB = 32,
      OP_LH,
      OP_LWL,
      OP_LW,
      OP_LBU,
      OP_LHU,
      OP_LWR,
      OP_SB = 40,
      OP_SH,
      OP_SWL,
      OP_SW, // Store Word
      OP_SWR = 46,
      OP_LWC0 = 48,
      OP_LWC1,
      OP_LWC2,
      OP_LWC3,
      OP_SWC0 = 56,
      OP_SWC1,
      OP_SWC2,
      OP_SWC3
   };

   enum SpecialType
   {
      SPEC_SLL,
      SPEC_SRL = 2,
      SPEC_SRA,
      SPEC_SLLV,
      SPEC_SRLV = 6,
      SPEC_SRAV,
      SPEC_JR,
      SPEC_JALR,
      SPEC_SYSCALL = 12,
      SPEC_BREAK,
      SPEC_MFHI = 16,
      SPEC_MTHI,
      SPEC_MFLO,
      SPEC_MTLO,
      SPEC_MULT = 24,
      SPEC_MULTU,
      SPEC_DIV,
      SPEC_DIVU,
      SPEC_ADD = 32,
      SPEC_ADDU,
      SPEC_SUB,
      SPEC_SUBU,
      SPEC_AND,
      SPEC_OR,
      SPEC_XOR,
      SPEC_NOR,
      SPEC_SLT = 42,
      SPEC_SLTU
   };

   // Branch conditions
   enum BCondType
   {
      BCOND_BLTZ,
      BCOND_BGEZ,
      BCOND_BLTZAL = 17,
      BCOND_BGEZAL,
   };

   enum COP
   {
      COP_MF,
      COP_CF = 2,
      COP_MT = 4,
      COP_CT = 6,
      COP_BC = 8
   };

   enum SysControlType
   {
      SC_TLBR = 1,
      SC_TLBWI,
      SC_TLBWR = 6,
      SC_TLBP = 8,
      SC_RFE = 16
   };
}