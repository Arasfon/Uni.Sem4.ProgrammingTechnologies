#include "pch.h"

#include "PhoneWithBlacklist.h"

#include "BaseStation.h"
#include "InvalidCallStateException.h"
#include "InvalidPhoneStateException.h"

using namespace System;
using namespace System::Threading::Tasks;

using namespace TelecommsSimulation::Utilities;

namespace TelecommsSimulation::Core
{
    ConcurrentHashSet<String^>^ PhoneWithBlacklist::Blacklist::get()
    {
        return _blacklist;
    }

    void PhoneWithBlacklist::Blacklist::set(ConcurrentHashSet<String^>^ value)
    {
        SetField<ConcurrentHashSet<String^>^>(_blacklist, value, "Blacklist");
    }

    PhoneWithBlacklist::PhoneWithBlacklist(String^ number, Coordinates location) : PhoneWithBlacklist(
        number, location, 100) {}

    PhoneWithBlacklist::PhoneWithBlacklist(String^ number, Coordinates location, double batteryLevel) : Phone(
        number, location, batteryLevel)
    {
        Blacklist = gcnew ConcurrentHashSet<String^>();
    }

    PhoneWithBlacklist::PhoneWithBlacklist(String^ number, Coordinates location,
                                           ConcurrentHashSet<String^>^ blacklist) :
        PhoneWithBlacklist(
            number, location, blacklist, 100) {}

    PhoneWithBlacklist::PhoneWithBlacklist(String^ number, Coordinates location,
                                           ConcurrentHashSet<String^>^ blacklist,
                                           double batteryLevel) : Phone(number, location, batteryLevel)
    {
        Blacklist = blacklist;
    }

    Task<CallAnswer>^ PhoneWithBlacklist::ReceiveCall(String^ from)
    {
        if (State != PhoneState::Connected)
            throw gcnew InvalidPhoneStateException();

        if (CallState != Core::CallState::Idle)
            throw gcnew InvalidCallStateException();

        if (Blacklist->Contains(from))
        {
            CallAnswered(this, gcnew CallAnsweredEventArgs(CallAnswer::Declined, Number, from));
            return Task::FromResult(CallAnswer::Declined);
        }

        return Phone::ReceiveCall(from);
    }
}
