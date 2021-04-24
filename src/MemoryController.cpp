#include "MemoryController.h"
#include "Expansion1.h"
#include "Expansion2.h"
#include "Bios.h"
#include <stdio.h>
#include <exception>

using namespace PSEmu;

// Switch Case ranges between x and x+y
#define GET_RANGE(x, y) x ... (x + y)

MemoryController::MemoryController():
   mExpansion1(new Expansion1()),
   mExpansion2(new Expansion2()),
   mBios(new Bios())
{
}

MemoryController::~MemoryController() 
{
   delete mExpansion1;
   delete mExpansion2;
   delete mBios;
}

void MemoryController::Initialize() 
{
   // Initialize the bios
   mBios->Initialize();
}

// Memory Region factory
Memory* MemoryController::GetMemoryRegion(const Word& addr, Word& out_offset)
{
   Memory* retMem = nullptr;
   
   switch(addr)
   {
      // Main Ram
      case GET_RANGE(MAIN_RAM_START_ADDR_KUSEG, MAIN_RAM_SIZE):
         out_offset = addr - MAIN_RAM_START_ADDR_KUSEG;
         retMem = mExpansion1;
         break;
      case GET_RANGE(MAIN_RAM_START_ADDR_KSEG0, MAIN_RAM_SIZE):
         out_offset = addr - MAIN_RAM_START_ADDR_KUSEG;
         retMem = mExpansion1;
         break;
      case GET_RANGE(MAIN_RAM_START_ADDR_KSEG1, MAIN_RAM_SIZE):
         out_offset = addr - MAIN_RAM_START_ADDR_KUSEG;
         retMem = mExpansion1;
         break;
      // Expansion 1
      case GET_RANGE(EXPANSION_1_START_ADDR_KUSEG, EXPANSION_1_SIZE):
         out_offset = addr - EXPANSION_1_START_ADDR_KUSEG;
         retMem = mExpansion1;
         break;
      case GET_RANGE(EXPANSION_1_START_ADDR_KSEG0, EXPANSION_1_SIZE):
         out_offset = addr - EXPANSION_1_START_ADDR_KSEG0;
         retMem = mExpansion1;
         break;
      case GET_RANGE(EXPANSION_1_START_ADDR_KSEG1, EXPANSION_1_SIZE):
         out_offset = addr - EXPANSION_1_START_ADDR_KSEG1;
         retMem = mExpansion1;
         break;

      // Expansion 2
      case GET_RANGE(EXPANSION_2_START_ADDR_KUSEG, EXPANSION_2_SIZE):
         out_offset = addr - EXPANSION_1_START_ADDR_KUSEG;
         retMem = mExpansion2;
         break;
      case GET_RANGE(EXPANSION_2_START_ADDR_KSEG0, EXPANSION_2_SIZE):
         out_offset = addr - EXPANSION_1_START_ADDR_KSEG0;
         retMem = mExpansion2;
         break;
      case GET_RANGE(EXPANSION_2_START_ADDR_KSEG1, EXPANSION_2_SIZE):
         out_offset = addr - EXPANSION_2_START_ADDR_KSEG1;
         retMem = mExpansion2;
         break;
      
      // Bios
      case GET_RANGE(BIOS_START_ADDR_KUSEG, BIOS_SIZE):
         out_offset = addr - BIOS_START_ADDR_KUSEG;
         retMem = mBios;
         break;
      case GET_RANGE(BIOS_START_ADDR_KSEG0, BIOS_SIZE):
         out_offset = addr - BIOS_START_ADDR_KSEG0;
         retMem = mBios;
         break;
      case GET_RANGE(BIOS_START_ADDR_KSEG1, BIOS_SIZE):
         out_offset = addr - BIOS_START_ADDR_KSEG1;
         retMem = mBios;
         break;
      default:
         break;
   }
   return retMem;
}

void MemoryController::Reset()
{
   mBios->Reset();
}

// Memory Mapping
Word MemoryController::GetWord(const Word& addr) 
{
   Word offset = 0;
   Word retVal = 0;
   Memory* memRegion = nullptr;

   // Address needs to be word aligned
   if(addr % 4 != 0)
   {
      printf("ERROR: %s Unaligned address", __func__);
   }
   else
   {
      memRegion = GetMemoryRegion(addr, offset);
      if(memRegion != nullptr)
      {
         retVal = memRegion->GetWord(offset);
      }
   }

   return retVal;
}

void MemoryController::StoreWord(const Word& addr, const Word val) 
{
   Word offset = 0;
   Memory* memRegion = nullptr;
   // Address needs to be word aligned
   if(addr % 4 != 0)
   {
      printf("ERROR: %s Unaligned address", __func__);
   }
   else
   {
      memRegion = GetMemoryRegion(addr, offset);
      if(memRegion == mBios ||
         memRegion == mExpansion1 ||
         memRegion == mExpansion2)
      {
         throw std::exception();
      }
      else if(memRegion != nullptr)
      {
         memRegion->StoreWord(offset, val);
      }

   }
}

bool MemoryController::CheckAddrInRange(const Word& addr,
                            const Word& startAddr,
                            const Word& memSize) 
{
   return (addr >= startAddr && addr < (startAddr + memSize));
}