#include "pch.h"

#include "BaseStation.h"

#include "InvalidBaseStationStateException.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::ComponentModel;
using namespace System::Diagnostics;
using namespace System::Linq;
using namespace System::Threading;
using namespace System::Threading::Tasks;

using namespace TelecommsSimulation::Utilities;

namespace TelecommsSimulation::Core
{
    IEnumerable<Phone^>^ BaseStation::ConnectedPhones::get()
    {
        return ConnectedPhonesMap->Values;
    }

    IEnumerable<CallPhoneData^>^ BaseStation::CurrentCalls::get()
    {
        return Enumerable::Distinct<CallPhoneData^>(CallDataLookupDictionary->Values);
    }

    String^ BaseStation::Name::get()
    {
        return _name;
    }

    void BaseStation::Name::set(String^ value)
    {
        SetField<String^>(_name, value, "Name");
    }

    bool BaseStation::IsEnabled::get()
    {
        return _isEnabled;
    }

    void BaseStation::IsEnabled::set(bool value)
    {
        SetField<bool>(_isEnabled, value, "IsEnabled");
    }

    Coordinates BaseStation::Location::get()
    {
        return _location;
    }

    void BaseStation::Location::set(Coordinates value)
    {
        SetField<Coordinates>(_location, value, "Location");
    }

    double BaseStation::CoverageRadiusKm::get()
    {
        return _coverageRadiusKm;
    }

    void BaseStation::CoverageRadiusKm::set(double value)
    {
        SetField<double>(_coverageRadiusKm, value, "CoverageRadiusKm");
    }

    int BaseStation::ConnectedPhonesCount::get()
    {
        return ConnectedPhonesMap->Count;
    }

    IEnumerable<BaseStation^>^ BaseStation::AllEnabledStations::get()
    {
        return AllEnabledStationsList;
    }

    BaseStation::BaseStation(String^ name, Coordinates location, double coverageRadiusKm)
    {
        UiSynchronizationContext = SynchronizationContext::Current;

        Name = name;
        Location = location;
        CoverageRadiusKm = coverageRadiusKm;
    }

    void BaseStation::Enable()
    {
        if (IsEnabled)
            throw gcnew InvalidBaseStationStateException();

        IsEnabled = true;
        AllEnabledStationsList->Add(this);
    }

    void BaseStation::Disable()
    {
        if (!IsEnabled)
            throw gcnew InvalidBaseStationStateException();

        AllEnabledStationsList->Remove(this);

        for each (KeyValuePair<String^, Phone^>^ connectedPhonePair in ConnectedPhonesMap)
            connectedPhonePair->Value->SwitchBaseStationIfNeeded();

        IsEnabled = false;
    }

    void BaseStation::RegisterPhone(Phone^ phone)
    {
        if (FindPhone(phone->Number) != nullptr)
            throw gcnew Exception("This number is already connected");

        if (!ConnectedPhonesMap->TryAdd(phone->Number, phone))
            throw gcnew Exception("This number is already connected");

        OnPropertyChanged("ConnectedPhonesCount");
        OnPropertyChanged("ConnectedPhones");

        phone->CallEnded += gcnew EventHandler<CallEventArgs^>(this, &BaseStation::CallEnded);
    }

    void BaseStation::UnregisterPhone(Phone^ phone)
    {
        Phone^ discard;
        CollectionExtensions::Remove(ConnectedPhonesMap, phone->Number, discard);

        OnPropertyChanged("ConnectedPhonesCount");
        OnPropertyChanged("ConnectedPhones");

        phone->CallEnded -= gcnew EventHandler<CallEventArgs^>(this, &BaseStation::CallEnded);
    }

    Task<CallResult>^ BaseStation::InitiateCall(Phone^ caller, String^ to)
    {
        Phone^ receiverPhone = FindPhone(to);
        if (receiverPhone == nullptr)
            return Task::FromResult(CallResult::NotFound);

        if (receiverPhone->CallState != CallState::Idle)
            return Task::FromResult(CallResult::Busy);

        CallPhoneData^ callPhoneData = gcnew CallPhoneData(caller, receiverPhone);
        if (!CallDataLookupDictionary->TryAdd(to, callPhoneData))
            return Task::FromResult(CallResult::Busy);

        bool callerAdded = CallDataLookupDictionary->TryAdd(caller->Number, callPhoneData);
        Debug::Assert(callerAdded);

        Task<CallAnswer>^ receiveCallTask = receiverPhone->ReceiveCall(caller->Number);
        return receiveCallTask->ContinueWith<CallResult>(
            gcnew Func<Task<CallAnswer>^, Object^, CallResult>(this, &BaseStation::InitiateCallContinuation),
            CallInitiationContinuationContext(to, caller, callPhoneData),
            TaskContinuationOptions::RunContinuationsAsynchronously);
    }

    CallResult BaseStation::InitiateCallContinuation(Task<CallAnswer>^ continuedTask, Object^ continuationContext)
    {
        CallInitiationContinuationContext context = safe_cast<CallInitiationContinuationContext>(continuationContext);

        CallPhoneData^ discard;

        if (continuedTask->IsCanceled || continuedTask->IsFaulted)
        {
            CallDataLookupDictionary->TryRemove(context.Caller->Number, discard);
            CallDataLookupDictionary->TryRemove(context.To, discard);
            return CallResult::Busy;
        }

        switch (continuedTask->Result)
        {
            case CallAnswer::Agreed:
                {
                    return CallResult::Established;
                }
            case CallAnswer::Declined:
                {
                    CallDataLookupDictionary->TryRemove(context.Caller->Number, discard);
                    CallDataLookupDictionary->TryRemove(context.To, discard);
                    return CallResult::Busy;
                }
            default:
                {
                    CallDataLookupDictionary->TryRemove(context.Caller->Number, discard);
                    CallDataLookupDictionary->TryRemove(context.To, discard);
                    throw gcnew ArgumentOutOfRangeException(nullptr, "Call answer was out of range");
                }
        }
    }

    void BaseStation::CallEnded(Object^ sender, CallEventArgs^ e)
    {
        CallPhoneData^ callData;

        if (!CollectionExtensions::Remove(CallDataLookupDictionary, e->CallerNumber, callData))
            return;

        Debug::Assert(callData != nullptr);

        const bool receiverRemoved =
            CollectionExtensions::Remove(CallDataLookupDictionary, e->ReceiverNumber, callData);

        Debug::Assert(receiverRemoved);

        callData->Caller->EndCall();
        callData->Receiver->EndCall();
    }

    Phone^ BaseStation::FindPhone(String^ number)
    {
        Phone^ phone = nullptr;
        for each (BaseStation^ baseStation in AllEnabledStations)
        {
            if (baseStation->ConnectedPhonesMap->TryGetValue(number, phone))
                break;
        }

        return phone;
    }

    void BaseStation::OnPropertyChanged(String^ propertyName)
    {
        // Workaround: WinForms' lack of threading awareness and the challenge of re-invoking handlers in C++/CLI
        if (UiSynchronizationContext != nullptr)
        {
            UiSynchronizationContext->Post(
                gcnew SendOrPostCallback(this, &BaseStation::OnPropertyChangedInvoke),
                propertyName);
        }
        else
        {
            PropertyChanged(this, gcnew PropertyChangedEventArgs(propertyName));
        }
    }

    void BaseStation::OnPropertyChangedInvoke(Object^ propertyName)
    {
        PropertyChanged(this, gcnew PropertyChangedEventArgs(safe_cast<String^>(propertyName)));
    }

    generic<typename T>
    bool BaseStation::SetField(T% field, T value, String^ propertyName)
    {
        if (EqualityComparer<T>::Default->Equals(field, value))
            return false;

        field = value;
        OnPropertyChanged(propertyName);
        return true;
    }
}
