#include "MemoryController.h"
#include "Kernel.h"
#include "UserMemory.h"
#include "ParallelPort.h"
#include "Scratchpad.h"
#include "HardwareRegisters.h"
#include "Bios.h"


#include <stdio.h>
#include <exception>

using namespace PSEmu;

// Switch Case ranges between x and x+y-1
#define GET_MEM_RANGE(x, y) x ... (x + y - 1)

MemoryController::MemoryController():
   mKernel(new Kernel()),
   mUserMemory(new UserMemory()),
   mParallelPort(new ParallelPort()),
   mScratchpad(new Scratchpad()),
   mHardwareRegisters(new HardwareRegisters()),
   mBios(new Bios)

{
}

MemoryController::~MemoryController() 
{
   delete mKernel;
   delete mUserMemory;
   delete mParallelPort;
   delete mScratchpad;
   delete mHardwareRegisters;
   delete mBios;
}

void MemoryController::Initialize() 
{
   mKernel->Initialize();
   mUserMemory->Initialize();
   mParallelPort->Initialize();
   mScratchpad->Initialize();
   mHardwareRegisters->Initialize();
   mBios->Initialize();
}

// Memory Map
I_Memory* MemoryController::GetMemoryRegion(const Word& addr)
{
   I_Memory* retMem = nullptr;
   
   switch(addr)
   {
      // Kernel
      case GET_MEM_RANGE(KERNEL_ADDR_1, KERNEL_SIZE):
      case GET_MEM_RANGE(KERNEL_ADDR_2, KERNEL_SIZE):
      case GET_MEM_RANGE(KERNEL_ADDR_3, KERNEL_SIZE):
         retMem = mKernel;
         break;

      // User Memory
      case GET_MEM_RANGE(USER_MEM_ADDR_1, USER_MEM_SIZE):
      case GET_MEM_RANGE(USER_MEM_ADDR_2, USER_MEM_SIZE):
      case GET_MEM_RANGE(USER_MEM_ADDR_3, USER_MEM_SIZE):
         retMem = mUserMemory;
         break;

      // Parallel Ports
      case GET_MEM_RANGE(PARALLEL_PORT_ADDR, PARALLEL_PORT_SIZE):
         retMem = mParallelPort;
         break;

      // Scratchpad
      case GET_MEM_RANGE(SCRATCHPAD_ADDR, SCRATCHPAD_SIZE):
         retMem = mScratchpad;
         break;

      // Hardware Registers
      case GET_MEM_RANGE(HW_REG_ADDR, HW_REG_SIZE):
         retMem = mHardwareRegisters;
         break;

      // Bios
      case GET_MEM_RANGE(BIOS_ADDR, BIOS_SIZE):
         retMem = mBios;
         break;
      default:
         throw std::exception();
         break;
   }
   return retMem;
}

void MemoryController::Reset()
{
   mKernel->Reset();
   mUserMemory->Reset();
   mParallelPort->Reset();
   mScratchpad->Reset();
   mHardwareRegisters->Reset();
   mBios->Reset();
}

Byte MemoryController::GetByte(const Word& addr) 
{
   Word retVal = 0;
   I_Memory* memRegion = nullptr;

   // Address needs to be word aligned
   if(addr % 4 != 0)
   {
      printf("ERROR: %s Unaligned address", __func__);
   }
   else
   {
      memRegion = GetMemoryRegion(addr);
      if(memRegion != nullptr)
      {
         retVal = memRegion->GetByte(addr);
      }
   }

   return retVal;
}

HalfWord MemoryController::GetHalfWord(const Word& addr) 
{
   Word retVal = 0;
   I_Memory* memRegion = nullptr;

   // Address needs to be word aligned
   if(addr % 4 != 0)
   {
      throw std::exception();
   }
   else
   {
      memRegion = GetMemoryRegion(addr);
      if(memRegion != nullptr)
      {
         retVal = memRegion->GetHalfWord(addr);
      }
   }

   return retVal;
}

// Memory Mapping
Word MemoryController::GetWord(const Word& addr) 
{
   Word retVal = 0;
   I_Memory* memRegion = nullptr;

   // Address needs to be word aligned
   if(addr % 4 != 0)
   {
      throw std::exception();
   }
   else
   {
      memRegion = GetMemoryRegion(addr);
      if(memRegion != nullptr)
      {
         retVal = memRegion->GetWord(addr);
      }
   }

   return retVal;
}

void MemoryController::StoreWord(const Word& addr, const Word val) 
{
   Word offset = 0;
   I_Memory* memRegion = nullptr;
   // Address needs to be word aligned
   if(addr % 4 != 0)
   {
      printf("ERROR: %s Unaligned address", __func__);
   }
   else
   {
      memRegion = GetMemoryRegion(addr);
      if(memRegion == mBios)
      {
         throw std::exception();
      }
      else if(memRegion != nullptr)
      {
         memRegion->StoreWord(offset, val);
      }

   }
}

bool MemoryController::CheckAddrInRange(const Word& addr,
                            const Word& startAddr,
                            const Word& memSize) 
{
   return (addr >= startAddr && addr < (startAddr + memSize));
}