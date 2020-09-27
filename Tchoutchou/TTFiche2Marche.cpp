// TTFiche2Marche.cpp : implementation file
//

#include "stdafx.h"
#include "TTFiche2Marche.h"
#include "Principale.h"


// CTTFiche2Marche

//IMPLEMENT_DYNAMIC(CTTFiche2Marche, CWnd)

CTTFiche2Marche::CTTFiche2Marche(CTTBd *Based)
{
	Base = Based;
	Vitesse = TArrets = MarcheType = NULL;
	Distance = MargeBase = MargeRegul = NULL;
}

CTTFiche2Marche::CTTFiche2Marche()
{
	Base = NULL;
	Vitesse = TArrets = MarcheType = NULL;
	Distance = MargeBase = MargeRegul = NULL;
}

CTTFiche2Marche::~CTTFiche2Marche()
{
	if (TArrets) delete[] TArrets;
	if (MarcheType) {
		delete[] MarcheType;
		delete[] Distance;
		delete[] MargeBase;
		delete[] MargeRegul;
		delete[] Vitesse;
	}
	if (ArriveeDepart)
		delete[] ArriveeDepart;
}

void CTTFiche2Marche::ModifIDTrain(int valeur){IDTrain = valeur;}

void CTTFiche2Marche::ModifIDParcours(int valeur){IDParcours = valeur;}

void CTTFiche2Marche::ModifDepart(int heurn,int minn,int heurp,int minp){
	if ((heurn*60 + minn)>(heurp * 60 + minp))
		Depart[0].ModifCylindre(-1);

	Depart[0].ModifHeure(heurn);
	Depart[0].ModifMinute(minn);
	Depart[1].ModifHeure(heurp);
	Depart[1].ModifMinute(minp);
}

void CTTFiche2Marche::ModifBase(CTTBd *pointeur){Base = pointeur;}

void CTTFiche2Marche::ModifTArrets(int *tableau){
	int i,NVoies;
	NVoies = Base->ConsultParcours(IDParcours).ConsultInt(3);
	TArrets = new int[(NVoies+1)*2];

	for (i=IndiceOrg*2;i<=((IndiceDst)*2);i++)
		TArrets[i] = tableau[i];
}

void CTTFiche2Marche::ModifOrgDst(int val1,int val2)
{
	IndiceOrg = val1;
	IndiceDst = val2;
}


CTTTime CTTFiche2Marche::ConsultDepartm(){
	return Depart[0];
}

CTTTime CTTFiche2Marche::ConsultDepartp(){
	return Depart[1];
}

int CTTFiche2Marche::ConsultIDTrain(){
	return IDTrain;
}

int CTTFiche2Marche::ConsultIDParcours(){
	return IDParcours;
}

int CTTFiche2Marche::ConsultOrgDst(int index){
	switch (index){
		case 0 : return IndiceOrg;
		case 1 : return IndiceDst;
	}
}

float* CTTFiche2Marche::ConsultDMbMr(int index)
{
	switch (index) {
		case 0 : return Distance;
		case 1 : return MargeBase;
		case 2 : return MargeRegul;
	}
}

int* CTTFiche2Marche::ConsultVMt(int index){
	switch (index) {
		case 0 : return Vitesse;
		case 1 : return MarcheType;
	}
}

CTTTime* CTTFiche2Marche::ConsultH(void){
	return ArriveeDepart;
}

int* CTTFiche2Marche::ConsultTArrets(void){
	return TArrets;
}

void CTTFiche2Marche::CalculFiche2Marche(){
	int i,NVoies = Base->ConsultParcours(IDParcours).ConsultInt(3);
	int *Par = Base->ConsultParcours(IDParcours).ConsultP();
	float PKorg,PKdst;
	int *inNoeud = NULL;
	TotalTArrets = 0;

	Distance = new float[NVoies+2];
	MargeBase = new float[NVoies+2];
	MargeRegul = new float[NVoies+2];
	Vitesse = new int[NVoies];
	MarcheType = new int[NVoies+2];


	ArriveeDepart = new CTTTime[(NVoies+1)*4];

	Distance[NVoies+1] = 0;
	MargeBase[NVoies+1] = 0;
	MargeRegul[NVoies+1] = 0;
	MarcheType[NVoies+1] = 0;

	ArriveeDepart[IndiceOrg*4+0] = Depart[0];
	ArriveeDepart[IndiceOrg*4+1] = Depart[1];
	ArriveeDepart[IndiceOrg*4+2] = Depart[0];
	ArriveeDepart[IndiceOrg*4+3] = Depart[1];

	inNoeud = InitindNoeud(Base,IDParcours);

	for (i=IndiceOrg+1;i<=IndiceDst;i++) {
		PKorg = Base->ConsultNoeud(inNoeud[i-1]).ConsultPk();
		PKdst = Base->ConsultNoeud(inNoeud[i]).ConsultPk();
		Distance[i] = (PKorg > PKdst)? (PKorg-PKdst):(PKdst-PKorg);	
		Distance[NVoies+1]+=Distance[i];
		Vitesse[i] = min((min(Base->ConsultVoie(Par[i-1]).ConsultVCat(),Base->ConsultVoie(Par[i-1]).ConsultVVoie())),Base->ConsultTrains(IDTrain).ConsultVitTr());

		MargeBase[i] = (Distance[i]*60)/Vitesse[i];
		MargeRegul[i] = MargeBase[i] * 0.1f;
		MarcheType[i] = (int) (MargeBase[i]+MargeRegul[i]+1);
		MargeBase[NVoies+1] +=MargeBase[i];
		MargeRegul[NVoies+1] += MargeRegul[i];
		MarcheType[NVoies+1] += MarcheType[i];

		ArriveeDepart[4*i + 0] = ArriveeDepart[4*i - 2];
		ArriveeDepart[4*i + 0].AjoutMinute(MarcheType[i]);

		ArriveeDepart[4*i + 1] = ArriveeDepart[4*i - 1];
		ArriveeDepart[4*i + 1].AjoutMinute(MarcheType[i]);

		ArriveeDepart[4*i + 2] = ArriveeDepart[4*i + 0];
		ArriveeDepart[4*i + 2].AjoutMinute(TArrets[(i-1)*2]);

		ArriveeDepart[4*i + 3] = ArriveeDepart[4*i + 1];
		ArriveeDepart[4*i + 3].AjoutMinute(TArrets[(i-1)*2]);

		TotalTArrets += TArrets[(i-1)*2];
	}
	delete[] inNoeud;
}

int CTTFiche2Marche::Calsf2m(void)
{
	int NVoies = Base->ConsultParcours(IDParcours).ConsultInt(3);
	return (MarcheType[NVoies+1] + TotalTArrets);
}



//BEGIN_MESSAGE_MAP(CTTFiche2Marche, CWnd)
//END_MESSAGE_MAP()



// CTTFiche2Marche message handlers


