#pragma once

#include "SimulationVisualizationForm.h"

#include "VisualizationRegistry.h"

namespace TelecommsSimulation
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// Control panel of simulation in free mode
    /// </summary>
    public ref class FreeControlPanelForm : public Form
    {
        Engine::TimeAwareSimulationEngine<Engine::ITimeAwareSimulatable^>^ _simulationEngine;

        VisualizationRegistry<Core::BaseStation^>^ _baseStationVisualizationRegistry;
        VisualizationRegistry<Core::Phone^>^ _phoneVisualizationRegistry;

        SimulationVisualizationForm^ _simulationVisualizationForm;

    public:
        FreeControlPanelForm();

    protected:
        /// <summary>
        /// Cleans up resources
        /// </summary>
        ~FreeControlPanelForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        TrackBar^ SimulationSpeedTrackBar;

        Label^ label1;
        Button^ SimulationStartButton;
        Button^ SimulationStopButton;


        GroupBox^ groupBox1;
        TableLayoutPanel^ tableLayoutPanel1;
        Label^ label2;
        Button^ CreateBaseStationButton;

        Label^ label3;
        NumericUpDown^ BaseStationLongitudeNumericUpDown;
        NumericUpDown^ BaseStationLatitudeNumericUpDown;


        GroupBox^ groupBox2;
        TableLayoutPanel^ tableLayoutPanel2;
        Label^ label4;
        Button^ CreatePhoneButton;

        Label^ label5;
        NumericUpDown^ PhoneLongitudeNumericUpDown;
        NumericUpDown^ PhoneLatitudeNumericUpDown;
        Button^ CreatePhoneWithBlacklistButton;
        Label^ label6;
        Label^ label7;
        Label^ label8;
        NumericUpDown^ BaseStationCoverageNumericUpDown;

        Label^ label9;
        TextBox^ PhoneNumberTextBox;

        Label^ label10;
        NumericUpDown^ PhoneBatteryLevelNumericUpDown;
        Label^ label11;
        TextBox^ BaseStationNameTextBox;

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
            ComponentResourceManager^ resources = (gcnew
                ComponentResourceManager(FreeControlPanelForm::typeid));
            this->SimulationSpeedTrackBar = (gcnew TrackBar());
            this->label1 = (gcnew Label());
            this->SimulationStartButton = (gcnew Button());
            this->SimulationStopButton = (gcnew Button());
            this->groupBox1 = (gcnew GroupBox());
            this->tableLayoutPanel1 = (gcnew TableLayoutPanel());
            this->label2 = (gcnew Label());
            this->CreateBaseStationButton = (gcnew Button());
            this->label3 = (gcnew Label());
            this->BaseStationLongitudeNumericUpDown = (gcnew NumericUpDown());
            this->BaseStationLatitudeNumericUpDown = (gcnew NumericUpDown());
            this->label8 = (gcnew Label());
            this->BaseStationCoverageNumericUpDown = (gcnew NumericUpDown());
            this->label11 = (gcnew Label());
            this->BaseStationNameTextBox = (gcnew TextBox());
            this->groupBox2 = (gcnew GroupBox());
            this->tableLayoutPanel2 = (gcnew TableLayoutPanel());
            this->label4 = (gcnew Label());
            this->CreatePhoneButton = (gcnew Button());
            this->label5 = (gcnew Label());
            this->PhoneLongitudeNumericUpDown = (gcnew NumericUpDown());
            this->PhoneLatitudeNumericUpDown = (gcnew NumericUpDown());
            this->CreatePhoneWithBlacklistButton = (gcnew Button());
            this->label9 = (gcnew Label());
            this->PhoneNumberTextBox = (gcnew TextBox());
            this->label10 = (gcnew Label());
            this->PhoneBatteryLevelNumericUpDown = (gcnew NumericUpDown());
            this->label6 = (gcnew Label());
            this->label7 = (gcnew Label());
            (cli::safe_cast<ISupportInitialize^>(this->SimulationSpeedTrackBar))->BeginInit();
            this->groupBox1->SuspendLayout();
            this->tableLayoutPanel1->SuspendLayout();
            (cli::safe_cast<ISupportInitialize^>(this->BaseStationLongitudeNumericUpDown))->
                BeginInit();
            (cli::safe_cast<ISupportInitialize^>(this->BaseStationLatitudeNumericUpDown))->
                BeginInit();
            (cli::safe_cast<ISupportInitialize^>(this->BaseStationCoverageNumericUpDown))->
                BeginInit();
            this->groupBox2->SuspendLayout();
            this->tableLayoutPanel2->SuspendLayout();
            (cli::safe_cast<ISupportInitialize^>(this->PhoneLongitudeNumericUpDown))->
                BeginInit();
            (cli::safe_cast<ISupportInitialize^>(this->PhoneLatitudeNumericUpDown))->
                BeginInit();
            (cli::safe_cast<ISupportInitialize^>(this->PhoneBatteryLevelNumericUpDown))->
                BeginInit();
            this->SuspendLayout();
            //
            // SimulationSpeedTrackBar
            //
            this->SimulationSpeedTrackBar->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->SimulationSpeedTrackBar->LargeChange = 10;
            this->SimulationSpeedTrackBar->Location = Point(39, 27);
            this->SimulationSpeedTrackBar->Maximum = 200;
            this->SimulationSpeedTrackBar->Name = L"SimulationSpeedTrackBar";
            this->SimulationSpeedTrackBar->Size = Drawing::Size(561, 45);
            this->SimulationSpeedTrackBar->SmallChange = 5;
            this->SimulationSpeedTrackBar->TabIndex = 0;
            this->SimulationSpeedTrackBar->TickFrequency = 10;
            this->SimulationSpeedTrackBar->Value = 100;
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Location = Point(12, 9);
            this->label1->Name = L"label1";
            this->label1->Size = Drawing::Size(127, 15);
            this->label1->TabIndex = 1;
            this->label1->Text = L"Скорость симуляции:";
            //
            // SimulationStartButton
            //
            this->SimulationStartButton->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->SimulationStartButton->Location = Point(12, 78);
            this->SimulationStartButton->Name = L"SimulationStartButton";
            this->SimulationStartButton->Size = Drawing::Size(614, 26);
            this->SimulationStartButton->TabIndex = 1;
            this->SimulationStartButton->Text = L"Запустить";
            this->SimulationStartButton->UseVisualStyleBackColor = true;
            this->SimulationStartButton->Click += gcnew EventHandler(
                this, &FreeControlPanelForm::SimulationStartButton_Click);
            //
            // SimulationStopButton
            //
            this->SimulationStopButton->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->SimulationStopButton->Enabled = false;
            this->SimulationStopButton->Location = Point(12, 110);
            this->SimulationStopButton->Name = L"SimulationStopButton";
            this->SimulationStopButton->Size = Drawing::Size(614, 26);
            this->SimulationStopButton->TabIndex = 2;
            this->SimulationStopButton->Text = L"Остановить";
            this->SimulationStopButton->UseVisualStyleBackColor = true;
            this->SimulationStopButton->Click += gcnew EventHandler(
                this, &FreeControlPanelForm::SimulationStopButton_Click);
            //
            // groupBox1
            //
            this->groupBox1->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->groupBox1->Controls->Add(this->tableLayoutPanel1);
            this->groupBox1->Location = Point(12, 142);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = Drawing::Size(614, 141);
            this->groupBox1->TabIndex = 4;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Фабрика базовых станций";
            //
            // tableLayoutPanel1
            //
            this->tableLayoutPanel1->ColumnCount = 4;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew ColumnStyle()));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew ColumnStyle(
                SizeType::Percent,
                50)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew ColumnStyle()));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew ColumnStyle(
                SizeType::Percent,
                50)));
            this->tableLayoutPanel1->Controls->Add(this->label2, 0, 1);
            this->tableLayoutPanel1->Controls->Add(this->CreateBaseStationButton, 0, 3);
            this->tableLayoutPanel1->Controls->Add(this->label3, 2, 1);
            this->tableLayoutPanel1->Controls->Add(this->BaseStationLongitudeNumericUpDown, 1, 1);
            this->tableLayoutPanel1->Controls->Add(this->BaseStationLatitudeNumericUpDown, 3, 1);
            this->tableLayoutPanel1->Controls->Add(this->label8, 0, 2);
            this->tableLayoutPanel1->Controls->Add(this->BaseStationCoverageNumericUpDown, 1, 2);
            this->tableLayoutPanel1->Controls->Add(this->label11, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->BaseStationNameTextBox, 1, 0);
            this->tableLayoutPanel1->Dock = DockStyle::Fill;
            this->tableLayoutPanel1->Location = Point(3, 19);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 4;
            this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle()));
            this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle()));
            this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle()));
            this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle()));
            this->tableLayoutPanel1->Size = Drawing::Size(608, 119);
            this->tableLayoutPanel1->TabIndex = 0;
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Dock = DockStyle::Fill;
            this->label2->Location = Point(3, 29);
            this->label2->Name = L"label2";
            this->label2->Size = Drawing::Size(89, 29);
            this->label2->TabIndex = 0;
            this->label2->Text = L"Долгота";
            this->label2->TextAlign = ContentAlignment::MiddleLeft;
            //
            // CreateBaseStationButton
            //
            this->tableLayoutPanel1->SetColumnSpan(this->CreateBaseStationButton, 4);
            this->CreateBaseStationButton->Dock = DockStyle::Fill;
            this->CreateBaseStationButton->Location = Point(3, 90);
            this->CreateBaseStationButton->Name = L"CreateBaseStationButton";
            this->CreateBaseStationButton->Size = Drawing::Size(602, 26);
            this->CreateBaseStationButton->TabIndex = 6;
            this->CreateBaseStationButton->Text = L"Создать";
            this->CreateBaseStationButton->UseVisualStyleBackColor = true;
            this->CreateBaseStationButton->Click += gcnew EventHandler(
                this, &FreeControlPanelForm::CreateBaseStationButton_Click);
            //
            // label3
            //
            this->label3->AutoSize = true;
            this->label3->Dock = DockStyle::Fill;
            this->label3->Location = Point(326, 29);
            this->label3->Name = L"label3";
            this->label3->Size = Drawing::Size(50, 29);
            this->label3->TabIndex = 2;
            this->label3->Text = L"Широта";
            this->label3->TextAlign = ContentAlignment::MiddleLeft;
            //
            // BaseStationLongitudeNumericUpDown
            //
            this->BaseStationLongitudeNumericUpDown->DecimalPlaces = 3;
            this->BaseStationLongitudeNumericUpDown->Dock = DockStyle::Fill;
            this->BaseStationLongitudeNumericUpDown->Location = Point(98, 32);
            this->BaseStationLongitudeNumericUpDown->Maximum = Decimal(gcnew array<Int32>(4){
                180, 0, 0, 0
            });
            this->BaseStationLongitudeNumericUpDown->Minimum = Decimal(gcnew array<Int32>(4){
                180, 0, 0, Int32::MinValue
            });
            this->BaseStationLongitudeNumericUpDown->Name = L"BaseStationLongitudeNumericUpDown";
            this->BaseStationLongitudeNumericUpDown->Size = Drawing::Size(222, 23);
            this->BaseStationLongitudeNumericUpDown->TabIndex = 3;
            //
            // BaseStationLatitudeNumericUpDown
            //
            this->BaseStationLatitudeNumericUpDown->DecimalPlaces = 3;
            this->BaseStationLatitudeNumericUpDown->Dock = DockStyle::Fill;
            this->BaseStationLatitudeNumericUpDown->Location = Point(382, 32);
            this->BaseStationLatitudeNumericUpDown->Maximum = Decimal(gcnew array<Int32>(4){
                90, 0, 0, 0
            });
            this->BaseStationLatitudeNumericUpDown->Minimum = Decimal(gcnew array<Int32>(4){
                90, 0, 0, Int32::MinValue
            });
            this->BaseStationLatitudeNumericUpDown->Name = L"BaseStationLatitudeNumericUpDown";
            this->BaseStationLatitudeNumericUpDown->Size = Drawing::Size(223, 23);
            this->BaseStationLatitudeNumericUpDown->TabIndex = 4;
            //
            // label8
            //
            this->label8->AutoSize = true;
            this->label8->Dock = DockStyle::Fill;
            this->label8->Location = Point(3, 58);
            this->label8->Name = L"label8";
            this->label8->Size = Drawing::Size(89, 29);
            this->label8->TabIndex = 5;
            this->label8->Text = L"Покрытие (км)";
            this->label8->TextAlign = ContentAlignment::MiddleLeft;
            //
            // BaseStationCoverageNumericUpDown
            //
            this->tableLayoutPanel1->SetColumnSpan(this->BaseStationCoverageNumericUpDown, 3);
            this->BaseStationCoverageNumericUpDown->Dock = DockStyle::Fill;
            this->BaseStationCoverageNumericUpDown->Location = Point(98, 61);
            this->BaseStationCoverageNumericUpDown->Maximum = Decimal(gcnew array<Int32>(4){
                -1, -1, -1, 0
            });
            this->BaseStationCoverageNumericUpDown->Minimum = Decimal(gcnew array<Int32>(4){
                1, 0, 0, 0
            });
            this->BaseStationCoverageNumericUpDown->Name = L"BaseStationCoverageNumericUpDown";
            this->BaseStationCoverageNumericUpDown->Size = Drawing::Size(507, 23);
            this->BaseStationCoverageNumericUpDown->TabIndex = 5;
            this->BaseStationCoverageNumericUpDown->Value = Decimal(gcnew array<Int32>(4){
                150, 0, 0, 0
            });
            //
            // label11
            //
            this->label11->AutoSize = true;
            this->label11->Dock = DockStyle::Fill;
            this->label11->Location = Point(3, 0);
            this->label11->Name = L"label11";
            this->label11->Size = Drawing::Size(89, 29);
            this->label11->TabIndex = 7;
            this->label11->Text = L"Название";
            this->label11->TextAlign = ContentAlignment::MiddleLeft;
            //
            // BaseStationNameTextBox
            //
            this->tableLayoutPanel1->SetColumnSpan(this->BaseStationNameTextBox, 3);
            this->BaseStationNameTextBox->Dock = DockStyle::Fill;
            this->BaseStationNameTextBox->Location = Point(98, 3);
            this->BaseStationNameTextBox->Name = L"BaseStationNameTextBox";
            this->BaseStationNameTextBox->Size = Drawing::Size(507, 23);
            this->BaseStationNameTextBox->TabIndex = 8;
            //
            // groupBox2
            //
            this->groupBox2->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->groupBox2->Controls->Add(this->tableLayoutPanel2);
            this->groupBox2->Location = Point(12, 289);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = Drawing::Size(614, 141);
            this->groupBox2->TabIndex = 5;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"Фабрика телефонов";
            //
            // tableLayoutPanel2
            //
            this->tableLayoutPanel2->ColumnCount = 4;
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew ColumnStyle()));
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew ColumnStyle(
                SizeType::Percent,
                50)));
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew ColumnStyle()));
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew ColumnStyle(
                SizeType::Percent,
                50)));
            this->tableLayoutPanel2->Controls->Add(this->label4, 0, 1);
            this->tableLayoutPanel2->Controls->Add(this->CreatePhoneButton, 0, 3);
            this->tableLayoutPanel2->Controls->Add(this->label5, 2, 1);
            this->tableLayoutPanel2->Controls->Add(this->PhoneLongitudeNumericUpDown, 1, 1);
            this->tableLayoutPanel2->Controls->Add(this->PhoneLatitudeNumericUpDown, 3, 1);
            this->tableLayoutPanel2->Controls->Add(this->CreatePhoneWithBlacklistButton, 2, 3);
            this->tableLayoutPanel2->Controls->Add(this->label9, 0, 0);
            this->tableLayoutPanel2->Controls->Add(this->PhoneNumberTextBox, 1, 0);
            this->tableLayoutPanel2->Controls->Add(this->label10, 0, 2);
            this->tableLayoutPanel2->Controls->Add(this->PhoneBatteryLevelNumericUpDown, 1, 2);
            this->tableLayoutPanel2->Dock = DockStyle::Fill;
            this->tableLayoutPanel2->Location = Point(3, 19);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 4;
            this->tableLayoutPanel2->RowStyles->Add((gcnew RowStyle()));
            this->tableLayoutPanel2->RowStyles->Add((gcnew RowStyle()));
            this->tableLayoutPanel2->RowStyles->Add((gcnew RowStyle()));
            this->tableLayoutPanel2->RowStyles->Add((gcnew RowStyle()));
            this->tableLayoutPanel2->Size = Drawing::Size(608, 119);
            this->tableLayoutPanel2->TabIndex = 0;
            //
            // label4
            //
            this->label4->AutoSize = true;
            this->label4->Dock = DockStyle::Fill;
            this->label4->Location = Point(3, 29);
            this->label4->Name = L"label4";
            this->label4->Size = Drawing::Size(52, 29);
            this->label4->TabIndex = 0;
            this->label4->Text = L"Долгота";
            this->label4->TextAlign = ContentAlignment::MiddleLeft;
            //
            // CreatePhoneButton
            //
            this->tableLayoutPanel2->SetColumnSpan(this->CreatePhoneButton, 2);
            this->CreatePhoneButton->Dock = DockStyle::Fill;
            this->CreatePhoneButton->Location = Point(3, 90);
            this->CreatePhoneButton->Name = L"CreatePhoneButton";
            this->CreatePhoneButton->Size = Drawing::Size(299, 26);
            this->CreatePhoneButton->TabIndex = 11;
            this->CreatePhoneButton->Text = L"Создать обычный";
            this->CreatePhoneButton->UseVisualStyleBackColor = true;
            this->CreatePhoneButton->Click += gcnew EventHandler(
                this, &FreeControlPanelForm::CreatePhoneButton_Click);
            //
            // label5
            //
            this->label5->AutoSize = true;
            this->label5->Dock = DockStyle::Fill;
            this->label5->Location = Point(308, 29);
            this->label5->Name = L"label5";
            this->label5->Size = Drawing::Size(50, 29);
            this->label5->TabIndex = 2;
            this->label5->Text = L"Широта";
            this->label5->TextAlign = ContentAlignment::MiddleLeft;
            //
            // PhoneLongitudeNumericUpDown
            //
            this->PhoneLongitudeNumericUpDown->DecimalPlaces = 3;
            this->PhoneLongitudeNumericUpDown->Dock = DockStyle::Fill;
            this->PhoneLongitudeNumericUpDown->Location = Point(61, 32);
            this->PhoneLongitudeNumericUpDown->Maximum = Decimal(gcnew array<Int32>(4){
                180, 0, 0, 0
            });
            this->PhoneLongitudeNumericUpDown->Minimum = Decimal(gcnew array<Int32>(4){
                180, 0, 0, Int32::MinValue
            });
            this->PhoneLongitudeNumericUpDown->Name = L"PhoneLongitudeNumericUpDown";
            this->PhoneLongitudeNumericUpDown->Size = Drawing::Size(241, 23);
            this->PhoneLongitudeNumericUpDown->TabIndex = 8;
            //
            // PhoneLatitudeNumericUpDown
            //
            this->PhoneLatitudeNumericUpDown->DecimalPlaces = 3;
            this->PhoneLatitudeNumericUpDown->Dock = DockStyle::Fill;
            this->PhoneLatitudeNumericUpDown->Location = Point(364, 32);
            this->PhoneLatitudeNumericUpDown->Maximum =
                Decimal(gcnew array<Int32>(4){90, 0, 0, 0});
            this->PhoneLatitudeNumericUpDown->Minimum = Decimal(gcnew array<Int32>(4){
                90, 0, 0, Int32::MinValue
            });
            this->PhoneLatitudeNumericUpDown->Name = L"PhoneLatitudeNumericUpDown";
            this->PhoneLatitudeNumericUpDown->Size = Drawing::Size(241, 23);
            this->PhoneLatitudeNumericUpDown->TabIndex = 9;
            //
            // CreatePhoneWithBlacklistButton
            //
            this->tableLayoutPanel2->SetColumnSpan(this->CreatePhoneWithBlacklistButton, 2);
            this->CreatePhoneWithBlacklistButton->Dock = DockStyle::Fill;
            this->CreatePhoneWithBlacklistButton->Location = Point(308, 90);
            this->CreatePhoneWithBlacklistButton->Name = L"CreatePhoneWithBlacklistButton";
            this->CreatePhoneWithBlacklistButton->Size = Drawing::Size(297, 26);
            this->CreatePhoneWithBlacklistButton->TabIndex = 12;
            this->CreatePhoneWithBlacklistButton->Text = L"Создать с чёрным списком";
            this->CreatePhoneWithBlacklistButton->UseVisualStyleBackColor = true;
            this->CreatePhoneWithBlacklistButton->Click += gcnew EventHandler(
                this, &FreeControlPanelForm::CreatePhoneWithBlacklistButton_Click);
            //
            // label9
            //
            this->label9->AutoSize = true;
            this->label9->Dock = DockStyle::Fill;
            this->label9->Location = Point(3, 0);
            this->label9->Name = L"label9";
            this->label9->Size = Drawing::Size(52, 29);
            this->label9->TabIndex = 6;
            this->label9->Text = L"Номер";
            this->label9->TextAlign = ContentAlignment::MiddleLeft;
            //
            // PhoneNumberTextBox
            //
            this->tableLayoutPanel2->SetColumnSpan(this->PhoneNumberTextBox, 3);
            this->PhoneNumberTextBox->Dock = DockStyle::Fill;
            this->PhoneNumberTextBox->Location = Point(61, 3);
            this->PhoneNumberTextBox->Name = L"PhoneNumberTextBox";
            this->PhoneNumberTextBox->Size = Drawing::Size(544, 23);
            this->PhoneNumberTextBox->TabIndex = 7;
            //
            // label10
            //
            this->label10->AutoSize = true;
            this->label10->Dock = DockStyle::Fill;
            this->label10->Location = Point(3, 58);
            this->label10->Name = L"label10";
            this->label10->Size = Drawing::Size(52, 29);
            this->label10->TabIndex = 8;
            this->label10->Text = L"Заряд";
            this->label10->TextAlign = ContentAlignment::MiddleLeft;
            //
            // PhoneBatteryLevelNumericUpDown
            //
            this->tableLayoutPanel2->SetColumnSpan(this->PhoneBatteryLevelNumericUpDown, 3);
            this->PhoneBatteryLevelNumericUpDown->Dock = DockStyle::Fill;
            this->PhoneBatteryLevelNumericUpDown->Location = Point(61, 61);
            this->PhoneBatteryLevelNumericUpDown->Name = L"PhoneBatteryLevelNumericUpDown";
            this->PhoneBatteryLevelNumericUpDown->Size = Drawing::Size(544, 23);
            this->PhoneBatteryLevelNumericUpDown->TabIndex = 10;
            this->PhoneBatteryLevelNumericUpDown->Value = Decimal(gcnew array<Int32>(4){
                100, 0, 0, 0
            });
            //
            // label6
            //
            this->label6->Location = Point(13, 28);
            this->label6->Name = L"label6";
            this->label6->Size = Drawing::Size(20, 16);
            this->label6->TabIndex = 6;
            this->label6->Text = L"0";
            this->label6->TextAlign = ContentAlignment::MiddleCenter;
            //
            // label7
            //
            this->label7->Anchor = AnchorStyles::Top | AnchorStyles::Right;
            this->label7->Location = Point(606, 28);
            this->label7->Name = L"label7";
            this->label7->Size = Drawing::Size(20, 16);
            this->label7->TabIndex = 7;
            this->label7->Text = L"2";
            this->label7->TextAlign = ContentAlignment::MiddleCenter;
            //
            // FreeControlPanelForm
            //
            this->AutoScaleDimensions = SizeF(7, 15);
            this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = Drawing::Size(638, 442);
            this->Controls->Add(this->label7);
            this->Controls->Add(this->label6);
            this->Controls->Add(this->groupBox2);
            this->Controls->Add(this->groupBox1);
            this->Controls->Add(this->SimulationStopButton);
            this->Controls->Add(this->SimulationStartButton);
            this->Controls->Add(this->label1);
            this->Controls->Add(this->SimulationSpeedTrackBar);
            this->Font = (gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Regular,
                                              GraphicsUnit::Point,
                                              static_cast<Byte>(0)));
            this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
            this->Icon = (cli::safe_cast<Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = Windows::Forms::Padding(true, 3, 4, 3);
            this->MaximizeBox = false;
            this->Name = L"FreeControlPanelForm";
            this->StartPosition = FormStartPosition::CenterScreen;
            this->Text = L"Симуляция телекоммуникаций: Панель управления";
            (cli::safe_cast<ISupportInitialize^>(this->SimulationSpeedTrackBar))->EndInit();
            this->groupBox1->ResumeLayout(false);
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel1->PerformLayout();
            (cli::safe_cast<ISupportInitialize^>(this->BaseStationLongitudeNumericUpDown))->
                EndInit();
            (cli::safe_cast<ISupportInitialize^>(this->BaseStationLatitudeNumericUpDown))->
                EndInit();
            (cli::safe_cast<ISupportInitialize^>(this->BaseStationCoverageNumericUpDown))->
                EndInit();
            this->groupBox2->ResumeLayout(false);
            this->tableLayoutPanel2->ResumeLayout(false);
            this->tableLayoutPanel2->PerformLayout();
            (cli::safe_cast<ISupportInitialize^>(this->PhoneLongitudeNumericUpDown))->EndInit();
            (cli::safe_cast<ISupportInitialize^>(this->PhoneLatitudeNumericUpDown))->EndInit();
            (cli::safe_cast<ISupportInitialize^>(this->PhoneBatteryLevelNumericUpDown))->
                EndInit();
            this->ResumeLayout(false);
            this->PerformLayout();
        }
#pragma endregion
        Void SimulationStartButton_Click(Object^ sender, EventArgs^ e);
        Void SimulationStopButton_Click(Object^ sender, EventArgs^ e);
        Void CreateBaseStationButton_Click(Object^ sender, EventArgs^ e);
        Void CreatePhoneButton_Click(Object^ sender, EventArgs^ e);
        Void CreatePhoneWithBlacklistButton_Click(Object^ sender, EventArgs^ e);
        Void OnSimulationEnginePropertyChanged(Object^ sender,
                                               PropertyChangedEventArgs^ e);
    };
}
