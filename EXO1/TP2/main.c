#include <stdio.h>
#include <stdlib.h>

int main() {

	int n;
	int som = 0;

	printf("la valeur de a est %d\n", n);
	while (n <= 100)
	{
		som = som + n;
		n += 1;
	}

	printf("la valeur de som est %d\n", som);

	for (int n = 2; n <= 100; n++)
	{
		som = som + n;
	}

	printf("la valeur de som est %d\n", som);

	do
	{
		som = som + n;
		n += 1;
	} while (n <= 100);

	printf("la valeur de som est %d\n", som);

	int max = 65535;
	int som = 0;
	int n = 50;
	while (max - n >= som)
	{
		som = som + n;
		n += 1;


	}

	printf("la valeur de som est %d\n", som);





	printf("entre la valeur de n\n");
	for (scanf_s("%d", &n); n <= 100; n++)
	{
		if (n > 100)
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