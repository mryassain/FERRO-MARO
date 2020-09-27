#include "StdAfx.h"
#include "TTGestionF2M.h"

CTTGestionF2M::CTTGestionF2M(CTTBd *valeur)
{
	int i;
	Base = valeur;
	parcours = new struct fiche*[Base->ConsultNelements(2)];
	for (i=0;i<Base->ConsultNelements(2);i++)
		parcours[i] = NULL;
}

CTTGestionF2M::~CTTGestionF2M(void)
{
}

void CTTGestionF2M::AjoutFiche(int idtrain,int idparcours,int* tarrets,
				int hdm,int mdm,int hdp,int mdp,int iorg,int idst)
{
	fiche *temp1 = new struct fiche(Base),*temp2,*temp3;
	temp1->f2m->ModifIDParcours(idparcours);
	temp1->f2m->ModifIDTrain(idtrain);
	temp1->f2m->ModifOrgDst(iorg,idst);
	temp1->f2m->ModifTArrets(tarrets);
	temp1->f2m->ModifDepart(hdm,mdm,hdp,mdp);
	temp1->f2m->CalculFiche2Marche();

	temp2 = temp3 = parcours[idparcours];

	while ( (temp2 != NULL) && (temp1->f2m->ConsultDepartm() < temp2->f2m->ConsultDepartm()) )
	{
		temp3 = temp2;
		temp2 = temp2->suivant;
	}

	if (parcours[idparcours] == temp2){
		temp1->suivant = parcours[idparcours];
		parcours[idparcours] = temp1;
	}
	else {
		temp1->suivant = temp2;
		temp3->suivant = temp1;
	}
}

void CTTGestionF2M::SupprFiche(int idparcours,int idtrain)
{
	struct fiche *temp1,*temp2;

	temp1 = temp2 = parcours[idparcours];

	while (temp1->f2m->ConsultIDTrain() != idtrain){
		temp2 = temp1;
		temp1 = temp1->suivant;
	}
	if (parcours[idparcours] == temp1)
		parcours[idparcours] = temp1->suivant;
	else
		temp2->suivant = temp1->suivant;
	
	delete temp1->f2m;
	delete temp1;

}