#pragma once

#include "CommonVal.h"

namespace PSEmu
{
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
      OP_LUI = 0b001111, // Load Upper Immediate
      OP_ORI = 0b001101, // OR Immediate
   };
}