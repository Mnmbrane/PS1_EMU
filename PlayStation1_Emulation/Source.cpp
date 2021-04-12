#include <stdio.h>
#include "CPU.h"
#include "Memory.h"

int main()
{
   Memory* mem = nullptr;
   CPU* cpu = new CPU(mem);

   delete cpu;
   delete mem;
   return 0;
}