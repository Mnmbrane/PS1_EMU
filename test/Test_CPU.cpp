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
   for(int reg = 0; reg < MAX_REG_NUM; reg++)
   {
      // Set register to 0xFFFF + reg which is just arbitrary
      mCPU->SetRegister(static_cast<RegisterType>(reg), reg + 0xFFFF);
   }
   mCPU->Reset();

   EXPECT_EQ(mCPU->GetRegister(PC), PC_RESET_VAL);
   for(int reg = 0; reg < MAX_REG_NUM; reg++)
   {
      if(reg == PC)
      {
         EXPECT_EQ(mCPU->GetRegister(PC), PC_RESET_VAL);
      }
      else
      {
         EXPECT_EQ(mCPU->GetRegister(static_cast<RegisterType>(reg)), 0);
      }
   }

   // Everything else is zero
}

TEST_F(CPUTest, DecodeInstructionTest)
{ 
   // Test instructions
   Instruction ins = 0x3c080013;
   InstructionDecodeType dIns = mCPU->DecodeInstruction(ins);

   EXPECT_EQ(E_INSTRUCTION_IMM, dIns.insSelect);
   EXPECT_EQ(0b001111, dIns.instruction.immType.op);

}