#pragma once

namespace TelecommsSimulation::Core
{
    public ref class CallEventArgs : public System::EventArgs
    {
        System::String^ _callerNumber;
        System::String^ _receiverNumber;

    public:
        property System::String^ CallerNumber
        {
            System::String^ get();
        protected:
            initonly void set(System::String^ value);
        }

        property System::String^ ReceiverNumber
        {
            System::String^ get();
        protected:
            initonly void set(System::String^ value);
        }

        CallEventArgs(System::String^ callerNumber, System::String^ receiverNumber);
    };
}
