#include "Bios.h"
#include "CommonTypes.h"

#include <string.h>
#include <fstream>
#include <sys/stat.h>
#include <openssl/sha.h>
#include <exception>

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
void Bios::Initialize() 
{
   // Check size of file
   if(CheckSize() == false)
   {
      delete [] mData;
      throw std::exception();
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
         delete [] mData;
         throw std::exception();
      }
   }
}

void Bios::Reset()
{
   // Set memory to garbage
   memset(mData, GARBAGE, BIOS_SIZE);
}

Byte Bios::GetByte(const Word& addr) 
{
   Word offset = addr - BIOS_ADDR;

   if(offset < 0 || offset >= BIOS_SIZE)
   {
      throw std::exception();
   }
   return *((Byte*)&(mData[offset]));
}

HalfWord Bios::GetHalfWord(const Word& addr) 
{
   Word offset = addr - BIOS_ADDR;

   if(offset < 0 || offset >= BIOS_SIZE)
   {
      throw std::exception();
   }
   return *((HalfWord*)&(mData[offset]));
}

Word Bios::GetWord(const Word& addr)
{
   Word offset = addr - BIOS_ADDR;

   if(offset < 0 || offset >= BIOS_SIZE)
   {
      throw std::exception();
   }
   return *((Word*)&(mData[offset]));
}

void Bios::StoreByte(const Word& addr, Word val) 
{
   throw std::exception();
}
   
void Bios::StoreHalfWord(const Word& addr, Word val)
{
   throw std::exception();
}

void Bios::StoreWord(const Word& addr, Word val)
{
   throw std::exception();
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
