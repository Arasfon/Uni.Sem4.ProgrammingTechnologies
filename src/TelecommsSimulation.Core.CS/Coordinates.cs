using System;

namespace TelecommsSimulation.Core;

public readonly struct Coordinates
{
    public double Latitude { get; }
    public double Longitude { get; }

    public Coordinates(double latitude, double longitude)
    {
        latitude = (latitude + 90) % 180 - 90;
        longitude = (longitude + 180) % 360 - 180;

        Latitude = latitude;
        Longitude = longitude;
    }

    public double CalculateKmDistanceTo(Coordinates to) =>
        CalculateKmDistance(this, to);

    public static double CalculateKmDistance(Coordinates from, Coordinates to)
    {
        const double earthMeanRadius = 6371;
        const double p = Math.PI / 180;

        double a = 0.5 - Math.Cos((to.Latitude - from.Latitude) * p) / 2 +
            Math.Cos(from.Latitude * p) * Math.Cos(to.Latitude * p) * (1 - Math.Cos((to.Longitude - from.Longitude) * p)) / 2;
        return 2 * earthMeanRadius * Math.Asin(Math.Sqrt(a));
    }
}
