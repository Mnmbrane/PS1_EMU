#pragma once

namespace PSEmu
{
   using Word = unsigned int;
   using HalfWord = unsigned short;
   using Byte = unsigned char;
   using Instruction = Word;


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
   constexpr Word PC_RESET_VAL = 0xbfc00000;

   typedef struct
   {
      unsigned int op         : OP_SIZE;
      unsigned int rs         : RS_SIZE;
      unsigned int rt         : RT_SIZE;
      unsigned int immediate  : IMM_SIZE;

   } InstructionSetImmediateType;

   typedef struct
   {
      unsigned int op      : OP_SIZE;
      unsigned int target  : TARGET_SIZE;

   } InstructionSetJumpType;

   typedef struct
   {
      unsigned int op      : OP_SIZE;
      unsigned int rs      : RS_SIZE;
      unsigned int rt      : RT_SIZE;
      unsigned int rd      : RD_SIZE;
      unsigned int shamt   : SHAMT_SIZE;
      unsigned int funct   : FUNCT_SIZE;

   } InstructionSetRegisterType;

}