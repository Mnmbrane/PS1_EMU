#include "gtest/gtest.h"

#include "MMU.h"
#include "CommonTypes.h"

using namespace PSEmu;

// Test fixture
struct MMUTest : public testing::Test
{
   virtual void SetUp()
   {
      mMMU = new MMU();
      // Read in the BIN file
      mMMU->Initialize();
   }
   virtual void TearDown()
   {
      delete mMMU;
   }
   MMU* mMMU;
};

TEST_F(MMUTest, GetWordBiosTest)
{
   // Test the first Word
   Word firstOffset = 0x0;
   Word first = 1007157267;

   // Test Last last Word
   Word lastOffset = 0x0007FFFC;
   Word last = 1111360516;

   // Test arbitrary Word
   Word arbOffset = 0x0003CFF8;
   Word arb = 2762539470;

   EXPECT_EQ(first, mMMU->GetWord(BIOS_START_ADDR + firstOffset));
   EXPECT_EQ(last, mMMU->GetWord(BIOS_START_ADDR + lastOffset));
   EXPECT_EQ(arb, mMMU->GetWord(BIOS_START_ADDR + arbOffset));
}