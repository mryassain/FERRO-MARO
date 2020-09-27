#pragma once
#include <string.h>


// CTTParcours

class CTTParcours //: public CWnd
{
	//DECLARE_DYNAMIC(CTTParcours)

public:
	CTTParcours();
	virtual ~CTTParcours();

	char *ConsultDest();
	char *ConsultOrig();
	int ConsultInt(int);
	bool ConsultPairImpair();
	int *ConsultP();

	void ModifDest(char *);
	void ModifOrig(char *);
	void ModifInt(int,int);
	void ModifPairImpair(bool);
	void ModifP(int*);



protected:
	char *Origine,*Destination;
	int Org,Dest;
	int Nvoie;
	bool PairImpair;
	int *P;

	//DECLARE_MESSAGE_MAP()
};


