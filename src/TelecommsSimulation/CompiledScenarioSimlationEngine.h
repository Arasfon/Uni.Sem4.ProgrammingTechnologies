#pragma once

#include "PhoneForm.h"
#include "PhoneBlacklistForm.h"
#include "BaseStationForm.h"

namespace TelecommsSimulation
{
    public ref class
        CompiledScenarioSimulationEngine : public Engine::TimeAwareSimulationEngine<Engine::ITimeAwareSimulatable^>
    {
        Core::Phone^ _phone1;
        Core::Phone^ _phone2;
        Core::PhoneWithBlacklist^ _phoneWithBlacklist;

        Core::BaseStation^ _baseStation1;
        Core::BaseStation^ _baseStation2;

        PhoneForm^ _phone1Form;
        PhoneForm^ _phone2Form;
        PhoneForm^ _phoneWithBlacklistForm;
        PhoneBlacklistForm^ _phoneWithBlacklistBlacklistForm;
        BaseStationForm^ _baseStation1Form;
        BaseStationForm^ _baseStation2Form;

        initonly Threading::SynchronizationContext^ UiSynchronizationContext;

    public:
        CompiledScenarioSimulationEngine();

        void OnTimeTick(Object^ sender, Timers::ElapsedEventArgs^ e) override;

        Threading::Tasks::Task^ CallReceived(Object^ sender, Core::CallEventArgs^ e);

    protected:
        void OnPropertyChanged(String^ propertyName) override;
        void OnPropertyChangedInvoke(Object^ propertyName);
    };
}
