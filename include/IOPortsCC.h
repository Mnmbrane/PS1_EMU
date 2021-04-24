#pragma once
#include "Memory.h"

namespace PSEmu
{
   class IOPortsCC : public Memory
   {
   public:
   IOPortsCC();
   ~IOPortsCC();

   virtual void Initialize();

   private:

   };
}