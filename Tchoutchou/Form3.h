#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Tchoutchou {

	/// <summary>
	/// Summary for Form3
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form3 : public System::Windows::Forms::Form
	{
	public:
		Form3(void)
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
		~Form3()
		{
			if (components)
			{
				delete components;
			}
		}














	private: System::Windows::Forms::DataGridView^  dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  pk_fmd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Noeuds_fmd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Distance_fmd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Vitesse_fmd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Margeb_fmd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Marger_fmd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  MBPMR_fmd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tpsparc_fmd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  TArrets_fmd;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  tpsarretsmax_fdm;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  HoraireAmin_fdm;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  HoraireAmax_fdm;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  HoraireDmin_fdm;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  HoraireDmax_fdm;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  remarque_fdm;

























































	protected: 

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
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form3::typeid));
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->pk_fmd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Noeuds_fmd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Distance_fmd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Vitesse_fmd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Margeb_fmd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Marger_fmd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->MBPMR_fmd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tpsparc_fmd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->TArrets_fmd = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->tpsarretsmax_fdm = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->HoraireAmin_fdm = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->HoraireAmax_fdm = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->HoraireDmin_fdm = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->HoraireDmax_fdm = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->remarque_fdm = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// dataGridView1
			// 
			this->dataGridView1->AccessibleRole = System::Windows::Forms::AccessibleRole::None;
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->BorderStyle = System::Windows::Forms::BorderStyle::None;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(15) {this->pk_fmd, 
				this->Noeuds_fmd, this->Distance_fmd, this->Vitesse_fmd, this->Margeb_fmd, this->Marger_fmd, this->MBPMR_fmd, this->tpsparc_fmd, 
				this->TArrets_fmd, this->tpsarretsmax_fdm, this->HoraireAmin_fdm, this->HoraireAmax_fdm, this->HoraireDmin_fdm, this->HoraireDmax_fdm, 
				this->remarque_fdm});
			this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->dataGridView1->Location = System::Drawing::Point(0, 0);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->Size = System::Drawing::Size(614, 430);
			this->dataGridView1->TabIndex = 0;
			// 
			// pk_fmd
			// 
			dataGridViewCellStyle1->NullValue = nullptr;
			this->pk_fmd->DefaultCellStyle = dataGridViewCellStyle1;
			this->pk_fmd->HeaderText = L"PK";
			this->pk_fmd->Name = L"pk_fmd";
			this->pk_fmd->ReadOnly = true;
			this->pk_fmd->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->pk_fmd->Width = 50;
			// 
			// Noeuds_fmd
			// 
			this->Noeuds_fmd->HeaderText = L"Noeuds";
			this->Noeuds_fmd->Name = L"Noeuds_fmd";
			this->Noeuds_fmd->ReadOnly = true;
			this->Noeuds_fmd->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Distance_fmd
			// 
			dataGridViewCellStyle2->Format = L"N2";
			this->Distance_fmd->DefaultCellStyle = dataGridViewCellStyle2;
			this->Distance_fmd->HeaderText = L"Distance (km)";
			this->Distance_fmd->Name = L"Distance_fmd";
			this->Distance_fmd->ReadOnly = true;
			this->Distance_fmd->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Distance_fmd->Width = 50;
			// 
			// Vitesse_fmd
			// 
			this->Vitesse_fmd->HeaderText = L"Vitesse (Km/h)";
			this->Vitesse_fmd->Name = L"Vitesse_fmd";
			this->Vitesse_fmd->ReadOnly = true;
			this->Vitesse_fmd->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Vitesse_fmd->Width = 50;
			// 
			// Margeb_fmd
			// 
			dataGridViewCellStyle3->Format = L"N2";
			this->Margeb_fmd->DefaultCellStyle = dataGridViewCellStyle3;
			this->Margeb_fmd->HeaderText = L"Marge de base";
			this->Margeb_fmd->Name = L"Margeb_fmd";
			this->Margeb_fmd->ReadOnly = true;
			this->Margeb_fmd->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Margeb_fmd->Width = 50;
			// 
			// Marger_fmd
			// 
			dataGridViewCellStyle4->Format = L"N2";
			this->Marger_fmd->DefaultCellStyle = dataGridViewCellStyle4;
			this->Marger_fmd->HeaderText = L"Marge de régularité";
			this->Marger_fmd->Name = L"Marger_fmd";
			this->Marger_fmd->ReadOnly = true;
			this->Marger_fmd->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Marger_fmd->Width = 50;
			// 
			// MBPMR_fmd
			// 
			dataGridViewCellStyle5->Format = L"N2";
			this->MBPMR_fmd->DefaultCellStyle = dataGridViewCellStyle5;
			this->MBPMR_fmd->HeaderText = L"MB + MR";
			this->MBPMR_fmd->Name = L"MBPMR_fmd";
			this->MBPMR_fmd->ReadOnly = true;
			this->MBPMR_fmd->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->MBPMR_fmd->Width = 50;
			// 
			// tpsparc_fmd
			// 
			this->tpsparc_fmd->HeaderText = L"tps de parcours";
			this->tpsparc_fmd->Name = L"tpsparc_fmd";
			this->tpsparc_fmd->ReadOnly = true;
			this->tpsparc_fmd->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->tpsparc_fmd->Width = 50;
			// 
			// TArrets_fmd
			// 
			this->TArrets_fmd->HeaderText = L"Tps d\'arret min";
			this->TArrets_fmd->Name = L"TArrets_fmd";
			this->TArrets_fmd->ReadOnly = true;
			this->TArrets_fmd->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->TArrets_fmd->Width = 50;
			// 
			// tpsarretsmax_fdm
			// 
			this->tpsarretsmax_fdm->HeaderText = L"Tps d\'arret MAX";
			this->tpsarretsmax_fdm->Name = L"tpsarretsmax_fdm";
			this->tpsarretsmax_fdm->ReadOnly = true;
			this->tpsarretsmax_fdm->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->tpsarretsmax_fdm->Width = 50;
			// 
			// HoraireAmin_fdm
			// 
			this->HoraireAmin_fdm->HeaderText = L"hA-min";
			this->HoraireAmin_fdm->Name = L"HoraireAmin_fdm";
			this->HoraireAmin_fdm->ReadOnly = true;
			this->HoraireAmin_fdm->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->HoraireAmin_fdm->Width = 50;
			// 
			// HoraireAmax_fdm
			// 
			this->HoraireAmax_fdm->HeaderText = L"hA-max";
			this->HoraireAmax_fdm->Name = L"HoraireAmax_fdm";
			this->HoraireAmax_fdm->ReadOnly = true;
			this->HoraireAmax_fdm->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// HoraireDmin_fdm
			// 
			this->HoraireDmin_fdm->HeaderText = L"hD-min";
			this->HoraireDmin_fdm->Name = L"HoraireDmin_fdm";
			this->HoraireDmin_fdm->ReadOnly = true;
			this->HoraireDmin_fdm->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// HoraireDmax_fdm
			// 
			this->HoraireDmax_fdm->HeaderText = L"hD-max";
			this->HoraireDmax_fdm->Name = L"HoraireDmax_fdm";
			this->HoraireDmax_fdm->ReadOnly = true;
			this->HoraireDmax_fdm->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// remarque_fdm
			// 
			this->remarque_fdm->HeaderText = L"Remarque";
			this->remarque_fdm->Name = L"remarque_fdm";
			this->remarque_fdm->ReadOnly = true;
			this->remarque_fdm->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			// 
			// Form3
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(614, 430);
			this->Controls->Add(this->dataGridView1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form3";
			this->Text = L"Fiche de marche";
			this->Load += gcnew System::EventHandler(this, &Form3::Form3_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);

		}
#pragma endregion
private: System::Void Form3_Load(System::Object^  sender, System::EventArgs^  e);
};
}
