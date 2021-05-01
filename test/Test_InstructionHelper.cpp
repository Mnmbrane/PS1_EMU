#include "gtest/gtest.h"

#include "InstructionHelper.h"
#include "CommonTypes.h"
#include "MemoryController.h"

#include <limits.h>
using namespace PSEmu;

// Test fixture
struct InstructionHelperTest : public testing::Test
{
   virtual void SetUp()
   {
      mMemoryController = new MemoryController();
      mInstructionHelper = new InstructionHelper(mMemoryController, &mRegisters);
      mMemoryController->Initialize();
      Reset();
   }
   virtual void TearDown()
   {
      delete mMemoryController;
   }
   void Reset()
   {
      memset(&mRegisters, GARBAGE, sizeof(mRegisters.genReg));
      mMemoryController->Reset();
      mMemoryController->Initialize();
      mRegisters.genReg[ZR] = 0;
   }
   void StoreTestReset(InstructionSetImmediateType& imm)
   {
      Reset();
      mRegisters.genReg[imm.rs] = SCRATCHPAD_ADDR;
      mRegisters.genReg[imm.rt] = 0xDEADBEEF;
   }
   RegisterType mRegisters;
   MemoryController* mMemoryController;
   InstructionHelper* mInstructionHelper;
};

TEST_F(InstructionHelperTest, LBTest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rs = 1;
   // Set to the beginning of the bios
   mRegisters.genReg[imm.rs] = BIOS_ADDR;

   // Byte Value at 0x124 is 49
   imm.immediate = 0x124;
   mInstructionHelper->LB(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x49);

   // Byte Value at 0x124 is DF or -33 signed
   imm.immediate = 0x320;
   mInstructionHelper->LB(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], -33);
}

TEST_F(InstructionHelperTest, LBUTest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rs = 1;
   // Set to the beginning of the bios
   mRegisters.genReg[imm.rs] = BIOS_ADDR;

   // Byte Value at 0x124 is 49
   imm.immediate = 0x124;
   mInstructionHelper->LBU(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x49);

   // Byte Value at 0x124 is DF or 223 signed
   imm.immediate = 0x320;
   mInstructionHelper->LBU(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 223);
}

TEST_F(InstructionHelperTest, LHTest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rs = 1;
   // Set to the beginning of the bios
   mRegisters.genReg[imm.rs] = BIOS_ADDR;

   // Byte Value at 0x124 is 49 6E -> 0x6E49
   imm.immediate = 0x124;
   mInstructionHelper->LH(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x6E49);

   // Byte Value at 0x320 is 25 F8 or -2011
   imm.immediate = 0x228;
   mInstructionHelper->LH(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], -2011);
}

TEST_F(InstructionHelperTest, LWTest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rs = 1;
   // Set to the beginning of the bios
   mRegisters.genReg[imm.rs] = BIOS_ADDR;

   // Byte Value at 0x124 is 49 6E 63 2E -> 0x2E636E49
   imm.immediate = 0x124;
   mInstructionHelper->LW(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x2E636E49);

   // Byte Value at 0x31C is 63525
   imm.immediate = 0x31C;
   mInstructionHelper->LW(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], -1388314500);
}

TEST_F(InstructionHelperTest, LWLTest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rs = 0b01;
   imm.rt = 0b10;

   mRegisters.genReg[imm.rt] = GARBAGE;
   mRegisters.genReg[imm.rs] = BIOS_ADDR + 0x150;
   imm.immediate = 0x3;
   mInstructionHelper->LWL(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x3C091F80);

   mRegisters.genReg[imm.rt] = GARBAGE;
   mRegisters.genReg[imm.rs] = BIOS_ADDR + 0x151;
   imm.immediate = 0x3;
   mInstructionHelper->LWL(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], GARBAGE >> 8);

   mRegisters.genReg[imm.rt] = GARBAGE;
   mRegisters.genReg[imm.rs] = BIOS_ADDR + 0x152;
   imm.immediate = 0x3;
   mInstructionHelper->LWL(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], (GARBAGE >> 16) | 0x10000000);

   mRegisters.genReg[imm.rt] = GARBAGE;
   mRegisters.genReg[imm.rs] = BIOS_ADDR + 0x153;
   imm.immediate = 0x3;
   mInstructionHelper->LWL(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], (GARBAGE >> 24) | 0x29100000);
}

TEST_F(InstructionHelperTest, LWRTest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rs = 0b01;
   imm.rt = 0b10;

   mRegisters.genReg[imm.rt] = GARBAGE;
   mRegisters.genReg[imm.rs] = BIOS_ADDR + 0x150;
   imm.immediate = 0x0;
   mInstructionHelper->LWR(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x3C091F80);

   mRegisters.genReg[imm.rt] = GARBAGE;
   mRegisters.genReg[imm.rs] = BIOS_ADDR + 0x151;
   imm.immediate = 0x0;
   mInstructionHelper->LWR(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], (GARBAGE << 24) | 0x003C091F);

   mRegisters.genReg[imm.rt] = GARBAGE;
   mRegisters.genReg[imm.rs] = BIOS_ADDR + 0x152;
   imm.immediate = 0x0;
   mInstructionHelper->LWR(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], (GARBAGE << 16) | 0x00003C09);

   mRegisters.genReg[imm.rt] = GARBAGE;
   mRegisters.genReg[imm.rs] = BIOS_ADDR + 0x153;
   imm.immediate = 0x0;
   mInstructionHelper->LWR(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], (GARBAGE << 8) | 0x0000003C);

}

TEST_F(InstructionHelperTest, LWLandLWRTest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rs = 1;
   // Set to the beginning of the bios
   mRegisters.genReg[imm.rs] = BIOS_ADDR + 0x153;
   mRegisters.genReg[imm.rt] = GARBAGE;
   imm.immediate = 0x0;
   mInstructionHelper->LWR(imm);
   imm.immediate = 0x3;
   mInstructionHelper->LWL(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x2910003C);

   mRegisters.genReg[imm.rt] = GARBAGE;
   imm.immediate = 0x3;
   mInstructionHelper->LWL(imm);
   imm.immediate = 0x0;
   mInstructionHelper->LWR(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x2910003C);

   mRegisters.genReg[imm.rs] = BIOS_ADDR + 0x152;
   mRegisters.genReg[imm.rt] = GARBAGE;
   imm.immediate = 0x0;
   mInstructionHelper->LWR(imm);
   imm.immediate = 0x3;
   mInstructionHelper->LWL(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x10003C09);

   mRegisters.genReg[imm.rt] = GARBAGE;
   imm.immediate = 0x3;
   mInstructionHelper->LWL(imm);
   imm.immediate = 0x0;
   mInstructionHelper->LWR(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x10003C09);

   mRegisters.genReg[imm.rs] = BIOS_ADDR + 0x151;
   mRegisters.genReg[imm.rt] = GARBAGE;
   imm.immediate = 0x0;
   mInstructionHelper->LWR(imm);
   imm.immediate = 0x3;
   mInstructionHelper->LWL(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x003C091F);

   mRegisters.genReg[imm.rt] = GARBAGE;
   imm.immediate = 0x3;
   mInstructionHelper->LWL(imm);
   imm.immediate = 0x0;
   mInstructionHelper->LWR(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x003C091F);

   mRegisters.genReg[imm.rs] = BIOS_ADDR + 0x150;
   mRegisters.genReg[imm.rt] = GARBAGE;
   imm.immediate = 0x0;
   mInstructionHelper->LWR(imm);
   imm.immediate = 0x3;
   mInstructionHelper->LWL(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x3C091F80);

   mRegisters.genReg[imm.rt] = GARBAGE;
   imm.immediate = 0x3;
   mInstructionHelper->LWL(imm);
   imm.immediate = 0x0;
   mInstructionHelper->LWR(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x3C091F80);
}

TEST_F(InstructionHelperTest, SBTest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rs = 1;
   imm.rt = 2;
   // Set to the beginning of the bios
   imm.immediate = 4;
   mRegisters.genReg[imm.rs] = SCRATCHPAD_ADDR;
   mRegisters.genReg[imm.rt] = 0xDEADBEEF;

   mInstructionHelper->SB(imm);
   EXPECT_EQ(mMemoryController->GetByte(SCRATCHPAD_ADDR + imm.immediate), 0xEF);
   EXPECT_EQ(mMemoryController->GetHalfWord(SCRATCHPAD_ADDR + imm.immediate), 0x6BEF);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR + imm.immediate), 0x6B6B6BEF);
}

TEST_F(InstructionHelperTest, SHTest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rs = 1;
   imm.rt = 2;
   // Set to the beginning of the bios
   imm.immediate = 4;
   mRegisters.genReg[imm.rs] = SCRATCHPAD_ADDR;
   mRegisters.genReg[imm.rt] = 0xDEADBEEF;

   mInstructionHelper->SH(imm);
   EXPECT_EQ(mMemoryController->GetByte(SCRATCHPAD_ADDR + imm.immediate), 0xEF);
   EXPECT_EQ(mMemoryController->GetHalfWord(SCRATCHPAD_ADDR + imm.immediate), 0xBEEF);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR + imm.immediate), 0x6B6BBEEF);
}

TEST_F(InstructionHelperTest, SWTest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rs = 1;
   imm.rt = 2;
   // Set to the beginning of the bios
   imm.immediate = 4;
   mRegisters.genReg[imm.rs] = SCRATCHPAD_ADDR;
   mRegisters.genReg[imm.rt] = 0xDEADBEEF;

   mInstructionHelper->SW(imm);
   EXPECT_EQ(mMemoryController->GetByte(SCRATCHPAD_ADDR + imm.immediate), 0xEF);
   EXPECT_EQ(mMemoryController->GetHalfWord(SCRATCHPAD_ADDR + imm.immediate), 0xBEEF);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR + imm.immediate), 0xDEADBEEF);
}

TEST_F(InstructionHelperTest, SWLTest)
{
   InstructionSetImmediateType imm;
   imm.rs = 1;
   imm.rt = 2;

   StoreTestReset(imm);
   imm.immediate = 3;
   mInstructionHelper->SWL(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR + 4), 0x6B6B6B6B);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0xDEADBEEF);

   StoreTestReset(imm);
   imm.immediate = 4;
   mInstructionHelper->SWL(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR + 4), 0x6B6B6BDE);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0x6B6B6B6B);

   StoreTestReset(imm);
   imm.immediate = 5;
   mInstructionHelper->SWL(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR + 4), 0x6B6BDEAD);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0x6B6B6B6B);

   StoreTestReset(imm);
   imm.immediate = 6;
   mInstructionHelper->SWL(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR + 4), 0x6BDEADBE);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0x6B6B6B6B);

   StoreTestReset(imm);
   imm.immediate = 7;
   mInstructionHelper->SWL(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR + 4), 0xDEADBEEF);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0x6B6B6B6B);
}

TEST_F(InstructionHelperTest, SWRTest)
{
   InstructionSetImmediateType imm;
   imm.rs = 1;
   imm.rt = 2;

   StoreTestReset(imm);
   imm.immediate = 4;
   mInstructionHelper->SWR(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0x6B6B6B6B);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR + 4), 0xDEADBEEF);

   StoreTestReset(imm);
   imm.immediate = 3;
   mInstructionHelper->SWR(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0xEF6B6B6B);

   StoreTestReset(imm);
   imm.immediate = 2;
   mInstructionHelper->SWR(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0xBEEF6B6B);

   StoreTestReset(imm);
   imm.immediate = 1;
   mInstructionHelper->SWR(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0xADBEEF6B);

   StoreTestReset(imm);
   imm.immediate = 0;
   mInstructionHelper->SWR(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0xDEADBEEF);
}

TEST_F(InstructionHelperTest, SWLandSWRTest)
{
   InstructionSetImmediateType imm;
   imm.rs = 1;
   imm.rt = 2; 

   StoreTestReset(imm);
   imm.immediate = 0;
   mInstructionHelper->SWR(imm);
   imm.immediate = 3;
   mInstructionHelper->SWL(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0xDEADBEEF);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR + 4), 0x6B6B6B6B);

   StoreTestReset(imm);
   imm.immediate = 1;
   mInstructionHelper->SWR(imm);
   imm.immediate = 4;
   mInstructionHelper->SWL(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0xADBEEF6B);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR + 4), 0x6B6B6BDE);

   StoreTestReset(imm);
   imm.immediate = 2;
   mInstructionHelper->SWR(imm);
   imm.immediate = 5;
   mInstructionHelper->SWL(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0xBEEF6B6B);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR + 4), 0x6B6BDEAD);

   StoreTestReset(imm);
   imm.immediate = 3;
   mInstructionHelper->SWR(imm);
   imm.immediate = 6;
   mInstructionHelper->SWL(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0xEF6B6B6B);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR + 4), 0x6BDEADBE);

   StoreTestReset(imm);
   imm.immediate = 4;
   mInstructionHelper->SWR(imm);
   imm.immediate = 8;
   mInstructionHelper->SWL(imm);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR), 0x6B6B6B6B);
   EXPECT_EQ(mMemoryController->GetWord(SCRATCHPAD_ADDR + 4), 0xDEADBEEF);
}

TEST_F(InstructionHelperTest, LHUTest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rs = 1;
   // Set to the beginning of the bios
   mRegisters.genReg[imm.rs] = BIOS_ADDR;

   // Byte Value at 0x124 is 49 6E -> 0x6E49
   imm.immediate = 0x124;
   mInstructionHelper->LHU(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 0x6E49);

   // Byte Value at 0x320 is 25 F8 or -2011
   imm.immediate = 0x228;
   mInstructionHelper->LHU(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 63525);
}

TEST_F(InstructionHelperTest, ADDITest)
{
   Reset();

   InstructionSetImmediateType imm;
   imm.rs = 0b10101;
   imm.rt = 0b10110;

   imm.immediate = (HalfWord)(2);
   mRegisters.genReg[imm.rs] = 2;
   mInstructionHelper->ADDI(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], 4);

   imm.immediate = (HalfWord)(-1347);
   mRegisters.genReg[imm.rs] = 0xABCD;
   mInstructionHelper->ADDI(imm);
   EXPECT_EQ(mRegisters.genReg[imm.rt], -1347 + 0xABCD);

   imm.immediate = 1;
   mRegisters.genReg[imm.rs] = INT_MAX;
   EXPECT_THROW(mInstructionHelper->ADDI(imm), std::exception);
}

TEST_F(InstructionHelperTest, ADDIUTest)
{

}

TEST_F(InstructionHelperTest, SLTITest)
{

}

TEST_F(InstructionHelperTest, SLTIUTest)
{

}

TEST_F(InstructionHelperTest, ANDITest)
{

}

TEST_F(InstructionHelperTest, ORITest)
{
   Reset();

   InstructionSetImmediateType imm;
   imm.rs = 0b10101;
   imm.rt = 0b10110;
   imm.immediate = 0xDEAD;
   mRegisters.genReg[imm.rs] = 0xABCD;
   mInstructionHelper->ORI(imm);

   EXPECT_EQ(mRegisters.genReg[imm.rt], 0xABCD | 0xDEAD);

   mRegisters.genReg[imm.rs] = 0xABCD0000;
   mInstructionHelper->ORI(imm);

   EXPECT_EQ(mRegisters.genReg[imm.rt], 0xABCDDEAD);
}

TEST_F(InstructionHelperTest, XORITest)
{
   Reset();

   InstructionSetImmediateType imm;
   imm.rs = 0b10101;
   imm.rt = 0b10110;
   imm.immediate = 0xDEAD;
   mRegisters.genReg[imm.rs] = 0xABCD;
   mInstructionHelper->XORI(imm);

   EXPECT_EQ(mRegisters.genReg[imm.rt], 0xABCD ^ 0xDEAD);
}

TEST_F(InstructionHelperTest, LUITest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rt = 0b10101;
   imm.immediate = 0xABCD;

   mInstructionHelper->LUI(imm);

   EXPECT_EQ(mRegisters.genReg[imm.rt], 0xABCD0000);
}

