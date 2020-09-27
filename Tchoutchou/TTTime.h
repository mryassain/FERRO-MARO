#pragma once

// CTTTime

class CTTTime //: public CWnd
{
	//DECLARE_DYNAMIC(CTTTime)

public:
	CTTTime();
	virtual ~CTTTime();

	int ConsultHeure();
	int ConsultMinute();
	int ConsultTotalMin();
	System::String^ ConsultHoraire(void);
	int ConsultCylindre();

	void ModifHeure(int);
	void ModifMinute(int);
	void ModifCylindre(int);

	void AjoutHeure(int);
	void AjoutMinute(int);
	void RetrancherMinute(int);

	CTTTime& operator=(CTTTime&);
	bool operator<(CTTTime&);
	bool operator>(CTTTime&);
	bool operator>=(CTTTime&);
	int operator-(CTTTime&);
	bool MemCylindre(CTTTime&);     
	CTTTime operator+(int);
	CTTTime operator-(int);

protected:
	int Heure;
	int Minute;
	int Cylindre;
	//DECLARE_MESSAGE_MAP()
};


