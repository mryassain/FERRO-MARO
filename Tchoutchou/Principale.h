#include "TTBd.h"
#include "TTGestionF2M.h"
#include "TTSexbanagoz.h"

/* 
   Une fonction qui prend en entr�e un pointeur vers une 
   chaine de caract�re,et retourne un tableau de type Object. 
   Chaque �l�ment du tableau contient un caract�re.
*/
cli::array<System::Object^>^ Char_ptoChar(char *);


/*
	Cette fonction sert � cr�er et � initialiser un tableau 
	d'indices ordonn�s de noeuds sur un parcours donn�.
*/
int* InitindNoeud(CTTBd *,int);

