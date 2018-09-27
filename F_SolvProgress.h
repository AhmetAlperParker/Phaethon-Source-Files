#ifndef F_SolvProgressH
#define F_SolvProgressH

#pragma once

namespace Phaethon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for F_SolvProgress
	/// </summary>
	public ref class F_SolvProgress : public System::Windows::Forms::Form
	{
	public:
		F_SolvProgress(bool pushover, int nSteps, int nSecs);


	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~F_SolvProgress()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  lblSection;
	protected: 
	private: System::Windows::Forms::Label^  lblStep;
	private: System::Windows::Forms::ProgressBar^  prbSection;
	private: System::Windows::Forms::ProgressBar^  prbStep;

	private:
		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void)
		{
			this->lblSection = (gcnew System::Windows::Forms::Label());
			this->lblStep = (gcnew System::Windows::Forms::Label());
			this->prbSection = (gcnew System::Windows::Forms::ProgressBar());
			this->prbStep = (gcnew System::Windows::Forms::ProgressBar());
			this->SuspendLayout();
			// 
			// lblSection
			// 
			this->lblSection->AutoSize = true;
			this->lblSection->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblSection->Location = System::Drawing::Point(15, 83);
			this->lblSection->Name = L"lblSection";
			this->lblSection->Size = System::Drawing::Size(68, 15);
			this->lblSection->TabIndex = 7;
			this->lblSection->Text = L"Section 0/n";
			// 
			// lblStep
			// 
			this->lblStep->AutoSize = true;
			this->lblStep->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(161)));
			this->lblStep->Location = System::Drawing::Point(15, 19);
			this->lblStep->Name = L"lblStep";
			this->lblStep->Size = System::Drawing::Size(52, 15);
			this->lblStep->TabIndex = 6;
			this->lblStep->Text = L"Step 0/n";
			// 
			// prbSection
			// 
			this->prbSection->Location = System::Drawing::Point(17, 101);
			this->prbSection->Name = L"prbSection";
			this->prbSection->Size = System::Drawing::Size(350, 23);
			this->prbSection->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->prbSection->TabIndex = 5;
			this->prbSection->Value = 1;
			// 
			// prbStep
			// 
			this->prbStep->Location = System::Drawing::Point(17, 37);
			this->prbStep->Name = L"prbStep";
			this->prbStep->Size = System::Drawing::Size(350, 23);
			this->prbStep->Step = 1;
			this->prbStep->Style = System::Windows::Forms::ProgressBarStyle::Continuous;
			this->prbStep->TabIndex = 4;
			this->prbStep->Value = 60;
			// 
			// F_SolvProgress
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(384, 144);
			this->ControlBox = false;
			this->Controls->Add(this->lblSection);
			this->Controls->Add(this->lblStep);
			this->Controls->Add(this->prbSection);
			this->Controls->Add(this->prbStep);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"F_SolvProgress";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Phaethon Pushover Solution Progress";
			this->TopMost = true;
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
		//mine
		public:
		void updStep(int iStep);
		void updSec(int iSec);
	};
}

#endif