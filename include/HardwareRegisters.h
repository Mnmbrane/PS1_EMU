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

   private:

   };
}