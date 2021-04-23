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

   // Shouuld be the same for kuseg, kseg0 and kseg1
   EXPECT_EQ(first, mMemController->GetWord(BIOS_START_ADDR_KUSEG + firstOffset));
   EXPECT_EQ(last, mMemController->GetWord(BIOS_START_ADDR_KUSEG + lastOffset));
   EXPECT_EQ(arb, mMemController->GetWord(BIOS_START_ADDR_KUSEG + arbOffset));

   EXPECT_EQ(first, mMemController->GetWord(BIOS_START_ADDR_KSEG0 + firstOffset));
   EXPECT_EQ(last, mMemController->GetWord(BIOS_START_ADDR_KSEG0 + lastOffset));
   EXPECT_EQ(arb, mMemController->GetWord(BIOS_START_ADDR_KSEG0 + arbOffset));

   EXPECT_EQ(first, mMemController->GetWord(BIOS_START_ADDR_KSEG1 + firstOffset));
   EXPECT_EQ(last, mMemController->GetWord(BIOS_START_ADDR_KSEG1 + lastOffset));
   EXPECT_EQ(arb, mMemController->GetWord(BIOS_START_ADDR_KSEG1 + arbOffset));
}