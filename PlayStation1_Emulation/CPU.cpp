#include "CPU.h"
#include "Memory.h"
#include "string.h" // memset

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
   mRegister{},
   mMemory(nullptr)
{
}

CPU::~CPU()
{
   delete inst;
   inst = nullptr;
}

void CPU::Reset()
{
   memset(&mRegister, 0, sizeof(mRegister));

   // reset the PC to the beginning of the BIOS
   mRegister.PC = 0xbfc00000;
   mMemory->Reset();
}

void CPU::InitMemory(Memory* memory)
{
   mMemory = memory;
}

Instruction CPU::FetchInstructions()
{
   // Get the memory pointed to by PC
   return mMemory->GetWord(this->mRegister.PC);
}
