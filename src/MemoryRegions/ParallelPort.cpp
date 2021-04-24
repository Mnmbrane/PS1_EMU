#include "ParallelPort.h"
#include "CommonTypes.h"

using namespace PSEmu;



ParallelPort::ParallelPort() :
   Memory(PARALLEL_PORT_SIZE)
{
}

ParallelPort::~ParallelPort() { }

// Get SCPH1001.BIN from external_bin
void ParallelPort::Initialize() 
{
   
}
