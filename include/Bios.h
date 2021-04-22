#pragma once
#include "Memory.h"

namespace PSEmu
{
   class Bios : public Memory
   {
   public:
   Bios();
   ~Bios();

   virtual void Initialize();

   private:

   // Checks if file size is equal to 512
   bool CheckSize();
   bool Checksum();
   };
}