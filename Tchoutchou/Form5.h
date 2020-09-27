#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Tchoutchou {

	/// <summary>
	/// Summary for Form5
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form5 : public System::Windows::Forms::Form
	{
	public:
		Form5(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form5()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Panel^  panel1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridView^  dataGridView1;

	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  km_fdmf;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Pointremarquable_fdmf;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  arrivee_fdmf;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  depart_fdmf;




	protected: 

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
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->km_fdmf = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Pointremarquable_fdmf = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->arrivee_fdmf = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->depart_fdmf = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->panel1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->dataGridView1);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 0);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(485, 485);
			this->panel1->TabIndex = 0;
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->AllowUserToResizeRows = false;
			this->dataGridView1->AutoSizeRowsMode = System::Windows::Forms::DataGridViewAutoSizeRowsMode::AllCells;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(4) {this->km_fdmf, 
				this->Pointremarquable_fdmf, this->arrivee_fdmf, this->depart_fdmf});
			this->dataGridView1->Location = System::Drawing::Point(6, 60);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(473, 422);
			this->dataGridView1->TabIndex = 4;
			// 
			// km_fdmf
			// 
			this->km_fdmf->Frozen = true;
			this->km_fdmf->HeaderText = L"KM";
			this->km_fdmf->Name = L"km_fdmf";
			this->km_fdmf->ReadOnly = true;
			this->km_fdmf->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->km_fdmf->Width = 80;
			// 
			// Pointremarquable_fdmf
			// 
			this->Pointremarquable_fdmf->Frozen = true;
			this->Pointremarquable_fdmf->HeaderText = L"Points Remarquables";
			this->Pointremarquable_fdmf->Name = L"Pointremarquable_fdmf";
			this->Pointremarquable_fdmf->ReadOnly = true;
			this->Pointremarquable_fdmf->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Pointremarquable_fdmf->Width = 190;
			// 
			// arrivee_fdmf
			// 
			this->arrivee_fdmf->Frozen = true;
			this->arrivee_fdmf->HeaderText = L"Arrivée";
			this->arrivee_fdmf->Name = L"arrivee_fdmf";
			this->arrivee_fdmf->ReadOnly = true;
			this->arrivee_fdmf->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// depart_fdmf
			// 
			this->depart_fdmf->Frozen = true;
			this->depart_fdmf->HeaderText = L"Depart";
			this->depart_fdmf->Name = L"depart_fdmf";
			this->depart_fdmf->ReadOnly = true;
			this->depart_fdmf->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Location = System::Drawing::Point(358, 20);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(121, 13);
			this->label4->TabIndex = 3;
			this->label4->Text = L"A : XXXXXXXXXXXXXX";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(351, 7);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(128, 13);
			this->label3->TabIndex = 2;
			this->label3->Text = L"De : XXXXXXXXXXXXXX";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Location = System::Drawing::Point(3, 9);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(141, 13);
			this->label2->TabIndex = 1;
			this->label2->Text = L"CATEGORIE : XXXXXXXXX";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(3, 31);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(102, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"N° TRAIN :  XXXXX";
			// 
			// Form5
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(485, 485);
			this->Controls->Add(this->panel1);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->MaximizeBox = false;
			this->Name = L"Form5";
			this->Text = L"Fiche de Marche Fixé";
			this->Load += gcnew System::EventHandler(this, &Form5::Form5_Load);
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form5_Load(System::Object^  sender, System::EventArgs^  e);
};
}
