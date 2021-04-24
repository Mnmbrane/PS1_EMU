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

   virtual Word GetWord(const Word& address);
   virtual void StoreWord(const Word& address, Word val);

   private:

   // Checks if file size is equal to 512
   bool CheckSize();
   bool Checksum();
   };
}