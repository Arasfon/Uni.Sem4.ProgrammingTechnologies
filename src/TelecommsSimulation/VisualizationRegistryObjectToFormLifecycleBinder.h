#pragma once

#include "IVisualizationRegistry.h"

namespace TelecommsSimulation
{
    generic<typename T>
    public ref class VisualizationRegistryObjectToFormLifecycleBinder
    {
        IVisualizationRegistry<T>^ _visualizationRegistry;
        T _object;
        System::Windows::Forms::Form^ _form;

    public:
        static VisualizationRegistryObjectToFormLifecycleBinder^ Bind(IVisualizationRegistry<T>^ visualizationRegistry, T obj,
            System::Windows::Forms::Form^ form);

    private:
        VisualizationRegistryObjectToFormLifecycleBinder(IVisualizationRegistry<T>^ visualizationRegistry, T obj,
            System::Windows::Forms::Form^ form);

        void FormShown(Object^ sender, System::EventArgs^ e);
        void FormClosed(Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
    };
}
