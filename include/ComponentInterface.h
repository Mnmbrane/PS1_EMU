#pragma once
#include "CommonTypes.h"

namespace PSEmu
{
   class I_Component
   {
   public:
      virtual void Initialize() = 0;
      virtual void Reset() = 0;

   };
}