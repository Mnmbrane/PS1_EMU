#pragma once
#include "CommonTypes.h"
#include "Component.h"

namespace PSEmu
{
   class MMU;

   class CPU : public I_Component
   {
   public:
      CPU();
      ~CPU();

      virtual bool Initialize();

      // Reset registers and Memory
      virtual void Reset();

      // Fetch instructions from memory
      Instruction FetchInstruction();

      void ExecuteInstruction(Instruction instruction);

      // 1. Fetch the instruction located at address PC
      // 2. Incremete the PC to point to the next instruction
      // 3. Execute the instruction
      // 4. Repeat
      void RunNextInstruction();

      void SetRegister(RegisterType reg, Word val);

      Word GetRegister(RegisterType reg);

   private:

      // Increment the PC to the next instruction
      void IncrementPC();

      // TODO: Might not need cache if we are emulating?
      // Instruction cache 4KB
      // Word mInstructionBuffer[4096 / sizeof(Word)];
      // Data Cache 1KB 
      // Word mDataBuffer[1024 / sizeof(Word)];

      Word mRegister[MAX_REG_NUM];

      MMU* mMMU;
   };
}


