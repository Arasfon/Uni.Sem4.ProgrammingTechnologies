#pragma once

#include "ILocatable.h"

namespace TelecommsSimulation::Core
{
    public interface class ILocatableMovable : public ILocatable
    {
        property Coordinates Location
        {
            Coordinates get();
            void set(Coordinates value);
        }
    };
}
