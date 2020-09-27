#pragma once

namespace Tchoutchou {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
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
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^  menuStrip1;
	protected: 
	private: System::Windows::Forms::ToolStripMenuItem^  fichierToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  ouvrirToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  enregistrerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripSeparator^  toolStripSeparator1;
	private: System::Windows::Forms::ToolStripMenuItem^  fermerToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  quiterToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  optionsToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aideToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  commentToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  aProposToolStripMenuItem;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::ComboBox^  comboBox1;
	private: System::Windows::Forms::ComboBox^  comboBox2;
	private: System::Windows::Forms::Button^  button3;
	private: System::Windows::Forms::Button^  button4;
	private: System::Windows::Forms::DataGridView^  dataGridView1;

	private: System::Windows::Forms::ToolStripMenuItem^  optionsProgrammeToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^  editionBdToolStripMenuItem;






	private: System::Windows::Forms::Button^  button5;
	private: System::Windows::Forms::OpenFileDialog^  openFileDialog1;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Parcours_dg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Train_dg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Categorie_dg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Origine_dg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Destination_dg;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^  Fiche_de_marche;
	private: System::Windows::Forms::Button^  button6;
	private: System::Windows::Forms::Button^  button7;
	private: System::Windows::Forms::PictureBox^  pictureBox1;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  label8;
	private: System::Windows::Forms::Panel^  panel1;


	private: System::Windows::Forms::Button^  button8;
	private: System::Windows::Forms::Button^  button11;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Button^  button9;

























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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			this->fichierToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->ouvrirToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->enregistrerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->toolStripSeparator1 = (gcnew System::Windows::Forms::ToolStripSeparator());
			this->fermerToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->quiterToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->optionsProgrammeToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->editionBdToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aideToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->commentToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->aProposToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->comboBox2 = (gcnew System::Windows::Forms::ComboBox());
			this->button3 = (gcnew System::Windows::Forms::Button());
			this->button4 = (gcnew System::Windows::Forms::Button());
			this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			this->Parcours_dg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Train_dg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Categorie_dg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Origine_dg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Destination_dg = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->Fiche_de_marche = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			this->button5 = (gcnew System::Windows::Forms::Button());
			this->openFileDialog1 = (gcnew System::Windows::Forms::OpenFileDialog());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->button6 = (gcnew System::Windows::Forms::Button());
			this->button7 = (gcnew System::Windows::Forms::Button());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->label8 = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->button11 = (gcnew System::Windows::Forms::Button());
			this->button8 = (gcnew System::Windows::Forms::Button());
			this->button9 = (gcnew System::Windows::Forms::Button());
			this->menuStrip1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// menuStrip1
			// 
			this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {this->fichierToolStripMenuItem, 
				this->optionsToolStripMenuItem, this->aideToolStripMenuItem});
			this->menuStrip1->Location = System::Drawing::Point(0, 0);
			this->menuStrip1->Name = L"menuStrip1";
			this->menuStrip1->Size = System::Drawing::Size(627, 24);
			this->menuStrip1->TabIndex = 0;
			this->menuStrip1->Text = L"menuStrip1";
			// 
			// fichierToolStripMenuItem
			// 
			this->fichierToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {this->ouvrirToolStripMenuItem, 
				this->enregistrerToolStripMenuItem, this->toolStripSeparator1, this->fermerToolStripMenuItem, this->quiterToolStripMenuItem});
			this->fichierToolStripMenuItem->Name = L"fichierToolStripMenuItem";
			this->fichierToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			this->fichierToolStripMenuItem->Text = L"Fichier";
			// 
			// ouvrirToolStripMenuItem
			// 
			this->ouvrirToolStripMenuItem->Enabled = false;
			this->ouvrirToolStripMenuItem->Name = L"ouvrirToolStripMenuItem";
			this->ouvrirToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->ouvrirToolStripMenuItem->Text = L"Ouvrir ..";
			this->ouvrirToolStripMenuItem->Click += gcnew System::EventHandler(this, &Form1::ouvrirToolStripMenuItem_Click);
			// 
			// enregistrerToolStripMenuItem
			// 
			this->enregistrerToolStripMenuItem->Enabled = false;
			this->enregistrerToolStripMenuItem->Name = L"enregistrerToolStripMenuItem";
			this->enregistrerToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->enregistrerToolStripMenuItem->Text = L"Enregistrer ..";
			// 
			// toolStripSeparator1
			// 
			this->toolStripSeparator1->Name = L"toolStripSeparator1";
			this->toolStripSeparator1->Size = System::Drawing::Size(135, 6);
			// 
			// fermerToolStripMenuItem
			// 
			this->fermerToolStripMenuItem->Enabled = false;
			this->fermerToolStripMenuItem->Name = L"fermerToolStripMenuItem";
			this->fermerToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->fermerToolStripMenuItem->Text = L"Fermer ..";
			// 
			// quiterToolStripMenuItem
			// 
			this->quiterToolStripMenuItem->Name = L"quiterToolStripMenuItem";
			this->quiterToolStripMenuItem->Size = System::Drawing::Size(138, 22);
			this->quiterToolStripMenuItem->Text = L"Quiter";
			// 
			// optionsToolStripMenuItem
			// 
			this->optionsToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->optionsProgrammeToolStripMenuItem, 
				this->editionBdToolStripMenuItem});
			this->optionsToolStripMenuItem->Name = L"optionsToolStripMenuItem";
			this->optionsToolStripMenuItem->Size = System::Drawing::Size(56, 20);
			this->optionsToolStripMenuItem->Text = L"Options";
			// 
			// optionsProgrammeToolStripMenuItem
			// 
			this->optionsProgrammeToolStripMenuItem->Name = L"optionsProgrammeToolStripMenuItem";
			this->optionsProgrammeToolStripMenuItem->Size = System::Drawing::Size(189, 22);
			this->optionsProgrammeToolStripMenuItem->Text = L"Options FERRO-MARRO";
			// 
			// editionBdToolStripMenuItem
			// 
			this->editionBdToolStripMenuItem->Name = L"editionBdToolStripMenuItem";
			this->editionBdToolStripMenuItem->Size = System::Drawing::Size(189, 22);
			this->editionBdToolStripMenuItem->Text = L"Edition Bd";
			// 
			// aideToolStripMenuItem
			// 
			this->aideToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(2) {this->commentToolStripMenuItem, 
				this->aProposToolStripMenuItem});
			this->aideToolStripMenuItem->Name = L"aideToolStripMenuItem";
			this->aideToolStripMenuItem->Size = System::Drawing::Size(40, 20);
			this->aideToolStripMenuItem->Text = L"Aide";
			// 
			// commentToolStripMenuItem
			// 
			this->commentToolStripMenuItem->Name = L"commentToolStripMenuItem";
			this->commentToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->commentToolStripMenuItem->Text = L"Comment .. \?\?";
			// 
			// aProposToolStripMenuItem
			// 
			this->aProposToolStripMenuItem->Name = L"aProposToolStripMenuItem";
			this->aProposToolStripMenuItem->Size = System::Drawing::Size(143, 22);
			this->aProposToolStripMenuItem->Text = L"A propos";
			// 
			// button1
			// 
			this->button1->Enabled = false;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button1->Location = System::Drawing::Point(11, 50);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(45, 31);
			this->button1->TabIndex = 1;
			this->button1->Text = L"+";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
			// 
			// button2
			// 
			this->button2->Enabled = false;
			this->button2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button2->Location = System::Drawing::Point(62, 50);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(45, 31);
			this->button2->TabIndex = 2;
			this->button2->Text = L"-";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &Form1::button2_Click);
			// 
			// comboBox1
			// 
			this->comboBox1->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox1->Enabled = false;
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Location = System::Drawing::Point(110, 54);
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(130, 21);
			this->comboBox1->TabIndex = 3;
			this->comboBox1->SelectionChangeCommitted += gcnew System::EventHandler(this, &Form1::comboBox1_SelectionChangeCommitted);
			// 
			// comboBox2
			// 
			this->comboBox2->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboBox2->Enabled = false;
			this->comboBox2->FormattingEnabled = true;
			this->comboBox2->Location = System::Drawing::Point(244, 54);
			this->comboBox2->Name = L"comboBox2";
			this->comboBox2->Size = System::Drawing::Size(130, 21);
			this->comboBox2->TabIndex = 4;
			this->comboBox2->SelectedIndexChanged += gcnew System::EventHandler(this, &Form1::comboBox2_SelectedIndexChanged);
			// 
			// button3
			// 
			this->button3->Enabled = false;
			this->button3->Location = System::Drawing::Point(379, 50);
			this->button3->Name = L"button3";
			this->button3->Size = System::Drawing::Size(106, 31);
			this->button3->TabIndex = 5;
			this->button3->Text = L"Config. Horaire";
			this->button3->UseVisualStyleBackColor = true;
			this->button3->Click += gcnew System::EventHandler(this, &Form1::button3_Click);
			// 
			// button4
			// 
			this->button4->Enabled = false;
			this->button4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->button4->Location = System::Drawing::Point(489, 49);
			this->button4->Name = L"button4";
			this->button4->Size = System::Drawing::Size(123, 32);
			this->button4->TabIndex = 6;
			this->button4->Text = L"Fiche de marche";
			this->button4->UseVisualStyleBackColor = true;
			this->button4->Click += gcnew System::EventHandler(this, &Form1::button4_Click);
			// 
			// dataGridView1
			// 
			this->dataGridView1->AllowUserToAddRows = false;
			this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(6) {this->Parcours_dg, 
				this->Train_dg, this->Categorie_dg, this->Origine_dg, this->Destination_dg, this->Fiche_de_marche});
			this->dataGridView1->Location = System::Drawing::Point(11, 87);
			this->dataGridView1->Name = L"dataGridView1";
			this->dataGridView1->ReadOnly = true;
			this->dataGridView1->RowHeadersVisible = false;
			this->dataGridView1->RowHeadersWidth = 20;
			this->dataGridView1->Size = System::Drawing::Size(604, 312);
			this->dataGridView1->TabIndex = 7;
			// 
			// Parcours_dg
			// 
			this->Parcours_dg->HeaderText = L"Parcours";
			this->Parcours_dg->Name = L"Parcours_dg";
			this->Parcours_dg->ReadOnly = true;
			// 
			// Train_dg
			// 
			this->Train_dg->HeaderText = L"Train";
			this->Train_dg->Name = L"Train_dg";
			this->Train_dg->ReadOnly = true;
			// 
			// Categorie_dg
			// 
			this->Categorie_dg->HeaderText = L"Categorie";
			this->Categorie_dg->Name = L"Categorie_dg";
			this->Categorie_dg->ReadOnly = true;
			// 
			// Origine_dg
			// 
			this->Origine_dg->HeaderText = L"Origine";
			this->Origine_dg->Name = L"Origine_dg";
			this->Origine_dg->ReadOnly = true;
			// 
			// Destination_dg
			// 
			this->Destination_dg->HeaderText = L"Destination";
			this->Destination_dg->Name = L"Destination_dg";
			this->Destination_dg->ReadOnly = true;
			// 
			// Fiche_de_marche
			// 
			this->Fiche_de_marche->HeaderText = L"Fiche de marche";
			this->Fiche_de_marche->Name = L"Fiche_de_marche";
			this->Fiche_de_marche->ReadOnly = true;
			// 
			// button5
			// 
			this->button5->Enabled = false;
			this->button5->Location = System::Drawing::Point(595, 49);
			this->button5->Name = L"button5";
			this->button5->Size = System::Drawing::Size(17, 32);
			this->button5->TabIndex = 8;
			this->button5->Text = L"F";
			this->button5->UseVisualStyleBackColor = true;
			this->button5->Click += gcnew System::EventHandler(this, &Form1::button5_Click);
			// 
			// openFileDialog1
			// 
			this->openFileDialog1->FileName = L"openFileDialog1";
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label1->Location = System::Drawing::Point(142, 36);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(56, 15);
			this->label1->TabIndex = 9;
			this->label1->Text = L"Parcours";
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.5F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->Location = System::Drawing::Point(284, 36);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(41, 15);
			this->label2->TabIndex = 10;
			this->label2->Text = L"Trains";
			// 
			// button6
			// 
			this->button6->Enabled = true;
			this->button6->Location = System::Drawing::Point(370, 405);
			this->button6->Name = L"button6";
			this->button6->Size = System::Drawing::Size(120, 28);
			this->button6->TabIndex = 11;
			this->button6->Text = L"Appliquer l\'algorithme";
			this->button6->UseVisualStyleBackColor = true;
			this->button6->Click += gcnew System::EventHandler(this, &Form1::button6_Click);
			// 
			// button7
			// 
			this->button7->Enabled = false;
			this->button7->Location = System::Drawing::Point(496, 405);
			this->button7->Name = L"button7";
			this->button7->Size = System::Drawing::Size(121, 28);
			this->button7->TabIndex = 12;
			this->button7->Text = L"Tracer le graphique";
			this->button7->UseVisualStyleBackColor = true;
			this->button7->Click += gcnew System::EventHandler(this, &Form1::button7_Click);
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(0, 0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(627, 57);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 0;
			this->pictureBox1->TabStop = false;
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Location = System::Drawing::Point(12, 99);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(0, 13);
			this->label3->TabIndex = 1;
			// 
			// label4
			// 
			this->label4->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label4->Location = System::Drawing::Point(232, 178);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(147, 66);
			this->label4->TabIndex = 2;
			this->label4->Text = L"\r\n   Président de projet:\r\n            \r\nPr. BRAHIM AGHEZZAF\r\n";
			// 
			// label5
			// 
			this->label5->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label5->Location = System::Drawing::Point(72, 72);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(493, 40);
			this->label5->TabIndex = 3;
			this->label5->Text = L"              Modélisation et Informatisation des problèmes\r\nd\'exploitation et de" 
				L" capacité d\'infrastructure ferroviaire au Maroc\r\n";
			// 
			// label6
			// 
			this->label6->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 10, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->Location = System::Drawing::Point(135, 123);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(355, 42);
			this->label6->TabIndex = 4;
			this->label6->Text = L"                          Presenté au   \r\nDépartement de Mathématiques et Informa" 
				L"tique\r\n\r\n  \r\n";
			// 
			// label7
			// 
			this->label7->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 8, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label7->Location = System::Drawing::Point(176, 260);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(272, 64);
			this->label7->TabIndex = 5;
			this->label7->Text = L"\r\n                        Realisé par :\r\n  \r\nKODAD YASSINE AND SOUINI ABDERRAHIM\r" 
				L"\n\r\n\r\n";
			// 
			// label8
			// 
			this->label8->AutoSize = true;
			this->label8->Location = System::Drawing::Point(13, 278);
			this->label8->Name = L"label8";
			this->label8->Size = System::Drawing::Size(0, 13);
			this->label8->TabIndex = 6;
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->label9);
			this->panel1->Controls->Add(this->button11);
			this->panel1->Controls->Add(this->button8);
			this->panel1->Controls->Add(this->label8);
			this->panel1->Controls->Add(this->label7);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->pictureBox1);
			this->panel1->Dock = System::Windows::Forms::DockStyle::Fill;
			this->panel1->Location = System::Drawing::Point(0, 24);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(627, 412);
			this->panel1->TabIndex = 13;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->BorderStyle = System::Windows::Forms::BorderStyle::Fixed3D;
			this->label9->Font = (gcnew System::Drawing::Font(L"Mistral", 20.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label9->Location = System::Drawing::Point(232, 356);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(161, 35);
			this->label9->TabIndex = 11;
			this->label9->Text = L"FERRO MARRO";
			// 
			// button11
			// 
			this->button11->Location = System::Drawing::Point(16, 353);
			this->button11->Name = L"button11";
			this->button11->Size = System::Drawing::Size(154, 46);
			this->button11->TabIndex = 10;
			this->button11->Text = L"Optimisation et Saturation ";
			this->button11->UseVisualStyleBackColor = true;
			// 
			// button8
			// 
			this->button8->Location = System::Drawing::Point(458, 352);
			this->button8->Name = L"button8";
			this->button8->Size = System::Drawing::Size(154, 47);
			this->button8->TabIndex = 7;
			this->button8->Text = L"Elaboration d\'horraire";
			this->button8->UseVisualStyleBackColor = true;
			this->button8->Click += gcnew System::EventHandler(this, &Form1::button8_Click);
			// 
			// button9
			// 
			this->button9->Location = System::Drawing::Point(12, 405);
			this->button9->Name = L"button9";
			this->button9->Size = System::Drawing::Size(130, 28);
			this->button9->TabIndex = 14;
			this->button9->Text = L"Fixer Fiche de Marche";
			this->button9->UseVisualStyleBackColor = true;
			this->button9->Visible = false;
			this->button9->Click += gcnew System::EventHandler(this, &Form1::button9_Click);
			// 
			// Form1
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(627, 436);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button7);
			this->Controls->Add(this->button6);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->button5);
			this->Controls->Add(this->dataGridView1);
			this->Controls->Add(this->button4);
			this->Controls->Add(this->button3);
			this->Controls->Add(this->comboBox2);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->menuStrip1);
			this->Controls->Add(this->button9);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedSingle;
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->MainMenuStrip = this->menuStrip1;
			this->MaximizeBox = false;
			this->Name = L"Form1";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"FERRO MARRO v1.0";
			this->Load += gcnew System::EventHandler(this, &Form1::Form1_Load);
			this->menuStrip1->ResumeLayout(false);
			this->menuStrip1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->dataGridView1))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void ouvrirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e);
		 void RemplirCombo(void);
		 System::Void button3_Click(System::Object^  sender, System::EventArgs^  e);
		 System::Void comboBox1_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e);
		 System::Void comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e);
		 System::Void button1_Click(System::Object^  sender, System::EventArgs^  e);
		 System::Void button4_Click(System::Object^  sender, System::EventArgs^  e);
		 System::Void button8_Click(System::Object^  sender, System::EventArgs^  e);
		 System::Void button6_Click(System::Object^  sender, System::EventArgs^  e);
		 System::Void Form1_Load(System::Object^  sender, System::EventArgs^  e);
		 System::Void button2_Click(System::Object^  sender, System::EventArgs^  e);
		 System::Void button5_Click(System::Object^  sender, System::EventArgs^  e);
		 System::Void button9_Click(System::Object^  sender, System::EventArgs^  e);
		 System::Void button7_Click(System::Object^  sender, System::EventArgs^  e);
};

}