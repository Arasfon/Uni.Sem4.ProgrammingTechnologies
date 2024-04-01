#include "pch.h"

#include "GraphicsExtensions.h"

using namespace System;
using namespace System::Drawing;

namespace TelecommsSimulation
{
    void GraphicsExtensions::DrawString(Graphics^ graphics, String^ s, Font^ font, Brush^ foregroundBrush,
                                        Brush^ backgroundBrush, PointF point, StringFormat^ stringFormat)
    {
        SizeF stringSize = graphics->MeasureString(s, font, point, stringFormat);
        RectangleF stringRectangle = RectangleF(point.X - stringSize.Width / 2, point.Y - stringSize.Height / 2,
                                                stringSize.Width, stringSize.Height);

        graphics->FillRectangle(backgroundBrush, stringRectangle);

        graphics->DrawString(s, font, foregroundBrush, point, stringFormat);
    }
}
