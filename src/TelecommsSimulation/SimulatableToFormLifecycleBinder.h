#pragma once

namespace TelecommsSimulation
{
    generic<typename T> where T : Engine::ISimulatable
    public ref class SimulatableToFormLifecycleBinder
    {
        Engine::ISimulationEngine<T>^ _simulationEngine;
        T _simulatable;
        System::Windows::Forms::Form^ _form;

    public:
        static SimulatableToFormLifecycleBinder^ Bind(Engine::ISimulationEngine<T>^ simulationEngine, T simulatable,
                                                      System::Windows::Forms::Form^ form);

    private:
        SimulatableToFormLifecycleBinder(Engine::ISimulationEngine<T>^ simulationEngine, T simulatable,
                                         System::Windows::Forms::Form^ form);

        void FormShown(Object^ sender, System::EventArgs^ e);
        void FormClosed(Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
    };
}
