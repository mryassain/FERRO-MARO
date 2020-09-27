#include "stdafx.h"
#include "Principale.h"




cli::array<System::Object^>^ Char_ptoChar(char *valeur)
{
	cli::array<System::Object^,1>^ retour;
	int i;
	retour = gcnew array<System::Object^,1>(strlen(valeur));
	i = 0;
	for (i=0;i<(int)strlen(valeur);i++){
		retour[i] = System::Convert::ToChar(valeur[i]);
	}
	return retour;
}



int* InitindNoeud(CTTBd *base,int Idparcours)
{
	int i;
	int Nvoie = base->ConsultParcours(Idparcours).ConsultInt(3);
	int *P = base->ConsultParcours(Idparcours).ConsultP();
	int *N = new int[Nvoie+1];
	for (i=0;i<Nvoie;i++)
	{
		if (base->ConsultParcours(Idparcours).ConsultPairImpair())
			N[i] = base->ConsultVoie(P[i]).ConsultOrg();
		else
			N[i] = base->ConsultVoie(P[i]).ConsultDest();
	}
	
	if (base->ConsultParcours(Idparcours).ConsultPairImpair()) 
			N[Nvoie] = base->ConsultVoie(P[Nvoie-1]).ConsultDest();
		else
			N[Nvoie] = base->ConsultVoie(P[Nvoie-1]).ConsultOrg();
	return N;
}