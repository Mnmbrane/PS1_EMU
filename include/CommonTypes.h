#pragma once

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
      HI,                              // Multiplication 64 bit high result or division remainder
      LO,                              // Multiplication 64 bit low result or division quotient
      PC,                              // Program Counter

      MAX_REG_NUM
   } RegisterType;

   const constexpr char* BIOS_FILE_LOC = "external_bin/bios.bin";

   // Sizes of fields contained within Instructions
   constexpr Word OP_SIZE = 6;
   constexpr Word RS_SIZE = 5;
   constexpr Word RT_SIZE = 5;
   constexpr Word IMM_SIZE = 16;
   constexpr Word TARGET_SIZE = 26;
   constexpr Word RD_SIZE = 5;
   constexpr Word SHAMT_SIZE = 5;
   constexpr Word FUNCT_SIZE = 6;

   // beginning of the BIOS
   constexpr Word BIOS_START_ADDR = 0xbfc00000;
   constexpr Word PC_RESET_VAL = BIOS_START_ADDR;

   // Size of instructions is 4 bytes
   constexpr Word INSTRUCTION_SIZE = 0x4;

   // Memory sizes
   constexpr Word BIOS_SIZE = 0x200 * 0x400;
   constexpr Word MAX_MEM_SIZE = 0xFFFFFFFF;

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
      InstructionSetImmediateType immType;
      InstructionSetJumpType      jumpType;
      InstructionSetRegisterType  regType;
   } InstructionSetType;

   typedef enum
   {
      E_INSTRUCTION_INVALID,
      E_INSTRUCTION_IMM,
      E_INSTRUCTION_JUMP,
      E_INSTRUCTION_REG
   } InsSelectType;

   typedef struct 
   {
      InstructionSetType instruction;
      InsSelectType insSelect;
   } InstructionDecodeType;

}