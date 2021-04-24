#pragma once
#include "Memory.h"

namespace PSEmu
{
   class HardwareRegisters : public Memory
   {
   public:
   HardwareRegisters();
   ~HardwareRegisters();

   virtual void Initialize();

   virtual Word GetWord(const Word& address);
   virtual void StoreWord(const Word& address, Word val);

   private:
   };

}