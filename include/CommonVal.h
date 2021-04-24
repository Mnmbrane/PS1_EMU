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

   // Kernel starting and size
   constexpr unsigned int KERNEL_ADDR_1 = 0x00000000;
   constexpr unsigned int KERNEL_ADDR_2 = 0x80000000;
   constexpr unsigned int KERNEL_ADDR_3 = 0xa0000000;
   constexpr unsigned int KERNEL_SIZE   = 0x10000;

   // User Memory
   constexpr unsigned int USER_MEM_ADDR_1 = 0x00010000;
   constexpr unsigned int USER_MEM_ADDR_2 = 0x80010000;
   constexpr unsigned int USER_MEM_ADDR_3 = 0xa0010000;
   constexpr unsigned int USER_MEM_SIZE   = 0x1f0000;

   // Parallel Port
   constexpr unsigned int PARALLEL_PORT_ADDR = 0x1f000000;
   constexpr unsigned int PARALLEL_PORT_SIZE = 0x10000;

   // Scratchpad starting and size
   constexpr unsigned int SCRATCHPAD_ADDR = 0x1f800000;
   constexpr unsigned int SCRATCHPAD_SIZE = 0x400;

   // IO Ports starting and size
   constexpr unsigned int HW_REG_ADDR = 0x1f801000;
   constexpr unsigned int HW_REG_SIZE = 0x2000;

   // Bios starting and size
   constexpr unsigned int BIOS_ADDR = 0xbfc00000;
   constexpr unsigned int BIOS_SIZE = 0x80000;


   constexpr unsigned int PC_RESET_VAL          = BIOS_ADDR;

   // Size of instructions is 4 bytes
   constexpr unsigned int INSTRUCTION_SIZE = 0x4;

   // Memory sizes
   constexpr unsigned int MAX_MEM_SIZE = 0xFFFFFFFF; // 4GB
}