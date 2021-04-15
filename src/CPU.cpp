#include "CPU.h"
#include "Memory.h"
#include <string.h> // memset
#include <exception>

using namespace PSEmu;
CPU::CPU(Memory* memory) :
   mRegister{},
   mMemory(memory)
{
   // make sure memory is not null or we'll have a problem
   if ( memory == nullptr )
   {
      throw std::exception();
   }
}

CPU::~CPU()
{

}

void CPU::Reset()
{
   memset(&mRegister, 0, sizeof(mRegister));

   // reset the PC to the beginning of the BIOS
   mRegister.PC = PC_RESET_VAL;
   mMemory->Reset();
}

void CPU::InitMemory(Memory* memory)
{
   mMemory = memory;
}

Instruction CPU::FetchInstruction()
{
   // Get the memory pointed to by PC
   return mMemory->GetWord(this->mRegister.PC);
}

void CPU::DecodeInstruction(Instruction instruction)
{
}

void CPU::ExecuteInstruction()
{
}

// TODO
void CPU::Run()
{
}
