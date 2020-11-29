#include "tab.h"

/* fonction pour initialiser un tableau de taille variable avec des 0 */

int initTab(int* tab, int size)
{
	if ((tab == NULL) || size < 0) // condition � traiter dans le cas ou tab est un pointeur NULL o� si la taille est n�gative 
	{
		return -1; // on renvoit -1 si la condition pr�c�dente est rempli
	}
	for (int i = 0; i < size; i++) // boulcle qui va nous permettre de parcourir chaque case du tableau
	{
		*(tab + i) = 0; // on affecte la valeur 0 � chaque case du tableau lorques la boucle for parcour le tableau
	}
	return size; // on renvoit la taille du tableau s'il n'y a pas d'erreur
}

/* fonction pour afficher le tableau */

int afficheTab(int* tab, int size, int nbElts)
{
	if ((tab == NULL) || size < 0 || size < nbElts) // condition � traiter dans le cas ou tab est un pointeur NULL o� si la taille est n�gative o� la taille inf�rieur aux nombres d'�l�ment
	{
		return -1; // on renvoit -1 si la condition pr�c�dente est rempli
	}
	for (int i = 0; i < nbElts; i++) // boulcle qui va nous permettre de parcourir chaque case du tableau
	{
		printf(" %d", *(tab + i)); // on affiche chaque valeur lors du parcour de la boucle for pr�c�dente
	}
	return 0; // on renvoit 0 s'il n'y a pas d'erreur
}

/* fonction pour ajouter un �l�ment */

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element)
{

	if (*nbElts < *size) // si le nombre d'�l�ment est inferieur � la taille du tableau on peut juste rajouter un �lement � la fin sans r�allocation
	{
		*(tab + *nbElts) = element;
		(*nbElts)++;
		return nbElts; // on revoit le nombre d'�l�ment
	}
	int* tab_tmp = (int*)malloc(tab, (*size + TAILLEAJOUT) * sizeof(int));  // on r�alloue de l'espace dans le cas o� le nombre d'�l�ment est sup�rieur � la taille du tableau 
	if (tab_tmp == NULL)
	{
		return -1; // si cela �choue on renvoie -1
	}
	tab = tab_tmp; // on affecte la nouvelle allocation au tableau
	*(tab + *nbElts) = element; // on ajoute l'�l�ment � la fin du tableau
	*size += TAILLEAJOUT; // on met � jour la taille du tableau
	(*nbElts)++; // on met � jour le nombre d'�l�ments

	return tab; // on renvoit le nouveau tableau
}