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

   private:

   };
}