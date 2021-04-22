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

void MemoryController::Reset()
{
   mBios->Reset();
}

// Memory Mapping
Word MemoryController::GetWord(const Word& addr) 
{
   Word offset = 0;
   Word retVal = 0;

   // Address needs to be word aligned
   if(addr % 4 != 0)
   {
      printf("ERROR: %s Unaligned address", __func__);
   }
   else
   {
      // If address is in bios, then get the word
      if(addr >= BIOS_START_ADDR && addr < (BIOS_START_ADDR + BIOS_SIZE))
      {
         offset = addr - BIOS_START_ADDR;
         retVal = mBios->GetWord(addr - BIOS_START_ADDR);
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