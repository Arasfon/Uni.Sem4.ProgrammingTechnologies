#pragma once

#include "ISimulatable.h"

namespace TelecommsSimulation::Engine
{
    public interface class ITimeAwareSimulatable : public ISimulatable
    {
        void ProcessTimeTick(unsigned long long currentTick);
    };
}
