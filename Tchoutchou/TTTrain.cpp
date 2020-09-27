// TTTrain.cpp : implementation file
//

#include "stdafx.h"
#include "TTTrain.h"


// CTTTrain

//IMPLEMENT_DYNAMIC(CTTTrain, CWnd)


CTTTrain::CTTTrain()
{
	NomTr = NULL;
}

void CTTTrain::ModifTout(char * Nom,int Vit,int longueur,CTTTrain::Catergorie categ)
{
	if (NomTr)
		delete NomTr;
	NomTr=new char[strlen(Nom)+1];
	strcpy(NomTr,Nom);

	VitTr = Vit;
	LongTr = longueur;
	categorie = categ;
}

CTTTrain::~CTTTrain()
{
	if (NomTr)
		delete[] NomTr;
}

void CTTTrain::ModifNomTr(char * Nom)
{
	if (NomTr)
		delete[] NomTr;
	NomTr=new char[strlen(Nom)+1];
	strcpy(NomTr,Nom);
}

void CTTTrain::ModifVitTr(int Vit){VitTr=Vit;}

void CTTTrain::ModifLongTr(int longueur){LongTr=longueur;}

void CTTTrain::ModifCatTr(CTTTrain::Catergorie categ){categorie = categ;}


char* CTTTrain::ConsultNomTr(){return NomTr;}

int CTTTrain::ConsultVitTr(){return VitTr;}

int CTTTrain::ConsultLongTr(){return LongTr;}

CTTTrain::Catergorie CTTTrain::ConsultCatTr(){return categorie;}

//BEGIN_MESSAGE_MAP(CTTTrain, CWnd)
//END_MESSAGE_MAP()



// CTTTrain message handlers


