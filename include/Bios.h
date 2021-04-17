#pragma once
#include "Memory.h"

namespace PSEmu
{
   class Bios : public I_Memory
   {
   public:
   Bios();
   ~Bios();

   virtual bool Initialize();
   virtual void Reset();
   virtual Word GetWord(const Word& address);

   private:
   // Checks if file size is equal to 512
   bool CheckSize();

   bool Checksum();

   
   };
}