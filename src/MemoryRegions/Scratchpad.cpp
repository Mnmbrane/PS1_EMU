#include "Scratchpad.h"
#include "CommonTypes.h"

#include <exception>
#include <string.h>

using namespace PSEmu;

Scratchpad::Scratchpad() :
   I_Memory(SCRATCHPAD_SIZE)
{
}

Scratchpad::~Scratchpad() { }

void Scratchpad::Initialize() 
{
   
}

void Scratchpad::Reset()
{
   // Set memory to garbage
   memset(mData, GARBAGE, SCRATCHPAD_SIZE);
}

Byte Scratchpad::GetByte(const Word& addr) 
{
   Word retWord = 0;
   Word offset = addr - SCRATCHPAD_ADDR;

   if(offset < 0 || offset >= SCRATCHPAD_SIZE)
   {
      throw std::exception();
   }
   return *((Byte*)&(mData[offset]));
}

HalfWord Scratchpad::GetHalfWord(const Word& addr) 
{
   Word offset = addr - SCRATCHPAD_ADDR;

   if(offset < 0 || offset >= SCRATCHPAD_SIZE)
   {
      throw std::exception();
   }
   return *((HalfWord*)&(mData[offset]));
}

Word Scratchpad::GetWord(const Word& address)
{
   Word offset = address - SCRATCHPAD_ADDR;

   if(offset < 0 || offset >= SCRATCHPAD_SIZE)
   {
      throw std::exception();
   }
   return *((Word*)&(mData[offset]));
}
   
void Scratchpad::StoreWord(const Word& address, Word val)
{
   Word offset = address - SCRATCHPAD_ADDR;
   if(offset < 0 || offset >= SCRATCHPAD_SIZE)
   {
      throw std::exception();
   }
   memcpy((void*)&(mData[offset]), (void*)(&val), sizeof(Word));
}