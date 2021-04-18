#include <stdio.h>
#include "CPU.h"
#include "Bios.h"
#include "Memory.h"

int main()
{
   PSEmu::CPU* cpu = new PSEmu::CPU();
   cpu->Initialize();

   cpu->RunNextInstruction();

   if(cpu != nullptr)
   {
      delete cpu;
      cpu = nullptr;
   }

   return 0;
}