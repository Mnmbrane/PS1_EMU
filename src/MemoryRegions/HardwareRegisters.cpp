#include "HardwareRegisters.h"
#include "CommonTypes.h"

#include <exception>
#include <string.h>

using namespace PSEmu;



HardwareRegisters::HardwareRegisters() :
   I_Memory(HW_REG_SIZE)
{
}

HardwareRegisters::~HardwareRegisters() { }

void HardwareRegisters::Initialize() 
{
   
}

void HardwareRegisters::Reset()
{
   // Set memory to garbage
   memset(mData, GARBAGE, HW_REG_SIZE);
}

Byte HardwareRegisters::GetByte(const Word& addr) 
{
   Word offset = addr - HW_REG_ADDR;

   if(offset < 0 || offset >= HW_REG_SIZE)
   {
      throw std::exception();
   }
   return *((Byte*)&(mData[offset]));
}

HalfWord HardwareRegisters::GetHalfWord(const Word& addr) 
{
   Word offset = addr - HW_REG_ADDR;

   if(offset < 0 || offset >= HW_REG_SIZE)
   {
      throw std::exception();
   }
   return *((HalfWord*)&(mData[offset]));
}

Word HardwareRegisters::GetWord(const Word& address) 
{
   Word offset = address - HW_REG_ADDR;

   if(offset < 0 || offset >= HW_REG_SIZE)
   {
      throw std::exception();
   }
   return *((Word*)&(mData[offset]));
}

void HardwareRegisters::StoreByte(const Word& addr, Word val) 
{
   
}
   
void HardwareRegisters::StoreHalfWord(const Word& addr, Word val)
{
   
}

void HardwareRegisters::StoreWord(const Word& address, Word val) 
{
   Word offset = address - HW_REG_ADDR;
   if(offset < 0 || offset >= HW_REG_SIZE)
   {
      throw std::exception();
   }
   memcpy((void*)&(mData[offset]), (void*)(&val), sizeof(Word));
}