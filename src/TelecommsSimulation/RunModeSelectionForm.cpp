#include "pch.h"

#include "RunModeSelectionForm.h"

#include "FreeControlPanelForm.h"
#include "ScenarioControlPanelForm.h"

namespace TelecommsSimulation
{
    void RunModeSelectionForm::FreeModeButton_Click(Object^ sender, EventArgs^ e)
    {
        Hide();
        (gcnew FreeControlPanelForm())->ShowDialog();
        Close();
    }

    void RunModeSelectionForm::ScenarioModeButton_Click(Object^ sender, EventArgs^ e)
    {
        Hide();
        (gcnew ScenarioControlPanelForm())->ShowDialog();
        Close();
    }
}
