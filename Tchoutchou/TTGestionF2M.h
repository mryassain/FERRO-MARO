#pragma once
#include "TTFiche2Marche.h"
#include "TTBd.h"

class CTTGestionF2M
{
public:
	CTTGestionF2M(CTTBd *);
	~CTTGestionF2M(void);

	struct fiche {
		CTTFiche2Marche f2m;
		fiche *suivant;
	};
	
	void AjoutFiche(int/*IDtrains*/,int/*IDparcours*/,int*/*Tarrets*/,
		int/*hdepart-*/,int/*mdepart-*/,int/*hdepart+*/,int/*mdepart+*/,int/*iorgine*/,int/*idst*/);

	void SupprFiche(int/*IDparcours*/,int/*IDtrains*/);

	CTTFiche2Marche* ConsultFiche(int/*IDparcours*/,int/*IDtrains*/);

	fiche* ConsultParcours(int);

private:
	struct fiche **parcours;
	CTTBd *Base;
};
