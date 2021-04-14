#include <stdio.h>
#include "CPU.h"
#include "Memory.h"

int main()
{
   PSEmu::Memory* mem = new PSEmu::Memory();
   PSEmu::CPU* cpu = new PSEmu::CPU(mem);

   if(cpu != nullptr)
      delete cpu;

   if(mem != nullptr)
      delete mem;
   return 0;
}