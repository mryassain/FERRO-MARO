#pragma once
#include "TTBd.h"
#include "TTTime.h"



// CTTFiche2Marche

class CTTFiche2Marche //: public CWnd
{
	//DECLARE_DYNAMIC(CTTFiche2Marche)

public:
	CTTFiche2Marche(CTTBd*);
	CTTFiche2Marche();
	virtual ~CTTFiche2Marche();

	void ModifIDTrain(int);
	void ModifIDParcours(int);
	void ModifDepart(int,int,int,int);
	void ModifBase(CTTBd*);
	void ModifTArrets(int*);
	void ModifOrgDst(int,int);

	CTTTime ConsultDepartm();
	CTTTime ConsultDepartp();
	int ConsultIDTrain();
	int ConsultIDParcours();
	int ConsultOrgDst(int);
	float* ConsultDMbMr(int);
	int* ConsultVMt(int);
	CTTTime* ConsultH(void);
	int* ConsultTArrets(void);

	void CalculFiche2Marche();
	int  Calsf2m(void);

protected:
	int IDTrain,IDParcours;
	int *TArrets,TotalTArrets;
	CTTTime Depart[2];
	CTTBd *Base;
	int IndiceOrg,IndiceDst;

	float *Distance,*MargeBase,*MargeRegul;
	int *Vitesse,*MarcheType;

	CTTTime *ArriveeDepart;

	//DECLARE_MESSAGE_MAP()
};


