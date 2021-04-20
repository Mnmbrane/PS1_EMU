#include "gtest/gtest.h"

#include "InstructionHelper.h"
#include "CommonTypes.h"

using namespace PSEmu;

// Test fixture
struct InstructionHelperTest : public testing::Test
{
   virtual void SetUp()
   {
      Reset();
   }
   virtual void TearDown()
   {

   }
   void Reset()
   {
      memset(&mRegisters, GARBAGE, sizeof(mRegisters.genReg));
      mRegisters.genReg[ZR] = 0;
   }
   RegisterType mRegisters;
};

TEST_F(InstructionHelperTest, LUITest)
{
   Reset();
   InstructionSetImmediateType imm;
   imm.rt = 0b10101;
   imm.immediate = 0xABCD;

   InstructionHelper::LUI(imm, mRegisters);

   EXPECT_EQ(mRegisters.genReg[imm.rt], 0xABCD0000);
}

TEST_F(InstructionHelperTest, ORTest)
{
   Reset();
   InstructionSetImmediateType imm1;
   imm1.rt = 0b10101;
   imm1.immediate = 0xABCD;

   InstructionHelper::LUI(imm1, mRegisters);

   InstructionSetImmediateType imm2;
   imm2.rs = 0b10101;
   imm2.rt = 0b10110;
   imm2.immediate = 0xDEAD;

   InstructionHelper::ORI(imm2, mRegisters);

   EXPECT_EQ(mRegisters.genReg[imm2.rt], 0xABCD0000 | 0xDEAD);
}