// TTParcours.cpp : implementation file
//

#include "stdafx.h"
#include "TTParcours.h"


// CTTParcours

//IMPLEMENT_DYNAMIC(CTTParcours, CWnd)

CTTParcours::CTTParcours()
{
	Origine = NULL;
	Destination = NULL;
	P = NULL;
}

CTTParcours::~CTTParcours()
{
	if (P){
		delete[] P;
		delete[] Destination;
		delete[] Origine;
	}
}

char* CTTParcours::ConsultDest()
{
	return Destination;
}

char* CTTParcours::ConsultOrig()
{
	return Origine;
}

int CTTParcours::ConsultInt(int index)
{
	switch (index){
		case 1: return Org;
		case 2: return Dest;
		case 3: return Nvoie;
	}
	return 0;
}

bool CTTParcours::ConsultPairImpair()
{
	return PairImpair;
}

int* CTTParcours::ConsultP()
{
	return P;
}

void CTTParcours::ModifDest(char *string)
{
	if (Destination) delete[] Destination;
	Destination = new char[strlen(string)+1];
	strcpy(Destination,string);
}

void CTTParcours::ModifOrig(char *string)
{
	if (Origine) delete[] Origine;
	Origine = new char[strlen(string)+1];
	strcpy(Origine,string);
}

void CTTParcours::ModifInt(int index, int entier)
{
	switch (index){
		case 1: Org = entier;
				break;
		case 2: Dest = entier;
				break;
		case 3: Nvoie = entier;
	}
}

void CTTParcours::ModifPairImpair(bool valeur)
{
	PairImpair = valeur;
}

void CTTParcours::ModifP(int* tab)
{
	int i;
	P = new int[Nvoie];
	for (i=0;i<Nvoie;i++)
		P[i]=tab[i];
}




//BEGIN_MESSAGE_MAP(CTTParcours, CWnd)
//END_MESSAGE_MAP()



// CTTParcours message handlers


