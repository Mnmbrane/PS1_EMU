#pragma once

namespace PSEmu
{
   const constexpr char* BIOS_FILE_LOC = "external_bin/bios.bin";

   // Sizes of fields contained within Instructions
   constexpr unsigned char OP_SIZE     = 6;
   constexpr unsigned char RS_SIZE     = 5;
   constexpr unsigned char RT_SIZE     = 5;
   constexpr unsigned char IMM_SIZE    = 16;
   constexpr unsigned char TARGET_SIZE = 26;
   constexpr unsigned char RD_SIZE     = 5;
   constexpr unsigned char SHAMT_SIZE  = 5;
   constexpr unsigned char FUNCT_SIZE  = 6;

   // beginning of the BIOS
   constexpr unsigned int BIOS_START_ADDR   = 0xbfc00000;
   constexpr unsigned int PC_RESET_VAL      = BIOS_START_ADDR;

   // Size of instructions is 4 bytes
   constexpr unsigned int INSTRUCTION_SIZE = 0x4;

   // Memory sizes
   constexpr unsigned int BIOS_SIZE    = 0x200 * 0x400;
   constexpr unsigned int MAX_MEM_SIZE = 0xFFFFFFFF; // 4GB
}