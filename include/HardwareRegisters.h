#pragma once
#include "MemoryInterface.h"

namespace PSEmu
{
   class HardwareRegisters : public I_Memory
   {
   public:
   HardwareRegisters();
   ~HardwareRegisters();

   virtual void Initialize();
   virtual void Reset();

   virtual Byte GetByte(const Word& addr);
   virtual HalfWord GetHalfWord(const Word& addr);
   virtual Word GetWord(const Word& address);

   virtual void StoreByte(const Word& addr, Word val);
   virtual void StoreHalfWord(const Word& addr, Word val);
   virtual void StoreWord(const Word& address, Word val);

   private:
   };
}