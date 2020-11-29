#include <stdio.h>
#include <stdlib.h>
#define carre(x) (x)*(x) /* défini le calcul du carre */

int main()
{

	int Nb = 5;
	printf("le carre de Nb est egal a %d\n", carre(Nb));
	printf("le carre de Nb + 1 est egal a %d\n", carre(Nb + 1)); /* il y avait un problème de priorité c'est pourquoi on a ajouté des parenthése sur la macro*/

	return 0;
}