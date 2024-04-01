#include "pch.h"

#include "TelecommsSimulationVisualizationEngine.h"

#include "GraphicsExtensions.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Drawing;
using namespace System::Drawing::Drawing2D;
using namespace System::Drawing::Text;

using namespace TelecommsSimulation::Core;

namespace TelecommsSimulation
{
    TelecommsSimulationVisualizationEngine::TelecommsSimulationVisualizationEngine(
        IVisualizationRegistry<BaseStation^>^ baseStationVisualizationRegistry,
        IVisualizationRegistry<Phone^>^ phoneVisualizationRegistry)
    {
        _baseStationVisualizationRegistry = baseStationVisualizationRegistry;
        _phoneVisualizationRegistry = phoneVisualizationRegistry;

        _centerStringFormat = gcnew StringFormat();
        _centerStringFormat->Alignment = StringAlignment::Center;
        _centerStringFormat->LineAlignment = StringAlignment::Center;

        _baseStationConnectionPen = gcnew Pen(Color::DarkSlateGray, 3);
        _phoneCallConnectionPen = gcnew Pen(Color::BlueViolet, 2);
    }

    TelecommsSimulationVisualizationEngine::~TelecommsSimulationVisualizationEngine()
    {
        delete _coverageBrush;
        delete _baseStationConnectionPen;
        delete _phoneCallConnectionPen;
        delete _stringFontFamily;
        delete _stringFont;
        delete _centerStringFormat;
    }

    void TelecommsSimulationVisualizationEngine::Visualize(Graphics^ graphics, SizeF areaSize)
    {
        graphics->CompositingQuality = CompositingQuality::HighQuality;
        graphics->SmoothingMode = SmoothingMode::AntiAlias;
        graphics->TextRenderingHint = TextRenderingHint::AntiAliasGridFit;

        PointF center = PointF(areaSize.Width / 2., areaSize.Height / 2.);

        Dictionary<Phone^, PointF>^ phonePointCache = gcnew Dictionary<Phone^, PointF>();

        // Fill coverage first, because it blends with other colors
        for each (BaseStation^ baseStation in _baseStationVisualizationRegistry)
        {
            graphics->FillEllipse(_coverageBrush,
                                  CalculateCoverageRectangleOnScreen(center, baseStation->Location,
                                                                     baseStation->CoverageRadiusKm));
        }

        for each (Phone^ phone in _phoneVisualizationRegistry)
        {
            PointF phonePoint = ConvertLocationToScreenPoint(phone->Location, center);

            phonePointCache->Add(phone, phonePoint);

            graphics->FillEllipse(Brushes::OrangeRed, phonePoint.X - _phonePointDiameter / 2,
                                  phonePoint.Y - _phonePointDiameter / 2, _phonePointDiameter, _phonePointDiameter);

            GraphicsExtensions::DrawString(graphics, phone->Number, _stringFont, Brushes::WhiteSmoke,
                                           Brushes::OrangeRed, phonePoint, _centerStringFormat);
        }

        for each (BaseStation^ baseStation in _baseStationVisualizationRegistry)
        {
            PointF baseStationPoint = ConvertLocationToScreenPoint(baseStation->Location, center);

            graphics->FillEllipse(Brushes::Black, baseStationPoint.X - _baseStationPointDiameter / 2,
                                  baseStationPoint.Y - _baseStationPointDiameter / 2, _baseStationPointDiameter,
                                  _baseStationPointDiameter);

            GraphicsExtensions::DrawString(graphics, baseStation->Name, _stringFont, Brushes::WhiteSmoke,
                                           Brushes::Black, baseStationPoint, _centerStringFormat);

            for each (Phone^ phone in baseStation->ConnectedPhones)
            {
                PointF phonePoint = phonePointCache[phone];

                graphics->DrawLine(_baseStationConnectionPen, phonePoint, baseStationPoint);
            }
        }

        for each (CallPhoneData^ callPhoneData in BaseStation::CurrentCalls)
        {
            PointF phone1Point = phonePointCache[callPhoneData->Caller];
            PointF phone2Point = phonePointCache[callPhoneData->Receiver];

            graphics->DrawLine(_phoneCallConnectionPen, phone1Point, phone2Point);
        }
    }

    PointF TelecommsSimulationVisualizationEngine::ConvertLocationToScreenPoint(const double latitude,
        const double longitude, PointF referencePoint)
    {
        return PointF(referencePoint.X + latitude * _latitudeToPixelRatio,
                      referencePoint.Y + longitude * _longitudeToPixelRatio);
    }

    PointF TelecommsSimulationVisualizationEngine::ConvertLocationToScreenPoint(
        Coordinates location, PointF referencePoint)
    {
        return ConvertLocationToScreenPoint(location.Latitude, location.Longitude, referencePoint);
    }

    SizeF TelecommsSimulationVisualizationEngine::ConvertLocationDifferenceToSize(
        const double latitude, const double longitude)
    {
        return SizeF(latitude * _latitudeToPixelRatio, longitude * _longitudeToPixelRatio);
    }

    RectangleF TelecommsSimulationVisualizationEngine::CalculateCoverageRectangleOnScreen(
        PointF center, Coordinates centerLocation,
        const double coverageRadius)
    {
        const double latitudeChange = coverageRadius / 110.574;
        const double longitudeChange = coverageRadius / 111.320 * Math::Cos(latitudeChange * Math::PI / 180);

        PointF screenPoint = ConvertLocationToScreenPoint(
            Coordinates(centerLocation.Latitude - latitudeChange, centerLocation.Longitude - longitudeChange), center);

        SizeF rectangleSize = ConvertLocationDifferenceToSize(latitudeChange * 2, longitudeChange * 2);

        return RectangleF(screenPoint, rectangleSize);
    }
}
