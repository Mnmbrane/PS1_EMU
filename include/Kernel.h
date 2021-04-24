#pragma once
#include "MemoryInterface.h"

namespace PSEmu
{
   class Kernel : public I_Memory
   {
   public:
   Kernel();
   ~Kernel();

   virtual void Initialize();
   virtual void Reset();

   virtual Byte GetByte(const Word& addr);
   virtual HalfWord GetHalfWord(const Word& addr);
   virtual Word GetWord(const Word& address);
   virtual void StoreWord(const Word& address, Word val);

   private:
   Word GetAddrOffset(const Word& address);
   };

}