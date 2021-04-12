#pragma once
#include "CommonTypes.h"

class Memory;

using namespace CommonTypes;

class CPU
{
public:
   CPU(Memory* memory);
   ~CPU();

   // Reset registers and Memory
   void Reset();

   // Initialize memory to what's passed in
   void InitMemory(Memory* memory);

   // Fetch instructions from memory
   Instruction FetchInstruction();

   void DecodeInstruction(Instruction instruction);

   void ExecuteInstruction();

   // 1. Fetch the instruction located at address PC
   // 2. Incremete the PC to point to the next instruction
   // 3. Execute the instruction
   // 4. Repeat
   void Run();

private:
   CPU() = delete; // Don't allow default construction
   CPU& operator=(const CPU&) {};

   void RunCycle();

   // TODO: Might not need cache if we are emulating?
   // Instruction cache 4KB
   // Word mInstructionBuffer[4096 / sizeof(Word)];
   // Data Cache 1KB 
   // Word mDataBuffer[1024 / sizeof(Word)];

   typedef struct
   {
      // General Purpose Registers
      Word ZR;                               // Constant 0
      Word AT;                               // Reserved for the assembler
      Word V0, V1;                           // Values for results and expression evaluation
      Word A0, A2, A3;                       // Arguments
      Word T0, T1, T2, T3, T4, T5, T6, T7;   // Temporaries (not preserved across call)
      Word S0, S1, S2, S3, S4, S5, S6, S7;   // Saved (preserved across call)
      Word T8, T9;                           // More temporaries (not preserved across call)
      Word K0, K1;                           // Reserved for OS Kernel
      Word GP;                               // Global Pointer
      Word SP;                               // Stack Pointer
      Word FP;                               // Frame Pointer
      Word RA;                               // Return address (set by function call)

      // Other Registers
      Word HI; // Multiplication 64 bit high result or division remainder
      Word LO; // Multiplication 64 bit low result or division quotient
      Word PC; // Program Counter 
   } CPURegisterType;

   CPURegisterType mRegister;
   
   Memory* mMemory;
};

