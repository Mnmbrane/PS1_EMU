#include "HardwareRegisters.h"
#include "CommonTypes.h"

#include <exception>
#include <string.h>

using namespace PSEmu;



HardwareRegisters::HardwareRegisters() :
   Memory(HW_REG_SIZE)
{
}

HardwareRegisters::~HardwareRegisters() { }

void HardwareRegisters::Initialize() 
{
   
}

Word HardwareRegisters::GetWord(const Word& address) 
{
   Word retWord = 0;
   Word offset = address - HW_REG_ADDR;

   if(offset < 0 || offset >= mDataSize)
   {
      throw std::exception();
   }
   memcpy((void*)&retWord, (void*)&(mData[offset]), sizeof(Word));
   return retWord;
}

void HardwareRegisters::StoreWord(const Word& address, Word val) 
{
   Word offset = address - HW_REG_ADDR;
   if(offset < 0 || offset >= mDataSize)
   {
      throw std::exception();
   }
   memcpy((void*)&(mData[offset]), (void*)(&val), sizeof(Word));
}