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

      // Intialize will be implemented by concrete classes
      virtual bool Initialize() = 0;

      virtual void Reset();
      virtual Word GetWord(const Word& address);
      virtual void SetWord(const Word& address, Word val);
   
   protected:
      Byte* mData;

   private:
      I_Memory() = delete;
      Word mDataSize;
   };
}

