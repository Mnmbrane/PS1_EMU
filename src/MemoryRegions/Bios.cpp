#include "Bios.h"
#include "CommonTypes.h"

#include <string.h>
#include <fstream>
#include <sys/stat.h>
#include <stdexcept>
#include <openssl/sha.h>

using namespace PSEmu;

const Byte BIOS_CHECK_SUM[20] = { 0x10, 0x15, 0x5d, 0x8d, 0x6e,
                                  0x6e, 0x83, 0x2d, 0x6e, 0xa6,
                                  0x6d, 0xb9, 0xbc, 0x09, 0x83,
                                  0x21, 0xfb, 0x5e, 0x8e, 0xbf };


Bios::Bios() :
   I_Memory(BIOS_SIZE)
{
}

Bios::~Bios() { }

// Get SCPH1001.BIN from external_bin
bool Bios::Initialize() 
{
   // Check size of file
   if(CheckSize() == false)
   {
      printf("Bad Bios file size\n");
      Reset();
      return false;
   }
   else
   {
      // Read file
      std::ifstream biosFile(BIOS_FILE_LOC, std::ios::binary);

      // Read to a mData
      biosFile.read(reinterpret_cast<char*>(mData), BIOS_SIZE);

      // Close file
      biosFile.close();

      // Checksum
      if(Checksum() == false)
      {
         printf("Bad Bios Checksum\n");
         Reset();
         return false;
      }
   }
   // Place into mData
   return true;
}

bool Bios::CheckSize() 
{
   struct stat results;
   if(stat(BIOS_FILE_LOC, &results) == 0)
   {
      return results.st_size == BIOS_SIZE;
   }
   else
   {
      // An error occured
      printf("Could not read file %s\n", BIOS_FILE_LOC);
      return false;
   }
}

bool Bios::Checksum()
{
   unsigned char* hash = SHA1(mData, BIOS_SIZE, nullptr);

   return (memcmp((void*) hash, (void*)BIOS_CHECK_SUM, sizeof(BIOS_CHECK_SUM)) == 0);
}
