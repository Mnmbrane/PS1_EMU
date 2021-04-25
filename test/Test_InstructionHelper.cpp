#include "gtest/gtest.h"

#include "InstructionHelper.h"
#include "CommonTypes.h"
#include "MemoryController.h"

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
      mRegisters.genReg[ZR] = 0;
   }
   RegisterType mRegisters;
   MemoryController* mMemoryController;
   InstructionHelper* mInstructionHelper;
};

TEST_F(InstructionHelperTest, LBTest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rs = 0b10;
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
   imm.rs = 0b10;
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
   imm.rs = 0b10;
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

TEST_F(InstructionHelperTest, LHUTest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rs = 0b10;
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

TEST_F(InstructionHelperTest, LUITest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rt = 0b10101;
   imm.immediate = 0xABCD;

   mInstructionHelper->LUI(imm);

   EXPECT_EQ(mRegisters.genReg[imm.rt], 0xABCD0000);
}

TEST_F(InstructionHelperTest, ORTest)
{
   Reset();
   InstructionSetImmediateType imm1;
   imm1.rt = 0b10101;
   imm1.immediate = 0xABCD;

   mInstructionHelper->LUI(imm1);

   InstructionSetImmediateType imm2;
   imm2.rs = 0b10101;
   imm2.rt = 0b10110;
   imm2.immediate = 0xDEAD;

   mInstructionHelper->ORI(imm2);

   EXPECT_EQ(mRegisters.genReg[imm2.rt], 0xABCD0000 | 0xDEAD);
}