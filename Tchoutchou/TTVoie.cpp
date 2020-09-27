// TTVoie.cpp : implementation file
//

#include "stdafx.h"
#include "TTVoie.h"


// CTTVoie

//IMPLEMENT_DYNAMIC(CTTVoie, CWnd)

CTTVoie::CTTVoie()
{
}

CTTVoie::~CTTVoie()
{
}

int CTTVoie::ConsultOrg()
{
	return Org;
}

int CTTVoie::ConsultDest()
{
	return Dest;
}

int CTTVoie::ConsultVVoie()
{
	return VitVoie;
}

int CTTVoie::ConsultVCat()
{
	return VitCat;
}

int CTTVoie::ConsultNvoies()
{
	return Nvoies;
}

void CTTVoie::ModifOD(int Ori,int Dst)
{
	Org = Ori;
	Dest = Dst;
}

void CTTVoie::ModifVVoie(int V)
{
	VitVoie = V;
}

void CTTVoie::ModifVCat(int V)
{
	VitCat = V;
}

void CTTVoie::ModifNvoies(int V)
{
	Nvoies = V;
}


//BEGIN_MESSAGE_MAP(CTTVoie, CWnd)
//END_MESSAGE_MAP()



// CTTVoie message handlers


