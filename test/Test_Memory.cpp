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

TEST_F(MemoryTest, GetTest)
{
   EXPECT_EQ(mMemory->GetWord(0), 0xDEADBEAF);
}

TEST_F(MemoryTest, SetTest)
{
   mMemory->SetWord(8, 0xABCDDCBA);
   EXPECT_EQ(mMemory->GetWord(8), 0xABCDDCBA);

   mMemory->SetWord(24, 0xABFA1234);
   EXPECT_EQ(mMemory->GetWord(8), 0xABCDDCBA);
   EXPECT_EQ(mMemory->GetWord(24), 0xABFA1234);
}


TEST_F(MemoryTest, ResetTest)
{
   mMemory->Reset();
   EXPECT_EQ(mMemory->GetWord(0), GARBAGE);
}

TEST_F(MemoryTest, OutOfBoundsTest)
{
   EXPECT_THROW(mMemory->GetWord(-1), std::exception);
   EXPECT_THROW(mMemory->GetWord(200000), std::exception);

   EXPECT_THROW(mMemory->SetWord(-1, 1), std::exception);
   EXPECT_THROW(mMemory->SetWord(200000, 1), std::exception);
}