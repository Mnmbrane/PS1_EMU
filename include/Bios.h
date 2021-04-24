#pragma once
#include "MemoryInterface.h"

namespace PSEmu
{
   class Bios : public I_Memory
   {
   public:
   Bios();
   ~Bios();

   virtual void Initialize();
   virtual void Reset();

   virtual Byte GetByte(const Word& addr);
   virtual HalfWord GetHalfWord(const Word& addr);
   virtual Word GetWord(const Word& addr);
   virtual void StoreWord(const Word& addr, Word val);

   private:

   // Checks if file size is equal to 512
   bool CheckSize();
   bool Checksum();
   };
}