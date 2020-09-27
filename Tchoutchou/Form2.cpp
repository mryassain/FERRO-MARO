#include "StdAfx.h"
#include "Form1.h"
#include "Form2.h"
#include "Principale.h"

extern CTTBd Bdo;
extern int SelParcours,SelTrain;
extern bool *TrainOnParcours;
int* TArretsf = NULL;
extern int Depart[4];
extern bool Okconfig;
extern int IndiceOrg,IndiceDst;

System::Void Tchoutchou::Form2::Form2_Load(System::Object^  sender, System::EventArgs^  e)
{
	int i;
	int* Temp1 = NULL;
	char* temp2 = NULL;

	for (i=0;i<Bdo.ConsultParcours(SelParcours).ConsultInt(3);i++)
	{
		if (Bdo.ConsultParcours(SelParcours).ConsultPairImpair())
			checkedListBox1->Items->Add(
			System::String::Concat(
				Char_ptoChar(Bdo.ConsultNoeud(Bdo.ConsultVoie(Bdo.ConsultParcours(SelParcours).ConsultP()[i]).ConsultOrg()).ConsultS(1))
				)
			);
		else
			checkedListBox1->Items->Add(
			System::String::Concat(
				Char_ptoChar(Bdo.ConsultNoeud(Bdo.ConsultVoie(Bdo.ConsultParcours(SelParcours).ConsultP()[i]).ConsultDest()).ConsultS(1))
				)
			);
	}
	
	if (Bdo.ConsultParcours(SelParcours).ConsultPairImpair())
		checkedListBox1->Items->Add(
		System::String::Concat(
			Char_ptoChar(Bdo.ConsultNoeud(Bdo.ConsultVoie(Bdo.ConsultParcours(SelParcours).ConsultP()[Bdo.ConsultParcours(SelParcours).ConsultInt(3)-1]).ConsultDest()).ConsultS(1))
			)
	);
	else
	checkedListBox1->Items->Add(
		System::String::Concat(
			Char_ptoChar(Bdo.ConsultNoeud(Bdo.ConsultVoie(Bdo.ConsultParcours(SelParcours).ConsultP()[Bdo.ConsultParcours(SelParcours).ConsultInt(3)-1]).ConsultOrg()).ConsultS(1))
			)
	);
	
}

System::Void Tchoutchou::Form2::checkedListBox1_ItemCheck(System::Object^  sender, System::Windows::Forms::ItemCheckEventArgs^  e)
{
	Int32 index;
	IEnumerator^ enumtemp = checkedListBox1->CheckedIndices->GetEnumerator();
	
	if (e->CurrentValue == CheckState::Unchecked)
		if (checkedListBox1->CheckedItems->Count==2){
			while (enumtemp->MoveNext()) {
			index =  *safe_cast<Int32^> (enumtemp->Current);
			
			checkedListBox1->SetItemCheckState(index,CheckState::Unchecked);
			}
		}
}

System::Void Tchoutchou::Form2::checkedListBox1_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e)
{
	Int32 index1,index2;
	int i,j;
	IEnumerator^ enumtemp = checkedListBox1->CheckedIndices->GetEnumerator();

	if (checkedListBox1->CheckedItems->Count==2){
		enumtemp->Reset();enumtemp->MoveNext();
		IndiceOrg = index1 =  *safe_cast<Int32^> (enumtemp->Current);
		enumtemp->MoveNext();
		IndiceDst = index2 =  *safe_cast<Int32^> (enumtemp->Current);
		dataGridView1->Rows->Clear();
		dataGridView1->Rows->Add(index2-index1);
		
		for(j=index1+1,i=0;i<(index2-index1);j++,i++){
			dataGridView1->Rows[i]->SetValues(checkedListBox1->Items[j]->ToString(),nullptr,nullptr);
		}
	}
}

System::Void Tchoutchou::Form2::button1_Click(System::Object^  sender, System::EventArgs^  e)
{
	int i,j;
	if (checkedListBox1->CheckedItems->Count!=2)
		System::Windows::Forms::MessageBox::Show(
			"Sélectionner une origine et une destination avant de cliquer sur le bouton « valider » !",
			"Informations manquantes",
			MessageBoxButtons::OK,
			MessageBoxIcon::Information
		);
	else
	{
		if (System::String::IsNullOrEmpty(textBox1->Text) || System::String::IsNullOrEmpty(textBox2->Text) || System::String::IsNullOrEmpty(textBox3->Text) || System::String::IsNullOrEmpty(textBox4->Text))
			System::Windows::Forms::MessageBox::Show(
						"Entrer les informations de départ correctement avant de cliquer sur le bouton « valider » !",
						"Informations manquantes",
						MessageBoxButtons::OK,
						MessageBoxIcon::Information
					);
		else
			if (
				(Convert::ToInt32(textBox1->Text)>=24 || Convert::ToInt32(textBox1->Text)<0 ) ||
				(Convert::ToInt32(textBox3->Text)>=24 || Convert::ToInt32(textBox3->Text)<0 ) ||
				(Convert::ToInt32(textBox2->Text)>=60 || Convert::ToInt32(textBox2->Text)<0 ) ||
				(Convert::ToInt32(textBox4->Text)>=60 || Convert::ToInt32(textBox4->Text)<0 ) )
					System::Windows::Forms::MessageBox::Show(
						"Entrer les informations de départ correctement avant de cliquer sur le bouton « valider » !",
						"Informations manquantes",
						MessageBoxButtons::OK,
						MessageBoxIcon::Information
					);
			else
			{
				Depart[0] = Convert::ToInt32(textBox1->Text);
				Depart[1] = Convert::ToInt32(textBox2->Text);
				Depart[2] = Convert::ToInt32(textBox3->Text);
				Depart[3] = Convert::ToInt32(textBox4->Text);
				
				
				TArretsf = new int[(Bdo.ConsultParcours(SelParcours).ConsultInt(3)+1)*2];
				for (j=IndiceOrg*2,i=0;i<dataGridView1->Rows->Count;j+=2,i++){
					if ( dataGridView1->Rows[i]->Cells[1]->Equals(String::Empty) ||
						dataGridView1->Rows[i]->Cells[2]->Equals(String::Empty) ||
						(Convert::ToInt32(dataGridView1->Rows[i]->Cells[1]->Value)>Convert::ToInt32(dataGridView1->Rows[i]->Cells[2]->Value))
						)
					{
						System::Windows::Forms::MessageBox::Show(
							"Entrer les informations des temps d'arrets correctement avant de cliquer sur le bouton « valider » !",
							"Informations manquantes",
							MessageBoxButtons::OK,
							MessageBoxIcon::Information
						);
						break;
					}
					else{
						TArretsf[j] = Convert::ToInt32(dataGridView1->Rows[i]->Cells[1]->Value);
						TArretsf[j+1] = Convert::ToInt32(dataGridView1->Rows[i]->Cells[2]->Value);
					}
				}
				Okconfig = true;
				if (i == dataGridView1->Rows->Count) Form2::Close();
			}
	}
}

System::Void Tchoutchou::Form2::button2_Click(System::Object^  sender, System::EventArgs^  e)
{
	Okconfig = false;
	Form2::Close();
}