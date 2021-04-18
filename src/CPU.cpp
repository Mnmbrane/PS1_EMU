#include "CPU.h"
#include "Bios.h"
#include "MMU.h"

#include <string.h> // memset
#include <stdexcept> // invalid_argument


using namespace PSEmu;

CPU::CPU() :
   mRegister{},
   mMMU(new MMU())
{
}

CPU::~CPU()
{
   delete mMMU;
}

bool CPU::Initialize() 
{
   bool retVal = false;
   // Initialize the memory
   retVal = mMMU->Initialize();
   
   ResetRegisters();

   return true;
}

void CPU::Reset()
{
   mMMU->Reset();
   
   ResetRegisters();
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
   // TODO
   // return mMemory->GetWord(mRegister[PC]);
   return 0;
}

void CPU::ExecuteInstruction(const Instruction& instruction)
{
   // TODO
   // Print the instructions
   printf("Instruction = %x\n", instruction);
}

void CPU::RunNextInstruction()
{
   // Get word at pointed to by PC in memory
   // TODO:
    Word instruction = mMMU->GetWord(mRegister[PC]);

   IncrementPC();

   // Execute the current instruction
   ExecuteInstruction(instruction);
}

void CPU::ResetRegisters() 
{
   memset(&mRegister, 0, sizeof(mRegister));

   // reset the PC to the beginning of the BIOS
   mRegister[PC] = PC_RESET_VAL;
}

void CPU::SetRegister(RegisterType reg, Word val) 
{
   mRegister[reg] = val;
}

Word CPU::GetRegister(RegisterType reg) 
{
   return mRegister[reg];
}
