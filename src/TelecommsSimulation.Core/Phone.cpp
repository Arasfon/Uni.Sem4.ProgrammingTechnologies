#include "pch.h"

#include "Phone.h"

#include "BaseStation.h"
#include "InvalidCallStateException.h"
#include "InvalidPhoneStateException.h"
#include "LinqExtensions.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;
using namespace System::Linq;
using namespace System::Threading;
using namespace System::Threading::Tasks;

using namespace TelecommsSimulation::Utilities;

namespace TelecommsSimulation::Core
{
    String^ Phone::Number::get()
    {
        return _number;
    }

    void Phone::Number::set(String^ value)
    {
        SetField<String^>(_number, value, "Number");
    }

    Coordinates Phone::Location::get()
    {
        return _location;
    }

    void Phone::Location::set(Coordinates value)
    {
        SetField<Coordinates>(_location, value, "Location");
        SwitchBaseStationIfNeeded();
    }

    PhoneState Phone::State::get()
    {
        return _state;
    }

    void Phone::State::set(PhoneState value)
    {
        SetField<PhoneState>(_state, value, "State");
    }

    CallState Phone::CallState::get()
    {
        return _callState;
    }

    void Phone::CallState::set(Core::CallState value)
    {
        SetField<Core::CallState>(_callState, value, "CallState");
    }

    String^ Phone::InCallWith::get()
    {
        return _inCallWith;
    }

    void Phone::InCallWith::set(String^ value)
    {
        SetField<String^>(_inCallWith, value, "InCallWith");
    }

    double Phone::BatteryLevel::get()
    {
        return _batteryLevel;
    }

    void Phone::BatteryLevel::set(double value)
    {
        SetField<double>(_batteryLevel, MathExtensions::Clamp(value, 0, 100), "BatteryLevel");
    }

    String^ Phone::ConnectedBaseStationName::get()
    {
        return ConnectedBaseStation->Name;
    }

    Phone::Phone(String^ number, Coordinates location) : Phone(number, location, 100) {}

    Phone::Phone(String^ number, Coordinates location, double batteryLevel)
    {
        UiSynchronizationContext = SynchronizationContext::Current;

        Number = number;
        Location = location;
        BatteryLevel = batteryLevel;
    }

    void Phone::TurnOn()
    {
        if (State != PhoneState::Off)
            throw gcnew InvalidPhoneStateException();

        if (BatteryLevel == 0)
            return;

        State = PhoneState::Disconnected;
    }

    void Phone::TurnOff()
    {
        if (State == PhoneState::Off)
            throw gcnew InvalidPhoneStateException();

        if (State == PhoneState::Connected)
            DisconnectFromBaseStation();

        State = PhoneState::Off;
    }

    void Phone::ConnectToBaseStation()
    {
        switch (State)
        {
            case PhoneState::Off:
                {
                    throw gcnew InvalidPhoneStateException();
                }
            case PhoneState::Connected:
                {
                    DisconnectFromBaseStation();
                    break;
                }
            default:
                break;
        }

        BaseStation^ nearestStation = FindBaseStation();

        if (nearestStation == nullptr)
            return;

        nearestStation->RegisterPhone(this);
        ConnectedBaseStation = nearestStation;
        OnPropertyChanged("ConnectedBaseStationName");

        State = PhoneState::Connected;
        Connected(this, EventArgs::Empty);
    }

    void Phone::DisconnectFromBaseStation()
    {
        if (State != PhoneState::Connected)
            throw gcnew InvalidPhoneStateException();

        if (CallState != Core::CallState::Idle)
            EndCall();

        ConnectedBaseStation->UnregisterPhone(this);
        ConnectedBaseStation = nullptr;
        OnPropertyChanged("ConnectedBaseStationName");

        State = PhoneState::Disconnected;
        Disconnected(this, EventArgs::Empty);
    }

    void Phone::SwitchBaseStationIfNeeded()
    {
        if (State != PhoneState::Connected)
            return;

        if (ConnectedBaseStation->IsEnabled && IsCoveredBy(ConnectedBaseStation))
            return;

        BaseStation^ nearestStation = FindBaseStation();

        if (nearestStation == nullptr)
        {
            DisconnectFromBaseStation();
            return;
        }

        ConnectedBaseStation->UnregisterPhone(this);

        nearestStation->RegisterPhone(this);

        ConnectedBaseStation = nearestStation;
        OnPropertyChanged("ConnectedBaseStationName");
    }

    Task<CallResult>^ Phone::MakeCall(String^ to)
    {
        if (State != PhoneState::Connected)
            throw gcnew InvalidPhoneStateException();

        if (CallState != Core::CallState::Idle)
            throw gcnew InvalidCallStateException();

        InCallWith = to;
        CallState = Core::CallState::Dialing;

        return ConnectedBaseStation->InitiateCall(this, to)->ContinueWith(
            gcnew Func<Task<CallResult>^, CallResult>(this, &Phone::MakeCallContinuation),
            TaskContinuationOptions::RunContinuationsAsynchronously);
    }

    CallResult Phone::MakeCallContinuation(Task<CallResult>^ task)
    {
        const CallResult result = task->Result;

        if (result != CallResult::Established)
        {
            InCallWith = nullptr;
            CallState = Core::CallState::Idle;

            return result;
        }

        CallState = Core::CallState::InCall;

        return result;
    }

    Task<CallAnswer>^ Phone::ReceiveCall(String^ from)
    {
        if (State != PhoneState::Connected)
            throw gcnew InvalidPhoneStateException();

        if (CallState != Core::CallState::Idle)
            throw gcnew InvalidCallStateException();

        InCallWith = from;
        CallState = Core::CallState::AwaitingAnswer;

        TaskCompletionSource<CallAnswer>^ callAnswerCompletionSource = CallAnswerCompletionSource =
            gcnew TaskCompletionSource<CallAnswer>(TaskCreationOptions::RunContinuationsAsynchronously);

        CallReceived(this, gcnew CallEventArgs(from, Number));

        return callAnswerCompletionSource->Task;
    }

    void Phone::AnswerCall(CallAnswer answer)
    {
        if (State != PhoneState::Connected)
            throw gcnew InvalidPhoneStateException();

        if (CallState != Core::CallState::AwaitingAnswer)
            throw gcnew InvalidCallStateException();

        CallAnswerCompletionSource->SetResult(answer);
        CallAnswerCompletionSource = nullptr;

        if (answer == CallAnswer::Agreed)
        {
            CallState = Core::CallState::InCall;
            return;
        }

        CallState = Core::CallState::Idle;
        InCallWith = nullptr;
    }

    void Phone::EndCall()
    {
        if (State != PhoneState::Connected)
            throw gcnew InvalidPhoneStateException();

        if (CallState == Core::CallState::Idle)
            throw gcnew InvalidCallStateException();

        if (CallAnswerCompletionSource != nullptr)
            CallAnswerCompletionSource->SetCanceled();
        CallAnswerCompletionSource = nullptr;

        CallEnded(this, gcnew CallEventArgs(Number, InCallWith));

        InCallWith = nullptr;
        CallState = Core::CallState::Idle;
    }

    BaseStation^ Phone::FindBaseStation()
    {
        return LinqExtensions::MinBy(
            Enumerable::Where(
                BaseStation::AllEnabledStations,
                gcnew Func<BaseStation^, bool>(this, &Phone::IsCoveredBy)),
            gcnew Func<BaseStation^, double>(this, &Phone::FindBaseStationMinByLambda));
    }

    double Phone::FindBaseStationMinByLambda(BaseStation^ x)
    {
        return x->Location.CalculateKmDistanceTo(Location);
    }

    bool Phone::IsCoveredBy(BaseStation^ baseStation)
    {
        return baseStation->Location.CalculateKmDistanceTo(Location) <= baseStation->CoverageRadiusKm;
    }

    void Phone::OnPropertyChanged(String^ propertyName)
    {
        // Workaround: WinForms' lack of threading awareness and the challenge of re-invoking handlers in C++/CLI
        if (UiSynchronizationContext != nullptr)
        {
            UiSynchronizationContext->Post(
                gcnew SendOrPostCallback(this, &Phone::OnPropertyChangedInvoke),
                propertyName);
        }
        else
        {
            PropertyChanged(this, gcnew PropertyChangedEventArgs(propertyName));
        }
    }

    void Phone::OnPropertyChangedInvoke(Object^ propertyName)
    {
        Phone::OnPropertyChanged(safe_cast<String^>(propertyName));
    }

    generic<typename T>
    bool Phone::SetField(T% field, T value, String^ propertyName)
    {
        if (EqualityComparer<T>::Default->Equals(field, value))
            return false;

        field = value;
        OnPropertyChanged(propertyName);
        return true;
    }
}
