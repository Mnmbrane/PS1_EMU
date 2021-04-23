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
      virtual Word GetWord(const Word& address);
      virtual void SetWord(const Word& address, Word val);

      virtual void Initialize() = 0;

   protected:
      Byte* mData;

   private:
      Memory() = delete;

      Word mDataSize;
   };

}

