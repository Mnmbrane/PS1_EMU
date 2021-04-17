#include "gtest/gtest.h"

#include "Bios.h"
#include "CommonTypes.h"

#include <string.h>
#include <fstream>

using namespace PSEmu;

// Test fixture
struct BiosTest : public testing::Test
{
   virtual void SetUp()
   {
      mBios = new Bios();
      // Read in the BIN file
      mBios->Initialize();
   }
   virtual void TearDown()
   {
      delete mBios;
   }
   Bios* mBios;
};

TEST_F(BiosTest, ReadTest)
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

   EXPECT_EQ(first, mBios->GetWord(firstOffset));
   EXPECT_EQ(last, mBios->GetWord(lastOffset));
   EXPECT_EQ(arb, mBios->GetWord(arbOffset));
}