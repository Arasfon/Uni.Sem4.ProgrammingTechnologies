#pragma once

#include "CallAnswer.h"
#include "CallEventArgs.h"
#include "CallResult.h"
#include "CallState.h"
#include "ILocatableMovable.h"
#include "PhoneState.h"

namespace TelecommsSimulation::Core
{
    ref class BaseStation;

    public ref class Phone : public ILocatableMovable, public System::ComponentModel::INotifyPropertyChanged
    {
        System::String^ _number;
        Coordinates _location;
        PhoneState _state = PhoneState::Off;
        CallState _callState = Core::CallState::Idle;
        System::String^ _inCallWith;
        double _batteryLevel;

    public:
        property System::String^ Number
        {
            System::String^ get();
        protected:
            initonly void set(System::String^ value);
        }

        property Coordinates Location
        {
            virtual Coordinates get();
            virtual void set(Coordinates value);
        }

        property PhoneState State
        {
            PhoneState get();
        private:
            void set(PhoneState value);
        }

        property CallState CallState
        {
            Core::CallState get();
        private:
            void set(Core::CallState value);
        }

        property System::String^ InCallWith
        {
            System::String^ get();
        private:
            void set(System::String^ value);
        }

        property double BatteryLevel
        {
            double get();
        private:
            void set(double value);
        }

        property System::String^ ConnectedBaseStationName
        {
            System::String^ get();
        }

    protected:
        BaseStation^ ConnectedBaseStation;

        initonly System::Threading::SynchronizationContext^ UiSynchronizationContext;

        System::Threading::Tasks::TaskCompletionSource<CallAnswer>^ CallAnswerCompletionSource;

    public:
        event System::EventHandler^ Connected;
        event System::EventHandler^ Disconnected;
        event Utilities::AsyncEventHandler<CallEventArgs^>^ CallReceived;
        event System::EventHandler<CallEventArgs^>^ CallEnded;

        Phone(System::String^ number, Coordinates location);
        Phone(System::String^ number, Coordinates location, double batteryLevel);

        virtual void TurnOn();
        virtual void TurnOff();
        virtual void ConnectToBaseStation();
        virtual void DisconnectFromBaseStation();
        virtual void SwitchBaseStationIfNeeded();
        virtual System::Threading::Tasks::Task<CallResult>^ MakeCall(System::String^ to);
        // Workaround: C++/CLI does not support lambda-functions 
        CallResult MakeCallContinuation(System::Threading::Tasks::Task<CallResult>^ task);
        virtual System::Threading::Tasks::Task<CallAnswer>^ ReceiveCall(System::String^ from);
        virtual void AnswerCall(CallAnswer answer);
        virtual void EndCall();

    protected:
        virtual BaseStation^ FindBaseStation();
        // Workaround: C++/CLI does not support lambda-functions
        double FindBaseStationMinByLambda(BaseStation^ x);
        bool IsCoveredBy(BaseStation^ baseStation);

    public:
        virtual event System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

    protected:
        virtual void OnPropertyChanged(System::String^ propertyName);
        // Workaround: C++/CLI does not support lambda-functions
        void OnPropertyChangedInvoke(Object^ propertyName);

        generic<typename T>
        bool SetField(T% field, T value, System::String^ propertyName);
    };
}
