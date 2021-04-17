#include "MMU.h"
#include "Bios.h"

namespace PSEmu
{
   MMU::MMU():
      mBios(new Bios())
   {
   }
   
   MMU::~MMU() 
   {
      
   }
   
   bool MMU::Initialize() 
   {
      // Initialize the bios
      mBios->Initialize();
   }
   
   void MMU::Reset() 
   {
      
   }
}