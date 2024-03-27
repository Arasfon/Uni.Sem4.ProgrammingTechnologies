#pragma once

namespace TelecommsSimulation::Utilities
{
    generic<typename T>
    public delegate System::Threading::Tasks::Task^ AsyncEventHandler(System::Object^ sender, T e);
}
