#include "pch.h"

#include "CallAnsweredEventArgs.h"

namespace TelecommsSimulation::Core
{
    CallAnswer CallAnsweredEventArgs::Answer::get()
    {
        return _answer;
    }

    void CallAnsweredEventArgs::Answer::set(CallAnswer value)
    {
        _answer = value;
    }

    System::String^ CallAnsweredEventArgs::To::get()
    {
        return _to;
    }

    void CallAnsweredEventArgs::To::set(System::String^ value)
    {
        _to = value;
    }

    System::String^ CallAnsweredEventArgs::From::get()
    {
        return _from;
    }

    void CallAnsweredEventArgs::From::set(System::String^ value)
    {
        _from = value;
    }

    CallAnsweredEventArgs::CallAnsweredEventArgs(CallAnswer answer, System::String^ to, System::String^ from)
    {
        Answer = answer;
        To = to;
        From = from;
    }
}
