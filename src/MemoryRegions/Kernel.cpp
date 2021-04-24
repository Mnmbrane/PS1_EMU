#include "Kernel.h"
#include "CommonTypes.h"
#include <exception>
#include <string.h>

using namespace PSEmu;



Kernel::Kernel() :
   Memory(KERNEL_SIZE)
{
}

Kernel::~Kernel() { }

void Kernel::Initialize() 
{
   
}

Word Kernel::GetWord(const Word& address) 
{
   Word retWord = 0;
   Word offset = GetAddrOffset(address);

   if(offset < 0 || offset >= mDataSize)
   {
      throw std::exception();
   }
   memcpy((void*)&retWord, (void*)&(mData[offset]), sizeof(Word));
   return retWord;
}

void Kernel::StoreWord(const Word& address, Word val) 
{
   Word retWord = 0;
   Word offset = GetAddrOffset(address);
   if(offset < 0 || offset >= mDataSize)
   {
      throw std::exception();
   }
   memcpy((void*)&(mData[offset]), (void*)(&val), sizeof(Word));
}

Word Kernel::GetAddrOffset(const Word& address) 
{
   Word offset = 0;
   if(address >= 0 && address <= KERNEL_ADDR_1)
   {
      offset = address - KERNEL_ADDR_1;
   }
   else if(address >= 0 && address <= KERNEL_ADDR_2)
   {
      offset = address - KERNEL_ADDR_2;
   }
   else if(address >= 0 && address <= KERNEL_ADDR_3)
   {
      offset = address - KERNEL_ADDR_3;
   }
   return offset;
}