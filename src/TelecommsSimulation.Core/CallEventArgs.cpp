#include "pch.h"

#include "CallEventArgs.h"

namespace TelecommsSimulation::Core
{
    System::String^ CallEventArgs::CallerNumber::get()
    {
        return _callerNumber;
    }

    void CallEventArgs::CallerNumber::set(System::String^ value)
    {
        _callerNumber = value;
    }

    System::String^ CallEventArgs::ReceiverNumber::get()
    {
        return _receiverNumber;
    }

    void CallEventArgs::ReceiverNumber::set(System::String^ value)
    {
        _receiverNumber = value;
    }

    CallEventArgs::CallEventArgs(System::String^ callerNumber, System::String^ receiverNumber)
    {
        CallerNumber = callerNumber;
        ReceiverNumber = receiverNumber;
    }
}
