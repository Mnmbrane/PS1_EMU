#include "gtest/gtest.h"

#include "Memory.h"
#include "CommonTypes.h"
#include <exception>

using namespace PSEmu;

class MemoryMock : public Memory
{
public:
   MemoryMock() :
      Memory(1024)
   { }
   void Initialize()
   {
      Word num = 0xDEADBEAF;
      memcpy(&mData[0], &num, 4);
   }
   Word GetWord(const Word& address) 
   { 
      Word retWord = 0;

      if(address < 0 || address >= mDataSize)
      {
         throw std::exception();
      }
      memcpy((void*)&retWord, (void*)&(mData[address]), sizeof(Word));
      return retWord;
   }

   void StoreWord(const Word& address, Word val) 
   { }
};

// Test fixture
struct MemoryTest : public testing::Test
{
   virtual void SetUp()
   {
      mMemory = new MemoryMock();
      mMemory->Initialize();
   }
   virtual void TearDown()
   {
      delete mMemory;
   }
   MemoryMock* mMemory;
};


TEST_F(MemoryTest, ResetTest)
{
   mMemory->Reset();
   EXPECT_EQ(mMemory->GetWord(0), GARBAGE);
}
