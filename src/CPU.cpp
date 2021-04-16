#include "CPU.h"
#include "Memory.h"
#include "ExceptionString.h"
#include <string.h> // memset
#include <stdexcept> // invalid_argument


using namespace PSEmu;
CPU::CPU(Memory* memory) :
   mRegister{},
   mMemory(memory)
{
   // make sure memory is not null or we'll have a problem
   if ( memory == nullptr )
   {
      throw std::invalid_argument(ExceptionString::Null_Memory_Arg);
   }
}

CPU::~CPU()
{

}

void CPU::Reset()
{
   memset(&mRegister, 0, sizeof(mRegister));

   // reset the PC to the beginning of the BIOS
   mRegister[PC] = static_cast<RegisterType>(PC_RESET_VAL);
   mMemory->Reset();
}

Instruction CPU::FetchInstruction()
{
   // Get the memory pointed to by PC
   return mMemory->GetWord(mRegister[PC]);
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

void CPU::SetRegister(RegisterType reg, Word val) 
{
   mRegister[reg] = static_cast<RegisterType>(val);
}

Word CPU::GetRegister(RegisterType reg) 
{
   return mRegister[reg];
}
