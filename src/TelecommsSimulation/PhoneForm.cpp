#include "pch.h"

#include "PhoneForm.h"

using namespace System::Threading::Tasks;

using namespace TelecommsSimulation::Core;
using namespace TelecommsSimulation::Engine;
using namespace TelecommsSimulation::Utilities;

namespace TelecommsSimulation
{
    // TODO: Rename second parameter
    PhoneForm::PhoneForm(Phone^ phone, const bool interceptAnswer)
    {
        InitializeComponent();

        _phone = phone;

        // ReSharper disable CppObjectMemberMightNotBeInitialized
        NumberLabel->Text = _phone->Number;

        Binding^ longitudeBinding = LongitudeNumericUpDown->DataBindings->Add(
            "Value", _phone, "Location", true);
        longitudeBinding->Format += gcnew ConvertEventHandler(this, &PhoneForm::OnLongitudeFormat);

        Binding^ latitudeBinding = LatitudeNumericUpDown->DataBindings->Add(
            "Value", _phone, "Location", true);
        latitudeBinding->Format += gcnew ConvertEventHandler(this, &PhoneForm::OnLatitudeFormat);

        StateLabel->DataBindings->Add("Text", _phone, "State");
        CallStateLabel->DataBindings->Add("Text", _phone, "CallState");
        InCallWithLabel->DataBindings->Add("Text", _phone, "InCallWith");
        BatteryLevelNumericUpDown->DataBindings->Add("Value", _phone, "BatteryLevel");
        ConnectedBaseStationNameLabel->DataBindings->Add("Text", _phone, "ConnectedBaseStationName");
        // ReSharper restore CppObjectMemberMightNotBeInitialized

        if (interceptAnswer)
            _phone->CallReceived += gcnew AsyncEventHandler<CallEventArgs^>(this, &PhoneForm::OnCallReceived);

        _phone->PropertyChanged += gcnew PropertyChangedEventHandler(
            this, &PhoneForm::OnPhonePropertyChanged);
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void PhoneForm::OnLongitudeFormat(Object^ sender, ConvertEventArgs^ e)
    {
        if (e->Value != nullptr && e->Value->GetType() == Coordinates::typeid)
        {
            Coordinates coordinates = safe_cast<Coordinates>(e->Value);
            e->Value = safe_cast<Decimal>(coordinates.Longitude);
        }
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void PhoneForm::OnLatitudeFormat(Object^ sender, ConvertEventArgs^ e)
    {
        if (e->Value != nullptr && e->Value->GetType() == Coordinates::typeid)
        {
            Coordinates coordinates = safe_cast<Coordinates>(e->Value);
            e->Value = safe_cast<Decimal>(coordinates.Latitude);
        }
    }

    void PhoneForm::PhoneForm_FormClosed(Object^ sender, FormClosedEventArgs^ e)
    {
        if (_phone->State != PhoneState::Off)
            _phone->TurnOff();
    }

    void PhoneForm::TurnOnButton_Click(Object^ sender, EventArgs^ e)
    {
        _phone->TurnOn();
    }

    void PhoneForm::TurnOffButton_Click(Object^ sender, EventArgs^ e)
    {
        _phone->TurnOff();
    }

    void PhoneForm::ConnectToBaseStationButton_Click(Object^ sender, EventArgs^ e)
    {
        _phone->ConnectToBaseStation();
    }

    void PhoneForm::DisconnectFromBaseStationButton_Click(Object^ sender, EventArgs^ e)
    {
        _phone->DisconnectFromBaseStation();
    }

    void PhoneForm::MakeCallButton_Click(Object^ sender, EventArgs^ e)
    {
        _phone->MakeCall(CalleeNumberTextBox->Text)->ContinueWith(
            gcnew Action<Task<CallResult>^>(this, &PhoneForm::_MakeCallButtonClickContinuation),
            TaskContinuationOptions::RunContinuationsAsynchronously);
    }

    // Workaround: C++/CLI does not support lambda-functions
    // ReSharper disable once CppMemberFunctionMayBeStatic
    void PhoneForm::_MakeCallButtonClickContinuation(Task<CallResult>^ task)
    {
        switch (task->Result)
        {
            case CallResult::Established:
                {
                    break;
                }
            case CallResult::NotFound:
                {
                    MessageBox::Show("Абонент не найден", "Ошибка звонка", MessageBoxButtons::OK,
                                     MessageBoxIcon::Error);
                    break;
                }
            case CallResult::Busy:
                {
                    MessageBox::Show("Абонент занят", "Ошибка звонка", MessageBoxButtons::OK, MessageBoxIcon::Error);
                    break;
                }
        }
    }

    void PhoneForm::EndCallButton_Click(Object^ sender, EventArgs^ e)
    {
        _phone->EndCall();
    }

    Task^ PhoneForm::OnCallReceived(Object^ sender, CallEventArgs^ e)
    {
        // ReSharper disable once CppTooWideScope
        const Windows::Forms::DialogResult answerResult = MessageBox::Show(
            String::Format("На телефон с номером {0} поступил звонок от абонента с номером {1}.\nПринять звонок?",
                           e->ReceiverNumber, e->CallerNumber), "Входящий вызов", MessageBoxButtons::YesNo,
            MessageBoxIcon::Question, MessageBoxDefaultButton::Button1);

        switch (answerResult)
        {
            case Windows::Forms::DialogResult::Yes:
                {
                    _phone->AnswerCall(CallAnswer::Agreed);
                    break;
                }
            case Windows::Forms::DialogResult::No:
                {
                    _phone->AnswerCall(CallAnswer::Declined);
                    break;
                }
            default:
                {
                    _phone->AnswerCall(CallAnswer::Declined);
                    break;
                }
        }

        return Task::CompletedTask;
    }

    void PhoneForm::OnPhonePropertyChanged(Object^ sender, PropertyChangedEventArgs^ e)
    {
        // if this->InvokeRequired ... (if without binding)

        if (e->PropertyName == "State")
        {
            switch (_phone->State)
            {
                case PhoneState::Off:
                    {
                        TurnOnButton->Enabled = true;
                        TurnOffButton->Enabled = false;
                        ConnectToBaseStationButton->Enabled = false;
                        DisconnectFromBaseStationButton->Enabled = false;
                        CalleeNumberTextBox->Enabled = false;
                        MakeCallButton->Enabled = false;
                        EndCallButton->Enabled = false;
                        break;
                    }
                case PhoneState::Disconnected:
                    {
                        TurnOnButton->Enabled = false;
                        TurnOffButton->Enabled = true;
                        ConnectToBaseStationButton->Enabled = true;
                        DisconnectFromBaseStationButton->Enabled = false;
                        CalleeNumberTextBox->Enabled = false;
                        MakeCallButton->Enabled = false;
                        EndCallButton->Enabled = false;
                        break;
                    }
                case PhoneState::Connected:
                    {
                        TurnOnButton->Enabled = false;
                        TurnOffButton->Enabled = true;
                        ConnectToBaseStationButton->Enabled = false;
                        DisconnectFromBaseStationButton->Enabled = true;
                        CalleeNumberTextBox->Enabled = true;
                        MakeCallButton->Enabled = true;
                        EndCallButton->Enabled = false;
                        break;
                    }
            }
        }
        else if (e->PropertyName == "CallState")
        {
            switch (_phone->CallState)
            {
                case CallState::Idle:
                    {
                        CalleeNumberTextBox->Enabled = true;
                        MakeCallButton->Enabled = true;
                        EndCallButton->Enabled = false;
                        break;
                    }
                case CallState::Dialing:
                    {
                        CalleeNumberTextBox->Enabled = false;
                        MakeCallButton->Enabled = false;
                        EndCallButton->Enabled = true;
                        break;
                    }
                case CallState::AwaitingAnswer:
                    {
                        CalleeNumberTextBox->Enabled = false;
                        MakeCallButton->Enabled = false;
                        EndCallButton->Enabled = false;
                        break;
                    }
                case CallState::InCall:
                    {
                        CalleeNumberTextBox->Enabled = false;
                        MakeCallButton->Enabled = false;
                        EndCallButton->Enabled = true;
                        break;
                    }
            }
        }
    }
}
