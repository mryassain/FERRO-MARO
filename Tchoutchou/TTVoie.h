#pragma once


// CTTVoie

class CTTVoie// : public CWnd
{
	//DECLARE_DYNAMIC(CTTVoie)

public:
	CTTVoie();
	virtual ~CTTVoie();

	int ConsultOrg();
	int ConsultDest();
	int ConsultVVoie();
	int ConsultVCat();
	int ConsultNvoies();

	void ModifOD(int,int);
	void ModifVVoie(int);
	void ModifVCat(int);
	void ModifNvoies(int);


protected:	
	int Org,Dest;
	int VitVoie,VitCat;
	int Nvoies;

	//DECLARE_MESSAGE_MAP()
};


