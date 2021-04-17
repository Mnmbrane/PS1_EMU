#include <stdio.h>
#include "CPU.h"
#include "Memory.h"

int main()
{
   PSEmu::CPU* cpu = new PSEmu::CPU();

   if(cpu != nullptr)
   {
      delete cpu;
      cpu = nullptr;
   }

   return 0;
}