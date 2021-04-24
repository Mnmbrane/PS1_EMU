#pragma once
#include "MemoryInterface.h"

namespace PSEmu
{
   class Scratchpad : public I_Memory
   {
   public:
   Scratchpad();
   ~Scratchpad();

   virtual void Initialize();
   virtual void Reset();

   virtual Byte GetByte(const Word& addr);
   virtual HalfWord GetHalfWord(const Word& addr);
   virtual Word GetWord(const Word& address);
   virtual void StoreWord(const Word& address, Word val);

   private:

   };
}