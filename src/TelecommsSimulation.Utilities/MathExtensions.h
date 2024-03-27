#pragma once

namespace TelecommsSimulation::Utilities
{
    public ref class MathExtensions sealed
    {
    public:
        static double FMod(const double x, const double y)
        {
            return x - y * System::Math::Floor(x / y);
        }

        static double Clamp(const double value, const double min, const double max)
        {
            if (value < min)
                return min;

            if (value > max)
                return max;

            return value;
        }
    };
}
