#include "pch.h"

#include "ScenarioControlPanelForm.h"

#include "CompiledScenarioSimlationEngine.h"

using namespace TelecommsSimulation::Engine;

namespace TelecommsSimulation
{
    ScenarioControlPanelForm::ScenarioControlPanelForm()
    {
        InitializeComponent();

        _simulationEngine = gcnew CompiledScenarioSimulationEngine();

        // ReSharper disable once CppObjectMemberMightNotBeInitialized
        SimulationSpeedTrackBar->DataBindings->Add("Value", _simulationEngine, "SpeedPercentage", false,
                                                   DataSourceUpdateMode::OnPropertyChanged);

        _simulationEngine->PropertyChanged += gcnew PropertyChangedEventHandler(
            this, &ScenarioControlPanelForm::OnSimulationEnginePropertyChanged);
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void ScenarioControlPanelForm::SimulationStartButton_Click(Object^ sender, EventArgs^ e)
    {
        _simulationEngine->Start();
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void ScenarioControlPanelForm::SimulationStopButton_Click(Object^ sender, EventArgs^ e)
    {
        _simulationEngine->Stop();
    }

    void ScenarioControlPanelForm::OnSimulationEnginePropertyChanged(Object^ sender, PropertyChangedEventArgs^ e)
    {
        if (e->PropertyName == "IsRunning")
        {
            switch (_simulationEngine->IsRunning)
            {
                case false:
                    {
                        SimulationStartButton->Enabled = true;
                        SimulationStopButton->Enabled = false;
                        break;
                    }
                case true:
                    {
                        SimulationStartButton->Enabled = false;
                        SimulationStopButton->Enabled = true;
                        break;
                    }
            }
        }
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void ScenarioControlPanelForm::ScenarioControlPanelForm_FormClosed(Object^ sender, FormClosedEventArgs^ e)
    {
        delete _simulationEngine;
    }
}
