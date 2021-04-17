#pragma once

#include "CommonTypes.h"
#include "Component.h"

namespace PSEmu
{
   class I_Memory : public I_Component
   {
   public:
      I_Memory(Word Size);
      virtual ~I_Memory();

      virtual void Reset();
      virtual Word GetWord(const Word& address);
   
   protected:
      Byte* mData;

   private:
      I_Memory() = delete;
      // TODO: Fix the size
   };
}

