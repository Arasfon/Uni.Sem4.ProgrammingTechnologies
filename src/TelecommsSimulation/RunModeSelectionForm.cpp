#include "pch.h"

#include "RunModeSelectionForm.h"

#include "FreeControlPanelForm.h"
#include "ScenarioControlPanelForm.h"

namespace TelecommsSimulation
{
    void RunModeSelectionForm::FreeModeButton_Click(Object^ sender, EventArgs^ e)
    {
        Hide();

        _controlPanelForm = gcnew FreeControlPanelForm();
        _controlPanelForm->FormClosed += gcnew FormClosedEventHandler(
            this, &RunModeSelectionForm::OnControlPanelFormClosed);
        _controlPanelForm->Show(this);
    }

    void RunModeSelectionForm::ScenarioModeButton_Click(Object^ sender, EventArgs^ e)
    {
        Hide();

        _controlPanelForm = gcnew ScenarioControlPanelForm();
        _controlPanelForm->FormClosed += gcnew FormClosedEventHandler(
            this, &RunModeSelectionForm::OnControlPanelFormClosed);
        _controlPanelForm->Show(this);
    }

    void RunModeSelectionForm::OnControlPanelFormClosed(Object^ sender, FormClosedEventArgs^ e)
    {
        Close();
    }
}
