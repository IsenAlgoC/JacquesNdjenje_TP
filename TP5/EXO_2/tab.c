#include "tab.h"


/* Fonction pour cr�er le tableau */

TABLEAU NewArray()
{
	TABLEAU tableau;
	tableau.elt = (int*)malloc(TAILLEINITIALE * sizeof(int)); // on alloue la m�moire n�cessaire au tableau entier
	tableau.size = TAILLEINITIALE; // initialisation de la taille du tableau � 100 
	tableau.eltsCount = 0; // initialisation du nombre d'�l�lement � 0
	if (tableau.elt != NULL && tableau.size > 0) // condition pour initialiser le tableau � 0
	{
		for (int i = 0; i < tableau.size; i++)
		{
			*(tableau.elt + i) = 0;
		}
		return tableau;
	}
	else
	{
		tableau.elt = NULL; // le tableau d'entier prend la valeur NULL si la condition d'initialiser n'est pas respect� et que l'allocation a �chou�

		return tableau;
	}

}

/* Fonction qui modifie la taille d'un tableau */

int IncrementArraySize(TABLEAU* tab, int IncrementValue)
{
	int* tab_tmp = (int*)realloc(tab->elt, (tab->size + IncrementValue) * sizeof(int));  // on cr�e une variable temporaire de type pointeur qui va recevoir une r�allocation de la m�moire avec les param�tre du tableau entier + le nombre � ajouter
	if (tab_tmp == NULL)
	{
		return -1; // si la r�allocation a �chou� on renvoit -1
	}
	tab->elt = tab_tmp;   // si la r�allocation a march� on affecte la m�moire de la variable temporaire au tableau entier
	tab->size += IncrementValue; //on met � jour la nouvelle taille du tableau
	return (tab->size); // on renvoit la nouvelle taille du tableau s'il n'y a pas d'erreur
}

/* Fonction qui insere un �l�ment a une position donne */

int SetElement(TABLEAU* tab, int pos, int element)
{
	if (pos < tab->size) // si la position est d�j� dans le tableau on remplace juste l'ancien contenu par element
	{
		*(tab->elt + pos - 1) = element; // on remplace tous les emplacement entre l'ancienne fin du tableau et la position par 0
		return pos; // on renvoit la position de l'�l�ment ins�r�
	}
	int* tab_tmp = (int*)realloc(tab->elt, (pos + 1) * sizeof(int)); // on cr�e une variable temporaire de type pointeur qui va recevoir une r�allocation de la m�moire avec les param�tre du tableau entier et la position
	if (tab_tmp == NULL)
	{
		return 0; // on renvoit 0 si la r�allocation a �chou�
	}
	tab->elt = tab_tmp; // le tableau entier recup�re la valeur de la variable temporaire pr�c�dente
	for (int i = tab->size; i <= pos - 1; i++) // la boucle pour remplacer tous les emplacement entre l'ancienne fin du tableau et la position par 0 
	{
		*(tab->elt + i) = 0;
	}
	*(tab->elt + pos - 1) = element; // on remplace tous les emplacement entre l'ancienne fin du tableau et la position par 0
	tab->size = pos;    // on met � jour la taille du tableau et le nombre d'elements du tableau
	tab->eltsCount = pos + 1; // on met � jour le nombre d'�l�ments du tableau
	return pos; // // on renvoit la position de l'�l�ment ins�r�
}

/* Fonction qui affiche une portion du tableau de l�indice d�but � l�indice fin */

int DisplayElements(TABLEAU* tab, int startPos, int endPos)
{
	if (startPos >= endPos) // traitement du cas ou le d�but de la position est sup�rieur � la fin de la position
	{
		int tmp = 0; // cr�ation d'une variable tamporaire pour �changer la valeur de startPos � endPos
		tmp = startPos;
		startPos = endPos;
		endPos = tmp;
	}

	if ((startPos >= 0) && (endPos < tab->size) && (endPos >= startPos)) // on v�rifie la validit� des param�tres en entr�e pour pourvoir afficher le tableau
	{
		for (int i = startPos; i <= endPos; i++) // boucle pour afficher les �l�ments du tableau entre startPos et endPos
		{
			printf("%d ", *(tab->elt + i));
		}
		printf("\n\n");
		return 0; // renvoit 0 s'il n'y pas d'erreur
	}
	return -1; // on renvoit -1 s'il y a erreur
}

/* Fonction qui suprime un �l�ment et met a jour la taille du tableau */

int DeleteElements(TABLEAU* tab, int startPos, int endPos)
{
	if (startPos >= endPos) // traitement du cas ou le d�but de la position est sup�rieur � la fin de la position
	{
		int tmp = 0; // cr�ation d'une variable tamporaire pour �changer la valeur de startPos � endPos
		tmp = startPos;
		startPos = endPos;
		endPos = tmp;
	}
	int j = 0; // initialisation de l'indice de la liste raccourcie
	int* tab_tmp = (int*)malloc((tab->size - (endPos - startPos) - 1) * sizeof(int)); // on cr�e une variable temporaire de type pointeur a qui on va allouer la m�moire n�cessaire
	if (tab_tmp == NULL)
	{
		return -1; // on renvoit -1 en cas d'erreur 
	}
	for (int i = 0; i <= tab->size - 1; i++)
	{
		if ((i < startPos - 1) || (i > endPos - 1)) //condition pour copier chaque �l�ment du tableau dans la copie lorsque son indice correspond aux param�tres d'entr�e
		{
			*(tab_tmp + j) = *(tab->elt + i);
			j++; //quand on rajoute un element on incremente l'indice de la copie pour la remplir au fur et � mesure
		}
	}
	tab->size -= (endPos - startPos) + 1; // on met � jour la taille du tableau 
	tab->eltsCount -= (endPos - startPos) + 1; // on met � jour le nombre d'�l�ments
	tab->elt = tab_tmp; // le tableau entier recup�re la valeur de la variable temporaire pr�c�dente
	return(tab->size); // on retourne la valeur du nouveau tableau
}