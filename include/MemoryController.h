#pragma once
#include "ComponentInterface.h"
#include <map>


namespace PSEmu
{
   class Kernel;
   class UserMemory;
   class ParallelPort;
   class Scratchpad;
   class HardwareRegisters;
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
       * 
       * @return - Memory object tied region
       */
      Memory* GetMemoryRegion(const Word& addr);

      Kernel*              mKernel;
      UserMemory*          mUserMemory;
      ParallelPort*        mParallelPort;
      Scratchpad*          mScratchpad;
      HardwareRegisters*   mHardwareRegisters;
      Bios*                mBios;
   };
   
}