#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Tchoutchou {

	/// <summary>
	/// Summary for Form2
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form2 : public System::Windows::Forms::Form
	{
	public:
		Form2(void)
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
		~Form2()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^  button1;
	protected: 
	private: System::Windows::Forms::Button^  button2;




	private: System::Windows::Forms::DataGridView^  dataGridView1;



	private: System::Windows::Forms::CheckedListBox^  checkedListBox1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::TextBox^  textBox2;
	private: System::Windows::Forms::TextBox^  textBox3;
	private: System::Windows::Forms::TextBox^  textBox4;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Noeuds;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Tarretsmin;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Tarretsmax;













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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form2::typeid));
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Noeuds = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Tarretsmin = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Tarretsmax = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->checkedListBox1 = (gcnew System::Windows::Forms::CheckedListBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			this->textBox3 = (gcnew System::Windows::Forms::TextBox());
			this->textBox4 = (gcnew System::Windows::Forms::TextBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(446, 7);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(65, 26);
			this->button1->TabIndex = 0;
			this->button1->Text = L"Valider";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form2::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(446, 39);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(65, 26);
			this->button2->TabIndex = 1;
			this->button2->Text = L"Annuler";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form2::button2_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->AllowUserToDeleteRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(3) {this->Noeuds, 
				this->Tarretsmin, this->Tarretsmax});
			this->dataGridView1->Location = System::Drawing::Point(184, 76);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 40;
			this->dataGridView1->Size = System::Drawing::Size(338, 336);
			this->dataGridView1->TabIndex = 2;
			// 
			// Noeuds
			// 
			this->Noeuds->Frozen = true;
			this->Noeuds->HeaderText = L"Noeuds";
			this->Noeuds->Name = L"Noeuds";
			this->Noeuds->ReadOnly = true;
			this->Noeuds->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Noeuds->Width = 142;
			// 
			// Tarretsmin
			// 
			this->Tarretsmin->HeaderText = L"Temps d\'arrets min";
			this->Tarretsmin->MaxInputLength = 10;
			this->Tarretsmin->Name = L"Tarretsmin";
			this->Tarretsmin->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Tarretsmin->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Tarretsmin->Width = 88;
			// 
			// Tarretsmax
			// 
			this->Tarretsmax->HeaderText = L"Temps d\'arrets max";
			this->Tarretsmax->MaxInputLength = 10;
			this->Tarretsmax->Name = L"Tarretsmax";
			this->Tarretsmax->Resizable = System::Windows::Forms::DataGridViewTriState::False;
			this->Tarretsmax->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::NotSortable;
			this->Tarretsmax->Width = 88;
			// 
			// checkedListBox1
			// 
			this->checkedListBox1->CheckOnClick = true;
			this->checkedListBox1->FormattingEnabled = true;
			this->checkedListBox1->Location = System::Drawing::Point(4, 48);
			this->checkedListBox1->Name = L"checkedListBox1";
			this->checkedListBox1->Size = System::Drawing::Size(174, 364);
			this->checkedListBox1->TabIndex = 3;
			this->checkedListBox1->ThreeDCheckBoxes = true;
			this->checkedListBox1->SelectedIndexChanged += gcnew System::EventHandler(this, &Form2::checkedListBox1_SelectedIndexChanged);
			this->checkedListBox1->ItemCheck += gcnew System::Windows::Forms::ItemCheckEventHandler(this, &Form2::checkedListBox1_ItemCheck);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(30, 8);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(122, 32);
			this->label1->TabIndex = 4;
			this->label1->Text = L"  Origine initiale \r\nDestination finale";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(333, 24);
			this->textBox1->MaxLength = 2;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(23, 20);
			this->textBox1->TabIndex = 5;
			this->textBox1->Text = L"0";
			// 
			// textBox2
			// 
			this->textBox2->Location = System::Drawing::Point(362, 24);
			this->textBox2->MaxLength = 2;
			this->textBox2->Name = L"textBox2";
			this->textBox2->Size = System::Drawing::Size(23, 20);
			this->textBox2->TabIndex = 6;
			this->textBox2->Text = L"0";
			// 
			// textBox3
			// 
			this->textBox3->Location = System::Drawing::Point(333, 50);
			this->textBox3->MaxLength = 2;
			this->textBox3->Name = L"textBox3";
			this->textBox3->Size = System::Drawing::Size(23, 20);
			this->textBox3->TabIndex = 7;
			this->textBox3->Text = L"0";
			// 
			// textBox4
			// 
			this->textBox4->Location = System::Drawing::Point(362, 50);
			this->textBox4->MaxLength = 2;
			this->textBox4->Name = L"textBox4";
			this->textBox4->Size = System::Drawing::Size(23, 20);
			this->textBox4->TabIndex = 8;
			this->textBox4->Text = L"0";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label2->Location = System::Drawing::Point(336, 8);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(17, 15);
			this->label2->TabIndex = 9;
			this->label2->Text = L"H";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label3->Location = System::Drawing::Point(364, 8);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(18, 15);
			this->label3->TabIndex = 10;
			this->label3->Text = L"M";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label4->Location = System::Drawing::Point(262, 27);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(63, 15);
			this->label4->TabIndex = 11;
			this->label4->Text = L"Depart min ";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Location = System::Drawing::Point(262, 53);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(63, 15);
			this->label5->TabIndex = 12;
			this->label5->Text = L"Depart max";
			// 
			// Form2
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(523, 415);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->textBox4);
			this->Controls->Add(this->textBox3);
			this->Controls->Add(this->textBox2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkedListBox1);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->ForeColor = System::Drawing::SystemColors::ControlText;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MaximizeBox = false;
			this->Name = L"Form2";
			this->Text = L"Configuration Horaire";
			this->Load += gcnew System::EventHandler(this, &Form2::Form2_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void Form2_Load(System::Object^  sender, System::EventArgs^  e);
		 System::Void checkedListBox1_ItemCheck(System::Object^  sender, System::Windows::Forms::ItemCheckEventArgs^  e);
		 System::Void checkedListBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		 System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
		 System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
};
}
