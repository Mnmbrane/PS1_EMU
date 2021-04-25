#include <stdio.h>
#include "CommonTypes.h"
#include "Bios.h"

using namespace PSEmu;

int main()
{
   Word num = 0xF001;

   printf("%x\n", (num << 16) >> 16);
   return 0;
}