#include "Memory.h"
#include "string.h" // memset
#include <stdio.h>
using namespace PSEmu;

I_Memory::I_Memory(Word size) //:
{
   mData = new Byte[size];
}

I_Memory::~I_Memory()
{
   delete [] mData;
   mData = nullptr;
}

void I_Memory::Reset()
{
   memset(&mData, 0, sizeof(mData));
}

Word I_Memory::GetWord(const Word& address)
{
   Word retWord = 0;
   return retWord;
}
