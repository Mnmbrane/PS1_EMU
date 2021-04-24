#pragma once
#include "Memory.h"

namespace PSEmu
{
   class MainRam : public Memory
   {
   public:
   MainRam();
   ~MainRam();

   virtual void Initialize();

   private:

   };
}