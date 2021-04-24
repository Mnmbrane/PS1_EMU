#pragma once
#include "ComponentInterface.h"
#include <map>


namespace PSEmu
{

   class Expansion1;
   class Expansion2;
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
      bool CheckAddrInRange(const Word& addr,
                            const Word& startAddr,
                            const Word& memSize);
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


      Expansion1* mExpansion1;
      Expansion2* mExpansion2;
      Bios* mBios;


   };
   
}