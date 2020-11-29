#pragma once
#include <stdio.h>
#include <stdlib.h>
#define TAILLEINITIALE 100

/* Creation du type tableau */
typedef struct Tableau
{
	int* elt;// le tableau d’entiers
	int size;// la taille de ce tableau d’entiers
	int eltsCount;// le nombre d’éléments dans le tableau
}TABLEAU;

TABLEAU NewArray(); // prototype de fonction pour la création du tableau
int IncrementArraySize(TABLEAU* , int ); // prototype de fonction pour modifier la taille du tableau 
int SetElement(TABLEAU* tab, int , int ); // prototype de fonction pour insérer un élément dans le tableau
int DisplayElements(TABLEAU* , int , int ); // prototype de fonction pour afficher une portion du tableau
int DeleteElements(TABLEAU* , int , int ); // prototype de fonction pour supprime des éléments avec compactage du tableau