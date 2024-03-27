#include "pch.h"

#include "SimulatableToFormLifecycleBinder.h"

using namespace System;
using namespace System::Windows::Forms;

using namespace TelecommsSimulation::Core;
using namespace TelecommsSimulation::Engine;

namespace TelecommsSimulation
{
    generic<typename T>
    SimulatableToFormLifecycleBinder<T>^ SimulatableToFormLifecycleBinder<T>::Bind(
        ISimulationEngine<T>^ simulationEngine, T simulatable,
        Form^ form)
    {
        // Creates an SimulatableToFormLifecycleBinder to manage ISimulatable addition to simulation engine and removal from it based on form's lifecycle.
        // The binder attaches itself to the form's events and does not need to be stored, but it is returned just in case.
        return gcnew SimulatableToFormLifecycleBinder(simulationEngine, simulatable, form);
    }

    generic<typename T>
    SimulatableToFormLifecycleBinder<T>::SimulatableToFormLifecycleBinder(
        ISimulationEngine<T>^ simulationEngine, T simulatable, Form^ form)
    {
        _simulationEngine = simulationEngine;
        _simulatable = simulatable;
        _form = form;

        _form->Shown += gcnew EventHandler(this, &SimulatableToFormLifecycleBinder::FormShown);
        _form->FormClosed += gcnew FormClosedEventHandler(this, &SimulatableToFormLifecycleBinder::FormClosed);
    }

    generic<typename T>
    void SimulatableToFormLifecycleBinder<T>::FormShown(Object^ sender, EventArgs^ e)
    {
        _simulationEngine->Add(_simulatable);
    }

    generic<typename T>
    void SimulatableToFormLifecycleBinder<T>::FormClosed(Object^ sender, FormClosedEventArgs^ e)
    {
        _simulationEngine->Remove(_simulatable);
    }
}
