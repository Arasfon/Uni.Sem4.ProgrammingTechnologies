#include "pch.h"

#include "FreeControlPanelForm.h"

#include "BaseStationForm.h"
#include "PhoneForm.h"
#include "PhoneBlacklistForm.h"
#include "RandomlyMovingSimulatable.h"
#include "SimulatableToFormLifecycleBinder.h"

using namespace TelecommsSimulation::Engine;
using namespace TelecommsSimulation::Core;

namespace TelecommsSimulation
{
    FreeControlPanelForm::FreeControlPanelForm()
    {
        InitializeComponent();

        _simulationEngine = gcnew TimeAwareSimulationEngine<ITimeAwareSimulatable^>();

        // ReSharper disable once CppObjectMemberMightNotBeInitialized
        SimulationSpeedTrackBar->DataBindings->Add("Value", _simulationEngine, "SpeedPercentage", false,
                                                   DataSourceUpdateMode::OnPropertyChanged);

        _simulationEngine->PropertyChanged += gcnew PropertyChangedEventHandler(
            this, &FreeControlPanelForm::OnSimulationEnginePropertyChanged);
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void FreeControlPanelForm::SimulationStartButton_Click(Object^ sender, EventArgs^ e)
    {
        _simulationEngine->Start();
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void FreeControlPanelForm::SimulationStopButton_Click(Object^ sender, EventArgs^ e)
    {
        _simulationEngine->Stop();
    }

    void FreeControlPanelForm::CreateBaseStationButton_Click(Object^ sender, EventArgs^ e)
    {
        auto baseStation = gcnew BaseStation(BaseStationNameTextBox->Text, Coordinates(
                                                 safe_cast<double>(BaseStationLatitudeNumericUpDown->Value),
                                                 safe_cast<double>(BaseStationLongitudeNumericUpDown->Value)),
                                             safe_cast<double>(BaseStationCoverageNumericUpDown->Value));

        (gcnew BaseStationForm(baseStation))->Show();
    }

    void FreeControlPanelForm::CreatePhoneButton_Click(Object^ sender, EventArgs^ e)
    {
        auto phone = gcnew Phone(PhoneNumberTextBox->Text, Coordinates(
                                     safe_cast<double>(PhoneLatitudeNumericUpDown->Value),
                                     safe_cast<double>(PhoneLongitudeNumericUpDown->Value)),
                                 safe_cast<double>(PhoneBatteryLevelNumericUpDown->Value));

        auto randomlyMovingPhone = gcnew RandomlyMovingSimulatable<Phone^>(phone);

        _simulationEngine->Add(randomlyMovingPhone);

        auto phoneForm = gcnew PhoneForm(phone, true);

        SimulatableToFormLifecycleBinder<ITimeAwareSimulatable^>::Bind(_simulationEngine, randomlyMovingPhone,
                                                                       phoneForm);

        phoneForm->Show();
    }

    void FreeControlPanelForm::CreatePhoneWithBlacklistButton_Click(Object^ sender, EventArgs^ e)
    {
        auto phone = gcnew PhoneWithBlacklist(PhoneNumberTextBox->Text, Coordinates(
                                                  safe_cast<double>(PhoneLatitudeNumericUpDown->Value),
                                                  safe_cast<double>(PhoneLongitudeNumericUpDown->Value)),
                                              safe_cast<double>(PhoneBatteryLevelNumericUpDown->Value));

        auto randomlyMovingPhone = gcnew RandomlyMovingSimulatable<Phone^>(phone);

        _simulationEngine->Add(randomlyMovingPhone);

        auto phoneForm = gcnew PhoneForm(phone, true);
        auto blacklistForm = gcnew PhoneBlacklistForm(phone);

        SimulatableToFormLifecycleBinder<ITimeAwareSimulatable^>::Bind(_simulationEngine, randomlyMovingPhone,
                                                                       phoneForm);

        phoneForm->Show();
        blacklistForm->Show(phoneForm);
    }

    void FreeControlPanelForm::OnSimulationEnginePropertyChanged(Object^ sender, PropertyChangedEventArgs^ e)
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
}
