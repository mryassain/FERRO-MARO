#include "StdAfx.h"
#include "Form5.h"
#include "Form1.h"
#include "Principale.h"

extern char *Categc[];
extern CTTBd Bdo;
extern CTTGestionF2M* Gf2m;
extern CTTSexbanagoz *Algo;
extern int SelParcours,SelTrain;

System::Void Tchoutchou::Form5::Form5_Load(System::Object^  sender, System::EventArgs^  e)
{
int *inNoeuds = InitindNoeud(&Bdo,SelParcours);
	CTTFiche2Marche* fiche = Gf2m->ConsultFiche(SelParcours,SelTrain);
	int i = fiche->ConsultOrgDst(0);

	label1->Text = System::String::Concat("N° TRAIN : ",System::String::Concat(Char_ptoChar(Bdo.ConsultTrains(SelTrain).ConsultNomTr())));
	label2->Text = System::String::Concat("Categorie : ",System::String::Concat(Char_ptoChar(Categc[Bdo.ConsultTrains(SelTrain).ConsultCatTr()])));
	label3->Text = System::String::Concat("De : ",System::String::Concat(Char_ptoChar(Bdo.ConsultNoeud(inNoeuds[fiche->ConsultOrgDst(0)]).ConsultS(1))));
	label4->Text = System::String::Concat("A : ",System::String::Concat(Char_ptoChar(Bdo.ConsultNoeud(inNoeuds[fiche->ConsultOrgDst(1)]).ConsultS(1))));

	dataGridView1->Rows->Add(
			Bdo.ConsultNoeud(inNoeuds[fiche->ConsultOrgDst(0)]).ConsultPk()
			,System::String::Concat(Char_ptoChar(Bdo.ConsultNoeud(inNoeuds[fiche->ConsultOrgDst(0)]).ConsultS(1))),
			""
			,Algo->ConsultTrainfixe(SelTrain,SelParcours)->p_horaire[fiche->ConsultOrgDst(0)].DepartArrivee[0].ConsultHoraire()
			);

	for (i = fiche->ConsultOrgDst(0)+1;i<=fiche->ConsultOrgDst(1);i++)
		dataGridView1->Rows->Add(
			Bdo.ConsultNoeud(inNoeuds[i]).ConsultPk()
			,System::String::Concat(Char_ptoChar(Bdo.ConsultNoeud(inNoeuds[i]).ConsultS(1))),
			Algo->ConsultTrainfixe(SelTrain,SelParcours)->p_horaire[i-1].DepartArrivee[1].ConsultHoraire()
			,Algo->ConsultTrainfixe(SelTrain,SelParcours)->p_horaire[i].DepartArrivee[0].ConsultHoraire()
		);
}