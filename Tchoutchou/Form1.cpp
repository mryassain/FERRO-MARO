#include "StdAfx.h"
#include "Form0.h"
#include "Form1.h"
#include "Form2.h"
#include "Form3.h"
#include "Form4.h"
#include "Form5.h"
#include "Form6.h"
#include "Principale.h"


char *Categc[]={"TNR","Voyag","Fret","Phosph","TGV"};
CTTBd Bdo;
CTTGestionF2M* Gf2m = NULL;
CTTSexbanagoz *Algo = NULL;
int SelParcours = -1 ,SelTrain = -1;
bool *TrainOnParcours = NULL;
bool *FixeAlgo = NULL;
bool *FixeFiche = NULL;
extern int* TArretsf;
int Depart[4]={0,0,0,0};
bool Okconfig = false;
int IndiceOrg = 0,IndiceDst = 0;
int *inNoeud;
int NTrain = 0;
extern bool passesok;
bool algoappliquee = false;
extern int Ntrainfichefixe;

System::Void Tchoutchou::Form1::Form1_Load(System::Object^  sender, System::EventArgs^  e)
{
	this->Visible=false;
	Form0^ FenPass = gcnew Form0();
	FenPass->ShowDialog();
	if (passesok)
		this->Visible=true;
	else
		this->~Form1();
}

System::Void Tchoutchou::Form1::ouvrirToolStripMenuItem_Click(System::Object^  sender, System::EventArgs^  e) 
{
	Bdo.ChargerBase((int)0);
	Gf2m = new CTTGestionF2M(&Bdo);
	RemplirCombo();
}

/* 
	Une fonction qui remplit les deux ComboBox de l'interface
	et initialise le tableau par rapport à l'ajout des trains.
*/
void Tchoutchou::Form1::RemplirCombo()
{
	int i;

	comboBox1->Enabled = true;
	comboBox2->Enabled = true;

	for (i=0;i<Bdo.ConsultNelements(2);i++)
		comboBox1->Items->Add(
			System::String::Concat(
				System::String::Concat(Char_ptoChar(Bdo.ConsultParcours(i).ConsultOrig()))
				,"->",
				System::String::Concat(Char_ptoChar(Bdo.ConsultParcours(i).ConsultDest()))
			)
		);

	for (i=0;i<Bdo.ConsultNelements(3);i++)
		comboBox2->Items->Add(
			System::String::Concat(
				System::String::Concat(Char_ptoChar(Bdo.ConsultTrains(i).ConsultNomTr()))
				,":",
				System::String::Concat(Char_ptoChar(Categc[Bdo.ConsultTrains(i).ConsultCatTr()]))
			)
		);
	
	//tableau a deux dimension
	TrainOnParcours = new bool[Bdo.ConsultNelements(3)*Bdo.ConsultNelements(2)];
	FixeAlgo = new bool[Bdo.ConsultNelements(3)*Bdo.ConsultNelements(2)];
	FixeFiche = new bool[Bdo.ConsultNelements(3)*Bdo.ConsultNelements(2)];
	for (i=0;i<(Bdo.ConsultNelements(3)*Bdo.ConsultNelements(2));i++){
		TrainOnParcours[i] = false;
		FixeAlgo[i] = false;
		FixeFiche[i] = false;
	}
}

System::Void Tchoutchou::Form1::button3_Click(System::Object^  sender, System::EventArgs^  e)
{
	Form2^ Config = gcnew Form2(); // lancer la configuration des arrets et du depart
	Config->ShowDialog();// une boite de dialogue pour eviter l'ouverture de plusieur fenetre
						  // de configuration
	if (Okconfig == true && !TrainOnParcours[SelTrain * Bdo.ConsultNelements(2) +  SelParcours])
	{
		button1->Enabled = true;
		Okconfig = false;
	}
	else
		button1->Enabled = false;
}

System::Void Tchoutchou::Form1::comboBox1_SelectionChangeCommitted(System::Object^  sender, System::EventArgs^  e)
{
	SelParcours = comboBox1->SelectedIndex::get();
	if (SelTrain != -1)
	{
		if (button3->Enabled == false)
			button3->Enabled = true;
		if (TrainOnParcours[SelTrain * Bdo.ConsultNelements(2) +  SelParcours]==false)
		{
			button2->Enabled = false;
			button4->Enabled = false;
		}
		else
		{
			button1->Enabled = false;
			button2->Enabled = true;
			button4->Enabled = true;
		}

		button9->Visible = FixeAlgo[SelTrain * Bdo.ConsultNelements(2) + SelParcours];
		button5->Enabled = FixeFiche[SelTrain * Bdo.ConsultNelements(2) + SelParcours];
	}
}

System::Void Tchoutchou::Form1::comboBox2_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	SelTrain = comboBox2->SelectedIndex::get();
	if (SelParcours != -1)
	{
		if (button3->Enabled == false)
			button3->Enabled = true;
		
		if (TrainOnParcours[SelTrain * Bdo.ConsultNelements(2) +  SelParcours] == false)
		{
			button2->Enabled = false;
			button4->Enabled = false;
		}
		else
		{
			button1->Enabled = false;
			button2->Enabled = true;
			button4->Enabled = true;
		}
	
		button9->Visible = FixeAlgo[SelTrain * Bdo.ConsultNelements(2) + SelParcours];
		button5->Enabled = FixeFiche[SelTrain * Bdo.ConsultNelements(2) + SelParcours];
	}	
}

System::Void Tchoutchou::Form1::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	NTrain++;
	
	for (int i=0;i<(Bdo.ConsultNelements(3)*Bdo.ConsultNelements(2));i++){
		FixeAlgo[i] = false;
		FixeFiche[i] = false;
	}
	Ntrainfichefixe = 0;

	button6->Enabled = true;
	button7->Enabled = true;
	algoappliquee = false;
	Gf2m->AjoutFiche(SelTrain,SelParcours,TArretsf,
		Depart[0],Depart[1],Depart[2],Depart[3],
		IndiceOrg,IndiceDst);
	
	inNoeud = InitindNoeud(&Bdo,SelParcours);
	
	dataGridView1->Rows->Add(comboBox1->Items[SelParcours]->ToString()
		,System::String::Concat(Char_ptoChar(Bdo.ConsultTrains(SelTrain).ConsultNomTr())),
		System::String::Concat(Char_ptoChar(Categc[Bdo.ConsultTrains(SelTrain).ConsultCatTr()]))
		,System::String::Concat(Char_ptoChar(Bdo.ConsultNoeud(inNoeud[IndiceOrg]).ConsultS(1))),
		System::String::Concat(Char_ptoChar(Bdo.ConsultNoeud(inNoeud[IndiceDst]).ConsultS(1)))
		,"Non Fixé"
		);

	TrainOnParcours[SelTrain * Bdo.ConsultNelements(2) +  SelParcours] = true;
	delete[] TArretsf;
	delete[] inNoeud;
	inNoeud = NULL;
	TArretsf = NULL;
	button1->Enabled = false;
	button2->Enabled = true;
	button4->Enabled = true;
	comboBox2_SelectedIndexChanged(sender,e);
}

System::Void Tchoutchou::Form1::button4_Click(System::Object^  sender, System::EventArgs^  e)
{
	Form3^ FichedeMarche = gcnew Form3();
	FichedeMarche->ShowDialog();
}

System::Void Tchoutchou::Form1::button8_Click(System::Object^  sender, System::EventArgs^  e)
{
	panel1->Visible = false;
	ouvrirToolStripMenuItem->Enabled = true;
	enregistrerToolStripMenuItem->Enabled = true;
	fermerToolStripMenuItem->Enabled = true;
}

System::Void Tchoutchou::Form1::button6_Click(System::Object^  sender, System::EventArgs^  e)
{
	int i,j;

	if (Algo){
		delete Algo;
		Algo = NULL;
	}
	
	for (i=0;i<(Bdo.ConsultNelements(3)*Bdo.ConsultNelements(2));i++){
		FixeFiche[i] = false;
		FixeAlgo[i] = false;
	}

	Algo = new CTTSexbanagoz(NTrain,&Bdo,Gf2m);
	Algo->Algorithme();
	for (i=0;i<NTrain;i++)
	{
		for (j=0;j<dataGridView1->Rows->Count;j++)
			if (comboBox1->Items[Algo->ConsultIDTrPa(i).IDParcours]->Equals(dataGridView1->Rows[j]->Cells[0]->Value)&& dataGridView1->Rows[j]->Cells[1]->Value->Equals(System::String::Concat(Char_ptoChar(Bdo.ConsultTrains(Algo->ConsultIDTrPa(i).IDtrain).ConsultNomTr()))))
				break;
		if (Algo->ConsultIDTrPa(i).fixe)
		{
			dataGridView1->Rows[j]->Cells[5]->Value::set("Fixé");
			dataGridView1->Rows[j]->Cells[5]->Style->BackColor::set(System::Drawing::Color::Green);
			FixeAlgo[Algo->ConsultIDTrPa(i).IDtrain * Bdo.ConsultNelements(2) + Algo->ConsultIDTrPa(i).IDParcours] = true;
		}
		else
		{
			dataGridView1->Rows[j]->Cells[5]->Value::set("Conflit");
			dataGridView1->Rows[j]->Cells[5]->Style->BackColor::set(System::Drawing::Color::Red);
		}
	}

	button7->Enabled = true;
	button6->Enabled = false;
	algoappliquee = true;
	comboBox2_SelectedIndexChanged(sender,e);
	}

System::Void Tchoutchou::Form1::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	int i;
	
	NTrain--;

	for (i=0;i<(Bdo.ConsultNelements(3)*Bdo.ConsultNelements(2));i++){
		FixeAlgo[i] = false;
		FixeFiche[i] = false;
	}
	Ntrainfichefixe = 0;

	button4->Enabled = false;
	button6->Enabled = true;
	algoappliquee = false;

	if (!NTrain){
		button6->Enabled = false;
		button7->Enabled = false;
	}
	
	button2->Enabled = false;
	TrainOnParcours[SelTrain * Bdo.ConsultNelements(2) +  SelParcours] = false;
	Gf2m->SupprFiche(SelParcours,SelTrain);
	for (i=0;i<dataGridView1->Rows->Count;i++)
		if (comboBox1->Items[SelParcours]->Equals(dataGridView1->Rows[i]->Cells[0]->Value)&& dataGridView1->Rows[i]->Cells[1]->Value->Equals(System::String::Concat(Char_ptoChar(Bdo.ConsultTrains(SelTrain).ConsultNomTr()))))
			break;
	dataGridView1->Rows->RemoveAt(i);

	comboBox2_SelectedIndexChanged(sender,e);
}

System::Void Tchoutchou::Form1::button5_Click(System::Object^  sender, System::EventArgs^  e)
{
	Form5^ fichefixe = gcnew Form5();
	fichefixe->ShowDialog();
}

System::Void Tchoutchou::Form1::button9_Click(System::Object^  sender, System::EventArgs^  e)
{
	Form4^ fixerhorraire = gcnew Form4();
	fixerhorraire->ShowDialog();
	comboBox2_SelectedIndexChanged(sender,e);
}

System::Void Tchoutchou::Form1::button7_Click(System::Object^  sender, System::EventArgs^  e)
{
	Form6^ menugraphique = gcnew Form6();
	menugraphique->ShowDialog();
}