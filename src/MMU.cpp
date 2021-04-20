#include "MMU.h"
#include "Bios.h"

#include <stdio.h>

using namespace PSEmu;

MMU::MMU():
   mBios(new Bios())
{
}

MMU::~MMU() 
{
   delete mBios;
}

bool MMU::Initialize() 
{
   bool retVal = false;

   // Initialize the bios
   retVal = mBios->Initialize();

   return retVal;
}

void MMU::Reset()
{
   mBios->Reset();
}

// Memory Mapping
Word MMU::GetWord(const Word& addr) 
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

void MMU::StoreWord(const Word& addr, const Word val) 
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