#pragma once

namespace TelecommsSimulation
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Form to choose run mode
    /// </summary>
    public ref class RunModeSelectionForm : public System::Windows::Forms::Form
    {
    private:
        Form^ _controlPanelForm;

    public:
        RunModeSelectionForm(void)
        {
            InitializeComponent();
        }

    protected:
        /// <summary>
        /// Cleans up resources
        /// </summary>
        ~RunModeSelectionForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::Button^ FreeModeButton;

    private:
        System::Windows::Forms::Button^ ScenarioModeButton;

    protected:

    protected:

    private:
        /// <summary>
        /// Required designer variable.
        /// </summary>
        System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
        /// <summary>
        /// Required method for Designer support - do not modify
        /// the contents of this method with the code editor.
        /// </summary>
        void InitializeComponent(void)
        {
            System::ComponentModel::ComponentResourceManager^ resources = (gcnew
                System::ComponentModel::ComponentResourceManager(RunModeSelectionForm::typeid));
            this->FreeModeButton = (gcnew System::Windows::Forms::Button());
            this->ScenarioModeButton = (gcnew System::Windows::Forms::Button());
            this->SuspendLayout();
            // 
            // FreeModeButton
            // 
            this->FreeModeButton->Location = System::Drawing::Point(12, 12);
            this->FreeModeButton->Name = L"FreeModeButton";
            this->FreeModeButton->Size = System::Drawing::Size(450, 26);
            this->FreeModeButton->TabIndex = 0;
            this->FreeModeButton->Text = L"Свободный";
            this->FreeModeButton->UseVisualStyleBackColor = true;
            this->FreeModeButton->Click += gcnew
                System::EventHandler(this, &RunModeSelectionForm::FreeModeButton_Click);
            // 
            // ScenarioModeButton
            // 
            this->ScenarioModeButton->Location = System::Drawing::Point(12, 44);
            this->ScenarioModeButton->Name = L"ScenarioModeButton";
            this->ScenarioModeButton->Size = System::Drawing::Size(450, 26);
            this->ScenarioModeButton->TabIndex = 1;
            this->ScenarioModeButton->Text = L"Сценарий";
            this->ScenarioModeButton->UseVisualStyleBackColor = true;
            this->ScenarioModeButton->Click += gcnew System::EventHandler(
                this, &RunModeSelectionForm::ScenarioModeButton_Click);
            // 
            // RunModeSelectionForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(474, 82);
            this->Controls->Add(this->ScenarioModeButton);
            this->Controls->Add(this->FreeModeButton);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->MaximizeBox = false;
            this->Name = L"RunModeSelectionForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Симуляция телекоммуникаций: Режим работы";
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        System::Void FreeModeButton_Click(System::Object^ sender, System::EventArgs^ e);

    private:
        System::Void ScenarioModeButton_Click(System::Object^ sender, System::EventArgs^ e);
        void OnControlPanelFormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);
    };
}
