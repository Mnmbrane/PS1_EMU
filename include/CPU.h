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

      InstructionDecodeType DecodeInstruction(const Instruction& instruction);

      void ExecuteInstruction(const InstructionDecodeType& decodedInstruction);

      // 1. Fetch the instruction located at address PC
      // 2. Incremete the PC to point to the next instruction
      // 3. Execute the instruction
      // 4. Repeat
      void RunNextInstruction();

      void ResetRegisters();

      void SetRegister(RegisterType reg, Word val);

      Word GetRegister(RegisterType reg);

   private:

      InsSelectType GetInstructionSetSelect(const Instruction& instruction);

      // Increment the PC to the next instruction
      void IncrementPC();

      void ExecuteImm(const InstructionDecodeType& decodedInstruction);

      void ExecuteReg(const InstructionDecodeType& decodedInstruction);

      void ExecuteJump(const InstructionDecodeType& decodedInstruction);

      // TODO: Might not need cache if we are emulating?
      // Instruction cache 4KB
      // Word mInstructionBuffer[4096 / sizeof(Word)];
      // Data Cache 1KB 
      // Word mDataBuffer[1024 / sizeof(Word)];

      Word mRegister[MAX_REG_NUM];

      MMU* mMMU;
   };
}


