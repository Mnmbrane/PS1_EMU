#pragma once
#include "CommonTypes.h"
#include "ComponentInterface.h"

namespace PSEmu
{
   class MemoryController;

   class CPU : public I_Component
   {
   public:
      CPU();
      ~CPU();

      virtual bool Initialize();

      // Reset registers and Memory
      virtual void Reset();

      InstructionDecodeType DecodeInstruction(const Instruction& instruction);

      void ExecuteInstruction(const InstructionDecodeType& decodedInstruction);

      // 1. Fetch the instruction located at address PC
      // 2. Incremete the PC to point to the next instruction
      // 3. Execute the instruction
      // 4. Repeat
      void RunNextInstruction();

      void ResetRegisters();

      void SetGenRegister(const GeneralRegisterType& regIndex, Word val);

      Word GetGenRegister(const GeneralRegisterType& regIndex);

      void SetSpecRegister(const SpecialRegisterType& regIndex, Word val);

      Word GetSpecRegister(const SpecialRegisterType& regIndex);

   private:

      InsSelectType GetInstructionSetSelect(const Instruction& instruction);

      // Increment the PC to the next instruction
      void IncrementPC();

      // TODO: Might not need cache if we are emulating?
      // Instruction cache 4KB
      // Word mInstructionBuffer[4096 / sizeof(Word)];
      // Data Cache 1KB 
      // Word mDataBuffer[1024 / sizeof(Word)];

      RegisterType mRegisters;

      MemoryController* mMemController;
   };
}


