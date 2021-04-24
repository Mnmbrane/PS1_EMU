#include "gtest/gtest.h"

#include "Bios.h"
#include "CommonTypes.h"

using namespace PSEmu;

// Test fixture
struct BiosTest : public testing::Test
{
   BiosTest() :
      mBios()
   { }
   virtual void SetUp()
   {
      // Read in the BIN file
      mBios.Initialize();
   }
   virtual void TearDown()
   {
      
   }
   Bios mBios;
};

TEST_F(BiosTest, GetWordTest)
{
   EXPECT_EQ(1007157267, mBios.GetWord(BIOS_ADDR));
   EXPECT_EQ(1111360516, mBios.GetWord(BIOS_ADDR + 0x0007FFFC));
   EXPECT_EQ(2762539470, mBios.GetWord(BIOS_ADDR + 0x0003CFF8));
}