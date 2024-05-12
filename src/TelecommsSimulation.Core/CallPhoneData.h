#pragma once

#include "Phone.h"

namespace TelecommsSimulation::Core
{
    public ref class CallPhoneData
    {
        Phone^ _caller;
        Phone^ _receiver;

    public:
        property Phone^ Caller
        {
            Phone^ get();
        protected:
            initonly void set(Phone^ value);
        }

        property Phone^ Receiver
        {
            Phone^ get();
        protected:
            initonly void set(Phone^ value);
        }

        CallPhoneData(Phone^ caller, Phone^ receiver);
    };
}
