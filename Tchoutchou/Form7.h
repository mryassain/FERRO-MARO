#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace Tchoutchou {

	/// <summary>
	/// Summary for Form7
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	/// </summary>
	public ref class Form7 : public System::Windows::Forms::Form
	{
	public:
		Form7(void)
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
		~Form7()
		{
			if (components)
			{
				delete components;
			}
		}

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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Form7::typeid));
			this->SuspendLayout();
			// 
			// Form7
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::White;
			this->ClientSize = System::Drawing::Size(577, 331);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^  >(resources->GetObject(L"$this.Icon")));
			this->Name = L"Form7";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Graphique";
			this->WindowState = System::Windows::Forms::FormWindowState::Maximized;
			this->Load += gcnew System::EventHandler(this, &Form7::Form7_Load);
			this->Paint += gcnew System::Windows::Forms::PaintEventHandler(this, &Form7::Form7_Paint);
			this->ResumeLayout(false);

		}
#pragma endregion
	private: System::Void Form7_Load(System::Object^  sender, System::EventArgs^  e);
			 System::Void Form7_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e);
			 void AvantAlgo(void);
			 void ApresAlgo(void);
			 void ApresFixation(void);
			 void DessinerGrille(void);
			 System::Drawing::Pen^ Stylo;
             System::Drawing::Graphics^ TableDessin;
			 System::Drawing::SolidBrush^ Richa;
			 cli::array<System::Drawing::PointF>^ noeudX;
			 cli::array<System::Drawing::PointF>^ noeudY;		 
	};
}
