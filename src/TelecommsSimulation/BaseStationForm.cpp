#include "pch.h"

#include "BaseStationForm.h"

using namespace TelecommsSimulation::Core;

namespace TelecommsSimulation
{
    BaseStationForm::BaseStationForm(BaseStation^ baseStation)
    {
        InitializeComponent();

        _baseStation = baseStation;

        // ReSharper disable CppObjectMemberMightNotBeInitialized
        NameLabel->Text = _baseStation->Name;
        CoverageNumericUpDown->Value = safe_cast<Decimal>(_baseStation->CoverageRadiusKm);

        Binding^ longitudeBinding = LongitudeNumericUpDown->DataBindings->Add(
            "Value", _baseStation, "Location", true);
        longitudeBinding->Format += gcnew ConvertEventHandler(this, &BaseStationForm::OnLongitudeFormat);

        Binding^ latitudeBinding = LatitudeNumericUpDown->DataBindings->Add(
            "Value", _baseStation, "Location", true);
        latitudeBinding->Format += gcnew ConvertEventHandler(this, &BaseStationForm::OnLatitudeFormat);

        ConnectedPhonesCountNumericUpDown->DataBindings->Add("Value", _baseStation, "ConnectedPhonesCount");
        // ReSharper restore CppObjectMemberMightNotBeInitialized

        _baseStation->PropertyChanged += gcnew PropertyChangedEventHandler(
            this, &BaseStationForm::OnBaseStationPropertyChanged);
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void BaseStationForm::OnLongitudeFormat(Object^ sender, ConvertEventArgs^ e)
    {
        if (e->Value != nullptr && e->Value->GetType() == Coordinates::typeid)
        {
            auto coordinates = safe_cast<Coordinates>(e->Value);
            e->Value = safe_cast<Decimal>(coordinates.Longitude);
        }
    }

    // ReSharper disable once CppMemberFunctionMayBeStatic
    void BaseStationForm::OnLatitudeFormat(Object^ sender, ConvertEventArgs^ e)
    {
        if (e->Value != nullptr && e->Value->GetType() == Coordinates::typeid)
        {
            auto coordinates = safe_cast<Coordinates>(e->Value);
            e->Value = safe_cast<Decimal>(coordinates.Latitude);
        }
    }

    void BaseStationForm::BaseStationForm_FormClosed(Object^ sender, FormClosedEventArgs^ e)
    {
        if (_baseStation->IsEnabled)
            _baseStation->Disable();
    }

    void BaseStationForm::EnableButton_Click(Object^ sender, EventArgs^ e)
    {
        _baseStation->Enable();
    }

    void BaseStationForm::DisableButton_Click(Object^ sender, EventArgs^ e)
    {
        _baseStation->Disable();
    }

    void BaseStationForm::OnBaseStationPropertyChanged(Object^ sender, PropertyChangedEventArgs^ e)
    {
        // if this->InvokeRequired ... (if without binding)

        if (e->PropertyName == "IsEnabled")
        {
            switch (_baseStation->IsEnabled)
            {
                case false:
                    {
                        EnableButton->Enabled = true;
                        DisableButton->Enabled = false;
                        break;
                    }
                case true:
                    {
                        EnableButton->Enabled = false;
                        DisableButton->Enabled = true;
                        break;
                    }
            }
        }
    }
}
