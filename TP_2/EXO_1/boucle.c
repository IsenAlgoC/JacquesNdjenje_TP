#include <stdio.h>
#include <stdlib.h>

int main() {

	int n;
	int som = 0;
    
	printf("entrer un nombre supérieur a 1");
	scanf_s("%d", &n);
	
	/* somme des n premiers entiers positifs avec la boucle while*/
	while (n <= 100)
	{
		som = som + n;
		n += 1;
	}

	printf("la valeur de som est %d\n", som);

	/* somme des n premiers entiers positifs avec la boucle for*/

	for (int n = 2; n <= 100; n++)
	{
		som = som + n;
	}

	printf("la valeur de som est %d\n", som);

	/* somme des n premiers entiers positifs avec la boucle do while*/

	do
	{
		som = som + n;
		n += 1;
	} while (n <= 100);

	printf("la valeur de som est %d\n", som);

	/* valeur maximun de n dépassement de capacité */

	int max = 65535;
	int som = 0;
	int n = 50;
	while (max - n >= som)
	{
		som = som + n;
		n += 1;


	}

	printf("la valeur de som est %d\n", som);

	/* demander la valeu n à l'utilisateur*/

	printf("entre la valeur de n\n");
	for (scanf_s("%d", &n); n <= 100; n++)
	{
		if (n > 100) 	/* condition sur la valeur den choisit */

		{
			printf("entrer un nouveau nombre\n");

		}
		else
		{
			som = som + n;
		}


	}

	printf("la valeur de som est %d\n", som);



	return 0;
}