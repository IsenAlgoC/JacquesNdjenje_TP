#include "tab.h"

int main() {

	int myTab1[10];
	int* myTab2 = NULL;
	int TAB2SIZE = TAILLEINITIALE;
	int nbElts = 99;


	myTab2 = (int*)malloc(TAILLEINITIALE * sizeof(int)); // on alloue de la mémoire à notre tableau créé de manière dynamique

	if (myTab2 != NULL) // condition pour tester si l'allocation à réussi
	{
		initTab(myTab2, TAB2SIZE); // si l'allocation à réussi on utilise la fonction initTab 
	}
	else
	{
		printf("mémoire insuffisante\n"); // sinon on affiche un message d'erreur
		return -1;
	}

	afficheTab(myTab2, TAB2SIZE, 100); //  on observe bien que l'allocation à réussi, la fonction afficheTab fonctionne et la fonction initTab fonctionne aussi bien
	printf("\n\n");

	for (int i = 0; i < 20; i++) // boucle pour parcourir les 20 premères case du tableau
	{
		*(myTab2 + i) = i + 1; // on affecte des valeurs de 1 à 20 durant le parcour du tableau
	}

	afficheTab(myTab2, TAB2SIZE, nbElts); // on observe bien  les 20 premières valeur avec des valeurs de 1 à 20 et le reste à 0
	printf("\n\n");
	ajoutElementDansTableau(myTab2, &TAB2SIZE, &nbElts, 105); // on ajoute un élément dans le tableau
	afficheTab(myTab2, TAB2SIZE, 100); // on observe bien que l'élément a été ajouté


	free(myTab2); // on détrui le tableau dès qu'on a plus besoin

	return 0;
}