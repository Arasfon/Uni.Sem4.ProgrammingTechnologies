#include "pch.h"

#include "SimulationVisualizationForm.h"

#include "TelecommsSimulationVisualizationEngine.h"

using namespace System::Timers;

using namespace TelecommsSimulation::Core;
using namespace TelecommsSimulation::Utilities;

namespace TelecommsSimulation
{
    SimulationVisualizationForm::SimulationVisualizationForm(
        IVisualizationRegistry<BaseStation^>^ baseStationVisualizationRegistry,
        IVisualizationRegistry<Phone^>^ phoneVisualizationRegistry)
    {
        InitializeComponent();

        _visualizationEngine = gcnew TelecommsSimulationVisualizationEngine(
            baseStationVisualizationRegistry, phoneVisualizationRegistry);

        _timer = gcnew Timers::Timer();
        _timer->Interval = 6; // ≈166 FPS
        _timer->Elapsed += gcnew ElapsedEventHandler(this, &SimulationVisualizationForm::OnTimerElapsed);
        _timer->Start();
    }

    void SimulationVisualizationForm::OnTimerElapsed(Object^ sender, ElapsedEventArgs^ e)
    {
        VisualizationPictureBox->Invalidate();
    }

    void SimulationVisualizationForm::VisualizationPictureBox_Paint(Object^ sender, PaintEventArgs^ e)
    {
        PictureBox^ pictureBox = safe_cast<PictureBox^>(sender);

        e->Graphics->Clear(pictureBox->BackColor);

        _visualizationEngine->Visualize(e->Graphics, pictureBox->Size);
    }

    void SimulationVisualizationForm::SimulationVisualizationForm_FormClosed(Object^ sender, FormClosedEventArgs^ e)
    {
        delete _visualizationEngine;
    }
}
