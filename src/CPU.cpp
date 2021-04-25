#include "CPU.h"
#include "Bios.h"
#include "MemoryController.h"
#include "InstructionHelper.h"

#include <string.h> // memset
#include <stdexcept> // invalid_argument


using namespace PSEmu;

CPU::CPU() :
   mRegisters{},
   mMemController(new MemoryController()),
   mInstructionHelper(new InstructionHelper(mMemController, &mRegisters))
{
}

CPU::~CPU()
{
   delete mMemController;
}

void CPU::Initialize() 
{
   // Initialize the memory
   mMemController->Initialize();
   
   ResetRegisters();

}

void CPU::Reset()
{
   mMemController->Reset();
   
   ResetRegisters();
}

InstructionDecodeType CPU::DecodeInstruction(const Instruction& instruction) 
{
   InstructionDecodeType decodedInstruction = { instruction };

   return decodedInstruction;
}

void CPU::ExecuteInstruction(const InstructionDecodeType& instruction)
{
   Byte opcode = instruction.ins >> 26;
   switch(opcode)
   {
      case OP_LUI:
         mInstructionHelper->LUI(instruction.immType);
         break;
      case OP_ORI:
         mInstructionHelper->ORI(instruction.immType);
         break;
      case OP_SW:
         mInstructionHelper->SW(instruction.immType);
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
   mRegisters.specReg[PC] += sizeof(Instruction);
}

void CPU::RunNextInstruction()
{
   // Get word at pointed to by PC in memory
   // Get instruction from memory
    Instruction ins = mMemController->GetWord(mRegisters.specReg[PC]);

   // Decode instruction
   InstructionDecodeType decodedInstruction = { ins };

   // Execute the current decoded instruction
   ExecuteInstruction(decodedInstruction);

   IncrementPC();
}

void CPU::ResetRegisters() 
{
   // Set everything to garbage
   memset(&mRegisters, GARBAGE, sizeof(mRegisters.genReg));
   mRegisters.genReg[ZR] = 0;

   // reset the PC to the beginning of the BIOS
   mRegisters.specReg[PC] = PC_RESET_VAL;
}

void CPU::SetGenRegister(const GeneralRegisterType& regIndex, Word val) 
{
   mRegisters.genReg[regIndex] = val;
}

Word CPU::GetGenRegister(const GeneralRegisterType& regIndex) 
{
   return mRegisters.genReg[regIndex];
}

void CPU::SetSpecRegister(const SpecialRegisterType& regIndex, Word val) 
{
   mRegisters.specReg[regIndex] = val;
}

Word CPU::GetSpecRegister(const SpecialRegisterType& regIndex) 
{
   return mRegisters.specReg[regIndex];
}
