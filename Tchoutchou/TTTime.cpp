// TTTime.cpp : implementation file
//

#include "stdafx.h"
#include "TTTime.h"


// CTTTime

//IMPLEMENT_DYNAMIC(CTTTime, CWnd)

CTTTime::CTTTime()
{
	Heure = Minute = 0;
	Cylindre = 0;
}

CTTTime::~CTTTime()
{
}

int CTTTime::ConsultHeure(){return Heure;}

int CTTTime::ConsultMinute(){return Minute;}

int CTTTime::ConsultTotalMin(){return Heure*60+Minute;}

System::String^ CTTTime::ConsultHoraire(void){
	System::String ^temp1,^temp2,^temp;
	if (Heure<10) 
		temp1 = System::String::Concat(System::String::Concat("0",System::Convert::ToInt32(Heure)),":");
	else
		temp1 = System::String::Concat(System::Convert::ToInt32(Heure),":");
	if (Minute<10)
		temp2 = System::String::Concat("0",System::Convert::ToInt32(Minute));
	else
		temp2 = System::Convert::ToString(System::Convert::ToInt32(Minute));
	return temp = System::String::Concat(temp1,temp2," "/*,System::Convert::ToInt32(Cylindre)*/) ;
}

int CTTTime::ConsultCylindre(){return Cylindre;}

void CTTTime::ModifHeure(int h){
		Heure = h % 24;
}

void CTTTime::ModifMinute(int m){
		Minute = m % 60;
}

void CTTTime::ModifCylindre(int C){Cylindre = C;}

void CTTTime::AjoutHeure(int h){
	Heure += h;
	if (Heure >= 24)
	 Heure %= 24,Cylindre++;
}

void CTTTime::AjoutMinute(int m){
	Minute += m;
	if (Minute >= 60) {
		AjoutHeure(Minute/60);
		Minute %= 60;
	}
}

void CTTTime::RetrancherMinute(int m){
	int temp = ConsultTotalMin();
	if (m<=temp)
	{
		Heure = (temp - m) /60;
		Minute = (temp - m) % 60;
	}
	else
	{
		Cylindre--;
		m %= 60 * 24;
		m -= ConsultTotalMin();
		
		if ((m/60)!=0)
			Heure = 24 - (m / 60);
		else
			Heure = 0;
		
		if ((m%60)!=0)
		{
			Minute = 60 - (m % 60),Heure?Heure--:Heure=23;
		}
		else
			Minute = 0;
	}
}

CTTTime& CTTTime::operator=(CTTTime& valeur){
	Heure = valeur.Heure;
	Minute = valeur.Minute;
	Cylindre = valeur.Cylindre;
	return *this;
}

bool CTTTime::operator<(CTTTime& valeur){
	if (Cylindre == valeur.Cylindre)
		return (((Heure*60)+Minute)<((valeur.Heure*60)+valeur.Minute));
	else
		return (Cylindre < valeur.Cylindre);
}

bool CTTTime::operator>=(CTTTime& valeur){
	if (Cylindre == valeur.Cylindre)
		return (((Heure*60)+Minute)>=((valeur.Heure*60)+valeur.Minute));
	else
		return (Cylindre > valeur.Cylindre);
}

bool CTTTime::operator>(CTTTime& valeur)
{
	if (Cylindre == valeur.Cylindre)
		return (((Heure*60)+Minute)>((valeur.Heure*60)+valeur.Minute));
	else
		return (Cylindre > valeur.Cylindre);
}

int CTTTime::operator-(CTTTime& valeur){
	int temp ;
	if (Cylindre == valeur.Cylindre)
	{
		temp =((Heure*60)+Minute) - ((valeur.Heure*60)+valeur.Minute);
		return ((temp>0) ? (temp):(-temp));
	}
	else
	{
		if (Cylindre > valeur.Cylindre)
			return ((24*60 - valeur.ConsultTotalMin()) + ((Cylindre - valeur.Cylindre - 1) * 24 * 60 ) + ConsultTotalMin());
		else
			return ((24*60 - ConsultTotalMin()) + ((valeur.Cylindre - Cylindre - 1) * 24 * 60 ) + valeur.ConsultTotalMin());
	}
}

CTTTime CTTTime::operator+(int minute){
	CTTTime temp;
	temp.ModifHeure(Heure);
	temp.ModifMinute(Minute);
	temp.ModifCylindre(Cylindre);
	temp.AjoutMinute(minute);

	return temp;
}

CTTTime CTTTime::operator-(int minute){
	CTTTime temp;
	temp.ModifHeure(Heure);
	temp.ModifMinute(Minute);
	temp.ModifCylindre(Cylindre);
	temp.RetrancherMinute(minute);

	return temp;
}

bool CTTTime::MemCylindre(CTTTime& T1)
{    return(T1.ConsultCylindre()==Cylindre);
}


//BEGIN_MESSAGE_MAP(CTTTime, CWnd)
//END_MESSAGE_MAP()



// CTTTime message handlers


