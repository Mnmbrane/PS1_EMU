#include "Scratchpad.h"
#include "CommonTypes.h"

#include <exception>
#include <string.h>

using namespace PSEmu;

Scratchpad::Scratchpad() :
   Memory(SCRATCHPAD_SIZE)
{
}

Scratchpad::~Scratchpad() { }

void Scratchpad::Initialize() 
{
   
}

Word Scratchpad::GetWord(const Word& address)
{
   Word retWord = 0;
   Word offset = address - SCRATCHPAD_ADDR;

   if(offset < 0 || offset >= mDataSize)
   {
      throw std::exception();
   }
   memcpy((void*)&retWord, (void*)&(mData[offset]), sizeof(Word));
   return retWord;
}
   
void Scratchpad::StoreWord(const Word& address, Word val)
{
   Word offset = address - SCRATCHPAD_ADDR;
   if(offset < 0 || offset >= mDataSize)
   {
      throw std::exception();
   }
   memcpy((void*)&(mData[offset]), (void*)(&val), sizeof(Word));
}