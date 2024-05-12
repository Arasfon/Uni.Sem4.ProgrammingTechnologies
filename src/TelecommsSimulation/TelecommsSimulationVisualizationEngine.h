#pragma once

#include "IVisualizationEngine.h"
#include "IVisualizationRegistry.h"

namespace TelecommsSimulation
{
    public ref class TelecommsSimulationVisualizationEngine : public IVisualizationEngine
    {
        IVisualizationRegistry<Core::BaseStation^>^ _baseStationVisualizationRegistry;
        IVisualizationRegistry<Core::Phone^>^ _phoneVisualizationRegistry;

        literal float _scale = 1.;
        literal float _latitudeToPixelRatio = 60. * _scale;
        literal float _longitudeToPixelRatio = 55. * _scale;

        literal float _phonePointDiameter = 18;
        literal float _baseStationPointDiameter = 24;

        System::Drawing::SolidBrush^ _coverageBrush = gcnew System::Drawing::SolidBrush(
            System::Drawing::Color::FromArgb(30, 0, 255, 0));
        // Workaround (see constructor): C++/CLI errors with recursive default member initializer
        System::Drawing::Pen^ _baseStationConnectionPen;
        /*= gcnew System::Drawing::Pen(System::Drawing::Color::DarkSlateGray, 3);*/
        System::Drawing::Pen^ _phoneCallConnectionPen;
        /*= gcnew System::Drawing::Pen(System::Drawing::Color::BlueViolet, 2);*/

        System::Drawing::FontFamily^ _stringFontFamily = gcnew System::Drawing::FontFamily("Segoe UI");
        System::Drawing::Font^ _stringFont = gcnew System::Drawing::Font(
            _stringFontFamily, 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Pixel);

        System::Drawing::StringFormat^ _centerStringFormat;

    public:
        TelecommsSimulationVisualizationEngine(
            IVisualizationRegistry<Core::BaseStation^>^ baseStationVisualizationRegistry,
            IVisualizationRegistry<Core::Phone^>^ phoneVisualizationRegistry);

        ~TelecommsSimulationVisualizationEngine();

        virtual void Visualize(System::Drawing::Graphics^ graphics, System::Drawing::SizeF areaSize);

    private:
        static System::Drawing::PointF ConvertLocationToScreenPoint(double latitude, double longitude,
                                                                    System::Drawing::PointF referencePoint);
        static System::Drawing::PointF ConvertLocationToScreenPoint(Core::Coordinates location,
                                                                    System::Drawing::PointF referencePoint);
        static System::Drawing::SizeF ConvertLocationDifferenceToSize(double latitude, double longitude);
        static System::Drawing::RectangleF CalculateCoverageRectangleOnScreen(
            System::Drawing::PointF center, Core::Coordinates centerLocation, double coverageRadius);
    };
}
