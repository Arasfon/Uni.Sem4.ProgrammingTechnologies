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
    /// Phone manager
    /// </summary>
    public ref class PhoneForm : public Form
    {
    private:
        System::Windows::Forms::GroupBox^ groupBox9;
        System::Windows::Forms::NumericUpDown^ BatteryLevelNumericUpDown;

    private:
        Core::Phone^ _phone;

    public:
        PhoneForm(Core::Phone^ phone, bool handleAnswer);

    protected:
        /// <summary>
        /// Cleans up resources
        /// </summary>
        ~PhoneForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel1;

    private:
        System::Windows::Forms::Label^ label1;

    private:
        System::Windows::Forms::Label^ label2;

    private:
        System::Windows::Forms::NumericUpDown^ LongitudeNumericUpDown;

    private:
        System::Windows::Forms::NumericUpDown^ LatitudeNumericUpDown;

    private:
        System::Windows::Forms::GroupBox^ groupBox1;

    private:
        System::Windows::Forms::GroupBox^ groupBox2;

    private:
        System::Windows::Forms::GroupBox^ groupBox3;

    private:
        System::Windows::Forms::GroupBox^ groupBox4;

    private:


    private:
        System::Windows::Forms::Label^ StateLabel;

    private:
        System::Windows::Forms::Label^ CallStateLabel;

    private:
        System::Windows::Forms::Label^ InCallWithLabel;

    private:


    private:
        System::Windows::Forms::Button^ TurnOnButton;

    private:
        System::Windows::Forms::Button^ TurnOffButton;

    private:
        System::Windows::Forms::Button^ ConnectToBaseStationButton;

    private:
        System::Windows::Forms::Button^ DisconnectFromBaseStationButton;

    private:
        System::Windows::Forms::GroupBox^ groupBox6;

    private:
        System::Windows::Forms::TableLayoutPanel^ tableLayoutPanel2;

    private:
        System::Windows::Forms::Label^ label7;

    private:
        System::Windows::Forms::Button^ MakeCallButton;

    private:
        System::Windows::Forms::TextBox^ CalleeNumberTextBox;

    private:
        System::Windows::Forms::GroupBox^ groupBox7;

    private:
        System::Windows::Forms::Label^ NumberLabel;

    private:
        System::Windows::Forms::GroupBox^ groupBox8;

    private:
        System::Windows::Forms::Label^ ConnectedBaseStationNameLabel;

    private:
        System::Windows::Forms::Button^ EndCallButton;

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
                System::ComponentModel::ComponentResourceManager(PhoneForm::typeid));
            this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label1 = (gcnew System::Windows::Forms::Label());
            this->label2 = (gcnew System::Windows::Forms::Label());
            this->LongitudeNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
            this->LatitudeNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
            this->groupBox1 = (gcnew System::Windows::Forms::GroupBox());
            this->groupBox2 = (gcnew System::Windows::Forms::GroupBox());
            this->StateLabel = (gcnew System::Windows::Forms::Label());
            this->groupBox3 = (gcnew System::Windows::Forms::GroupBox());
            this->CallStateLabel = (gcnew System::Windows::Forms::Label());
            this->groupBox4 = (gcnew System::Windows::Forms::GroupBox());
            this->InCallWithLabel = (gcnew System::Windows::Forms::Label());
            this->TurnOnButton = (gcnew System::Windows::Forms::Button());
            this->TurnOffButton = (gcnew System::Windows::Forms::Button());
            this->ConnectToBaseStationButton = (gcnew System::Windows::Forms::Button());
            this->DisconnectFromBaseStationButton = (gcnew System::Windows::Forms::Button());
            this->groupBox6 = (gcnew System::Windows::Forms::GroupBox());
            this->tableLayoutPanel2 = (gcnew System::Windows::Forms::TableLayoutPanel());
            this->label7 = (gcnew System::Windows::Forms::Label());
            this->MakeCallButton = (gcnew System::Windows::Forms::Button());
            this->CalleeNumberTextBox = (gcnew System::Windows::Forms::TextBox());
            this->EndCallButton = (gcnew System::Windows::Forms::Button());
            this->groupBox7 = (gcnew System::Windows::Forms::GroupBox());
            this->NumberLabel = (gcnew System::Windows::Forms::Label());
            this->groupBox8 = (gcnew System::Windows::Forms::GroupBox());
            this->ConnectedBaseStationNameLabel = (gcnew System::Windows::Forms::Label());
            this->groupBox9 = (gcnew System::Windows::Forms::GroupBox());
            this->BatteryLevelNumericUpDown = (gcnew System::Windows::Forms::NumericUpDown());
            this->tableLayoutPanel1->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LongitudeNumericUpDown))->BeginInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LatitudeNumericUpDown))->BeginInit();
            this->groupBox1->SuspendLayout();
            this->groupBox2->SuspendLayout();
            this->groupBox3->SuspendLayout();
            this->groupBox4->SuspendLayout();
            this->groupBox6->SuspendLayout();
            this->tableLayoutPanel2->SuspendLayout();
            this->groupBox7->SuspendLayout();
            this->groupBox8->SuspendLayout();
            this->groupBox9->SuspendLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BatteryLevelNumericUpDown))->BeginInit();
            this->SuspendLayout();
            //
            // tableLayoutPanel1
            //
            this->tableLayoutPanel1->ColumnCount = 4;
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->tableLayoutPanel1->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                50)));
            this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->label2, 2, 0);
            this->tableLayoutPanel1->Controls->Add(this->LongitudeNumericUpDown, 1, 0);
            this->tableLayoutPanel1->Controls->Add(this->LatitudeNumericUpDown, 3, 0);
            this->tableLayoutPanel1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel1->Location = System::Drawing::Point(3, 19);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 1;
            this->tableLayoutPanel1->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel1->Size = System::Drawing::Size(466, 29);
            this->tableLayoutPanel1->TabIndex = 0;
            //
            // label1
            //
            this->label1->AutoSize = true;
            this->label1->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label1->Location = System::Drawing::Point(3, 0);
            this->label1->Name = L"label1";
            this->label1->Size = System::Drawing::Size(52, 29);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Долгота";
            this->label1->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            //
            // label2
            //
            this->label2->AutoSize = true;
            this->label2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label2->Location = System::Drawing::Point(237, 0);
            this->label2->Name = L"label2";
            this->label2->Size = System::Drawing::Size(50, 29);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Широта";
            this->label2->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            //
            // LongitudeNumericUpDown
            //
            this->LongitudeNumericUpDown->DecimalPlaces = 3;
            this->LongitudeNumericUpDown->Dock = System::Windows::Forms::DockStyle::Fill;
            this->LongitudeNumericUpDown->Location = System::Drawing::Point(61, 3);
            this->LongitudeNumericUpDown->Maximum = System::Decimal(gcnew cli::array<System::Int32>(4){180, 0, 0, 0});
            this->LongitudeNumericUpDown->Minimum = System::Decimal(gcnew cli::array<System::Int32>(4){
                180, 0, 0, System::Int32::MinValue
            });
            this->LongitudeNumericUpDown->Name = L"LongitudeNumericUpDown";
            this->LongitudeNumericUpDown->ReadOnly = true;
            this->LongitudeNumericUpDown->Size = System::Drawing::Size(170, 23);
            this->LongitudeNumericUpDown->TabIndex = 2;
            //
            // LatitudeNumericUpDown
            //
            this->LatitudeNumericUpDown->DecimalPlaces = 3;
            this->LatitudeNumericUpDown->Dock = System::Windows::Forms::DockStyle::Fill;
            this->LatitudeNumericUpDown->Location = System::Drawing::Point(293, 3);
            this->LatitudeNumericUpDown->Maximum = System::Decimal(gcnew cli::array<System::Int32>(4){90, 0, 0, 0});
            this->LatitudeNumericUpDown->Minimum = System::Decimal(gcnew cli::array<System::Int32>(4){
                90, 0, 0, System::Int32::MinValue
            });
            this->LatitudeNumericUpDown->Name = L"LatitudeNumericUpDown";
            this->LatitudeNumericUpDown->ReadOnly = true;
            this->LatitudeNumericUpDown->Size = System::Drawing::Size(170, 23);
            this->LatitudeNumericUpDown->TabIndex = 3;
            //
            // groupBox1
            //
            this->groupBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox1->Controls->Add(this->tableLayoutPanel1);
            this->groupBox1->Location = System::Drawing::Point(12, 60);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = System::Drawing::Size(472, 51);
            this->groupBox1->TabIndex = 1;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Местоположение";
            //
            // groupBox2
            //
            this->groupBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox2->Controls->Add(this->StateLabel);
            this->groupBox2->Location = System::Drawing::Point(12, 117);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = System::Drawing::Size(472, 42);
            this->groupBox2->TabIndex = 2;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"Состояние";
            //
            // StateLabel
            //
            this->StateLabel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->StateLabel->Location = System::Drawing::Point(3, 19);
            this->StateLabel->Name = L"StateLabel";
            this->StateLabel->Size = System::Drawing::Size(466, 20);
            this->StateLabel->TabIndex = 0;
            //
            // groupBox3
            //
            this->groupBox3->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox3->Controls->Add(this->CallStateLabel);
            this->groupBox3->Location = System::Drawing::Point(12, 165);
            this->groupBox3->Name = L"groupBox3";
            this->groupBox3->Size = System::Drawing::Size(472, 42);
            this->groupBox3->TabIndex = 3;
            this->groupBox3->TabStop = false;
            this->groupBox3->Text = L"Состояние звонка";
            //
            // CallStateLabel
            //
            this->CallStateLabel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->CallStateLabel->Location = System::Drawing::Point(3, 19);
            this->CallStateLabel->Name = L"CallStateLabel";
            this->CallStateLabel->Size = System::Drawing::Size(466, 20);
            this->CallStateLabel->TabIndex = 0;
            //
            // groupBox4
            //
            this->groupBox4->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox4->Controls->Add(this->InCallWithLabel);
            this->groupBox4->Location = System::Drawing::Point(12, 213);
            this->groupBox4->Name = L"groupBox4";
            this->groupBox4->Size = System::Drawing::Size(472, 42);
            this->groupBox4->TabIndex = 4;
            this->groupBox4->TabStop = false;
            this->groupBox4->Text = L"Находится в звонке с";
            //
            // InCallWithLabel
            //
            this->InCallWithLabel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->InCallWithLabel->Location = System::Drawing::Point(3, 19);
            this->InCallWithLabel->Name = L"InCallWithLabel";
            this->InCallWithLabel->Size = System::Drawing::Size(466, 20);
            this->InCallWithLabel->TabIndex = 0;
            //
            // TurnOnButton
            //
            this->TurnOnButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->TurnOnButton->Location = System::Drawing::Point(12, 366);
            this->TurnOnButton->Name = L"TurnOnButton";
            this->TurnOnButton->Size = System::Drawing::Size(472, 26);
            this->TurnOnButton->TabIndex = 6;
            this->TurnOnButton->Text = L"Включить телефон";
            this->TurnOnButton->UseVisualStyleBackColor = true;
            this->TurnOnButton->Click += gcnew System::EventHandler(this, &PhoneForm::TurnOnButton_Click);
            //
            // TurnOffButton
            //
            this->TurnOffButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->TurnOffButton->Enabled = false;
            this->TurnOffButton->Location = System::Drawing::Point(12, 398);
            this->TurnOffButton->Name = L"TurnOffButton";
            this->TurnOffButton->Size = System::Drawing::Size(472, 26);
            this->TurnOffButton->TabIndex = 7;
            this->TurnOffButton->Text = L"Выключить телефон";
            this->TurnOffButton->UseVisualStyleBackColor = true;
            this->TurnOffButton->Click += gcnew System::EventHandler(this, &PhoneForm::TurnOffButton_Click);
            //
            // ConnectToBaseStationButton
            //
            this->ConnectToBaseStationButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->ConnectToBaseStationButton->Enabled = false;
            this->ConnectToBaseStationButton->Location = System::Drawing::Point(12, 430);
            this->ConnectToBaseStationButton->Name = L"ConnectToBaseStationButton";
            this->ConnectToBaseStationButton->Size = System::Drawing::Size(472, 26);
            this->ConnectToBaseStationButton->TabIndex = 8;
            this->ConnectToBaseStationButton->Text = L"Подключиться к базовой станции";
            this->ConnectToBaseStationButton->UseVisualStyleBackColor = true;
            this->ConnectToBaseStationButton->Click += gcnew System::EventHandler(
                this, &PhoneForm::ConnectToBaseStationButton_Click);
            //
            // DisconnectFromBaseStationButton
            //
            this->DisconnectFromBaseStationButton->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->DisconnectFromBaseStationButton->Enabled = false;
            this->DisconnectFromBaseStationButton->Location = System::Drawing::Point(12, 462);
            this->DisconnectFromBaseStationButton->Name = L"DisconnectFromBaseStationButton";
            this->DisconnectFromBaseStationButton->Size = System::Drawing::Size(472, 26);
            this->DisconnectFromBaseStationButton->TabIndex = 9;
            this->DisconnectFromBaseStationButton->Text = L"Отключиться от базовой станции";
            this->DisconnectFromBaseStationButton->UseVisualStyleBackColor = true;
            this->DisconnectFromBaseStationButton->Click += gcnew System::EventHandler(
                this, &PhoneForm::DisconnectFromBaseStationButton_Click);
            //
            // groupBox6
            //
            this->groupBox6->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox6->Controls->Add(this->tableLayoutPanel2);
            this->groupBox6->Location = System::Drawing::Point(12, 494);
            this->groupBox6->Name = L"groupBox6";
            this->groupBox6->Size = System::Drawing::Size(472, 115);
            this->groupBox6->TabIndex = 10;
            this->groupBox6->TabStop = false;
            this->groupBox6->Text = L"Звонки";
            //
            // tableLayoutPanel2
            //
            this->tableLayoutPanel2->ColumnCount = 2;
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle()));
            this->tableLayoutPanel2->ColumnStyles->Add((gcnew System::Windows::Forms::ColumnStyle(
                System::Windows::Forms::SizeType::Percent,
                100)));
            this->tableLayoutPanel2->Controls->Add(this->label7, 0, 0);
            this->tableLayoutPanel2->Controls->Add(this->MakeCallButton, 0, 1);
            this->tableLayoutPanel2->Controls->Add(this->CalleeNumberTextBox, 1, 0);
            this->tableLayoutPanel2->Controls->Add(this->EndCallButton, 0, 2);
            this->tableLayoutPanel2->Dock = System::Windows::Forms::DockStyle::Fill;
            this->tableLayoutPanel2->Location = System::Drawing::Point(3, 19);
            this->tableLayoutPanel2->Name = L"tableLayoutPanel2";
            this->tableLayoutPanel2->RowCount = 3;
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel2->RowStyles->Add((gcnew System::Windows::Forms::RowStyle()));
            this->tableLayoutPanel2->Size = System::Drawing::Size(466, 93);
            this->tableLayoutPanel2->TabIndex = 0;
            //
            // label7
            //
            this->label7->AutoSize = true;
            this->label7->Dock = System::Windows::Forms::DockStyle::Fill;
            this->label7->Location = System::Drawing::Point(3, 0);
            this->label7->Name = L"label7";
            this->label7->Size = System::Drawing::Size(174, 29);
            this->label7->TabIndex = 0;
            this->label7->Text = L"Номер телефона собеседника";
            this->label7->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
            //
            // MakeCallButton
            //
            this->tableLayoutPanel2->SetColumnSpan(this->MakeCallButton, 2);
            this->MakeCallButton->Dock = System::Windows::Forms::DockStyle::Fill;
            this->MakeCallButton->Enabled = false;
            this->MakeCallButton->Location = System::Drawing::Point(3, 32);
            this->MakeCallButton->Name = L"MakeCallButton";
            this->MakeCallButton->Size = System::Drawing::Size(460, 26);
            this->MakeCallButton->TabIndex = 3;
            this->MakeCallButton->Text = L"Позвонить";
            this->MakeCallButton->UseVisualStyleBackColor = true;
            this->MakeCallButton->Click += gcnew System::EventHandler(this, &PhoneForm::MakeCallButton_Click);
            //
            // CalleeNumberTextBox
            //
            this->CalleeNumberTextBox->Dock = System::Windows::Forms::DockStyle::Fill;
            this->CalleeNumberTextBox->Enabled = false;
            this->CalleeNumberTextBox->Location = System::Drawing::Point(183, 3);
            this->CalleeNumberTextBox->Name = L"CalleeNumberTextBox";
            this->CalleeNumberTextBox->Size = System::Drawing::Size(280, 23);
            this->CalleeNumberTextBox->TabIndex = 4;
            //
            // EndCallButton
            //
            this->tableLayoutPanel2->SetColumnSpan(this->EndCallButton, 2);
            this->EndCallButton->Dock = System::Windows::Forms::DockStyle::Fill;
            this->EndCallButton->Enabled = false;
            this->EndCallButton->Location = System::Drawing::Point(3, 64);
            this->EndCallButton->Name = L"EndCallButton";
            this->EndCallButton->Size = System::Drawing::Size(460, 26);
            this->EndCallButton->TabIndex = 5;
            this->EndCallButton->Text = L"Отменить звонок";
            this->EndCallButton->UseVisualStyleBackColor = true;
            this->EndCallButton->Click += gcnew System::EventHandler(this, &PhoneForm::EndCallButton_Click);
            //
            // groupBox7
            //
            this->groupBox7->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox7->Controls->Add(this->NumberLabel);
            this->groupBox7->Location = System::Drawing::Point(12, 12);
            this->groupBox7->Name = L"groupBox7";
            this->groupBox7->Size = System::Drawing::Size(472, 42);
            this->groupBox7->TabIndex = 3;
            this->groupBox7->TabStop = false;
            this->groupBox7->Text = L"Номер телефона";
            //
            // NumberLabel
            //
            this->NumberLabel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->NumberLabel->Location = System::Drawing::Point(3, 19);
            this->NumberLabel->Name = L"NumberLabel";
            this->NumberLabel->Size = System::Drawing::Size(466, 20);
            this->NumberLabel->TabIndex = 0;
            //
            // groupBox8
            //
            this->groupBox8->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox8->Controls->Add(this->ConnectedBaseStationNameLabel);
            this->groupBox8->Location = System::Drawing::Point(12, 318);
            this->groupBox8->Name = L"groupBox8";
            this->groupBox8->Size = System::Drawing::Size(472, 42);
            this->groupBox8->TabIndex = 11;
            this->groupBox8->TabStop = false;
            this->groupBox8->Text = L"Название подключённой базовой станции";
            //
            // ConnectedBaseStationNameLabel
            //
            this->ConnectedBaseStationNameLabel->Dock = System::Windows::Forms::DockStyle::Fill;
            this->ConnectedBaseStationNameLabel->Location = System::Drawing::Point(3, 19);
            this->ConnectedBaseStationNameLabel->Name = L"ConnectedBaseStationNameLabel";
            this->ConnectedBaseStationNameLabel->Size = System::Drawing::Size(466, 20);
            this->ConnectedBaseStationNameLabel->TabIndex = 0;
            //
            // groupBox9
            //
            this->groupBox9->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->groupBox9->Controls->Add(this->BatteryLevelNumericUpDown);
            this->groupBox9->Location = System::Drawing::Point(12, 261);
            this->groupBox9->Name = L"groupBox9";
            this->groupBox9->Size = System::Drawing::Size(472, 51);
            this->groupBox9->TabIndex = 12;
            this->groupBox9->TabStop = false;
            this->groupBox9->Text = L"Процент заряда батареи";
            //
            // BatteryLevelNumericUpDown
            //
            this->BatteryLevelNumericUpDown->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((
                    System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->BatteryLevelNumericUpDown->DecimalPlaces = 3;
            this->BatteryLevelNumericUpDown->Location = System::Drawing::Point(6, 22);
            this->BatteryLevelNumericUpDown->Name = L"BatteryLevelNumericUpDown";
            this->BatteryLevelNumericUpDown->ReadOnly = true;
            this->BatteryLevelNumericUpDown->Size = System::Drawing::Size(460, 23);
            this->BatteryLevelNumericUpDown->TabIndex = 0;
            //
            // PhoneForm
            //
            this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(496, 621);
            this->Controls->Add(this->groupBox9);
            this->Controls->Add(this->groupBox8);
            this->Controls->Add(this->groupBox7);
            this->Controls->Add(this->groupBox6);
            this->Controls->Add(this->DisconnectFromBaseStationButton);
            this->Controls->Add(this->ConnectToBaseStationButton);
            this->Controls->Add(this->TurnOffButton);
            this->Controls->Add(this->TurnOnButton);
            this->Controls->Add(this->groupBox4);
            this->Controls->Add(this->groupBox3);
            this->Controls->Add(this->groupBox2);
            this->Controls->Add(this->groupBox1);
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular,
                                                      System::Drawing::GraphicsUnit::Point,
                                                      static_cast<System::Byte>(0)));
            this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->MaximizeBox = false;
            this->Name = L"PhoneForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Симуляция телекоммуникаций: Телефон";
            this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(
                this, &PhoneForm::PhoneForm_FormClosed);
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel1->PerformLayout();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LongitudeNumericUpDown))->EndInit();
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->LatitudeNumericUpDown))->EndInit();
            this->groupBox1->ResumeLayout(false);
            this->groupBox2->ResumeLayout(false);
            this->groupBox3->ResumeLayout(false);
            this->groupBox4->ResumeLayout(false);
            this->groupBox6->ResumeLayout(false);
            this->tableLayoutPanel2->ResumeLayout(false);
            this->tableLayoutPanel2->PerformLayout();
            this->groupBox7->ResumeLayout(false);
            this->groupBox8->ResumeLayout(false);
            this->groupBox9->ResumeLayout(false);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->BatteryLevelNumericUpDown))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        System::Void PhoneForm_FormClosed(System::Object^ sender, System::Windows::Forms::FormClosedEventArgs^ e);

    private:
        System::Void OnLongitudeFormat(System::Object^ sender, System::Windows::Forms::ConvertEventArgs^ e);

    private:
        System::Void OnLatitudeFormat(System::Object^ sender, System::Windows::Forms::ConvertEventArgs^ e);

    private:
        System::Void TurnOnButton_Click(System::Object^ sender, System::EventArgs^ e);

    private:
        System::Void TurnOffButton_Click(System::Object^ sender, System::EventArgs^ e);

    private:
        System::Void ConnectToBaseStationButton_Click(System::Object^ sender, System::EventArgs^ e);

    private:
        System::Void DisconnectFromBaseStationButton_Click(System::Object^ sender, System::EventArgs^ e);

    private:
        System::Void MakeCallButton_Click(System::Object^ sender, System::EventArgs^ e);

    private:
        System::Void _MakeCallButtonClickContinuation(Threading::Tasks::Task<Core::CallResult>^ task);

    private:
        System::Void EndCallButton_Click(System::Object^ sender, System::EventArgs^ e);

    private:
        System::Threading::Tasks::Task^ OnCallReceived(System::Object^ sender,
                                                       TelecommsSimulation::Core::CallEventArgs^ e);

    private:
        System::Void OnPhonePropertyChanged(System::Object^ sender,
                                            System::ComponentModel::PropertyChangedEventArgs^ e);
    };
}
