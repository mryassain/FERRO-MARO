#pragma once
#include <string.h>


// CTTTrain

class CTTTrain //: public CWnd
{
	//DECLARE_DYNAMIC(CTTTrain)

public:
	enum Catergorie {
		Tnr,
		Voyageur,
		Fret,
		Phosphat,
		Tgv
	};
	
	CTTTrain();
	virtual ~CTTTrain();
	
	void ModifNomTr(char *);
	void ModifVitTr(int);
	void ModifLongTr(int);
	void ModifCatTr(CTTTrain::Catergorie);
	void ModifTout(char*,int,int,CTTTrain::Catergorie);
	
	char *ConsultNomTr();
	int ConsultVitTr();
	int ConsultLongTr();
	CTTTrain::Catergorie ConsultCatTr();

protected:
	char *NomTr; //nom du train
	int VitTr; // vitesse du train
	int LongTr;
	Catergorie categorie;

	//DECLARE_MESSAGE_MAP()
};


