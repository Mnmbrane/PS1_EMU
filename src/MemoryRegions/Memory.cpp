#include "Memory.h"
#include "string.h" // memset

#include <stdio.h>
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
