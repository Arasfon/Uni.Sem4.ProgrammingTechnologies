#include "pch.h"

#include "TimeAwareSimulationEngine.h"

using namespace System;
using namespace System::Collections::Generic;
using namespace System::Timers;
using namespace System::ComponentModel;

using namespace TelecommsSimulation::Utilities;

namespace TelecommsSimulation::Engine
{
    generic<typename T>
    double TimeAwareSimulationEngine<T>::Speed::get()
    {
        return _speed;
    }

    generic<typename T>
    void TimeAwareSimulationEngine<T>::Speed::set(double value)
    {
        value = MathExtensions::Clamp(value, 0.01, 2);

        SetField<double>(_speed, value, "Speed");
        OnPropertyChanged("TickIntervalMilliseconds");
        OnPropertyChanged("TickInterval");

        Timer->Interval = TickIntervalMilliseconds;
    }

    generic<typename T>
    int TimeAwareSimulationEngine<T>::SpeedPercentage::get()
    {
        return safe_cast<int>(Speed * 100);
    }

    generic<typename T>
    void TimeAwareSimulationEngine<T>::SpeedPercentage::set(int value)
    {
        Speed = value / 100.0;
    }

    generic<typename T>
    double TimeAwareSimulationEngine<T>::TickIntervalMilliseconds::get()
    {
        return BaseTickIntervalMilliseconds / Speed;
    }

    generic<typename T>
    TimeSpan TimeAwareSimulationEngine<T>::TickInterval::get()
    {
        return TimeSpan::FromMilliseconds(TickIntervalMilliseconds);
    }

    generic<typename T>
    unsigned long long TimeAwareSimulationEngine<T>::CurrentTick::get()
    {
        return _currentTick;
    }

    generic<typename T>
    void TimeAwareSimulationEngine<T>::CurrentTick::set(unsigned long long value)
    {
        SetField<unsigned long long>(_currentTick, value, "CurrentTick");
    }

    generic<typename T>
    IEnumerable<T>^ TimeAwareSimulationEngine<T>::SimulatedEntities::get()
    {
        return _simulatedEntities;
    }

    generic<typename T>
    bool TimeAwareSimulationEngine<T>::IsRunning::get()
    {
        return _isRunning;
    }

    generic<typename T>
    void TimeAwareSimulationEngine<T>::IsRunning::set(bool value)
    {
        SetField<bool>(_isRunning, value, "IsRunning");
    }

    generic<typename T>
    TimeAwareSimulationEngine<T>::TimeAwareSimulationEngine()
    {
        Timer = gcnew Timers::Timer(TickIntervalMilliseconds);
        Timer->Elapsed += gcnew ElapsedEventHandler(this, &TimeAwareSimulationEngine::OnTimeTick);
    }

    generic<typename T>
    void TimeAwareSimulationEngine<T>::Start()
    {
        if (IsRunning)
            throw gcnew InvalidOperationException();

        Timer->Start();

        IsRunning = true;
    }

    generic<typename T>
    void TimeAwareSimulationEngine<T>::Stop()
    {
        if (!IsRunning)
            throw gcnew InvalidOperationException();

        Timer->Stop();

        CurrentTick = 0;

        IsRunning = false;
    }

    generic<typename T>
    void TimeAwareSimulationEngine<T>::Add(T simulatable)
    {
        _simulatedEntities->TryAdd(simulatable);
    }

    generic<typename T>
    void TimeAwareSimulationEngine<T>::Remove(T simulatable)
    {
        _simulatedEntities->TryRemove(simulatable);
    }

    generic<typename T>
    void TimeAwareSimulationEngine<T>::OnTimeTick(Object^ sender, ElapsedEventArgs^ e)
    {
        if (!IsRunning)
            return;

        CurrentTick++;

        for each (T entity in _simulatedEntities)
            entity->ProcessTimeTick(CurrentTick);
    }

    generic<typename T>
    void TimeAwareSimulationEngine<T>::OnPropertyChanged(String^ propertyName)
    {
        PropertyChanged(this, gcnew PropertyChangedEventArgs(propertyName));
    }

    generic<typename T>
    generic<typename TValue>
    bool TimeAwareSimulationEngine<T>::SetField(TValue% field, TValue value, String^ propertyName)
    {
        if (EqualityComparer<T>::Default->Equals(field, value))
            return false;

        field = value;
        OnPropertyChanged(propertyName);
        return true;
    }
}
