#include <stdio.h>
#include "CPU.h"
#include "Bios.h"
#include "Memory.h"

int main()
{
   PSEmu::CPU* cpu = new PSEmu::CPU();
   PSEmu::Bios bios;


   bios.Initialize();

   if(cpu != nullptr)
   {
      delete cpu;
      cpu = nullptr;
   }

   return 0;
}