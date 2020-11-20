#include<stdio.h>
#include<stdlib.h>

int main()
{

	int nbre;
	/* on entre un nombre tant qu'il est entre 0 et 10000 */
	do
	{
		printf("entrer un nombre entre 0 et 10000\n");
		scanf_s("%d", &nbre
		);
	} while (nbre < 0 || nbre > 10000);
	
	/* utilisation d'une expression logique pour resoudre le problème */
	/*if (nbre % 4 == 0 && nbre != 100 || nbre % 400 == 0 )
	{
		printf("c'est une annee bissextile\n");
	}
	else
	{
		printf("c'est une annee non bissextile\n");
	}*/

	/* utilisation des instrucions if..else imbriquées pour resoudre le problème*/

	if (nbre % 4 == 0)
	{
		if (nbre != 100)
		{
			if (nbre % 400 == 0)
			{
				printf("c'est une annee bissextile\n");

			}
			else
			{
				printf("c'est une annee non bissextile");
			}
		}
		else
		{
			printf("c'est une annee non bissextile\n");
		}
		
	}
	else
	{
		printf("c'est une annee non bissextile\n");
	}

	return 0;
}