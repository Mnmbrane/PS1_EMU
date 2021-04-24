#include "UserMemory.h"
#include "CommonTypes.h"

using namespace PSEmu;



UserMemory::UserMemory() :
   Memory(USER_MEM_SIZE)
{
}

UserMemory::~UserMemory() { }

// Get SCPH1001.BIN from external_bin
void UserMemory::Initialize() 
{
   
}
