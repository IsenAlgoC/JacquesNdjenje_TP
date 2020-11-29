#pragma once
#include <stdio.h>
#include <stdlib.h>
#define TAILLEINITIALE 100

/* Creation du type tableau */
typedef struct Tableau
{
	int* elt;// le tableau d�entiers
	int size;// la taille de ce tableau d�entiers
	int eltsCount;// le nombre d��l�ments dans le tableau
}TABLEAU;

TABLEAU NewArray(); // prototype de fonction pour la cr�ation du tableau
int IncrementArraySize(TABLEAU* , int ); // prototype de fonction pour modifier la taille du tableau 
int SetElement(TABLEAU* tab, int , int ); // prototype de fonction pour ins�rer un �l�ment dans le tableau
int DisplayElements(TABLEAU* , int , int ); // prototype de fonction pour afficher une portion du tableau
int DeleteElements(TABLEAU* , int , int ); // prototype de fonction pour supprime des �l�ments avec compactage du tableau