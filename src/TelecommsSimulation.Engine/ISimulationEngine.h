#pragma once

#include "ISimulatable.h"

namespace TelecommsSimulation::Engine
{
    generic<typename T> where T : ISimulatable
    public interface class ISimulationEngine : public System::ComponentModel::INotifyPropertyChanged
    {
        property System::Collections::Generic::IEnumerable<T>^ SimulatedEntities
        {
            System::Collections::Generic::IEnumerable<T>^ get();
        }

        property bool IsRunning
        {
            bool get();
        }

        void Start();
        void Stop();
        void Add(T simulatable);
        void Remove(T simulatable);
    };
}
