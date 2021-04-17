#pragma once
#include "Memory.h"

namespace PSEmu
{
   class Bios : public I_Memory
   {
   public:
   Bios();
   ~Bios();

   virtual void Initialize();
   virtual void Reset();
   virtual Word GetWord(const Word& address);

   private:
   };
}