#pragma once
#include "Memory.h"

namespace PSEmu
{
   class ParallelPort : public Memory
   {
   public:
   ParallelPort();
   ~ParallelPort();

   virtual void Initialize();

   private:

   };
}