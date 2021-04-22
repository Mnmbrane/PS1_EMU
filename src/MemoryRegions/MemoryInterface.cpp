#include "MemoryInterface.h"
#include "string.h" // memset
#include <stdio.h>
using namespace PSEmu;

I_Memory::I_Memory(Word size) :
   mData(new Byte[size]),
   mDataSize(size)
{ }

I_Memory::~I_Memory()
{
   delete [] mData;
   mData = nullptr;
}


void I_Memory::Reset()
{
   memset(&mData, 0, mDataSize);
}

Word I_Memory::GetWord(const Word& address)
{
   Word retWord = 0;
   memcpy((void*)&retWord, (void*)&(mData[address]), sizeof(Word));
   return retWord;
}

void I_Memory::SetWord(const Word& address, Word val) 
{
   memcpy((void*)&(mData[address]), (void*)(&val), sizeof(Word));
}
