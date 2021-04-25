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