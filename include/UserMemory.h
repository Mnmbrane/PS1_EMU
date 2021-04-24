#pragma once
#include "Memory.h"

namespace PSEmu
{
   class UserMemory : public Memory
   {
   public:
   UserMemory();
   ~UserMemory();

   virtual void Initialize();

   virtual Word GetWord(const Word& address);
   virtual void StoreWord(const Word& address, Word val);

   private:
   Word GetAddrOffset(const Word& address);

   };
}