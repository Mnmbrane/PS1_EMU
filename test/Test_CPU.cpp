#include "gtest/gtest.h"

#include "CPU.h"
#include "Memory.h"

#include <stdexcept> // invalid_argument
#include <time.h>    // time
#include <stdlib.h>  // rand

using namespace PSEmu;

// Test fixture
struct CPUTest : public testing::Test
{
   virtual void SetUp()
   {
      mMem = new Memory();
      mCPU = new CPU(mMem);
   }
   virtual void TearDown()
   {
      delete mCPU;
      delete mMem;
   }
   CPU* mCPU;
   Memory* mMem;
};

TEST(TestConstruction, NullMemory)
{
   EXPECT_THROW(CPU(nullptr), std::invalid_argument);
}

TEST_F(CPUTest, TestReset)
{
   srand(time(NULL));
   for(int reg = 0; reg < MAX_REG_NUM; reg++)
   {
      mCPU->SetRegister(static_cast<RegisterType>(reg), rand() % 0xFFFF);
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