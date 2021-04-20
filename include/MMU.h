#pragma once
#include "Component.h"


namespace PSEmu
{
   class Bios;

   class MMU : public I_Component
   {
   public:
      MMU();
      ~MMU();
      virtual bool Initialize();
      virtual void Reset();

      // Get word from a location
      Word GetWord(const Word& addr);

      void StoreWord(const Word& addr, const Word val);
   private:
      Bios* mBios;
   };
   
}