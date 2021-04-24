#pragma once
#include "Memory.h"

namespace PSEmu
{
   class Kernel : public Memory
   {
   public:
   Kernel();
   ~Kernel();

   virtual void Initialize();

   virtual Word GetWord(const Word& address);
   virtual void StoreWord(const Word& address, Word val);

   private:
   Word GetAddrOffset(const Word& address);
   };

}