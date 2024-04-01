#pragma once

#include "IVisualizationEngine.h"
#include "IVisualizationRegistry.h"

namespace TelecommsSimulation
{
    using namespace System;
    using namespace System::ComponentModel;
    using namespace System::Collections;
    using namespace System::Windows::Forms;
    using namespace System::Data;
    using namespace System::Drawing;

    /// <summary>
    /// From to visualize simulation
    /// </summary>
    public ref class SimulationVisualizationForm : public System::Windows::Forms::Form
    {
    private:
        IVisualizationEngine^ _visualizationEngine;
        System::Timers::Timer^ _timer;

    public:
        SimulationVisualizationForm(IVisualizationRegistry<Core::BaseStation^>^ baseStationVisualizationRegistry,
                                    IVisualizationRegistry<Core::Phone^>^ phoneVisualizationRegistry);

    protected:
        /// <summary>
        /// Cleans up resources
        /// </summary>
        ~SimulationVisualizationForm()
        {
            if (components)
            {
                delete components;
            }
        }

    private:
        System::Windows::Forms::PictureBox^ VisualizationPictureBox;

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
                System::ComponentModel::ComponentResourceManager(SimulationVisualizationForm::typeid));
            this->VisualizationPictureBox = (gcnew System::Windows::Forms::PictureBox());
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VisualizationPictureBox))->BeginInit();
            this->SuspendLayout();
            // 
            // VisualizationPictureBox
            // 
            this->VisualizationPictureBox->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((
                        System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
                    | System::Windows::Forms::AnchorStyles::Left)
                | System::Windows::Forms::AnchorStyles::Right));
            this->VisualizationPictureBox->Location = System::Drawing::Point(14, 14);
            this->VisualizationPictureBox->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->VisualizationPictureBox->Name = L"VisualizationPictureBox";
            this->VisualizationPictureBox->Size = System::Drawing::Size(980, 701);
            this->VisualizationPictureBox->TabIndex = 0;
            this->VisualizationPictureBox->TabStop = false;
            this->VisualizationPictureBox->Paint += gcnew System::Windows::Forms::PaintEventHandler(
                this, &SimulationVisualizationForm::VisualizationPictureBox_Paint);
            // 
            // SimulationVisualizationForm
            // 
            this->AutoScaleDimensions = System::Drawing::SizeF(7, 15);
            this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
            this->ClientSize = System::Drawing::Size(1008, 729);
            this->Controls->Add(this->VisualizationPictureBox);
            this->DoubleBuffered = true;
            this->Font = (gcnew System::Drawing::Font(L"Segoe UI", 9, System::Drawing::FontStyle::Regular,
                                                      System::Drawing::GraphicsUnit::Point,
                                                      static_cast<System::Byte>(0)));
            this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
            this->Margin = System::Windows::Forms::Padding(4, 3, 4, 3);
            this->Name = L"SimulationVisualizationForm";
            this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
            this->Text = L"Симуляция телекоммуникаций: Визуализация симуляции";
            this->FormClosed += gcnew System::Windows::Forms::FormClosedEventHandler(
                this, &SimulationVisualizationForm::SimulationVisualizationForm_FormClosed);
            (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->VisualizationPictureBox))->EndInit();
            this->ResumeLayout(false);
        }
#pragma endregion

    private:
        System::Void OnTimerElapsed(System::Object^ sender, System::Timers::ElapsedEventArgs^ e);

    private:
        System::Void VisualizationPictureBox_Paint(System::Object^ sender, System::Windows::Forms::PaintEventArgs^ e);

    private:
        System::Void SimulationVisualizationForm_FormClosed(System::Object^ sender,
                                                            System::Windows::Forms::FormClosedEventArgs^ e);
    };
}
