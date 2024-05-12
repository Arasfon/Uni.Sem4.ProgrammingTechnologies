#include "pch.h"

#include "CallPhoneData.h"

namespace TelecommsSimulation::Core
{
    Phone^ CallPhoneData::Caller::get()
    {
        return _caller;
    }

    void CallPhoneData::Caller::set(Phone^ value)
    {
        _caller = value;
    }

    Phone^ CallPhoneData::Receiver::get()
    {
        return _receiver;
    }

    void CallPhoneData::Receiver::set(Phone^ value)
    {
        _receiver = value;
    }

    CallPhoneData::CallPhoneData(Phone^ caller, Phone^ receiver)
    {
        Caller = caller;
        Receiver = receiver;
    }
}
