#pragma once

namespace TelecommsSimulation
{
    [System::Runtime::CompilerServices::ExtensionAttribute]
    public ref class GraphicsExtensions sealed
    {
    public:
        [System::Runtime::CompilerServices::ExtensionAttribute]
        static void DrawString(System::Drawing::Graphics^ graphics, System::String^ s, System::Drawing::Font^ font,
                               System::Drawing::Brush^ foregroundBrush, System::Drawing::Brush^ backgroundBrush,
                               System::Drawing::PointF point, System::Drawing::StringFormat^ stringFormat);
    };
}
