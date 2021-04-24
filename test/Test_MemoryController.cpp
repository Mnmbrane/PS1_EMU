#include "gtest/gtest.h"

#include "MemoryController.h"
#include "CommonTypes.h"

using namespace PSEmu;

// Test fixture
struct MemoryControllerTest : public testing::Test
{
   virtual void SetUp()
   {
      mMemController = new MemoryController();
      // Read in the BIN file
      mMemController->Initialize();
   }
   virtual void TearDown()
   {
      delete mMemController;
   }
   MemoryController* mMemController;
};

TEST_F(MemoryControllerTest, GetWordBiosTest)
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

   EXPECT_EQ(first, mMemController->GetWord(BIOS_ADDR + firstOffset));
   EXPECT_EQ(last, mMemController->GetWord(BIOS_ADDR + lastOffset));
   EXPECT_EQ(arb, mMemController->GetWord(BIOS_ADDR + arbOffset));
}