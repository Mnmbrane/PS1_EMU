#include "Memory.h"
#include "string.h" // memset
#include <stdio.h>
#include <exception>
using namespace PSEmu;

Memory::Memory(Word size) :
   mData(new Byte[size]),
   mDataSize(size)
{ }

Memory::~Memory()
{
   delete [] mData;
   mData = nullptr;
}

void Memory::Reset()
{
   // Set memory to garbage
   memset(mData, GARBAGE, mDataSize);
}

Word Memory::GetWord(const Word& address)
{
   Word retWord = 0;
   if(address < 0 || address >= mDataSize)
   {
      throw std::exception();
   }
   memcpy((void*)&retWord, (void*)&(mData[address]), sizeof(Word));
   return retWord;
}

void Memory::StoreWord(const Word& address, Word val) 
{
   if(address < 0 || address >= mDataSize)
   {
      throw std::exception();
   }
   memcpy((void*)&(mData[address]), (void*)(&val), sizeof(Word));
}