#pragma once

#include "Phone.h"

namespace TelecommsSimulation::Core
{
    public ref class PhoneWithBlacklist : public Phone
    {
        Utilities::ConcurrentHashSet<System::String^>^ _blacklist;

    public:
        property Utilities::ConcurrentHashSet<System::String^>^ Blacklist
        {
            Utilities::ConcurrentHashSet<System::String^>^ get();
        protected:
            initonly void set(Utilities::ConcurrentHashSet<System::String^>^ value);
        }

        PhoneWithBlacklist(System::String^ number, Coordinates location);
        PhoneWithBlacklist(System::String^ number, Coordinates location, double batteryLevel);

        PhoneWithBlacklist(System::String^ number, Coordinates location,
                           Utilities::ConcurrentHashSet<System::String^>^ blacklist);
        PhoneWithBlacklist(System::String^ number, Coordinates location,
                           Utilities::ConcurrentHashSet<System::String^>^ blacklist, double batteryLevel);

        System::Threading::Tasks::Task<CallAnswer>^ ReceiveCall(System::String^ from) override;
    };
}
