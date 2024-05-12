#pragma once

namespace TelecommsSimulation::Core
{
    public value struct Coordinates
    {
    private:
        double _latitude;
        double _longitude;

    public:
        property double Latitude
        {
            double get();
        protected:
            initonly void set(double value);
        }

        property double Longitude
        {
            double get();
        protected:
            initonly void set(double value);
        }

        Coordinates(double latitude, double longitude);

        double CalculateKmDistanceTo(Coordinates to);

        static double CalculateKmDistance(Coordinates from, Coordinates to);
    };
}
