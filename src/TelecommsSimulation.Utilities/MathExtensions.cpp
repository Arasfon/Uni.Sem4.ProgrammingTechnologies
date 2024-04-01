#include "pch.h"

namespace TelecommsSimulation::Utilities
{
    double MathExtensions::FMod(const double x, const double y)
    {
        return x - y * System::Math::Floor(x / y);
    }

    double MathExtensions::Clamp(const double value, const double min, const double max)
    {
        if (value < min)
            return min;

        if (value > max)
            return max;

        return value;
    }
}
