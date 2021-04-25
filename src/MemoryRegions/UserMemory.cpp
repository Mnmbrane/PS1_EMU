#include "UserMemory.h"
#include "CommonTypes.h"

#include <exception>
#include <string.h>

using namespace PSEmu;

UserMemory::UserMemory() :
   I_Memory(USER_MEM_SIZE)
{
}

UserMemory::~UserMemory() { }

void UserMemory::Initialize() 
{
   
}

void UserMemory::Reset()
{
   // Set memory to garbage
   memset(mData, GARBAGE, USER_MEM_SIZE);
}

Byte UserMemory::GetByte(const Word& addr) 
{
   Word offset = GetAddrOffset(addr);

   if(offset < 0 || offset >= USER_MEM_SIZE)
   {
      throw std::exception();
   }
   return *((Byte*)&(mData[offset]));
}

HalfWord UserMemory::GetHalfWord(const Word& addr) 
{
   Word offset = GetAddrOffset(addr);

   if(offset < 0 || offset >= USER_MEM_SIZE)
   {
      throw std::exception();
   }
   return *((HalfWord*)&(mData[offset]));
}

Word UserMemory::GetWord(const Word& address) 
{
   Word offset = GetAddrOffset(address);

   if(offset < 0 || offset >= USER_MEM_SIZE)
   {
      throw std::exception();
   }
   return *((Word*)&(mData[offset]));
}

void UserMemory::StoreByte(const Word& addr, Word val) 
{
   Word offset = GetAddrOffset(addr);

   if(offset < 0 || offset >= USER_MEM_SIZE)
   {
      throw std::exception();
   }
   *(Word*)(&mData[offset]) = 0;
   *(Byte*)(&mData[offset]) = val;
}

void UserMemory::StoreHalfWord(const Word& addr, Word val)
{
   Word offset = GetAddrOffset(addr);

   if(offset < 0 || offset >= USER_MEM_SIZE)
   {
      throw std::exception();
   }
   *(Word*)(&mData[offset]) = 0;
   *(HalfWord*)(&mData[offset]) = val;
}

void UserMemory::StoreWord(const Word& address, Word val) 
{
   Word offset = GetAddrOffset(address);

   if(offset < 0 || offset >= USER_MEM_SIZE)
   {
      throw std::exception();
   }
   *(Word*)(&mData[offset]) = val;
}

Word UserMemory::GetAddrOffset(const Word& address) 
{
   Word offset = 0;
   if(address >= 0 && address <= USER_MEM_ADDR_1)
   {
      offset = address - USER_MEM_ADDR_1;
   }
   else if(address >= 0 && address <= USER_MEM_ADDR_2)
   {
      offset = address - USER_MEM_ADDR_2;
   }
   else if(address >= 0 && address <= USER_MEM_ADDR_3)
   {
      offset = address - USER_MEM_ADDR_3;
   }
   return offset;
}