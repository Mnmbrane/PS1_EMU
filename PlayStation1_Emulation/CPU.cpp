#include "CPU.h"

// Initialize this instance to null
CPU* CPU::inst = nullptr;

CPU* CPU::GetInstance()
{
   if ( inst == nullptr )
   {
      inst = new CPU();
   }
   return inst;
}

CPU::CPU() :
   mRegister{}
{
}

CPU::~CPU()
{
   delete inst;
   inst = nullptr;
}

Instruction CPU::FetchInstructions(const Memory& mem)
{
   // Get the first 32-bits from memory

   return 0;
}
