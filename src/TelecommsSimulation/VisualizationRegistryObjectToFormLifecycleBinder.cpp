#include "pch.h"

#include "VisualizationRegistryObjectToFormLifecycleBinder.h"

using namespace System;
using namespace System::Windows::Forms;

namespace TelecommsSimulation
{
    generic<typename T>
    VisualizationRegistryObjectToFormLifecycleBinder<T>^ VisualizationRegistryObjectToFormLifecycleBinder<T>::Bind(
        IVisualizationRegistry<T>^ visualizationRegistry, T obj, Form^ form)
    {
        // Creates an VisualizationRegistryObjectToFormLifecycleBinder to manage T's addition to visualization registry and removal from it based on form's lifecycle.
        // The binder attaches itself to the form's events and does not need to be stored, but it is returned just in case.
        return gcnew VisualizationRegistryObjectToFormLifecycleBinder(visualizationRegistry, obj, form);
    }

    generic<typename T>
    VisualizationRegistryObjectToFormLifecycleBinder<T>::VisualizationRegistryObjectToFormLifecycleBinder(
        IVisualizationRegistry<T>^ visualizationRegistry, T obj, Form^ form)
    {
        _visualizationRegistry = visualizationRegistry;
        _object = obj;
        _form = form;

        _form->Shown += gcnew EventHandler(this, &VisualizationRegistryObjectToFormLifecycleBinder::FormShown);
        _form->FormClosed += gcnew FormClosedEventHandler(this, &VisualizationRegistryObjectToFormLifecycleBinder::FormClosed);
    }

    generic<typename T>
    void VisualizationRegistryObjectToFormLifecycleBinder<T>::FormShown(Object^ sender, EventArgs^ e)
    {
        _visualizationRegistry->TryAdd(_object);
    }

    generic<typename T>
    void VisualizationRegistryObjectToFormLifecycleBinder<T>::FormClosed(Object^ sender, FormClosedEventArgs^ e)
    {
        _visualizationRegistry->TryRemove(_object);
    }
}
