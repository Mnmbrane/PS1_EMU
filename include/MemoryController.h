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
      /**
       * Gets the Memory object tied to a specific region.
       * 
       * @param[in] addr      - Address trying to be accessed
       * @param[out] offset   - Offset of add when taking starting address
       *                        into account
       * 
       * @return - Memory object tied region
       */
      Memory* GetMemoryRegion(const Word& addr,
                              Word& out_offset);

      Bios* mBios;
   };
   
}