#ifndef F_LongReinfH
#define F_LongReinfH


#pragma once
#include <string>

using namespace std;

namespace Phaethon {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for F_LongReinf
	/// </summary>
	public ref class F_LongReinf : public System::Windows::Forms::Form
	{
	private: System::Windows::Forms::DataGridView^  gridRectLonginReinf;
	public:
		F_LongReinf(int nMidFibers, double* fAs, int nprev);
					 
	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~F_LongReinf()
		{
			if (components)
			{
				delete components;
			}
		}

	protected: 

	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Button^  btnOk;
	private: System::Windows::Forms::Button^  btnCancel;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  clmRectReinfID;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  clmRectReinfArea;







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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->gridRectLonginReinf = (gcnew System::Windows::Forms::DataGridView());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->btnCancel = (gcnew System::Windows::Forms::Button());
			this->btnOk = (gcnew System::Windows::Forms::Button());
			this->clmRectReinfID = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->clmRectReinfArea = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->gridRectLonginReinf))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// gridRectLonginReinf
			// 
			this->gridRectLonginReinf->AllowUserToAddRows = false;
			this->gridRectLonginReinf->AllowUserToDeleteRows = false;
			this->gridRectLonginReinf->AllowUserToResizeColumns = false;
			this->gridRectLonginReinf->AllowUserToResizeRows = false;
			this->gridRectLonginReinf->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->gridRectLonginReinf->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(2) {this->clmRectReinfID, 
				this->clmRectReinfArea});
			this->gridRectLonginReinf->Dock = System::Windows::Forms::DockStyle::Top;
			this->gridRectLonginReinf->Location = System::Drawing::Point(0, 0);
			this->gridRectLonginReinf->Name = L"gridRectLonginReinf";
			this->gridRectLonginReinf->ScrollBars = System::Windows::Forms::ScrollBars::Vertical;
			this->gridRectLonginReinf->SelectionMode = System::Windows::Forms::DataGridViewSelectionMode::FullRowSelect;
			this->gridRectLonginReinf->Size = System::Drawing::Size(336, 261);
			this->gridRectLonginReinf->TabIndex = 0;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->btnCancel);
			this->panel1->Controls->Add(this->btnOk);
			this->panel1->Controls->Add(this->gridRectLonginReinf);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(336, 296);
			this->panel1->TabIndex = 1;
			// 
			// btnCancel
			// 
			this->btnCancel->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Right));
			this->btnCancel->DialogResult = System::Windows::Forms::DialogResult::Cancel;
			this->btnCancel->Location = System::Drawing::Point(258, 270);
			this->btnCancel->Name = L"btnCancel";
			this->btnCancel->Size = System::Drawing::Size(75, 23);
			this->btnCancel->TabIndex = 2;
			this->btnCancel->Text = L"Cancel";
			this->btnCancel->UseVisualStyleBackColor = true;
			// 
			// btnOk
			// 
			this->btnOk->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Bottom | System::Windows::Forms::AnchorStyles::Left));
			this->btnOk->DialogResult = System::Windows::Forms::DialogResult::OK;
			this->btnOk->Location = System::Drawing::Point(3, 270);
			this->btnOk->Name = L"btnOk";
			this->btnOk->Size = System::Drawing::Size(75, 23);
			this->btnOk->TabIndex = 1;
			this->btnOk->Text = L"OK";
			this->btnOk->UseVisualStyleBackColor = true;
			// 
			// clmRectReinfID
			// 
			this->clmRectReinfID->Frozen = true;
			this->clmRectReinfID->HeaderText = L"Reinforcing Steel Layer ID";
			this->clmRectReinfID->Name = L"clmRectReinfID";
			this->clmRectReinfID->ReadOnly = true;
			this->clmRectReinfID->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->clmRectReinfID->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->clmRectReinfID->Width = 137;
			// 
			// clmRectReinfArea
			// 
			dataGridViewCellStyle1->Format = L"#######.###";
			dataGridViewCellStyle1->NullValue = nullptr;
			this->clmRectReinfArea->DefaultCellStyle = dataGridViewCellStyle1;
			this->clmRectReinfArea->HeaderText = L"Area of Reinforcing Steel Layer (mm²)";
			this->clmRectReinfArea->Name = L"clmRectReinfArea";
			this->clmRectReinfArea->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->clmRectReinfArea->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->clmRectReinfArea->Width = 156;
			// 
			// F_LongReinf
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->AutoSize = true;
			this->ClientSize = System::Drawing::Size(336, 296);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedDialog;
			this->MaximizeBox = false;
			this->Name = L"F_LongReinf";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterParent;
			this->Text = L"Area of Longitudinal Steel Layers";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->gridRectLonginReinf))->EndInit();
			this->panel1->ResumeLayout(false);
			this->ResumeLayout(false);

		}
#pragma endregion
		//mine
		public:
		double getCell(int iRow, int iCol, bool decimalComma);
};
}

#endif