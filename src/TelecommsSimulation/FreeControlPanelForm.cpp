#include "pch.h"

#include "FreeControlPanelForm.h"

#include "BaseStationForm.h"
#include "PhoneForm.h"
#include "PhoneBlacklistForm.h"
#include "RandomlyMovingSimulatable.h"
#include "SimulatableToFormLifecycleBinder.h"

#include "SimulationVisualizationForm.h"
#include "VisualizationRegistry.h"
#include "VisualizationRegistryObjectToFormLifecycleBinder.h"

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

        _baseStationVisualizationRegistry = gcnew VisualizationRegistry<BaseStation^>();
        _phoneVisualizationRegistry = gcnew VisualizationRegistry<Phone^>();

        _simulationVisualizationForm = gcnew SimulationVisualizationForm(_baseStationVisualizationRegistry, _phoneVisualizationRegistry);
        _simulationVisualizationForm->Show();
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
        BaseStation^ baseStation = gcnew BaseStation(BaseStationNameTextBox->Text, Coordinates(
                                                         safe_cast<double>(BaseStationLatitudeNumericUpDown->Value),
                                                         safe_cast<double>(BaseStationLongitudeNumericUpDown->Value)),
                                                     safe_cast<double>(BaseStationCoverageNumericUpDown->Value));

        BaseStationForm^ baseStationForm = gcnew BaseStationForm(baseStation);

        VisualizationRegistryObjectToFormLifecycleBinder<BaseStation^>::Bind(_baseStationVisualizationRegistry, baseStation, baseStationForm);

        baseStationForm->Show();
    }

    void FreeControlPanelForm::CreatePhoneButton_Click(Object^ sender, EventArgs^ e)
    {
        Phone^ phone = gcnew Phone(PhoneNumberTextBox->Text, Coordinates(
                                       safe_cast<double>(PhoneLatitudeNumericUpDown->Value),
                                       safe_cast<double>(PhoneLongitudeNumericUpDown->Value)),
                                   safe_cast<double>(PhoneBatteryLevelNumericUpDown->Value));

        RandomlyMovingSimulatable<Phone^>^ randomlyMovingPhone = gcnew RandomlyMovingSimulatable<Phone^>(phone);

        _simulationEngine->Add(randomlyMovingPhone);

        PhoneForm^ phoneForm = gcnew PhoneForm(phone, true);

        SimulatableToFormLifecycleBinder<ITimeAwareSimulatable^>::Bind(_simulationEngine, randomlyMovingPhone,
                                                                       phoneForm);

        VisualizationRegistryObjectToFormLifecycleBinder<Phone^>::Bind(_phoneVisualizationRegistry, phone, phoneForm);

        phoneForm->Show();
    }

    void FreeControlPanelForm::CreatePhoneWithBlacklistButton_Click(Object^ sender, EventArgs^ e)
    {
        PhoneWithBlacklist^ phone = gcnew PhoneWithBlacklist(PhoneNumberTextBox->Text, Coordinates(
                                                                 safe_cast<double>(PhoneLatitudeNumericUpDown->Value),
                                                                 safe_cast<double>(PhoneLongitudeNumericUpDown->Value)),
                                                             safe_cast<double>(PhoneBatteryLevelNumericUpDown->Value));

        RandomlyMovingSimulatable<Phone^>^ randomlyMovingPhone = gcnew RandomlyMovingSimulatable<Phone^>(phone);

        _simulationEngine->Add(randomlyMovingPhone);

        PhoneForm^ phoneForm = gcnew PhoneForm(phone, true);
        PhoneBlacklistForm^ blacklistForm = gcnew PhoneBlacklistForm(phone);

        SimulatableToFormLifecycleBinder<ITimeAwareSimulatable^>::Bind(_simulationEngine, randomlyMovingPhone,
                                                                       phoneForm);

        VisualizationRegistryObjectToFormLifecycleBinder<Phone^>::Bind(_phoneVisualizationRegistry, phone, phoneForm);

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
