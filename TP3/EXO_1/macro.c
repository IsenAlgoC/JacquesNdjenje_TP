#include <stdio.h>
#include <stdlib.h>
#define carre(x) (x)*(x) /* d�fini le calcul du carre */

int main()
{

	int Nb = 5;
	printf("le carre de Nb est egal a %d\n", carre(Nb));
	printf("le carre de Nb + 1 est egal a %d\n", carre(Nb + 1)); /* il y avait un probl�me de priorit� c'est pourquoi on a ajout� des parenth�se sur la macro*/

	return 0;
}