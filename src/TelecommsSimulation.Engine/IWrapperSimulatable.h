#pragma once

#include "ISimulatable.h"

namespace TelecommsSimulation::Engine
{
    generic<typename T>
    public interface class IWrapperSimulatable : public ISimulatable
    {
        property T Entity
        {
            T get();
        }
    };
}
