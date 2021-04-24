#pragma once
#include "Memory.h"

namespace PSEmu
{
   class Scratchpad : public Memory
   {
   public:
   Scratchpad();
   ~Scratchpad();

   virtual void Initialize();

   virtual Word GetWord(const Word& address);
   virtual void StoreWord(const Word& address, Word val);

   private:

   };
}