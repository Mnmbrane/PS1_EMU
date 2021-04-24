#include <stdio.h>
#include "CommonTypes.h"
#include "Bios.h"

using namespace PSEmu;

int main()
{
   Bios* b = new Bios();

   b->Initialize();

   unsigned int num = 0xdeadbeef; 

   printf("%x\n", (*(char*)&num));

   delete b;
   return 0;
}