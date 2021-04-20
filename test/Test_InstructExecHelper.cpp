#include "gtest/gtest.h"

#include "InstructionHelper.h"
#include "CommonTypes.h"

using namespace PSEmu;

// Test fixture
struct InstructExecHelperTest : public testing::Test
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

TEST_F(InstructExecHelperTest, LUITest)
{
   InstructionSetImmediateType imm;
   imm.rt = 0b10101;
   imm.immediate = 0xABCD;

   InstructionHelper::LUI(imm, mRegisters);

   EXPECT_EQ(mRegisters.genReg[imm.rt], 0xABCD0000);
}