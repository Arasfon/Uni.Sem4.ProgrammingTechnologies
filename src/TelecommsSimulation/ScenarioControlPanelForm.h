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
    /// Control panel of simulation in scenario mode
    /// </summary>
    public ref class ScenarioControlPanelForm : public System::Windows::Forms::Form
    {
        static Engine::TimeAwareSimulationEngine<Engine::ITimeAwareSimulatable^>^ _simulationEngine;

    public:
        ScenarioControlPanelForm();

    protected:
        /// <summary>
        /// Cleans up resources
        /// </summary>
        ~ScenarioControlPanelForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TrackBar^ SimulationSpeedTrackBar;

    private:
        System::Windows::Forms::Label^ label1;
        System::Windows::Forms::Button^ SimulationStartButton;
        System::Windows::Forms::Button^ SimulationStopButton;


        System::Windows::Forms::Label^ label6;
        System::Windows::Forms::Label^ label7;

    private:
        /// <summary>
        /// Required designer variable
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
                System::ComponentModel::ComponentResourceManager(ScenarioControlPanelForm::typeid));
            this->SimulationSpeedTrackBar = (gcnew System::Windows::Forms::TrackBar());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->SimulationStartButton = (gcnew System::Windows::Forms::Button());
            this->SimulationStopButton = (gcnew System::Windows::Forms::Button());
            this->label6 = (gcnew System::Windows::Forms::Label());
            this->label7 = (gcnew System::Windows::Forms::Label());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SimulationSpeedTrackBar))->BeginInit();
            this->SuspendLayout();
            // 
            // SimulationSpeedTrackBar
            // 
            this->SimulationSpeedTrackBar->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->SimulationSpeedTrackBar->LargeChange = 10;
            this->SimulationSpeedTrackBar->Location = System::Drawing::Point(39, 27);
            this->SimulationSpeedTrackBar->Maximum = 200;
            this->SimulationSpeedTrackBar->Name = L"SimulationSpeedTrackBar";
            this->SimulationSpeedTrackBar->Size = System::Drawing::Size(561, 45);
            this->SimulationSpeedTrackBar->SmallChange = 5;
            this->SimulationSpeedTrackBar->TabIndex = 0;
            this->SimulationSpeedTrackBar->TickFrequency = 10;
            this->SimulationSpeedTrackBar->Value = 100;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Location = System::Drawing::Point(12, 9);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(127, 15);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Скорость симуляции:";
            // 
            // SimulationStartButton
            // 
            this->SimulationStartButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->SimulationStartButton->Location = System::Drawing::Point(12, 78);
            this->SimulationStartButton->Name = L"SimulationStartButton";
            this->SimulationStartButton->Size = System::Drawing::Size(614, 26);
            this->SimulationStartButton->TabIndex = 1;
            this->SimulationStartButton->Text = L"Запустить";
            this->SimulationStartButton->UseVisualStyleBackColor = true;
            this->SimulationStartButton->Click += gcnew System::EventHandler(
                this, &ScenarioControlPanelForm::SimulationStartButton_Click);
            // 
            // SimulationStopButton
            // 
            this->SimulationStopButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->SimulationStopButton->Enabled = false;
            this->SimulationStopButton->Location = System::Drawing::Point(12, 110);
            this->SimulationStopButton->Name = L"SimulationStopButton";
            this->SimulationStopButton->Size = System::Drawing::Size(614, 26);
            this->SimulationStopButton->TabIndex = 2;
            this->SimulationStopButton->Text = L"Остановить";
            this->SimulationStopButton->UseVisualStyleBackColor = true;
            this->SimulationStopButton->Click += gcnew System::EventHandler(
                this, &ScenarioControlPanelForm::SimulationStopButton_Click);
            // 
            // label6
            // 
            this->label6->Location = System::Drawing::Point(13, 28);
            this->label6->Name = L"label6";
            this->label6->Size = System::Drawing::Size(20, 16);
            this->label6->TabIndex = 6;
            this->label6->Text = L"0";
            this->label6->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // label7
            // 
            this->label7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((
                System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Right));
            this->label7->Location = System::Drawing::Point(606, 28);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(20, 16);
            this->label7->TabIndex = 7;
            this->label7->Text = L"2";
            this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
            // 
            // ScenarioControlPanelForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(638, 148);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->SimulationStopButton);
            this->Controls->Add(this->SimulationStartButton);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->SimulationSpeedTrackBar);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular,
                                                      System::Drawing::GraphicsUnit::Point,
                                                      static_cast<System::Byte>(0)));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(1, 3, 4, 3);
            this->MaximizeBox = false;
            this->Name = L"ScenarioControlPanelForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Симуляция телекоммуникаций: Панель управления сценарием";
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->SimulationSpeedTrackBar))->EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
        System::Void SimulationStartButton_Click(Object^ sender, System::EventArgs^ e);
        System::Void SimulationStopButton_Click(Object^ sender, System::EventArgs^ e);
        System::Void OnSimulationEnginePropertyChanged(System::Object^ sender,
                                                       System::ComponentModel::PropertyChangedEventArgs^ e);
    };
}
