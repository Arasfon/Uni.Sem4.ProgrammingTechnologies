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
    /// BaseStation manager
    /// </summary>
    public ref class BaseStationForm : public Form
    {
        Core::BaseStation^ _baseStation;

    public:
        BaseStationForm(Core::BaseStation^ baseStation);

    protected:
        /// <summary>
        /// Cleans up resources
        /// </summary>
        ~BaseStationForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        GroupBox^ groupBox7;

    private:
        Label^ NameLabel;

        GroupBox^ groupBox1;

        TableLayoutPanel^ tableLayoutPanel1;

        Label^ label1;

        Label^ label2;

        NumericUpDown^ LongitudeNumericUpDown;

        NumericUpDown^ LatitudeNumericUpDown;

        GroupBox^ groupBox2;

        NumericUpDown^ CoverageNumericUpDown;

        GroupBox^ groupBox3;

        NumericUpDown^ ConnectedPhonesCountNumericUpDown;

        Button^ EnableButton;

        Button^ DisableButton;

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
            ComponentResourceManager^ resources = (gcnew
                ComponentResourceManager(BaseStationForm::typeid));
            this->groupBox7 = (gcnew GroupBox());
            this->NameLabel = (gcnew Label());
            this->groupBox1 = (gcnew GroupBox());
            this->tableLayoutPanel1 = (gcnew TableLayoutPanel());
            this->label1 = (gcnew Label());
            this->label2 = (gcnew Label());
            this->LongitudeNumericUpDown = (gcnew NumericUpDown());
            this->LatitudeNumericUpDown = (gcnew NumericUpDown());
            this->groupBox2 = (gcnew GroupBox());
            this->CoverageNumericUpDown = (gcnew NumericUpDown());
            this->groupBox3 = (gcnew GroupBox());
            this->ConnectedPhonesCountNumericUpDown = (gcnew NumericUpDown());
            this->EnableButton = (gcnew Button());
            this->DisableButton = (gcnew Button());
            this->groupBox7->SuspendLayout();
            this->groupBox1->SuspendLayout();
            this->tableLayoutPanel1->SuspendLayout();
            (cli::safe_cast<ISupportInitialize^>(this->LongitudeNumericUpDown))->BeginInit();
            (cli::safe_cast<ISupportInitialize^>(this->LatitudeNumericUpDown))->BeginInit();
            this->groupBox2->SuspendLayout();
            (cli::safe_cast<ISupportInitialize^>(this->CoverageNumericUpDown))->BeginInit();
            this->groupBox3->SuspendLayout();
            (cli::safe_cast<ISupportInitialize^>(this->ConnectedPhonesCountNumericUpDown))->
                BeginInit();
            this->SuspendLayout();
            // 
            // groupBox7
            // 
            this->groupBox7->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->groupBox7->Controls->Add(this->NameLabel);
            this->groupBox7->Location = Point(12, 12);
            this->groupBox7->Name = L"groupBox7";
            this->groupBox7->Size = Drawing::Size(521, 42);
            this->groupBox7->TabIndex = 5;
            this->groupBox7->TabStop = false;
            this->groupBox7->Text = L"Название";
            // 
            // NameLabel
            // 
            this->NameLabel->Dock = DockStyle::Fill;
            this->NameLabel->Location = Point(3, 19);
            this->NameLabel->Name = L"NameLabel";
            this->NameLabel->Size = Drawing::Size(515, 20);
            this->NameLabel->TabIndex = 0;
            // 
            // groupBox1
            // 
            this->groupBox1->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->groupBox1->Controls->Add(this->tableLayoutPanel1);
            this->groupBox1->Location = Point(12, 60);
            this->groupBox1->Name = L"groupBox1";
            this->groupBox1->Size = Drawing::Size(521, 51);
            this->groupBox1->TabIndex = 4;
            this->groupBox1->TabStop = false;
            this->groupBox1->Text = L"Местоположение";
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
            this->tableLayoutPanel1->Controls->Add(this->label1, 0, 0);
            this->tableLayoutPanel1->Controls->Add(this->label2, 2, 0);
            this->tableLayoutPanel1->Controls->Add(this->LongitudeNumericUpDown, 1, 0);
            this->tableLayoutPanel1->Controls->Add(this->LatitudeNumericUpDown, 3, 0);
            this->tableLayoutPanel1->Dock = DockStyle::Fill;
            this->tableLayoutPanel1->Location = Point(3, 19);
            this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
            this->tableLayoutPanel1->RowCount = 1;
            this->tableLayoutPanel1->RowStyles->Add((gcnew RowStyle()));
            this->tableLayoutPanel1->Size = Drawing::Size(515, 29);
            this->tableLayoutPanel1->TabIndex = 0;
            // 
            // label1
            // 
            this->label1->AutoSize = true;
            this->label1->Dock = DockStyle::Fill;
            this->label1->Location = Point(3, 0);
            this->label1->Name = L"label1";
            this->label1->Size = Drawing::Size(52, 29);
            this->label1->TabIndex = 0;
            this->label1->Text = L"Долгота";
            this->label1->TextAlign = ContentAlignment::MiddleLeft;
            // 
            // label2
            // 
            this->label2->AutoSize = true;
            this->label2->Dock = DockStyle::Fill;
            this->label2->Location = Point(261, 0);
            this->label2->Name = L"label2";
            this->label2->Size = Drawing::Size(50, 29);
            this->label2->TabIndex = 1;
            this->label2->Text = L"Широта";
            this->label2->TextAlign = ContentAlignment::MiddleLeft;
            // 
            // LongitudeNumericUpDown
            // 
            this->LongitudeNumericUpDown->DecimalPlaces = 3;
            this->LongitudeNumericUpDown->Dock = DockStyle::Fill;
            this->LongitudeNumericUpDown->Location = Point(61, 3);
            this->LongitudeNumericUpDown->Maximum = Decimal(gcnew array<Int32>(4){180, 0, 0, 0});
            this->LongitudeNumericUpDown->Minimum = Decimal(gcnew array<Int32>(4){
                180, 0, 0, Int32::MinValue
            });
            this->LongitudeNumericUpDown->Name = L"LongitudeNumericUpDown";
            this->LongitudeNumericUpDown->ReadOnly = true;
            this->LongitudeNumericUpDown->Size = Drawing::Size(194, 23);
            this->LongitudeNumericUpDown->TabIndex = 2;
            // 
            // LatitudeNumericUpDown
            // 
            this->LatitudeNumericUpDown->DecimalPlaces = 3;
            this->LatitudeNumericUpDown->Dock = DockStyle::Fill;
            this->LatitudeNumericUpDown->Location = Point(317, 3);
            this->LatitudeNumericUpDown->Maximum = Decimal(gcnew array<Int32>(4){90, 0, 0, 0});
            this->LatitudeNumericUpDown->Minimum = Decimal(gcnew array<Int32>(4){
                90, 0, 0, Int32::MinValue
            });
            this->LatitudeNumericUpDown->Name = L"LatitudeNumericUpDown";
            this->LatitudeNumericUpDown->ReadOnly = true;
            this->LatitudeNumericUpDown->Size = Drawing::Size(195, 23);
            this->LatitudeNumericUpDown->TabIndex = 3;
            // 
            // groupBox2
            // 
            this->groupBox2->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->groupBox2->Controls->Add(this->CoverageNumericUpDown);
            this->groupBox2->Location = Point(12, 117);
            this->groupBox2->Name = L"groupBox2";
            this->groupBox2->Size = Drawing::Size(521, 51);
            this->groupBox2->TabIndex = 6;
            this->groupBox2->TabStop = false;
            this->groupBox2->Text = L"Радиус покрытия (км)";
            // 
            // CoverageNumericUpDown
            // 
            this->CoverageNumericUpDown->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->CoverageNumericUpDown->DecimalPlaces = 3;
            this->CoverageNumericUpDown->Location = Point(6, 22);
            this->CoverageNumericUpDown->Maximum = Decimal(gcnew array<Int32>(4){-1, -1, -1, 0});
            this->CoverageNumericUpDown->Name = L"CoverageNumericUpDown";
            this->CoverageNumericUpDown->ReadOnly = true;
            this->CoverageNumericUpDown->Size = Drawing::Size(509, 23);
            this->CoverageNumericUpDown->TabIndex = 0;
            // 
            // groupBox3
            // 
            this->groupBox3->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->groupBox3->Controls->Add(this->ConnectedPhonesCountNumericUpDown);
            this->groupBox3->Location = Point(12, 174);
            this->groupBox3->Name = L"groupBox3";
            this->groupBox3->Size = Drawing::Size(521, 51);
            this->groupBox3->TabIndex = 7;
            this->groupBox3->TabStop = false;
            this->groupBox3->Text = L"Кол-во подключённых телефонов";
            // 
            // ConnectedPhonesCountNumericUpDown
            // 
            this->ConnectedPhonesCountNumericUpDown->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->ConnectedPhonesCountNumericUpDown->Location = Point(6, 22);
            this->ConnectedPhonesCountNumericUpDown->Maximum = Decimal(gcnew array<Int32>(4){
                -1, -1, -1, 0
            });
            this->ConnectedPhonesCountNumericUpDown->Name = L"ConnectedPhonesCountNumericUpDown";
            this->ConnectedPhonesCountNumericUpDown->ReadOnly = true;
            this->ConnectedPhonesCountNumericUpDown->Size = Drawing::Size(509, 23);
            this->ConnectedPhonesCountNumericUpDown->TabIndex = 0;
            // 
            // EnableButton
            // 
            this->EnableButton->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->EnableButton->Location = Point(12, 231);
            this->EnableButton->Name = L"EnableButton";
            this->EnableButton->Size = Drawing::Size(521, 26);
            this->EnableButton->TabIndex = 8;
            this->EnableButton->Text = L"Включить";
            this->EnableButton->UseVisualStyleBackColor = true;
            this->EnableButton->Click += gcnew EventHandler(this, &BaseStationForm::EnableButton_Click);
            // 
            // DisableButton
            // 
            this->DisableButton->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->DisableButton->Enabled = false;
            this->DisableButton->Location = Point(12, 263);
            this->DisableButton->Name = L"DisableButton";
            this->DisableButton->Size = Drawing::Size(521, 26);
            this->DisableButton->TabIndex = 9;
            this->DisableButton->Text = L"Выключить";
            this->DisableButton->UseVisualStyleBackColor = true;
            this->DisableButton->Click += gcnew EventHandler(this, &BaseStationForm::DisableButton_Click);
            // 
            // BaseStationForm
            // 
            this->AutoScaleDimensions = SizeF(7, 15);
            this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = Drawing::Size(545, 301);
            this->Controls->Add(this->DisableButton);
            this->Controls->Add(this->EnableButton);
            this->Controls->Add(this->groupBox3);
            this->Controls->Add(this->groupBox2);
            this->Controls->Add(this->groupBox7);
            this->Controls->Add(this->groupBox1);
            this->Font = (gcnew Drawing::Font(L"Segoe UI", 9, FontStyle::Regular,
                                              GraphicsUnit::Point,
                                              static_cast<Byte>(0)));
            this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
            this->Icon = (cli::safe_cast<Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = Windows::Forms::Padding(true, 3, 4, 3);
            this->MaximizeBox = false;
            this->Name = L"BaseStationForm";
            this->StartPosition = FormStartPosition::CenterScreen;
            this->Text = L"Симуляция телекоммуникаций: Базовая станция";
            this->FormClosed += gcnew FormClosedEventHandler(
                this, &BaseStationForm::BaseStationForm_FormClosed);
            this->groupBox7->ResumeLayout(false);
            this->groupBox1->ResumeLayout(false);
            this->tableLayoutPanel1->ResumeLayout(false);
            this->tableLayoutPanel1->PerformLayout();
            (cli::safe_cast<ISupportInitialize^>(this->LongitudeNumericUpDown))->EndInit();
            (cli::safe_cast<ISupportInitialize^>(this->LatitudeNumericUpDown))->EndInit();
            this->groupBox2->ResumeLayout(false);
            (cli::safe_cast<ISupportInitialize^>(this->CoverageNumericUpDown))->EndInit();
            this->groupBox3->ResumeLayout(false);
            (cli::safe_cast<ISupportInitialize^>(this->ConnectedPhonesCountNumericUpDown))->
                EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion

        Void BaseStationForm_FormClosed(Object^ sender, FormClosedEventArgs^ e);

        Void OnLongitudeFormat(Object^ sender, ConvertEventArgs^ e);

        Void OnLatitudeFormat(Object^ sender, ConvertEventArgs^ e);

        Void EnableButton_Click(Object^ sender, EventArgs^ e);

        Void DisableButton_Click(Object^ sender, EventArgs^ e);

        Void OnBaseStationPropertyChanged(Object^ sender, PropertyChangedEventArgs^ e);
    };
}
