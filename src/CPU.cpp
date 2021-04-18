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

InstructionDecodeType CPU::DecodeInstruction(const Instruction& instruction) 
{
   InstructionDecodeType decodedInstruction = {};

   memcpy((void*)&decodedInstruction.instruction, 
          (void*)&instruction,
          sizeof(Instruction));

   decodedInstruction.insSelect = GetInstructionSetSelect(instruction);
   return decodedInstruction;
}

void CPU::ExecuteInstruction(const InstructionDecodeType& instruction)
{
   switch(instruction.insSelect)
   {
      case E_INSTRUCTION_IMM:
         ExecuteImm(instruction);
         break;
      case E_INSTRUCTION_REG:
         ExecuteReg(instruction);
         break;
      case E_INSTRUCTION_JUMP:
         ExecuteJump(instruction);
         break;
      default:
         printf("ERROR: Wrong instruction type");
         break;
   }
}

void CPU::IncrementPC()
{
   // Increment PC by instruction size
   // This will point to the next instruction
   mRegister[PC] += sizeof(Instruction);
}

void CPU::ExecuteImm(const InstructionDecodeType& decodedInstruction) 
{
   
}

void CPU::ExecuteReg(const InstructionDecodeType& decodedInstruction) 
{
   
}

void CPU::ExecuteJump(const InstructionDecodeType& decodedInstruction) 
{
   
}


void CPU::RunNextInstruction()
{
   // Get word at pointed to by PC in memory
   // Get instruction from memory
    Instruction ins = mMMU->GetWord(mRegister[PC]);

   // Decode instruction
   InstructionDecodeType decodedInstruction = {};
   decodedInstruction = DecodeInstruction(ins);

   // Execute the current decoded instruction
   ExecuteInstruction(decodedInstruction);

   IncrementPC();
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

InsSelectType CPU::GetInstructionSetSelect(const Instruction& instruction) 
{
   InsSelectType selectType = E_INSTRUCTION_INVALID;
   Word opcode = instruction >> 26;
   switch(opcode)
   {
      case E_LUI: selectType = E_INSTRUCTION_IMM;
         break;
   }
   return selectType;
}

