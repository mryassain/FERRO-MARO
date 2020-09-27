#include "StdAfx.h"
#include "Form3.h"
#include "Form2.h"
#include "Form1.h"
#include "TTFiche2Marche.h"
#include "TTGestionF2M.h"
#include "Principale.h"

extern CTTBd Bdo;
extern int SelParcours,SelTrain;
extern CTTGestionF2M* Gf2m;

System::Void Tchoutchou::Form3::Form3_Load(System::Object^  sender, System::EventArgs^  e)
{
	int *inNoeuds = InitindNoeud(&Bdo,SelParcours);
	CTTFiche2Marche* fiche = Gf2m->ConsultFiche(SelParcours,SelTrain);
	int i = fiche->ConsultOrgDst(0);

	dataGridView1->Rows->Add(
			Bdo.ConsultNoeud(inNoeuds[fiche->ConsultOrgDst(0)]).ConsultPk()
			,System::String::Concat(Char_ptoChar(Bdo.ConsultNoeud(inNoeuds[fiche->ConsultOrgDst(0)]).ConsultS(1))),
			" "," "," "," "," "," "," "," "," "," ",
			fiche->ConsultH()[4*i+2].ConsultHoraire()
			,fiche->ConsultH()[4*i+3].ConsultHoraire()," "
			);

	for (i = fiche->ConsultOrgDst(0)+1;i<=fiche->ConsultOrgDst(1);i++)
		dataGridView1->Rows->Add(
			Bdo.ConsultNoeud(inNoeuds[i]).ConsultPk()
			,System::String::Concat(Char_ptoChar(Bdo.ConsultNoeud(inNoeuds[i]).ConsultS(1))),
			System::Convert::ToDecimal(fiche->ConsultDMbMr(0)[i])
			,System::Convert::ToInt32(fiche->ConsultVMt(0)[i]),
			System::Convert::ToDecimal(fiche->ConsultDMbMr(1)[i])
			,System::Convert::ToDecimal(fiche->ConsultDMbMr(2)[i]),
			System::Convert::ToDecimal(fiche->ConsultDMbMr(1)[i]+fiche->ConsultDMbMr(2)[i])
			,System::Convert::ToInt32(fiche->ConsultVMt(1)[i]),
			System::Convert::ToInt32(fiche->ConsultTArrets()[(i-1)*2])
			,System::Convert::ToInt32(fiche->ConsultTArrets()[(i-1)*2 + 1]),
			fiche->ConsultH()[4*i].ConsultHoraire()
			,fiche->ConsultH()[4*i+1].ConsultHoraire(),
			fiche->ConsultH()[4*i+2].ConsultHoraire()
			,fiche->ConsultH()[4*i+3].ConsultHoraire(),
			System::String::Concat(Char_ptoChar(Bdo.ConsultNoeud(inNoeuds[i]).ConsultS(3)))
		);
	

	dataGridView1->Rows->Add(
			""
			,"+++SOMMES+++",
			System::Convert::ToDecimal(fiche->ConsultDMbMr(0)[Bdo.ConsultNelements(1)+1])
			,"",
			System::Convert::ToDecimal(fiche->ConsultDMbMr(1)[Bdo.ConsultNelements(1)+1])
			,System::Convert::ToDecimal(fiche->ConsultDMbMr(2)[Bdo.ConsultNelements(1)+1]),
			System::Convert::ToDecimal(fiche->ConsultDMbMr(1)[Bdo.ConsultNelements(1)+1])+System::Convert::ToDecimal(fiche->ConsultDMbMr(2)[i])
			,System::Convert::ToInt32(fiche->ConsultVMt(1)[Bdo.ConsultNelements(1)+1])
			,"","","","","","",""
			);
}

