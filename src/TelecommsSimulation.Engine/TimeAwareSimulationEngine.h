#pragma once

#include "ISimulationEngine.h"
#include "ITimeAwareSimulatable.h"

namespace TelecommsSimulation::Engine
{
    generic<typename T> where T : ITimeAwareSimulatable
    public ref class TimeAwareSimulationEngine : public ISimulationEngine<T>
    {
        double _speed = 1;
        bool _isRunning;
        initonly Utilities::ConcurrentHashSet<T>^ _simulatedEntities = gcnew Utilities::ConcurrentHashSet<T>();
        unsigned long long _currentTick;

    protected:
        initonly System::Timers::Timer^ Timer;

    public:
        static initonly double BaseTickIntervalMilliseconds = 100;

        property double Speed
        {
            double get();
            void set(double value);
        }

        // Workaround for TrackBar
        property int SpeedPercentage
        {
            int get();
            void set(int value);
        }

        property double TickIntervalMilliseconds
        {
            double get();
        }

        property System::TimeSpan TickInterval
        {
            System::TimeSpan get();
        }

        property unsigned long long CurrentTick
        {
            unsigned long long get();
        private:
            void set(unsigned long long value);
        }

        // Workaround: C++/CLI does not support System.Collections.Immutable even from C# NuGet reference (because it does not support NuGet altogether)
        property System::Collections::Generic::IEnumerable<T>^ SimulatedEntities
        {
            virtual System::Collections::Generic::IEnumerable<T>^ get();
        }

        property bool IsRunning
        {
            virtual bool get();
        private:
            void set(bool value);
        }

        virtual event System::ComponentModel::PropertyChangedEventHandler^ PropertyChanged;

        TimeAwareSimulationEngine();

        virtual void Start();
        virtual void Stop();
        virtual void Add(T simulatable);
        virtual void Remove(T simulatable);

    protected:
        virtual void OnPropertyChanged(System::String^ propertyName);

        virtual void OnTimeTick(Object^ sender, System::Timers::ElapsedEventArgs^ e);

        generic<typename TValue>
        bool SetField(TValue% field, TValue value, System::String^ propertyName);
    };
}
