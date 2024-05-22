#pragma once

#include "CallAnswer.h"

namespace TelecommsSimulation::Core
{
    ref class CallAnsweredEventArgs : public System::EventArgs
    {
        CallAnswer _answer;
        System::String^ _to;
        System::String^ _from;

    public:
        property CallAnswer Answer
        {
            CallAnswer get();
            initonly void set(CallAnswer value);
        }

        property System::String^ To
        {
            System::String^ get();
        protected:
            initonly void set(System::String^ value);
        }

        property System::String^ From
        {
            System::String^ get();
        protected:
            initonly void set(System::String^ value);
        }

        CallAnsweredEventArgs(CallAnswer answer, System::String^ to, System::String^ from);
    };
}
