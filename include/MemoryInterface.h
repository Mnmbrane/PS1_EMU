#pragma once

#include "CommonTypes.h"
#include "ComponentInterface.h"

namespace PSEmu
{
   class I_Memory : public I_Component
   {
   public:
      I_Memory(Word Size);
      virtual ~I_Memory();

      virtual void Initialize() = 0;
      virtual void Reset() = 0;
      virtual Byte GetByte(const Word& addr) = 0;
      virtual HalfWord GetHalfWord(const Word& addr) = 0;
      virtual Word GetWord(const Word& address) = 0;
      virtual void StoreWord(const Word& address, Word val) = 0;

   protected:
      Byte* mData;

   private:
      I_Memory() = delete;

   };

}

