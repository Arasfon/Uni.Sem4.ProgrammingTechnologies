#pragma once

namespace TelecommsSimulation
{
    public interface class IVisualizationEngine
    {
        void Visualize(System::Drawing::Graphics^ graphics, System::Drawing::SizeF areaSize);
    };
}
