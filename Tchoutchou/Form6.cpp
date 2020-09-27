#include "StdAfx.h"
#include "Principale.h"
#include "Form1.h"
#include "Form6.h"
#include "Form7.h"

extern CTTSexbanagoz *Algo;
extern int Ntrainfichefixe;
extern bool algoappliquee;
int choixgraphique = -1;

System::Void Tchoutchou::Form6::Form6_Load(System::Object^  sender, System::EventArgs^  e)
{
	button2->Enabled = algoappliquee;

	if (Algo != NULL && Ntrainfichefixe && Ntrainfichefixe == Algo->ConsultNtrainfixe())
		button3->Enabled = true;
}

System::Void Tchoutchou::Form6::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Visible = false;
	choixgraphique = 0;
	Form7^ graphique = gcnew Form7();
	graphique->ShowDialog();
	this->Visible = true;
}

System::Void Tchoutchou::Form6::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Visible = false;
	choixgraphique = 1;
	Form7^ graphique = gcnew Form7();
	graphique->ShowDialog();
	this->Visible = true;
}

System::Void Tchoutchou::Form6::button3_Click(System::Object^  sender, System::EventArgs^  e)
{
	this->Visible = false;
	choixgraphique = 2;
	Form7^ graphique = gcnew Form7();
	graphique->ShowDialog();
	this->Visible = true;
}