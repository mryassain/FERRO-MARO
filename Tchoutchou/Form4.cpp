#include "StdAfx.h"
#include "Form1.h"
#include "Form4.h"
#include "Principale.h"
#include "TTTime.h"

extern bool *FixeAlgo;
extern bool *FixeFiche;
extern CTTSexbanagoz *Algo;
extern int SelParcours,SelTrain;
extern CTTBd Bdo;
extern CTTGestionF2M* Gf2m;
int Ntrainfichefixe = 0;

System::Void Tchoutchou::Form4::Form4_Load(System::Object^  sender, System::EventArgs^  e)
{
	label2->Text = System::String::Concat("H-Min : [ ",Algo->ConsultIDTrPa(SelTrain,SelParcours).p_horaire[Gf2m->ConsultFiche(SelParcours,SelTrain)->ConsultOrgDst(0)].DepartArrivee[0].ConsultHoraire()," ]");
	label3->Text = System::String::Concat("H-Max : [ ",Algo->ConsultIDTrPa(SelTrain,SelParcours).p_horaire[Gf2m->ConsultFiche(SelParcours,SelTrain)->ConsultOrgDst(0)].DepartArrivee[1].ConsultHoraire()," ]");
	if (Algo->ConsultTrainfixe(SelTrain,SelParcours)->fixe){
		textBox1->Text = System::Convert::ToString(System::Convert::ToInt32(Algo->ConsultTrainfixe(SelTrain,SelParcours)->p_horaire[Gf2m->ConsultFiche(SelParcours,SelTrain)->ConsultOrgDst(0)].DepartArrivee[0].ConsultHeure()));
		textBox2->Text = System::Convert::ToString(System::Convert::ToInt32(Algo->ConsultTrainfixe(SelTrain,SelParcours)->p_horaire[Gf2m->ConsultFiche(SelParcours,SelTrain)->ConsultOrgDst(0)].DepartArrivee[0].ConsultMinute()));
	}
}

System::Void Tchoutchou::Form4::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	CTTTime Depart;
	if (!System::String::IsNullOrEmpty(textBox1->Text) && !System::String::IsNullOrEmpty(textBox2->Text)){
	Depart.ModifHeure(System::Convert::ToInt32(textBox1->Text));
	Depart.ModifMinute(System::Convert::ToInt32(textBox2->Text));
	}

	if (!System::String::IsNullOrEmpty(textBox1->Text) && !System::String::IsNullOrEmpty(textBox2->Text) && (Depart.ConsultTotalMin() >= Algo->ConsultIDTrPa(SelTrain,SelParcours).p_horaire[Gf2m->ConsultFiche(SelParcours,SelTrain)->ConsultOrgDst(0)].DepartArrivee[0].ConsultTotalMin()) && (Depart.ConsultTotalMin() <= Algo->ConsultIDTrPa(SelTrain,SelParcours).p_horaire[Gf2m->ConsultFiche(SelParcours,SelTrain)->ConsultOrgDst(0)].DepartArrivee[1].ConsultTotalMin()))
	{
		Algo->FixerTrain(SelTrain,SelParcours,Depart);
		if (!FixeFiche[SelTrain * Bdo.ConsultNelements(2) + SelParcours]){
			Ntrainfichefixe++;
			FixeFiche[SelTrain * Bdo.ConsultNelements(2) + SelParcours] = true;
		}
		Form4::Close();
	}
	else
	{
		System::Windows::Forms::MessageBox::Show(
							"entrer un temps de depart correcte avant de cliquer sur le bouton « OK » !",
							"Informations manquantes ou incorrecte !",
							MessageBoxButtons::OK,
							MessageBoxIcon::Information
						);
	}
}