#include "StdAfx.h"
#include "Principale.h"
#include "TTSexbanagoz.h"
#include "Form7.h"
#include "Form6.h"
#include "Form1.h"

extern int choixgraphique;
extern CTTBd Bdo;
extern CTTGestionF2M* Gf2m;
extern CTTSexbanagoz *Algo;
extern int Ntrainfichefixe;
extern bool algoappliquee;
extern int SelParcours,SelTrain;
extern int *inNoeud;
extern int NTrain;

int NVoies;
float PKorg,PKdst,*Distance;


System::Void Tchoutchou::Form7::Form7_Load(System::Object^  sender, System::EventArgs^  e)
{
	int i;
	NVoies = Bdo.ConsultParcours(0).ConsultInt(3);
	inNoeud = InitindNoeud(&Bdo,0);
	Distance = new float[NVoies+2];
	noeudX = gcnew cli::array<System::Drawing::PointF>(25);
	noeudY = gcnew cli::array<System::Drawing::PointF>(NVoies+1);
	
	for (i=1;i<NVoies+1;i++) {
		PKorg = Bdo.ConsultNoeud(inNoeud[i-1]).ConsultPk();
		PKdst = Bdo.ConsultNoeud(inNoeud[i]).ConsultPk();
		Distance[i] = (PKorg > PKdst)? (PKorg-PKdst):(PKdst-PKorg);	
		Distance[NVoies+1]+=Distance[i];
	}
}

void Tchoutchou::Form7::DessinerGrille()
{
	int i;

	noeudX[0].Y::set(0);
	noeudX[0].X::set((float) (110));
	for (int i=1;i<noeudX->Length;i++)
	{
		noeudX[i].Y::set(0);
		noeudX[i].X::set(noeudX[i-1].X + (((float)(this->Width-130))/(float)24));
	}

	noeudY[0].X::set(0);
	noeudY[0].Y::set((float)0);
	for (i=1;i<noeudY->Length;i++)
	{
		noeudY[i].X::set(0);
		noeudY[i].Y::set(noeudY[i-1].Y + ((Distance[i]*((float)(this->Height-50)))/Distance[NVoies+1]));
	}

	System::Drawing::Font^ taktak = gcnew System::Drawing::Font("Arial",8);
	Richa = gcnew SolidBrush(System::Drawing::Color::Black);
	Stylo = gcnew System::Drawing::Pen(System::Drawing::Color::Black);
	TableDessin = this->CreateGraphics();
	System::Drawing::PointF pointtemp1,pointtemp2;
	for (i=0;i<NVoies+1;i++)
	{
		TableDessin->DrawString(System::Convert::ToString(System::Convert::ToSingle(Bdo.ConsultNoeud(inNoeud[i]).ConsultPk())),taktak,Richa,noeudY[i]);
		pointtemp1 = noeudY[i];
		pointtemp1.X = pointtemp1.X + 30;
		TableDessin->DrawString(System::String::Concat(Char_ptoChar(Bdo.ConsultNoeud(inNoeud[i]).ConsultS(2))),taktak,Richa,pointtemp1);
		pointtemp1.X = pointtemp1.X + 80;
		pointtemp1.Y = noeudY[i].Y+6;
		pointtemp2.X = noeudX[24].X;
		pointtemp2.Y = noeudY[i].Y+6;
		TableDessin->DrawLine(Stylo,pointtemp1,pointtemp2);	
		pointtemp1.Y = noeudY[i].Y+5;
		pointtemp2.Y = noeudY[i].Y+7;
		for (int j=0;j<24;j++){
			pointtemp1.X = noeudX[j].X;
			for (int k=0;k<12;k++){
				pointtemp1.X =	pointtemp1.X + (((((float)(this->Width-130))/(float)24))/12);
				pointtemp2.X = pointtemp1.X;
				TableDessin->DrawLine(Stylo,pointtemp1,pointtemp2);
			}
		}
	}
	for (i=0;i<25;i++)
	{
		pointtemp1.X = noeudX[i].X;
		pointtemp1.Y = noeudY[0].Y+6;
		pointtemp2.X = noeudX[i].X;
		pointtemp2.Y = noeudY[NVoies].Y+6;
		TableDessin->DrawLine(Stylo,pointtemp1,pointtemp2);
		pointtemp1.X = noeudX[i].X;
		pointtemp1.Y = noeudY[NVoies].Y+5;
		TableDessin->DrawString(System::Convert::ToString(System::Convert::ToInt32(i)),taktak,Richa,pointtemp1);
	}
}

void Tchoutchou::Form7::AvantAlgo()
{ 
	TableDessin = this->CreateGraphics();
	System::Drawing::Color couleurTrain;
	int k,j,i;
	CTTGestionF2M::fiche *temp;

	for(j=0,i=0;i<Bdo.ConsultNelements(2);i++)
	{
		if (temp = Gf2m->ConsultParcours(i))
		{
			if (Bdo.ConsultParcours(i).ConsultPairImpair())
			{
				while (temp != NULL && j < NTrain)
				{
					System::Drawing::PointF pointtemp1(-1,-1),pointtemp2(-1,-1),
						pointtemp3(-1,-1),pointtemp4(-1,-1);
					cli::array<System::Drawing::PointF>^ Polypoint = {pointtemp1,pointtemp2,
						pointtemp4,pointtemp3};
					switch (Bdo.ConsultTrains(temp->f2m.ConsultIDTrain()).ConsultCatTr()) {
						case 0 : couleurTrain = System::Drawing::Color::Green;break;
						case 1 : couleurTrain = System::Drawing::Color::Red;break;
						case 2 : couleurTrain = System::Drawing::Color::Blue;break;
						case 3 : couleurTrain = System::Drawing::Color::Violet;
					}
					Richa = gcnew SolidBrush(System::Drawing::Color::FromArgb(System::Convert::ToInt32(90),couleurTrain));
					Stylo = gcnew System::Drawing::Pen(couleurTrain,1.5f);
					for (k=0;k<Bdo.ConsultParcours(temp->f2m.ConsultIDParcours()).ConsultInt(3);k++)
					{
						if ((temp->f2m.ConsultOrgDst(0)<=k) && (temp->f2m.ConsultOrgDst(1)>k))
						{
							Polypoint[0].Y = noeudY[k].Y + 6;
							Polypoint[1].Y = noeudY[k].Y + 6;
							Polypoint[0].X = ((float)(temp->f2m.ConsultH())[4 * k + 2].ConsultTotalMin() * (float)(this->Width-130))/(float)(60*24) + 110;
							Polypoint[1].X = ((float)(temp->f2m.ConsultH())[4 * k + 3].ConsultTotalMin() * (float)(this->Width-130))/(float)(60*24) + 110;
							Polypoint[3].Y = noeudY[k+1].Y + 6;
							Polypoint[2].Y = noeudY[k+1].Y + 6;
							Polypoint[3].X = ((float)(temp->f2m.ConsultH())[4 * k + 4].ConsultTotalMin() * (float)(this->Width-130))/(float)(60*24) + 110;
							Polypoint[2].X = ((float)(temp->f2m.ConsultH())[4 * k + 5].ConsultTotalMin() * (float)(this->Width-130))/(float)(60*24) + 110;
							if (Polypoint[0].X<=noeudX[24].X && Polypoint[1].X<=noeudX[24].X && Polypoint[2].X<=noeudX[24].X && Polypoint[3].X<=noeudX[24].X)
							{
								TableDessin->DrawPolygon(Stylo,Polypoint);
								TableDessin->FillPolygon(Richa,Polypoint);
							}
						}
					}
					temp = temp->suivant;
					j++;
				}
			}
			else
			{
				while (temp != NULL && j < NTrain)
				{
					System::Drawing::PointF pointtemp1(-1,-1),pointtemp2(-1,-1),
						pointtemp3(-1,-1),pointtemp4(-1,-1);
					cli::array<System::Drawing::PointF>^ Polypoint = {pointtemp1,pointtemp2,
						pointtemp4,pointtemp3};
					switch (Bdo.ConsultTrains(temp->f2m.ConsultIDTrain()).ConsultCatTr()) {
						case 0 : couleurTrain = System::Drawing::Color::Green;break;
						case 1 : couleurTrain = System::Drawing::Color::Red;break;
						case 2 : couleurTrain = System::Drawing::Color::Blue;break;
						case 3 : couleurTrain = System::Drawing::Color::Violet;
					}
					Richa = gcnew SolidBrush(System::Drawing::Color::FromArgb(System::Convert::ToInt32(90),couleurTrain));
					Stylo = gcnew System::Drawing::Pen(couleurTrain,1.5f);
					for (k=0;k<Bdo.ConsultParcours(temp->f2m.ConsultIDParcours()).ConsultInt(3);k++)
					{
						if ((temp->f2m.ConsultOrgDst(0)<=k) && (temp->f2m.ConsultOrgDst(1)>k))
						{
							Polypoint[0].Y = noeudY[Bdo.ConsultParcours(temp->f2m.ConsultIDParcours()).ConsultInt(3)-k].Y + 6;
							Polypoint[1].Y = noeudY[Bdo.ConsultParcours(temp->f2m.ConsultIDParcours()).ConsultInt(3)-k].Y + 6;
							Polypoint[0].X = ((float)(temp->f2m.ConsultH())[4 * k + 2].ConsultTotalMin() * (float)(this->Width-130))/(float)(60*24) + 110;
							Polypoint[1].X = ((float)(temp->f2m.ConsultH())[4 * k + 3].ConsultTotalMin() * (float)(this->Width-130))/(float)(60*24) + 110;
							Polypoint[3].Y = noeudY[Bdo.ConsultParcours(temp->f2m.ConsultIDParcours()).ConsultInt(3)-k-1].Y + 6;
							Polypoint[2].Y = noeudY[Bdo.ConsultParcours(temp->f2m.ConsultIDParcours()).ConsultInt(3)-k-1].Y + 6;
							Polypoint[3].X = ((float)(temp->f2m.ConsultH())[4 * k + 4].ConsultTotalMin() * (float)(this->Width-130))/(float)(60*24) + 110;
							Polypoint[2].X = ((float)(temp->f2m.ConsultH())[4 * k + 5].ConsultTotalMin() * (float)(this->Width-130))/(float)(60*24) + 110;
							if (Polypoint[0].X<=noeudX[24].X && Polypoint[1].X<=noeudX[24].X && Polypoint[2].X<=noeudX[24].X && Polypoint[3].X<=noeudX[24].X)
							{
								TableDessin->DrawPolygon(Stylo,Polypoint);
								TableDessin->FillPolygon(Richa,Polypoint);
							}
						}
					}
					temp = temp->suivant;
					j++;
				}
			}
		}
	}
}

void Tchoutchou::Form7::ApresAlgo()
{
}

void Tchoutchou::Form7::ApresFixation()
{
	TableDessin = this->CreateGraphics();
	System::Drawing::Color couleurTrain;
	for (int i=0;i<Algo->ConsultNtrainfixe();i++){
		System::Drawing::PointF pointtemp1(-1,-1),pointtemp2(-1,-1);
		switch (Bdo.ConsultTrains(Algo->ConsultTrainfixe(i)->IDtrain).ConsultCatTr()) {
			case 0 : couleurTrain = System::Drawing::Color::Green;break;
			case 1 : couleurTrain = System::Drawing::Color::Red;break;
			case 2 : couleurTrain = System::Drawing::Color::Blue;break;
			case 3 : couleurTrain = System::Drawing::Color::Violet;
		}
		Stylo = gcnew System::Drawing::Pen(couleurTrain,2.5f);
		if (Algo->ConsultTrainfixe(i)->IDParcours == 0)
		{
			for (int j=Gf2m->ConsultFiche(Algo->ConsultTrainfixe(i)->IDParcours,Algo->ConsultTrainfixe(i)->IDtrain)->ConsultOrgDst(0);j<Gf2m->ConsultFiche(Algo->ConsultTrainfixe(i)->IDParcours,Algo->ConsultTrainfixe(i)->IDtrain)->ConsultOrgDst(1);j++){
				pointtemp1.Y = noeudY[j].Y + 6;
				pointtemp1.X = ((float)Algo->ConsultTrainfixe(i)->p_horaire[j].DepartArrivee[0].ConsultTotalMin() * (float)(this->Width-130))/(float)(60*24) + 110;
				if (pointtemp1.X!=pointtemp2.X && pointtemp2.X!=-1 )
					TableDessin->DrawLine(Stylo,pointtemp1.X,noeudY[j].Y+6,pointtemp2.X,noeudY[j].Y+6);
				pointtemp2.Y = noeudY[j+1].Y + 6;
				pointtemp2.X = ((float)Algo->ConsultTrainfixe(i)->p_horaire[j].DepartArrivee[1].ConsultTotalMin() * (float)(this->Width-130))/(float)(60*24) + 110;
				if (pointtemp1.X<pointtemp2.X)
					TableDessin->DrawLine(Stylo,pointtemp1,pointtemp2);
				else
				{
					System::Drawing::PointF pointtemp3;
					pointtemp3.X = noeudX[24].X;
					pointtemp3.Y = ((pointtemp1.Y*(noeudX[24].X - pointtemp2.X) + pointtemp2.Y * (pointtemp1.X - noeudX[24].X))/(pointtemp1.X - pointtemp2.X)) + 6;
					TableDessin->DrawLine(Stylo,pointtemp1,pointtemp3);
					pointtemp3.X = noeudX[0].X;
					TableDessin->DrawLine(Stylo,pointtemp3,pointtemp2);
				}
			}
		}
		else
		{
			for (int m=Bdo.ConsultParcours(Algo->ConsultTrainfixe(i)->IDParcours).ConsultInt(3)-Gf2m->ConsultFiche(Algo->ConsultTrainfixe(i)->IDParcours,Algo->ConsultTrainfixe(i)->IDtrain)->ConsultOrgDst(0),j=Gf2m->ConsultFiche(Algo->ConsultTrainfixe(i)->IDParcours,Algo->ConsultTrainfixe(i)->IDtrain)->ConsultOrgDst(0);j<Gf2m->ConsultFiche(Algo->ConsultTrainfixe(i)->IDParcours,Algo->ConsultTrainfixe(i)->IDtrain)->ConsultOrgDst(1);j++,m--){
				pointtemp1.Y = noeudY[m].Y + 6;
				pointtemp1.X = ((float)Algo->ConsultTrainfixe(i)->p_horaire[j].DepartArrivee[0].ConsultTotalMin() * (float)(this->Width-130))/(float)(60*24) + 110;
				if (pointtemp1.X!=pointtemp2.X && pointtemp2.X!=-1 )
					TableDessin->DrawLine(Stylo,pointtemp1.X,noeudY[m].Y+6,pointtemp2.X,noeudY[m].Y+6);
				pointtemp2.Y = noeudY[m-1].Y + 6;
				pointtemp2.X = ((float)Algo->ConsultTrainfixe(i)->p_horaire[j].DepartArrivee[1].ConsultTotalMin() * (float)(this->Width-130))/(float)(60*24) + 110;
				if (pointtemp1.X<pointtemp2.X)
					TableDessin->DrawLine(Stylo,pointtemp1,pointtemp2);
				else
				{
					System::Drawing::PointF pointtemp3;
					pointtemp3.X = noeudX[24].X;
					pointtemp3.Y = ((pointtemp1.Y*(noeudX[24].X - pointtemp2.X) + pointtemp2.Y * (pointtemp1.X - noeudX[24].X))/(pointtemp1.X - pointtemp2.X)) + 6;
					TableDessin->DrawLine(Stylo,pointtemp1,pointtemp3);
					pointtemp3.X = noeudX[0].X;
					TableDessin->DrawLine(Stylo,pointtemp3,pointtemp2);
				}
			}
		}
		System::Drawing::Font^ taktak = gcnew System::Drawing::Font("Arial",11);
		Richa = gcnew SolidBrush(couleurTrain);
		pointtemp2.Y -= 12; 
		TableDessin->DrawString(System::String::Concat(Char_ptoChar(Bdo.ConsultTrains(Algo->ConsultTrainfixe(i)->IDtrain).ConsultNomTr())),taktak,Richa,pointtemp2);
	}
}

System::Void Tchoutchou::Form7::Form7_Paint(System::Object^  sender, System::Windows::Forms::PaintEventArgs^  e)
{
	DessinerGrille();
	switch (choixgraphique){
		case 0 : AvantAlgo();break;
		case 1 : ApresAlgo();break;
		case 2 : ApresFixation();
	}
}