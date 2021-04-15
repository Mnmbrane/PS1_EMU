#include <stdio.h>
#include "CPU.h"
#include "Memory.h"

int main()
{
   PSEmu::Memory* mem = new PSEmu::Memory();
   PSEmu::CPU* cpu = new PSEmu::CPU(mem);

   if(cpu != nullptr)
   {
      delete cpu;
      cpu = nullptr;
   }

   if(mem != nullptr)
   {
      delete mem;
      mem = nullptr;
   }

   return 0;
}