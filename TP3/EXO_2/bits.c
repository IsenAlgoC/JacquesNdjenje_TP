#include <stdio.h>
#include <stdlib.h>

int main()
{

	unsigned int Nbre = 2868838400;
    
	printf("le nombre d'octets utilise est de %d\n", sizeof(Nbre)); /* on calcal et affiche le nombre d'octets utile */
	printf("le nombre de bits utilise est de %d\n", sizeof(Nbre) * 8); /* on calcal et affiche le nombre de bits utile */
	
	for (int i = 0; i < 32; i++) /* utilisation de la boucle for */
	{
		int tester = Nbre & 1; /* utilisation d'un apérateur de bit pour tester la valeur de chaque bit */
		
		if (tester == 1)
		{
			printf("bits %d", i);
			printf("   : ON \n"); /* affichage de l'état correspondant au bit testé lorsqu'il est égal à 1*/ 

		}
		else
		{
			printf("bits %d", i);
			printf("   : OFF\n");/* affichage de l'état correspondant au bit testé lorsqu'il est égal à 0*/
		}
		
		Nbre >>= 1; /* utilisation de l'opérateur de décalage pour passer au bits suivant*/
		
	}

	printf(" BYE !\n"); /* affichage du message de courtoisie avant la fin du programme */

	return 0;
}