#include "UserMemory.h"
#include "CommonTypes.h"

#include <exception>
#include <string.h>

using namespace PSEmu;

UserMemory::UserMemory() :
   Memory(USER_MEM_SIZE)
{
}

UserMemory::~UserMemory() { }

void UserMemory::Initialize() 
{
   
}

Word UserMemory::GetWord(const Word& address) 
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
   
void UserMemory::StoreWord(const Word& address, Word val) 
{
   Word retWord = 0;
   Word offset = GetAddrOffset(address);

   if(offset < 0 || offset >= mDataSize)
   {
      throw std::exception();
   }
   memcpy((void*)&(mData[offset]), (void*)(&val), sizeof(Word));
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