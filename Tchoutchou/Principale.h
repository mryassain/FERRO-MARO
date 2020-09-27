#include "TTBd.h"
#include "TTGestionF2M.h"
#include "TTSexbanagoz.h"

/* 
   Une fonction qui prend en entrée un pointeur vers une 
   chaine de caractère,et retourne un tableau de type Object. 
   Chaque élément du tableau contient un caractère.
*/
cli::array<System::Object^>^ Char_ptoChar(char *);


/*
	Cette fonction sert à créer et à initialiser un tableau 
	d'indices ordonnés de noeuds sur un parcours donné.
*/
int* InitindNoeud(CTTBd *,int);

