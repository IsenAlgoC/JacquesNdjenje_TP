#include "tab.h"

/* fonction pour initialiser un tableau de taille variable avec des 0 */

int initTab(int* tab, int size)
{
	if ((tab == NULL) || size < 0) // condition à traiter dans le cas ou tab est un pointeur NULL où si la taille est négative 
	{
		return -1; // on renvoit -1 si la condition précédente est rempli
	}
	for (int i = 0; i < size; i++) // boulcle qui va nous permettre de parcourir chaque case du tableau
	{
		*(tab + i) = 0; // on affecte la valeur 0 à chaque case du tableau lorques la boucle for parcour le tableau
	}
	return size; // on renvoit la taille du tableau s'il n'y a pas d'erreur
}

/* fonction pour afficher le tableau */

int afficheTab(int* tab, int size, int nbElts)
{
	if ((tab == NULL) || size < 0 || size < nbElts) // condition à traiter dans le cas ou tab est un pointeur NULL où si la taille est négative où la taille inférieur aux nombres d'élément
	{
		return -1; // on renvoit -1 si la condition précédente est rempli
	}
	for (int i = 0; i < nbElts; i++) // boulcle qui va nous permettre de parcourir chaque case du tableau
	{
		printf(" %d", *(tab + i)); // on affiche chaque valeur lors du parcour de la boucle for précédente
	}
	return 0; // on renvoit 0 s'il n'y a pas d'erreur
}

/* fonction pour ajouter un élément */

int* ajoutElementDansTableau(int* tab, int* size, int* nbElts, int element)
{

	if (*nbElts < *size) // si le nombre d'élément est inferieur à la taille du tableau on peut juste rajouter un élement à la fin sans réallocation
	{
		*(tab + *nbElts) = element;
		(*nbElts)++;
		return nbElts; // on revoit le nombre d'élément
	}
	int* tab_tmp = (int*)malloc(tab, (*size + TAILLEAJOUT) * sizeof(int));  // on réalloue de l'espace dans le cas où le nombre d'élément est supérieur à la taille du tableau 
	if (tab_tmp == NULL)
	{
		return -1; // si cela échoue on renvoie -1
	}
	tab = tab_tmp; // on affecte la nouvelle allocation au tableau
	*(tab + *nbElts) = element; // on ajoute l'élément à la fin du tableau
	*size += TAILLEAJOUT; // on met à jour la taille du tableau
	(*nbElts)++; // on met à jour le nombre d'éléments

	return tab; // on renvoit le nouveau tableau
}