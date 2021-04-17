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
   mRegister[PC] = PC_RESET_VAL;
   mMemory->Reset();
}

void CPU::IncrementPC()
{
   // Increment PC by instruction size
   // This will point to the next instruction
   mRegister[PC] += INSTRUCTION_SIZE;
}

Instruction CPU::FetchInstruction()
{
   // Get the memory pointed to by PC
   return mMemory->GetWord(mRegister[PC]);
}

void CPU::ExecuteInstruction(Instruction instruction)
{
   // TODO
}

void CPU::RunNextInstruction()
{
   // Get word at pointed to by PC in memory
   Word instruction = mMemory->GetWord(mRegister[PC]);

   IncrementPC();

   // Execute the current instruction
   ExecuteInstruction(instruction);
}

void CPU::SetRegister(RegisterType reg, Word val) 
{
   mRegister[reg] = val;
}

Word CPU::GetRegister(RegisterType reg) 
{
   return mRegister[reg];
}
