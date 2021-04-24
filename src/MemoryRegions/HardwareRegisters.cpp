#include "HardwareRegisters.h"
#include "CommonTypes.h"

using namespace PSEmu;



HardwareRegisters::HardwareRegisters() :
   Memory(HW_REG_SIZE)
{
}

HardwareRegisters::~HardwareRegisters() { }

// Get SCPH1001.BIN from external_bin
void HardwareRegisters::Initialize() 
{
   
}
