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
   class I_Memory;

   class MemoryController : public I_Component
   {
   public:
      MemoryController();
      ~MemoryController();

      virtual void Initialize();
      virtual void Reset();

      Byte GetByte(const Word& addr);
      HalfWord GetHalfWord(const Word& addr);
      Word GetWord(const Word& addr);
      
      void StoreByte(const Word& addr, const Word val);
      void StoreHalfWord(const Word& addr, const Word val);
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
      I_Memory* GetMemoryRegion(const Word& addr);

      Kernel*              mKernel;
      UserMemory*          mUserMemory;
      ParallelPort*        mParallelPort;
      Scratchpad*          mScratchpad;
      HardwareRegisters*   mHardwareRegisters;
      Bios*                mBios;
   };
   
}