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
    /// PhoneWithBlacklist's blacklist manager
    /// </summary>
    public ref class PhoneBlacklistForm : public Form
    {
        Core::PhoneWithBlacklist^ _phoneWithBlacklist;

    public:
        PhoneBlacklistForm(Core::PhoneWithBlacklist^ phoneWithBlacklist);

    protected:
        /// <summary>
        /// Cleans up resources
        /// </summary>
        ~PhoneBlacklistForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        GroupBox^ groupBox7;

        Label^ NumberLabel;

        GroupBox^ groupBox9;

        Button^ RemoveSelectedFromBlacklistButton;

        ListBox^ BlacklistListBox;

        GroupBox^ groupBox10;

        Button^ AddToBlacklistButton;

        TextBox^ AddToBlacklistNumberTextBox;

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
            auto resources = (gcnew
                ComponentResourceManager(PhoneBlacklistForm::typeid));
            this->groupBox7 = (gcnew GroupBox());
            this->NumberLabel = (gcnew Label());
            this->groupBox9 = (gcnew GroupBox());
            this->RemoveSelectedFromBlacklistButton = (gcnew Button());
            this->BlacklistListBox = (gcnew ListBox());
            this->groupBox10 = (gcnew GroupBox());
            this->AddToBlacklistButton = (gcnew Button());
            this->AddToBlacklistNumberTextBox = (gcnew TextBox());
            this->groupBox7->SuspendLayout();
            this->groupBox9->SuspendLayout();
            this->groupBox10->SuspendLayout();
            this->SuspendLayout();
            // 
            // groupBox7
            // 
            this->groupBox7->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->groupBox7->Controls->Add(this->NumberLabel);
            this->groupBox7->Location = Point(12, 12);
            this->groupBox7->Name = L"groupBox7";
            this->groupBox7->Size = Drawing::Size(472, 42);
            this->groupBox7->TabIndex = 15;
            this->groupBox7->TabStop = false;
            this->groupBox7->Text = L"Номер телефона";
            // 
            // NumberLabel
            // 
            this->NumberLabel->Dock = DockStyle::Fill;
            this->NumberLabel->Location = Point(3, 16);
            this->NumberLabel->Name = L"NumberLabel";
            this->NumberLabel->Size = Drawing::Size(466, 23);
            this->NumberLabel->TabIndex = 0;
            // 
            // groupBox9
            // 
            this->groupBox9->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->groupBox9->Controls->Add(this->RemoveSelectedFromBlacklistButton);
            this->groupBox9->Controls->Add(this->BlacklistListBox);
            this->groupBox9->Controls->Add(this->groupBox10);
            this->groupBox9->Location = Point(12, 60);
            this->groupBox9->Name = L"groupBox9";
            this->groupBox9->Size = Drawing::Size(472, 288);
            this->groupBox9->TabIndex = 25;
            this->groupBox9->TabStop = false;
            this->groupBox9->Text = L"Чёрный список";
            // 
            // RemoveSelectedFromBlacklistButton
            // 
            this->RemoveSelectedFromBlacklistButton->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->RemoveSelectedFromBlacklistButton->Location = Point(6, 256);
            this->RemoveSelectedFromBlacklistButton->Name = L"RemoveSelectedFromBlacklistButton";
            this->RemoveSelectedFromBlacklistButton->Size = Drawing::Size(460, 26);
            this->RemoveSelectedFromBlacklistButton->TabIndex = 2;
            this->RemoveSelectedFromBlacklistButton->Text = L"Удалить выбранный номер телефона";
            this->RemoveSelectedFromBlacklistButton->UseVisualStyleBackColor = true;
            this->RemoveSelectedFromBlacklistButton->Click += gcnew EventHandler(
                this, &PhoneBlacklistForm::RemoveSelectedFromBlacklistButton_Click);
            // 
            // BlacklistListBox
            // 
            this->BlacklistListBox->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->BlacklistListBox->FormattingEnabled = true;
            this->BlacklistListBox->Location = Point(6, 111);
            this->BlacklistListBox->Name = L"BlacklistListBox";
            this->BlacklistListBox->Size = Drawing::Size(460, 134);
            this->BlacklistListBox->TabIndex = 1;
            // 
            // groupBox10
            // 
            this->groupBox10->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->groupBox10->Controls->Add(this->AddToBlacklistButton);
            this->groupBox10->Controls->Add(this->AddToBlacklistNumberTextBox);
            this->groupBox10->Location = Point(6, 22);
            this->groupBox10->Name = L"groupBox10";
            this->groupBox10->Size = Drawing::Size(460, 83);
            this->groupBox10->TabIndex = 0;
            this->groupBox10->TabStop = false;
            this->groupBox10->Text = L"Добавить номер телефона";
            // 
            // AddToBlacklistButton
            // 
            this->AddToBlacklistButton->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->AddToBlacklistButton->Location = Point(6, 51);
            this->AddToBlacklistButton->Name = L"AddToBlacklistButton";
            this->AddToBlacklistButton->Size = Drawing::Size(448, 26);
            this->AddToBlacklistButton->TabIndex = 1;
            this->AddToBlacklistButton->Text = L"Добавить";
            this->AddToBlacklistButton->UseVisualStyleBackColor = true;
            this->AddToBlacklistButton->Click += gcnew EventHandler(
                this, &PhoneBlacklistForm::AddToBlacklistButton_Click);
            // 
            // AddToBlacklistNumberTextBox
            // 
            this->AddToBlacklistNumberTextBox->Anchor = AnchorStyles::Top | AnchorStyles::Left
                | AnchorStyles::Right;
            this->AddToBlacklistNumberTextBox->Location = Point(6, 22);
            this->AddToBlacklistNumberTextBox->Name = L"AddToBlacklistNumberTextBox";
            this->AddToBlacklistNumberTextBox->Size = Drawing::Size(448, 20);
            this->AddToBlacklistNumberTextBox->TabIndex = 0;
            // 
            // PhoneBlacklistForm
            // 
            this->AutoScaleDimensions = SizeF(6, 13);
            this->AutoScaleMode = Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = Drawing::Size(496, 360);
            this->Controls->Add(this->groupBox9);
            this->Controls->Add(this->groupBox7);
            this->FormBorderStyle = Windows::Forms::FormBorderStyle::FixedSingle;
            this->Icon = (cli::safe_cast<Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->MaximizeBox = false;
            this->Name = L"PhoneBlacklistForm";
            this->StartPosition = FormStartPosition::CenterScreen;
            this->Text = L"Симуляций телекоммуникаций: Чёрный список телефона";
            this->groupBox7->ResumeLayout(false);
            this->groupBox9->ResumeLayout(false);
            this->groupBox10->ResumeLayout(false);
            this->groupBox10->PerformLayout();
            this->ResumeLayout(false);
        }
#pragma endregion

        Void AddToBlacklistButton_Click(Object^ sender, EventArgs^ e);

        Void RemoveSelectedFromBlacklistButton_Click(Object^ sender, EventArgs^ e);
        Void OnBlacklistChanged(Object^ sender,
                                Specialized::NotifyCollectionChangedEventArgs^ e);
    };
}
