#pragma once

namespace CommonTypes
{
   using Word = unsigned int;
   using HalfWord = unsigned short;
   using Byte = unsigned char;
   using Instruction = Word;


   constexpr Word opSize = 6;
   constexpr Word rsSize = 5;
   constexpr Word rtSize = 5;
   constexpr Word immediateSize = 16;
   constexpr Word targetSize = 26;
   constexpr Word rdSize = 5;
   constexpr Word shamtSize = 5;
   constexpr Word functSize = 6;
   constexpr Word otherSize = 26;

   // beginning of the BIOS
   constexpr Word PC_RESET_VAL = 0xbfc00000;

   typedef struct
   {
      unsigned int op         : opSize;
      unsigned int rs         : rsSize;
      unsigned int rt         : rtSize;
      unsigned int immediate  : immediateSize;

   } InstructionSetImmediateType;

   typedef struct
   {
      unsigned int op      : opSize;
      unsigned int target  : targetSize;

   } InstructionSetJumpType;

   typedef struct
   {
      unsigned int op      : opSize;
      unsigned int rs      : rsSize;
      unsigned int rt      : rtSize;
      unsigned int rd      : rdSize;
      unsigned int shamt   : shamtSize;
      unsigned int funct   : functSize;

   } InstructionSetRegisterType;

}