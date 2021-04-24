#include "Kernel.h"
#include "CommonTypes.h"

using namespace PSEmu;



Kernel::Kernel() :
   Memory(KERNEL_SIZE)
{
}

Kernel::~Kernel() { }

// Get SCPH1001.BIN from external_bin
void Kernel::Initialize() 
{
   
}
