#include "MemoryController.h"
#include "Bios.h"

#include <stdio.h>

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
Memory* MemoryController::GetMemoryRegion(const Word& addr)
{
   if(addr >= BIOS_START_ADDR && addr < (BIOS_START_ADDR + BIOS_SIZE))
   {
      return mBios;
   }
   return nullptr;
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
      memRegion = GetMemoryRegion(addr);
      if(memRegion != nullptr)
      {
         offset = addr - memRegion->GetStartingAddress();
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