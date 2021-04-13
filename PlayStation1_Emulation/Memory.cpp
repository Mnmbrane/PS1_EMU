#include "Memory.h"

#include "string.h" // memset

using namespace PSEmu;

Memory::Memory() //:
{
   mData = new Byte[0x7FFFFFF];

}

Memory::~Memory()
{
   delete [] mData;
   mData = nullptr;
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
