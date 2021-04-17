#pragma once

namespace PSEmu
{
   class I_Component
   {
   public:
      virtual bool Initialize() = 0;
      virtual void Reset() = 0;
   };
}