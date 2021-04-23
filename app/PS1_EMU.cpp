#include <stdio.h>
#include "CommonTypes.h"
#include "Bios.h"

using namespace PSEmu;

int main()
{
   Bios* b = new Bios();

   b->Initialize();

   delete b;
   return 0;
}