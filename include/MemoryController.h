#pragma once
#include "ComponentInterface.h"


namespace PSEmu
{
   class Bios;
   class Memory;

   class MemoryController : public I_Component
   {
   public:
      MemoryController();
      ~MemoryController();

      virtual void Initialize();
      virtual void Reset();

      // Get word from a location
      Word GetWord(const Word& addr);

      void StoreWord(const Word& addr, const Word val);

   private:
      Memory* GetMemoryRegion(const Word& addr);

      Bios* mBios;
   };
   
}