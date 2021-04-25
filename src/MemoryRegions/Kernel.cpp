#include "Kernel.h"
#include "CommonTypes.h"
#include <exception>
#include <string.h>

using namespace PSEmu;



Kernel::Kernel() :
   I_Memory(KERNEL_SIZE)
{
}

Kernel::~Kernel() { }

void Kernel::Initialize() 
{
   
}

void Kernel::Reset()
{
   // Set memory to garbage
   memset(mData, GARBAGE, KERNEL_SIZE);
}

Byte Kernel::GetByte(const Word& addr) 
{
   Word retWord = 0;
   Word offset = GetAddrOffset(addr);

   if(offset < 0 || offset >= KERNEL_SIZE)
   {
      throw std::exception();
   }
   return *((Byte*)&(mData[offset]));
}

HalfWord Kernel::GetHalfWord(const Word& addr) 
{
   Word offset = GetAddrOffset(addr);

   if(offset < 0 || offset >= KERNEL_SIZE)
   {
      throw std::exception();
   }
   return *((HalfWord*)&(mData[offset]));
}

Word Kernel::GetWord(const Word& address) 
{
   Word offset = GetAddrOffset(address);

   if(offset < 0 || offset >= KERNEL_SIZE)
   {
      throw std::exception();
   }
   return *((Word*)&(mData[offset]));
}

void Kernel::StoreByte(const Word& addr, Word val) 
{
   Word offset = GetAddrOffset(addr);
   if(offset < 0 || offset >= KERNEL_SIZE)
   {
      throw std::exception();
   }
   *(Byte*)(&mData[offset]) = val;
}
   
void Kernel::StoreHalfWord(const Word& addr, Word val)
{
   Word offset = GetAddrOffset(addr);
   if(offset < 0 || offset >= KERNEL_SIZE)
   {
      throw std::exception();
   }
   *(HalfWord*)(&mData[offset]) = val;
}

void Kernel::StoreWord(const Word& addr, Word val) 
{
   Word offset = GetAddrOffset(addr);
   if(offset < 0 || offset >= KERNEL_SIZE)
   {
      throw std::exception();
   }
   *(Word*)(&mData[offset]) = val;
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