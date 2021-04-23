#include "MemoryController.h"
#include "Bios.h"

#include <stdio.h>
#include <map>

using namespace PSEmu;


MemoryController::MemoryController():
   mBios(new Bios())
{
}

MemoryController::~MemoryController() 
{
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
   // BIOS
   if(addr >= BIOS_START_ADDR_KUSEG && addr < (BIOS_START_ADDR_KUSEG + BIOS_SIZE))
   {
      out_offset = addr - BIOS_START_ADDR_KUSEG;
      retMem = mBios;
   }
   else if(addr >= BIOS_START_ADDR_KSEG0 && addr < (BIOS_START_ADDR_KSEG0 + BIOS_SIZE))
   {
      out_offset = addr - BIOS_START_ADDR_KSEG0;
      retMem = mBios;
   }
   else if(addr >= BIOS_START_ADDR_KSEG1 && addr < (BIOS_START_ADDR_KSEG1 + BIOS_SIZE))
   {
      out_offset = addr - BIOS_START_ADDR_KSEG1;
      retMem = mBios;
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
   // Address needs to be word aligned
   if(addr % 4 != 0)
   {
      printf("ERROR: %s Unaligned address", __func__);
   }
   else
   {
      // TODO
   }
}