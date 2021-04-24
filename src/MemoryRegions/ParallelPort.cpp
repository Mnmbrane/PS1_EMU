#include "ParallelPort.h"
#include "CommonTypes.h"

#include <exception>
#include <string.h>

using namespace PSEmu;

ParallelPort::ParallelPort() :
   Memory(PARALLEL_PORT_SIZE)
{
}

ParallelPort::~ParallelPort() { }

void ParallelPort::Initialize() 
{
   
}

Word ParallelPort::GetWord(const Word& address) 
{
   Word retWord = 0;
   Word offset = address - PARALLEL_PORT_ADDR;

   if(offset < 0 || offset >= mDataSize)
   {
      throw std::exception();
   }
   memcpy((void*)&retWord, (void*)&(mData[offset]), sizeof(Word));
   return retWord;
}
   
void ParallelPort::StoreWord(const Word& address, Word val) 
{
   Word offset = address - PARALLEL_PORT_ADDR;
   if(offset < 0 || offset >= mDataSize)
   {
      throw std::exception();
   }
   memcpy((void*)&(mData[offset]), (void*)(&val), sizeof(Word));
}