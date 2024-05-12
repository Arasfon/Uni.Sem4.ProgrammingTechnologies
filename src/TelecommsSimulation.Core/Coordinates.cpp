#include "pch.h"

#include "Coordinates.h"

using namespace System;

using namespace TelecommsSimulation::Utilities;

namespace TelecommsSimulation::Core
{
    double Coordinates::Latitude::get()
    {
        return _latitude;
    }

    void Coordinates::Latitude::set(double value)
    {
        _latitude = value;
    }

    double Coordinates::Longitude::get()
    {
        return _longitude;
    }

    void Coordinates::Longitude::set(double value)
    {
        _longitude = value;
    }

    Coordinates::Coordinates(double latitude, double longitude)
    {
        latitude = MathExtensions::FMod(latitude + 90, 180) - 90;
        longitude = MathExtensions::FMod(longitude + 180, 360) - 180;

        Latitude = latitude;
        Longitude = longitude;
    }

    double Coordinates::CalculateKmDistanceTo(Coordinates to)
    {
        return CalculateKmDistance(*this, to);
    }

    double Coordinates::CalculateKmDistance(Coordinates from, Coordinates to)
    {
        constexpr double earthMeanRadius = 6371;
        constexpr double p = Math::PI / 180;

        const double a = 0.5 - Math::Cos((to.Latitude - from.Latitude) * p) / 2 +
            Math::Cos(from.Latitude * p) * Math::Cos(to.Latitude * p) * (1 - Math::Cos((to.Longitude - from.Longitude) * p)) / 2;
        return 2 * earthMeanRadius * Math::Asin(Math::Sqrt(a));
    }
}
