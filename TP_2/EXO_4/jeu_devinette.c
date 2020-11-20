#include<stdio.h>
#include<stdlib.h>
#include <time.h>


int main()
{
	srand(time(NULL));
	int score = 0; /* nombre de proposition effectué par le joueur */
	int nbre; /* nombre entré par l'utilisateur*/
	int nbre_alre = rand() % 200 + 1; /* déclaration du nombre aléatoire fourni par la fonction srand*/
	
	do
	{
		printf("entrer un nombre de 0 a 200\n ");
		scanf_s("%d", &nbre);
		if (nbre < nbre_alre)
		{
			printf("le nombre est trop petit\n");
		}
		if (nbre > nbre_alre)
		{
			printf("le nombre est trop grand\n");
		}
		score++;
	} while (nbre != nbre_alre);

	printf("FELICITATION VOUS AVEZ DEVINE LE NOMBRE\n");
	printf("%d", score);

	return 0;
}