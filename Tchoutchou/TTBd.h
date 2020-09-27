#pragma once
#include <stdio.h>
#include <string.h>
#include "TTNoeud.h"
#include "TTVoie.h"
#include "TTParcours.h"
#include "TTTrain.h"

// CTTBd

class CTTBd //: public CWnd
{
	//DECLARE_DYNAMIC(CTTBd)

public:
	CTTBd();
	virtual ~CTTBd();
	
	void ChargerBase(int);
	
	int ConsultID();
	int ConsultNelements(int);

	CTTNoeud& ConsultNoeud(int) const;
	CTTVoie& ConsultVoie(int) const;
	CTTParcours& ConsultParcours(int) const;
	CTTTrain& ConsultTrains(int) const;

protected:
	int ID; // Identificateur de la base actuel ( 0=base par default )
	CTTNoeud *Noeuds; // tableau de noeuds
	CTTVoie *Voies; // tableau de voies
	CTTParcours *Parcours; // tableau de parcours
	CTTTrain *Trains; // tableau de trains

	int NNoeuds,NVoies,NParcours,NTrains; // nombres d'elements des tableaux
	char CodeFilec[7];

	/****************************************************************
	 mini structures pour la lecture et l'ecriture sur les fichiers 
	****************************************************************/
	struct  {
		CTTNoeud::Categorie categ;
		float pk; // position kilometrique
		char s1,s2,s3; // taille des chaines de caracteres
	} noeud;
	struct {
		int org,dest;
		int vitvoie,vitcat;
		int nvoies;
	} voie;
	struct {
		int org,dest,nvoie;
		bool pairimpair;
		char s1,s2; // taille des chaines de caracteres
	} parcours;
	struct {
		int vittr;
		int longtr;
		CTTTrain::Catergorie categ;
		char s1; // taille de la chaine de caractere
	} train;

	char *nomab,*nomco,*rq; // complement struct noeud
	char *origine,*destination; // complement struct parcours
	int *p; // complement struct parcours
	char *nomtr; // complement struct train

	int ChargerFichier(int);

	//DECLARE_MESSAGE_MAP()
};


