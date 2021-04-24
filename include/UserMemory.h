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

   private:

   };
}