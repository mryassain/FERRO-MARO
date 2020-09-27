#pragma once
#include <string.h>

// CTTNoeud

class CTTNoeud
{

public:
	enum Categorie { // les differentes categorie d'un noeud
		Bif, 
		Gare,
		Halt,
		Poste
	};

	CTTNoeud(); // constructeur
	virtual ~CTTNoeud(); // destructeur
	
	// les méthodes permettant de consulter les attributs
	char* ConsultS(int); 
	CTTNoeud::Categorie ConsultCateg();
	float ConsultPk();

	// les méthodes permettant de modifier les attributs
	void ModifS(int,char *);
	void ModifCateg(CTTNoeud::Categorie);
	void ModifPk(float);

protected:
	char *NomAb; // Nom abregé du noeud
	char *NomCo; // Nom complet
	Categorie categorie;
	char *Rq; // Remarque sur la noeud
	float Pk; // Position kilometrique

};


