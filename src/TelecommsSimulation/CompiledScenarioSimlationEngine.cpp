#include "pch.h"

#include "CompiledScenarioSimlationEngine.h"

#include "BaseStationForm.h"
#include "PhoneBlacklistForm.h"
#include "PhoneForm.h"
#include "SimulationVisualizationForm.h"
#include "VisualizationRegistry.h"

using namespace System::Timers;
using namespace System::Threading;
using namespace System::Threading::Tasks;

using namespace TelecommsSimulation::Core;
using namespace TelecommsSimulation::Engine;
using namespace TelecommsSimulation::Utilities;

namespace TelecommsSimulation
{
    CompiledScenarioSimulationEngine::CompiledScenarioSimulationEngine() : TimeAwareSimulationEngine()
    {
        UiSynchronizationContext = SynchronizationContext::Current;

        // ReSharper disable CppLocalVariableMightNotBeInitialized
        Timer->AutoReset = false;
        Speed = 0.02; // Once in 5 seconds
        // ReSharper restore CppLocalVariableMightNotBeInitialized

        _baseStation1 = gcnew BaseStation("Central", Coordinates(0, 0), 300);
        _baseStation2 = gcnew BaseStation("Outskirts", Coordinates(-2, -2), 400);

        _baseStation1Form = gcnew BaseStationForm(_baseStation1);
        _baseStation1Form->Show();
        _baseStation2Form = gcnew BaseStationForm(_baseStation2);
        _baseStation2Form->Show();

        _phone1 = gcnew Phone("+1", Coordinates(-1, 0), 100);
        _phone2 = gcnew Phone("+2", Coordinates(0, 1), 100);
        _phoneWithBlacklist = gcnew PhoneWithBlacklist("+3", Coordinates(-0.75, -0.75), 100);

        _phone1->CallReceived += gcnew AsyncEventHandler<CallEventArgs^>(
            this, &CompiledScenarioSimulationEngine::CallReceived);
        _phone2->CallReceived += gcnew AsyncEventHandler<CallEventArgs^>(
            this, &CompiledScenarioSimulationEngine::CallReceived);
        _phoneWithBlacklist->CallReceived += gcnew AsyncEventHandler<CallEventArgs^>(
            this, &CompiledScenarioSimulationEngine::CallReceived);

        _phone1Form = gcnew PhoneForm(_phone1, false);
        _phone1Form->Show();
        _phone2Form = gcnew PhoneForm(_phone2, false);
        _phone2Form->Show();
        _phoneWithBlacklistForm = gcnew PhoneForm(_phoneWithBlacklist, false);
        _phoneWithBlacklistForm->Show();
        _phoneWithBlacklistBlacklistForm = gcnew PhoneBlacklistForm(_phoneWithBlacklist);
        _phoneWithBlacklistBlacklistForm->Show();

        IVisualizationRegistry<BaseStation^>^ baseStationVisualizationRegistry = gcnew VisualizationRegistry<BaseStation
            ^>();
        baseStationVisualizationRegistry->TryAdd(_baseStation1);
        baseStationVisualizationRegistry->TryAdd(_baseStation2);

        IVisualizationRegistry<Phone^>^ phoneVisualizationRegistry = gcnew VisualizationRegistry<Phone^>();
        phoneVisualizationRegistry->TryAdd(_phone1);
        phoneVisualizationRegistry->TryAdd(_phone2);
        phoneVisualizationRegistry->TryAdd(_phoneWithBlacklist);

        _simulationVisualizationForm = gcnew SimulationVisualizationForm(
            baseStationVisualizationRegistry, phoneVisualizationRegistry);
        _simulationVisualizationForm->Show();
    }

    void CompiledScenarioSimulationEngine::OnTimeTick(Object^ sender, ElapsedEventArgs^ e)
    {
        if (!IsRunning)
            return;

        switch (CurrentTick)
        {
            case 0:
                {
                    _baseStation1->Enable();
                    _baseStation2->Enable();

                    _phone1->TurnOn();
                    _phone2->TurnOn();
                    _phoneWithBlacklist->TurnOn();

                    break;
                }
            case 1:
                {
                    _phone1->ConnectToBaseStation();
                    _phone2->ConnectToBaseStation();
                    _phoneWithBlacklist->ConnectToBaseStation();

                    break;
                }
            case 2:
                {
                    _phone1->MakeCall("+2");
                    _phoneWithBlacklist->MakeCall("+2");

                    break;
                }
            case 3:
                {
                    _phone1->Location = Coordinates(-2.20, -2.20);

                    break;
                }
            case 4:
                {
                    _phone2->EndCall();
                    _phoneWithBlacklist->Blacklist->TryAdd("+2");

                    break;
                }
            case 5:
                {
                    CallResult res = _phone2->MakeCall("+3")->GetAwaiter().GetResult();

                    MessageBox::Show("Результат вызова +2 → +3: " + res.ToString(), "Результат вызова +2 → +3");

                    break;
                }
            case 6:
                {
                    _phone1->MakeCall("+3");

                    break;
                }
            case 7:
                {
                    _phoneWithBlacklist->EndCall();
                    _phoneWithBlacklist->MakeCall("+2");

                    break;
                }
            case 8:
                {
                    _phoneWithBlacklist->Location = Coordinates(3, 3);

                    break;
                }
            case 9:
                {
                    _baseStation1->Disable();
                    _baseStation2->Disable();

                    _phone1->TurnOff();
                    _phone2->TurnOff();
                    _phoneWithBlacklist->TurnOff();

                    _phoneWithBlacklist->Blacklist->Clear();

                    _phone1->Location = Coordinates(-1, 0);
                    _phone2->Location = Coordinates(0, 1);
                    _phoneWithBlacklist->Location = Coordinates(-0.75, -0.75);

                    break;
                }
            case 10:
                {
                    Stop();

                    break;
                }
            default:
                break;
        }

        TimeAwareSimulationEngine::OnTimeTick(sender, e);

        Timer->Start();
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    Task^ CompiledScenarioSimulationEngine::CallReceived(Object^ sender, CallEventArgs^ e)
    {
        Phone^ phone = safe_cast<Phone^>(sender);

        phone->AnswerCall(CallAnswer::Agreed);

        return Task::CompletedTask;
    }

    void CompiledScenarioSimulationEngine::OnPropertyChanged(String^ propertyName)
    {
        // Workaround: WinForms' lack of threading awareness and the challenge of re-invoking handlers in C++/CLI
        if (UiSynchronizationContext != nullptr)
        {
            UiSynchronizationContext->Post(
                gcnew SendOrPostCallback(this, &CompiledScenarioSimulationEngine::OnPropertyChangedInvoke),
                propertyName);
        }
        else
        {
            OnPropertyChangedInvoke(propertyName);
        }
    }

    // Workaround: C++/CLI does not support lambda-functions
    void CompiledScenarioSimulationEngine::OnPropertyChangedInvoke(Object^ propertyName)
    {
        TimeAwareSimulationEngine<ITimeAwareSimulatable^>::OnPropertyChanged(safe_cast<String^>(propertyName));
    }

    CompiledScenarioSimulationEngine::~CompiledScenarioSimulationEngine()
    {
        if (IsRunning)
            Stop();

        _simulationVisualizationForm->Close();

        _phone1Form->Close();
        _phone2Form->Close();
        _phoneWithBlacklistBlacklistForm->Close();
        _phoneWithBlacklistForm->Close();

        _baseStation1Form->Close();
        _baseStation2Form->Close();
    }
}
