#include "tab.h"

int main() {
	TABLEAU table = NewArray(); // création d'un tableau initiliser avec des 0  pour tester nos différentes fonction

	printf("\t TABLEAU INITIAL\n\n");
	DisplayElements(&table, 0, table.size - 1); // on affiche le tableau initial


	for (int i = 0; i <= table.size - 1; i++) {     // on affecte des valeurs d'indices au tableau pour mieux voir les différentes modifications sachant que à la position 0 on a 1
		*(table.elt + i) = i + 1;
	}

	printf("\t INSERTION DU NOMBRE 33 A LA POSITION 106\n\n");
	SetElement(&table, 106, 33); // on teste l'insertion d'élément en dehors de la taille du tableau
	DisplayElements(&table, 0, table.size - 1); // on observe bien le nombre 33 a la position 106 et on voit bien que la taille du tableau a augmenté et des 0 inséré 

	printf("\t INSERTION DU NOMBRE 75 A LA POSITION 33\n\n");
	SetElement(&table, 33, 75);  // on teste l'insertion d'élément dans la taille du tableau
	DisplayElements(&table, table.size - 1, 0);   // on observe bien un changement et le traitement du cas ou startPos >= endPos

	printf("\t ON SUPPRIME LES ELEMENTS ENTRE 10 ET 25 INCLUS\n\n");
	DeleteElements(&table, 25, 10); // on teste la suppression d'éléments entre un intervalle
	DisplayElements(&table, 0, table.size - 1); // on onbserve bien la suppression 

	printf("\t ON SUPPRIME LES ELEMENTS ENTRE 41 ET 53 INCLUS\n\n");
	DeleteElements(&table, 53, 41);  // on teste la suppression d'éléments entre la position de début supérieur a la position de fin 
	DisplayElements(&table, 0, table.size - 1); // on observe bien que le cas startPos >= endPos a été traité et que la position de début a changer avec la position de fin

	printf("\t TAILLE DU TABLEAU\n\n");
	printf("\t %d\n\n", table.size);  // on affiche la taille du tableau

	printf("\t NOUVELLE TAILLE DU TABLEAU\n\n");
	int taille = IncrementArraySize(&table, 10); // on teste l'augmentation de la taille  du tableau 
	printf("\t %d\n", taille); // on observe bien que la taille du tableau a augmenté
	free(table.elt);

	return 0;
}