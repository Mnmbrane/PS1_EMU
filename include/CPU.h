#pragma once
#include "CommonTypes.h"

namespace PSEmu
{
   class Memory;
}

namespace PSEmu
{
   class CPU
   {
   public:
      CPU(Memory* memory);
      ~CPU();

      // Reset registers and Memory
      void Reset();

      // Fetch instructions from memory
      Instruction FetchInstruction();

      void DecodeInstruction(Instruction instruction);

      void ExecuteInstruction();

      // 1. Fetch the instruction located at address PC
      // 2. Incremete the PC to point to the next instruction
      // 3. Execute the instruction
      // 4. Repeat
      void Run();

      void SetRegister(RegisterType reg, Word val);

      Word GetRegister(RegisterType reg);

   private:
      CPU() = delete; // Don't allow default construction

      void RunCycle();

      // TODO: Might not need cache if we are emulating?
      // Instruction cache 4KB
      // Word mInstructionBuffer[4096 / sizeof(Word)];
      // Data Cache 1KB 
      // Word mDataBuffer[1024 / sizeof(Word)];

      RegisterType mRegister[MAX_REG_NUM];
   
      PSEmu::Memory* mMemory;
   };
}


