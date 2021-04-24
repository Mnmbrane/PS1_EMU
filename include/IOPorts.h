#pragma once
#include "Memory.h"

namespace PSEmu
{
   class IOPorts : public Memory
   {
   public:
   IOPorts();
   ~IOPorts();

   virtual void Initialize();

   private:

   };
}