#include "MemoryInterface.h"
#include "string.h" // memset

#include <stdio.h>
using namespace PSEmu;

I_Memory::I_Memory(Word size) :
   mData(new Byte[size])
{ }

I_Memory::~I_Memory()
{
   delete [] mData;
   mData = nullptr;
}
