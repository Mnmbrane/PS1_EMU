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

   private:

   };
}