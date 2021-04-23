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

   // Main Ram starting and size
   constexpr unsigned int MAIN_RAM_NUM_REGION       = 3;
   constexpr unsigned int MAIN_RAM_START_ADDR_KUSEG = 0x00000000;
   constexpr unsigned int MAIN_RAM_START_ADDR_KSEG0 = 0x80000000;
   constexpr unsigned int MAIN_RAM_START_ADDR_KSEG1 = 0xa0000000;
   constexpr unsigned int MAIN_RAM_SIZE             = 2048 * 1024; // 2048K

   // Expansion Region 1 starting and size
   constexpr unsigned int EXPANSION_1_NUM_REGION       = 3;
   constexpr unsigned int EXPANSION_1_START_ADDR_KUSEG = 0x1f000000;
   constexpr unsigned int EXPANSION_1_START_ADDR_KSEG0 = 0x9f000000;
   constexpr unsigned int EXPANSION_1_START_ADDR_KSEG1 = 0xbf000000;
   constexpr unsigned int EXPANSION_1_SIZE             = 8192 * 1024; // 8192K

   // Scratchpad starting and size
   constexpr unsigned int SCRATCHPAD_NUM_REGION       = 2;
   constexpr unsigned int SCRATCHPAD_START_ADDR_KUSEG = 0x1f800000;
   constexpr unsigned int SCRATCHPAD_START_ADDR_KSEG0 = 0x9f800000;
   constexpr unsigned int SCRATCHPAD_SIZE             = 1024; // 1K

   // IO Ports starting and size
   constexpr unsigned int IO_PORTS_NUM_REGION       = 3;
   constexpr unsigned int IO_PORTS_START_ADDR_KUSEG = 0x1f801000;
   constexpr unsigned int IO_PORTS_START_ADDR_KSEG0 = 0x9f801000;
   constexpr unsigned int IO_PORTS_START_ADDR_KSEG1 = 0xbf801000;
   constexpr unsigned int IO_PORTS_SIZE             = 8 * 1024; // 8K

   // Expansion Region 2 starting and size
   constexpr unsigned int EXPANSION_2_NUM_REGION       = 3;
   constexpr unsigned int EXPANSION_2_START_ADDR_KUSEG = 0x1f802000;
   constexpr unsigned int EXPANSION_2_START_ADDR_KSEG0 = 0x9f802000;
   constexpr unsigned int EXPANSION_2_START_ADDR_KSEG1 = 0xbf802000;
   constexpr unsigned int EXPANSION_2_SIZE             = 8 * 1024; // 8K

   // Expansion Region 3 starting and size
   constexpr unsigned int EXPANSION_3_NUM_REGION       = 3;
   constexpr unsigned int EXPANSION_3_START_ADDR_KUSEG = 0x1fa00000;
   constexpr unsigned int EXPANSION_3_START_ADDR_KSEG0 = 0x9fa00000;
   constexpr unsigned int EXPANSION_3_START_ADDR_KSEG1 = 0xbfA00000;
   constexpr unsigned int EXPANSION_3_SIZE             = 2048 * 1024; // 2048K

   // Bios starting and size
   constexpr unsigned int BIOS_NUM_REGION       = 3;
   constexpr unsigned int BIOS_START_ADDR_KUSEG = 0x1fc00000;
   constexpr unsigned int BIOS_START_ADDR_KSEG0 = 0x9fc00000;
   constexpr unsigned int BIOS_START_ADDR_KSEG1 = 0xbfc00000;
   constexpr unsigned int BIOS_SIZE             = 512 * 1024; // 512KB

   // IO Ports (Cache Control) starting and size
   constexpr unsigned int IO_PORTS_CC_NUM_REGION       = 1;
   constexpr unsigned int IO_PORTS_CC_START_ADDR_KSEG2 = 0xFFFE0000;
   constexpr unsigned int IO_PORTS_CC_SIZE             = 512; // 512 bytes

   constexpr unsigned int PC_RESET_VAL          = BIOS_START_ADDR_KSEG1;

   // Size of instructions is 4 bytes
   constexpr unsigned int INSTRUCTION_SIZE = 0x4;

   // Memory sizes
   constexpr unsigned int MAX_MEM_SIZE = 0xFFFFFFFF; // 4GB
}