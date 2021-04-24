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

   virtual Word GetWord(const Word& address);
   virtual void StoreWord(const Word& address, Word val);

   private:

   };

}