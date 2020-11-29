#include "tab.h"

int main() {

	int myTab1[10];
	int* myTab2 = NULL;
	int TAB2SIZE = TAILLEINITIALE;
	int nbElts = 99;


	myTab2 = (int*)malloc(TAILLEINITIALE * sizeof(int)); // on alloue de la m�moire � notre tableau cr�� de mani�re dynamique

	if (myTab2 != NULL) // condition pour tester si l'allocation � r�ussi
	{
		initTab(myTab2, TAB2SIZE); // si l'allocation � r�ussi on utilise la fonction initTab 
	}
	else
	{
		printf("m�moire insuffisante\n"); // sinon on affiche un message d'erreur
		return -1;
	}

	afficheTab(myTab2, TAB2SIZE, 100); //  on observe bien que l'allocation � r�ussi, la fonction afficheTab fonctionne et la fonction initTab fonctionne aussi bien
	printf("\n\n");

	for (int i = 0; i < 20; i++) // boucle pour parcourir les 20 prem�res case du tableau
	{
		*(myTab2 + i) = i + 1; // on affecte des valeurs de 1 � 20 durant le parcour du tableau
	}

	afficheTab(myTab2, TAB2SIZE, nbElts); // on observe bien  les 20 premi�res valeur avec des valeurs de 1 � 20 et le reste � 0
	printf("\n\n");
	ajoutElementDansTableau(myTab2, &TAB2SIZE, &nbElts, 105); // on ajoute un �l�ment dans le tableau
	afficheTab(myTab2, TAB2SIZE, 100); // on observe bien que l'�l�ment a �t� ajout�


	free(myTab2); // on d�trui le tableau d�s qu'on a plus besoin

	return 0;
}