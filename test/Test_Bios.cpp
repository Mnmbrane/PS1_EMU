#include "gtest/gtest.h"

#include "Bios.h"
#include "CommonTypes.h"

#include <exception>

using namespace PSEmu;

TEST(BiosTest, ResetTest)
{
   Bios bios = {};
   bios.Initialize();
   bios.Reset();
   EXPECT_EQ(GARBAGE, bios.GetWord(BIOS_ADDR));
   EXPECT_EQ(GARBAGE, bios.GetWord(BIOS_ADDR + 0x0007FFFC));
   EXPECT_EQ(GARBAGE, bios.GetWord(BIOS_ADDR + 0x0003CFF8));
}

TEST(BiosTest, GetWordTest)
{
   Bios bios = {};
   bios.Initialize();

   EXPECT_EQ(1007157267, bios.GetWord(BIOS_ADDR));
   EXPECT_EQ(1111360516, bios.GetWord(BIOS_ADDR + 0x0007FFFC));
   EXPECT_EQ(2762539470, bios.GetWord(BIOS_ADDR + 0x0003CFF8));
}

TEST(BiosTest, StoreWordTest)
{
   Bios bios = {};
   bios.Initialize();
   EXPECT_THROW(bios.StoreByte(BIOS_ADDR, 1), std::exception);
   EXPECT_THROW(bios.StoreHalfWord(BIOS_ADDR, 1), std::exception);
   EXPECT_THROW(bios.StoreWord(BIOS_ADDR, 1), std::exception);
}
