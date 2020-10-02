#include <stdio.h>
#include <stdlib.h>
#define carre(x) (x)*(x)

main() {

	int Nb = 5;

	printf(" le carre de Nb est %d \n", carre(Nb));
	printf("le carre de Nb+1 est %d \n", carre(Nb + 1));

	return 0;
}