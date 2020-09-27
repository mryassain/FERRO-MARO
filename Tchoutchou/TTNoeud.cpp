// TTNoeud.cpp : implementation file
//

#include "stdafx.h"
#include "TTNoeud.h"
#include "Principale.h" // a suprimé


// CTTNoeud


CTTNoeud::CTTNoeud()
{
	// initialisation des pointeurs par la valeur nulle
	NomAb = NomCo = Rq = NULL; 
}

CTTNoeud::~CTTNoeud()
{
	if (NomAb || NomCo){ // libére l'espace alloué par new
		delete[] NomAb;
		delete[] NomCo;
		if (Rq) delete[] Rq;
	}
}

// retourne les pointeurs sur char par index de l'attribut
char* CTTNoeud::ConsultS(int index)
{
	switch (index){
		case 1 : return NomCo;
		case 2 : return NomAb;
		case 3 : return Rq;
	}
	return NULL;
}

CTTNoeud::Categorie CTTNoeud::ConsultCateg(){return categorie;}

float CTTNoeud::ConsultPk(){return Pk;}

// Modification des attributs char* par index
void CTTNoeud::ModifS(int index,char *string)
{
	switch (index){
		case 1: NomAb = new char[strlen(string)+1];
			strcpy(NomAb,string);
				break;		
		case 2: NomCo = new char[strlen(string)+1];
			    strcpy(NomCo,string);
				break;
		case 3: Rq = new char[strlen(string)+1];
				strcpy(Rq,string);
	}
}

void CTTNoeud::ModifCateg(CTTNoeud::Categorie categ){categorie = categ;}

void CTTNoeud::ModifPk(float reel){Pk = reel;}

//BEGIN_MESSAGE_MAP(CTTNoeud, CWnd)
//END_MESSAGE_MAP()



// CTTNoeud message handlers


