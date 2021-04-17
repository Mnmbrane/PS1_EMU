#include "Bios.h"
#include "CommonTypes.h"

#include <string.h>
//#include <ifstream>

using namespace PSEmu;

Bios::Bios() :
   I_Memory(BIOS_SIZE)
{
}

Bios::~Bios() { }

// Get SCPH1001.BIN from external_bin
void Bios::Initialize() 
{
   // Read file from memory
   
   // Place into mData

   // Checksum
}

void Bios::Reset() 
{
   memset((void*)mData, 0, BIOS_SIZE);
}

Word Bios::GetWord(const Word& address) 
{
   // TODO
   return 0;
}
