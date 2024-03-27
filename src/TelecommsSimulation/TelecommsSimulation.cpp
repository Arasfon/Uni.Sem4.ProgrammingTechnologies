#include "pch.h"

#include "RunModeSelectionForm.h"

using namespace System;
using namespace System::Windows::Forms;

using namespace TelecommsSimulation;

[STAThread]
int main(array<String^>^ args)
{
    Application::EnableVisualStyles();
    Application::SetCompatibleTextRenderingDefault(false);
    Application::Run(gcnew RunModeSelectionForm());
    return 0;
}
