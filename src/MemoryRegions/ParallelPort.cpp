#include "ParallelPort.h"
#include "CommonTypes.h"

#include <exception>
#include <string.h>

using namespace PSEmu;

ParallelPort::ParallelPort() :
   I_Memory(PARALLEL_PORT_SIZE)
{
}

ParallelPort::~ParallelPort() { }

void ParallelPort::Initialize() 
{
   
}

void ParallelPort::Reset()
{
   // Set memory to garbage
   memset(mData, GARBAGE, PARALLEL_PORT_SIZE);
}

Byte ParallelPort::GetByte(const Word& addr) 
{
   Word retWord = 0;
   Word offset = addr - PARALLEL_PORT_ADDR;

   if(offset < 0 || offset >= PARALLEL_PORT_SIZE)
   {
      throw std::exception();
   }
   return *((Byte*)&(mData[offset]));
}

HalfWord ParallelPort::GetHalfWord(const Word& addr) 
{
   Word offset = addr - PARALLEL_PORT_ADDR;

   if(offset < 0 || offset >= PARALLEL_PORT_SIZE)
   {
      throw std::exception();
   }
   return *((HalfWord*)&(mData[offset]));
}

Word ParallelPort::GetWord(const Word& address) 
{
   Word offset = address - PARALLEL_PORT_ADDR;

   if(offset < 0 || offset >= PARALLEL_PORT_SIZE)
   {
      throw std::exception();
   }
   return *((Word*)&(mData[offset]));
}

void ParallelPort::StoreByte(const Word& addr, Word val) 
{
   
}
   
void ParallelPort::StoreHalfWord(const Word& addr, Word val)
{
   
}

void ParallelPort::StoreWord(const Word& address, Word val) 
{
   Word offset = address - PARALLEL_PORT_ADDR;
   if(offset < 0 || offset >= PARALLEL_PORT_SIZE)
   {
      throw std::exception();
   }
   memcpy((void*)&(mData[offset]), (void*)(&val), sizeof(Word));
}