#include "Memory.h"

#include "string.h" // memset

Memory::Memory() :
   mData{}
{
}

Memory::~Memory()
{
   Reset();
}

void Memory::Reset()
{
   memset(&mData, 0, sizeof(mData));
}

Word Memory::GetWord(const Word& address)
{
   Word retWord = 0;
   return retWord;
}
