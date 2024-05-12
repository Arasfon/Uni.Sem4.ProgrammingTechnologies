#pragma once

#include "Coordinates.h"

namespace TelecommsSimulation::Core
{
    public interface class ILocatable
    {
        property Coordinates Location
        {
            Coordinates get();
        }
    };
}
