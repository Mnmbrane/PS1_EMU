#pragma once
#include "CommonTypes.h"

using namespace PSEmu;

class Memory
{
public:
   Memory();
   ~Memory();

   void Reset();
   Word GetWord(const Word& address);
private:
   // TODO: Fix the size
   Byte* mData;
};

