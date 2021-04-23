#pragma once
#include "Config.h"

namespace PSEmu
{
   const constexpr char* BIOS_FILE_LOC = BIOS_PATH_DATA;

   constexpr unsigned int GARBAGE = 0x6B6B6B6B;

   // Sizes of fields contained within Instructions
   constexpr unsigned char OP_SIZE     = 6;
   constexpr unsigned char RS_SIZE     = 5;
   constexpr unsigned char RT_SIZE     = 5;
   constexpr unsigned char IMM_SIZE    = 16;
   constexpr unsigned char TARGET_SIZE = 26;
   constexpr unsigned char RD_SIZE     = 5;
   constexpr unsigned char SHAMT_SIZE  = 5;
   constexpr unsigned char FUNCT_SIZE  = 6;

   // Bios starting and size
   constexpr unsigned int BIOS_START_ADDR_KUSEG = 0x1fc00000;
   constexpr unsigned int BIOS_START_ADDR_KSEG0 = 0x9fc00000;
   constexpr unsigned int BIOS_START_ADDR_KSEG1 = 0xbfc00000;
   constexpr unsigned int BIOS_SIZE             = 0x200 * 0x400; // 512KB

   constexpr unsigned int PC_RESET_VAL          = BIOS_START_ADDR_KSEG1;

   // Size of instructions is 4 bytes
   constexpr unsigned int INSTRUCTION_SIZE = 0x4;

   // Memory sizes
   constexpr unsigned int MAX_MEM_SIZE = 0xFFFFFFFF; // 4GB
}