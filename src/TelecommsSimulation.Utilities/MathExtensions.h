#pragma once

namespace TelecommsSimulation::Utilities
{
    public ref class MathExtensions sealed
    {
    public:
        static double FMod(double x, double y);
        static double Clamp(double value, double min, double max);
    };
}
