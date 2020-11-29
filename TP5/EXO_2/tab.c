#include "tab.h"


/* Fonction pour créer le tableau */

TABLEAU NewArray()
{
	TABLEAU tableau;
	tableau.elt = (int*)malloc(TAILLEINITIALE * sizeof(int)); // on alloue la mémoire nécessaire au tableau entier
	tableau.size = TAILLEINITIALE; // initialisation de la taille du tableau à 100 
	tableau.eltsCount = 0; // initialisation du nombre d'élélement à 0
	if (tableau.elt != NULL && tableau.size > 0) // condition pour initialiser le tableau à 0
	{
		for (int i = 0; i < tableau.size; i++)
		{
			*(tableau.elt + i) = 0;
		}
		return tableau;
	}
	else
	{
		tableau.elt = NULL; // le tableau d'entier prend la valeur NULL si la condition d'initialiser n'est pas respecté et que l'allocation a échoué

		return tableau;
	}

}

/* Fonction qui modifie la taille d'un tableau */

int IncrementArraySize(TABLEAU* tab, int IncrementValue)
{
	int* tab_tmp = (int*)realloc(tab->elt, (tab->size + IncrementValue) * sizeof(int));  // on crée une variable temporaire de type pointeur qui va recevoir une réallocation de la mémoire avec les paramétre du tableau entier + le nombre à ajouter
	if (tab_tmp == NULL)
	{
		return -1; // si la réallocation a échoué on renvoit -1
	}
	tab->elt = tab_tmp;   // si la réallocation a marché on affecte la mémoire de la variable temporaire au tableau entier
	tab->size += IncrementValue; //on met à jour la nouvelle taille du tableau
	return (tab->size); // on renvoit la nouvelle taille du tableau s'il n'y a pas d'erreur
}

/* Fonction qui insere un élément a une position donne */

int SetElement(TABLEAU* tab, int pos, int element)
{
	if (pos < tab->size) // si la position est déjà dans le tableau on remplace juste l'ancien contenu par element
	{
		*(tab->elt + pos - 1) = element; // on remplace tous les emplacement entre l'ancienne fin du tableau et la position par 0
		return pos; // on renvoit la position de l'élément inséré
	}
	int* tab_tmp = (int*)realloc(tab->elt, (pos + 1) * sizeof(int)); // on crée une variable temporaire de type pointeur qui va recevoir une réallocation de la mémoire avec les paramétre du tableau entier et la position
	if (tab_tmp == NULL)
	{
		return 0; // on renvoit 0 si la réallocation a échoué
	}
	tab->elt = tab_tmp; // le tableau entier recupère la valeur de la variable temporaire précédente
	for (int i = tab->size; i <= pos - 1; i++) // la boucle pour remplacer tous les emplacement entre l'ancienne fin du tableau et la position par 0 
	{
		*(tab->elt + i) = 0;
	}
	*(tab->elt + pos - 1) = element; // on remplace tous les emplacement entre l'ancienne fin du tableau et la position par 0
	tab->size = pos;    // on met à jour la taille du tableau et le nombre d'elements du tableau
	tab->eltsCount = pos + 1; // on met à jour le nombre d'éléments du tableau
	return pos; // // on renvoit la position de l'élément inséré
}

/* Fonction qui affiche une portion du tableau de l’indice début à l’indice fin */

int DisplayElements(TABLEAU* tab, int startPos, int endPos)
{
	if (startPos >= endPos) // traitement du cas ou le début de la position est supérieur à la fin de la position
	{
		int tmp = 0; // création d'une variable tamporaire pour échanger la valeur de startPos à endPos
		tmp = startPos;
		startPos = endPos;
		endPos = tmp;
	}

	if ((startPos >= 0) && (endPos < tab->size) && (endPos >= startPos)) // on vérifie la validité des paramètres en entrée pour pourvoir afficher le tableau
	{
		for (int i = startPos; i <= endPos; i++) // boucle pour afficher les éléments du tableau entre startPos et endPos
		{
			printf("%d ", *(tab->elt + i));
		}
		printf("\n\n");
		return 0; // renvoit 0 s'il n'y pas d'erreur
	}
	return -1; // on renvoit -1 s'il y a erreur
}

/* Fonction qui suprime un élément et met a jour la taille du tableau */

int DeleteElements(TABLEAU* tab, int startPos, int endPos)
{
	if (startPos >= endPos) // traitement du cas ou le début de la position est supérieur à la fin de la position
	{
		int tmp = 0; // création d'une variable tamporaire pour échanger la valeur de startPos à endPos
		tmp = startPos;
		startPos = endPos;
		endPos = tmp;
	}
	int j = 0; // initialisation de l'indice de la liste raccourcie
	int* tab_tmp = (int*)malloc((tab->size - (endPos - startPos) - 1) * sizeof(int)); // on crée une variable temporaire de type pointeur a qui on va allouer la mémoire nécessaire
	if (tab_tmp == NULL)
	{
		return -1; // on renvoit -1 en cas d'erreur 
	}
	for (int i = 0; i <= tab->size - 1; i++)
	{
		if ((i < startPos - 1) || (i > endPos - 1)) //condition pour copier chaque élément du tableau dans la copie lorsque son indice correspond aux paramètres d'entrée
		{
			*(tab_tmp + j) = *(tab->elt + i);
			j++; //quand on rajoute un element on incremente l'indice de la copie pour la remplir au fur et à mesure
		}
	}
	tab->size -= (endPos - startPos) + 1; // on met à jour la taille du tableau 
	tab->eltsCount -= (endPos - startPos) + 1; // on met à jour le nombre d'éléments
	tab->elt = tab_tmp; // le tableau entier recupère la valeur de la variable temporaire précédente
	return(tab->size); // on retourne la valeur du nouveau tableau
}