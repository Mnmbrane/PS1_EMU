#pragma once

#include "CommonTypes.h"

namespace PSEmu
{
   class Memory
   {
   public:
      Memory();
      ~Memory();

      void Reset();
      Word GetWord(const Word& address);
   private:
      // TODO: Fix the size
      Byte* mData;
   };
}

