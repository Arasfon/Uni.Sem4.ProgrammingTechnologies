#include "pch.h"

using namespace System;

namespace TelecommsSimulation::Utilities
{
    double MathExtensions::FMod(const double x, const double y)
    {
        return x - y * Math::Truncate(x / y);
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
