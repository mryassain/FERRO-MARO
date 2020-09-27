// TTBd.cpp : implementation file
//

#include "stdafx.h"
#include "TTBd.h"


// CTTBd

//IMPLEMENT_DYNAMIC(CTTBd, CWnd)

CTTBd::CTTBd()
{
	ID = 0; // chargement de la base par default
	//ChargerBase(ID);
}

CTTBd::~CTTBd()
{
	int i;
	if (Noeuds) {
		for (i=0;i<NNoeuds;i++) Noeuds[i].~CTTNoeud();
		for (i=0;i<NParcours;i++) Parcours[i].~CTTParcours();
		for (i=0;i<NTrains;i++) Trains[i].~CTTTrain();
		
	}
		delete[] Parcours;
		//delete[] Noeuds;
		delete[] Trains;
		delete[] Voies;
	
}

int CTTBd::ChargerFichier(int nom)
{
	FILE *fp;
	char *nomcomplet;
	errno_t err;
	int i;
	static char * NomFich[4] = {"NOEUDS","VOIES","PARCOURS","TRAINS"};

	nomcomplet = new char[19 + strlen(NomFich[nom])];

	nomcomplet[0]='\0';
	
	strcat(nomcomplet,".\\");
	strcat(nomcomplet,CodeFilec);
	strcat(nomcomplet,"\\");
	strcat(nomcomplet,NomFich[nom]);
	strcat(nomcomplet,CodeFilec);
	strcat(nomcomplet,".TT");
	
	if ((err = fopen_s(&fp,nomcomplet,"rb"))!=0)
		return 1;

	switch (nom){
		case 0 :
				fread((int*)&NNoeuds,sizeof(int),1,fp);
				Noeuds = new CTTNoeud[NNoeuds];
				
				for (i=0;i<NNoeuds;i++) {
					fread(&noeud,sizeof(noeud),1,fp);
					nomab = new char[noeud.s1+1];
					nomco = new char[noeud.s2+1];
					rq = new char[noeud.s3+1];
					nomab[noeud.s1]=nomco[noeud.s2]=rq[noeud.s3]=0;

					fread((char *)nomab,sizeof(char),noeud.s1,fp);
					fread((char *)nomco,sizeof(char),noeud.s2,fp);
					fread((char *)rq,sizeof(char),noeud.s3,fp);

					Noeuds[i].ModifCateg(noeud.categ);
					Noeuds[i].ModifPk(noeud.pk);
					Noeuds[i].ModifS(1,nomab);
					Noeuds[i].ModifS(2,nomco);
					Noeuds[i].ModifS(3,rq);

					delete[] nomab;
					delete[] nomco;
					delete[] rq;
				}
				return 0;
		case 1 :
				fread((int*)&NVoies,sizeof(int),1,fp);
				Voies = new CTTVoie[NVoies];

				for (i=0;i<NVoies;i++){
					fread(&voie,sizeof(voie),1,fp);
					Voies[i].ModifOD(voie.org,voie.dest);
					Voies[i].ModifVCat(voie.vitcat);
					Voies[i].ModifVVoie(voie.vitvoie);
					Voies[i].ModifNvoies(voie.nvoies);
				}
				return 0;
		case 2 :
				fread((int*)&NParcours,sizeof(int),1,fp);
				Parcours = new CTTParcours[NParcours];

				for (i=0;i<NParcours;i++){
					fread(&parcours,sizeof(parcours),1,fp);
					origine = new char[parcours.s1+1];
					destination = new char[parcours.s2+1];
					p = new int[parcours.nvoie];
					origine[parcours.s1]=destination[parcours.s2]=0;

					fread((char *)origine,sizeof(char),parcours.s1,fp);
					fread((char *)destination,sizeof(char),parcours.s2,fp);
					fread((int *) p,sizeof(int),parcours.nvoie,fp);

					Parcours[i].ModifInt(1,parcours.org);
					Parcours[i].ModifInt(2,parcours.dest);
					Parcours[i].ModifInt(3,parcours.nvoie);

					Parcours[i].ModifPairImpair(parcours.pairimpair);

					Parcours[i].ModifP(p);
					Parcours[i].ModifOrig(origine);
					Parcours[i].ModifDest(destination);

					delete[] p;
					delete[] origine;
					delete[] destination;
					origine=NULL;
					destination=NULL;p=NULL;
				}
				return 0;
		case 3 :
				fread((int *)&NTrains,sizeof(int),1,fp);
				Trains = new CTTTrain[NTrains];
				
				for (i=0;i<NTrains;i++){
					fread(&train,sizeof(train),1,fp);
					nomtr = new char[train.s1+1];
					nomtr[train.s1]=0;

					fread((char *) nomtr,sizeof(char),train.s1,fp);
					Trains[i].ModifTout(nomtr,train.vittr,train.longtr,train.categ);
					delete[] nomtr;
				}
				return 0;
	}
	return 0;
}

void CTTBd::ChargerBase(int id)
{
	int i;
	static int CodeFilei[6] = {18,16,22,10,15,10}; // -1

	for(i=0;i<6;i++)
		CodeFilec[i]=48+((CodeFilei[i]*(79+id))%10);
	CodeFilec[6] = '\0';

	for (i=0;i<4;i++)
		ChargerFichier(i);
}

int CTTBd::ConsultID(){return ID;}

int CTTBd::ConsultNelements(int index){
	switch (index){
		case 0: return NNoeuds;
		case 1: return NVoies;
		case 2: return NParcours;
		case 3: return NTrains;
	}
	return 0;
}

CTTNoeud& CTTBd::ConsultNoeud(int index) const {
	if (index<NNoeuds)
		return Noeuds[index];
	else
		return Noeuds[0];
}

CTTVoie& CTTBd::ConsultVoie(int index) const {
	if (index<NVoies)
		return Voies[index];
	else
		return Voies[0];
}

CTTParcours& CTTBd::ConsultParcours(int index) const {
	if (index<NParcours)
		return Parcours[index];
	else
		return Parcours[0];
}

CTTTrain& CTTBd::ConsultTrains(int index) const {
	if (index<NTrains)
		return Trains[index];
	else
		return Trains[0];
}


//BEGIN_MESSAGE_MAP(CTTBd, CWnd)
//END_MESSAGE_MAP()



// CTTBd message handlers


