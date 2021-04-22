#pragma once
#include "MemoryInterface.h"

namespace PSEmu
{
   class Bios : public I_Memory
   {
   public:
   Bios();
   ~Bios();

   virtual bool Initialize();

   private:

   // Checks if file size is equal to 512
   bool CheckSize();
   bool Checksum();
   };
}