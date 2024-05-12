#pragma once

#include "Phone.h"
#include "CallEventArgs.h"
#include "CallPhoneData.h"
#include "ILocatable.h"
#include "CallResult.h"

namespace TelecommsSimulation::Core
{
    value struct CallInitiationContinuationContext sealed
    {
        System::String^ To;
        Phone^ Caller;
        CallPhoneData^ CallData;

        CallInitiationContinuationContext(System::String^ to, Phone^ caller, CallPhoneData^ callData)
        {
            To = to;
            Caller = caller;
            CallData = callData;
        }
    };

    public ref class BaseStation : public ILocatable, public System::ComponentModel::INotifyPropertyChanged
    {
        System::String^ _name;
        bool _isEnabled;
        Coordinates _location;
        double _coverageRadiusKm;

    protected:
        initonly System::Collections::Concurrent::ConcurrentDictionary<System::String^, Phone^>^ ConnectedPhonesMap =
            gcnew System::Collections::Concurrent::ConcurrentDictionary<System::String^, Phone^>();

    public:
        // Workaround: C++/CLI does not support System.Collections.Immutable even from C# NuGet reference (because it does not support NuGet altogether)
        // Hack: Also should be private, but it's public for the sake of connection visualization
        property System::Collections::Generic::IEnumerable<Phone^>^ ConnectedPhones
        {
            System::Collections::Generic::IEnumerable<Phone^>^ get();
        }

    protected:
        static initonly System::Collections::Concurrent::ConcurrentDictionary<System::String^, CallPhoneData^>^
            CallDataLookupDictionary = gcnew System::Collections::Concurrent::ConcurrentDictionary<
                System::String^, CallPhoneData^>();

    public:
        // Workaround: C++/CLI does not support System.Collections.Immutable even from C# NuGet reference (because it does not support NuGet altogether)
        // Hack: Also should not exist at all, but exists for the sake of calls visualization
        static property System::Collections::Generic::IEnumerable<CallPhoneData^>^ CurrentCalls
        {
            System::Collections::Generic::IEnumerable<CallPhoneData^>^ get();
        }

        property System::String^ Name
        {
            System::String^ get();
        protected:
            initonly void set(System::String^ value);
        }

        property bool IsEnabled
        {
            bool get();
        protected:
            initonly void set(bool value);
        }

        property Coordinates Location
        {
            virtual Coordinates get();
        protected:
            initonly void set(Coordinates value);
        }

        property double CoverageRadiusKm
        {
            double get();
        protected:
            initonly void set(double value);
        }

        property int ConnectedPhonesCount
        {
            int get();
        }

    protected:
        static initonly System::Collections::Generic::List<BaseStation^>^ AllEnabledStationsList = gcnew
            System::Collections::Generic::List<BaseStation^>();

    public:
        // Workaround: C++/CLI does not support System.Collections.Immutable even from C# NuGet reference (because it does not support NuGet altogether)
        static property System::Collections::Generic::IEnumerable<BaseStation^>^ AllEnabledStations
        {
            System::Collections::Generic::IEnumerable<BaseStation^>^ get();
        }

    protected:
        initonly System::Threading::SynchronizationContext^ UiSynchronizationContext;

    public:
        BaseStation(System::String^ name, Coordinates location, double coverageRadiusKm);

        virtual void Enable();
        virtual void Disable();
        virtual void RegisterPhone(Phone^ phone);
        virtual void UnregisterPhone(Phone^ phone);
        virtual System::Threading::Tasks::Task<CallResult>^ InitiateCall(Phone^ caller, System::String^ to);
        // Workaround: C++/CLI does not support async/await
        CallResult InitiateCallContinuation(System::Threading::Tasks::Task<CallAnswer>^ continuedTask, Object^ continuationContext);

    protected:
        void CallEnded(Object^ sender, CallEventArgs^ e);
        static Phone^ FindPhone(System::String^ number);

    public:
        virtual event System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

    protected:
        virtual void OnPropertyChanged(System::String^ propertyName);
        // Workaround: C++/CLI does not support lambda-functions
        void OnPropertyChangedInvoke(Object^ propertyName);

        generic<typename T>
        bool SetField(T% field, T value, System::String^ propertyName);
    };
}
