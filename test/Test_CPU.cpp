#include "gtest/gtest.h"

#include "CPU.h"
#include "CommonTypes.h"

using namespace PSEmu;

// Test fixture
struct CPUTest : public testing::Test
{
   virtual void SetUp()
   {
      mCPU = new CPU();
      mCPU->Initialize();
   }
   virtual void TearDown()
   {
      delete mCPU;
   }
   CPU* mCPU;
};

TEST_F(CPUTest, TestReset)
{
   mCPU->Reset();

   EXPECT_EQ(mCPU->GetSpecRegister(PC), PC_RESET_VAL);
   for(int reg = 0; reg < MAX_GEN_REG_NUM; reg++)
   {
      if(reg == 0)
      {
         EXPECT_EQ(mCPU->GetGenRegister(ZR), 0);
      }
      else
      {
         EXPECT_EQ(mCPU->GetGenRegister(static_cast<GeneralRegisterType>(reg)), GARBAGE);
      }
   }

   // Everything else is zero
}

TEST_F(CPUTest, DecodeInstructionTest)
{ 
   // Test instructions
   Instruction ins = 0x3c080013;
   InstructionDecodeType dIns = mCPU->DecodeInstruction(ins);

   EXPECT_EQ(15, dIns.immType.op);
   EXPECT_EQ(8, dIns.immType.rt);
   EXPECT_EQ(19, dIns.immType.immediate);
}