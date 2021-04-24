#pragma once

#include "CommonTypes.h"
#include "ComponentInterface.h"

namespace PSEmu
{
   class Memory : public I_Component
   {
   public:
      Memory(Word Size);
      virtual ~Memory();

      virtual void Reset();

      virtual Word GetWord(const Word& address) = 0;
      virtual void StoreWord(const Word& address, Word val) = 0;
      virtual void Initialize() = 0;

   protected:
      Byte* mData;
      Word mDataSize;

   private:
      Memory() = delete;

   };

}

