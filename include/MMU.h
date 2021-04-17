#pragma once
#include "Component.h"


namespace PSEmu
{
   class Bios;

   class MMU : public I_Component
   {
   public:
      MMU();
      ~MMU();
      virtual bool Initialize();
      virtual void Reset();
   private:
      Bios* mBios;
   };
   
}