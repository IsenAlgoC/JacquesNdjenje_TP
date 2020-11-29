#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#include<stdbool.h>
#define NBMAXNOTES 30 /* taille du tableau passe en define */


int main()
{

	float moyenne = 0; /* moyenne des notes */
	int notes1 = 0; /* nombre de note entre */
	int notes2 = 0; /* nombre de note entre pour suivre indexe */
	float note[NBMAXNOTES]; /* note entre */
	int indexe[NBMAXNOTES] ; /* indice des notes */
	char reponse = 0; /* stock la rep user*/
	bool stop = false; /* condition sortie du do while*/
	int absent = 0; /* compteur d absent(s) */
	float max = 0; /* valeur max du tableau init a 0 par dafaut */
	float min = 20; /* valeur min du tableau init a 20 par defaut*/
	int i = 0, j = 0; /* compteur */
	float somme = 0; /* somme des notes du tableau */
	float varriance = 0; /* calcule variance*/
	float ecart_type = 0; /* calcule ecart type*/
	int range[NBMAXNOTES]; /* ctableau de note range */
	

	/* rempli le tableau indexe de -1 le tableau range et note de -2 */
	for (i = 0; i < NBMAXNOTES; i++) 
	{
		note[i] = -2;
		indexe[i] = -1;
		range[i] = -2;		
	}

	do
	{
		printf("entrez la note no %d : ", notes1 + 1); /* recuperation des notes */
		scanf_s("%f", &note[notes1]);
		printf("\n");

		if ((note[notes1] >= 0) && (note[notes1] <= 20)) /* test si note repsect les conditions */
		{
			if (note[notes1] > max) /* cherche val max */
			{
				max = note[notes1];
			}
			if (note[notes1] < min) /* cherche val min */
			{
				min = note[notes1];
			}
			indexe[notes2] = notes2 + 1;
			notes1++; /* incrementation du nombre de note */
			notes2++; /* incrementation indice de note */

		}
		else /* si conditions non respectees */
		{
			note[notes1] = -2;
			indexe[notes2] = -2;
			printf("Vous avez tape une note invalide, l'eleve est-il (A)bsent ou voulez vous arreter la saisie (O)ui (N)on ?\n"); /* demande intention de l utilisateur */
			reponse = _getch();/* recup saisie clavier */

			if (reponse == 'A') /* s il y a un absent */
			{
				note[notes1] = -1; /* ajoute un absent au tableau */
				indexe[notes2] = -1;
				notes1 = notes1 + 1; /* invcremante compteur de note */
				absent++; /* incremente le nombre d abcent*/
				notes2++;
				printf("un absent a ete comptee\n");
			}
			if (reponse == 'O')
			{
				stop = true; /* sort du do while */
			}
			if (reponse == 'N')
			{
				printf("reprise du programe\n");
			}
		}

	} while ((notes1 < 30) && ( stop == false)); /* boucle tant que 30 notes sont pas rentrees ou tant que l utilisateur ne dit pas stop*/

	
	int a = notes1 - absent; /* déclaration de la variable a qui va nous permettre de calculer le nombre de notes valide */

	/* la boucle qui va nous permettre de calculer la somme des notes saisie */
	for (i = 0; i < 30; i++)
	{
		if ((note[i] != -2) && (note[i] != -1))
		{
			somme = somme + note[i];
		}

	}

	moyenne = somme / a; /* on effectu le calcul de la moyenne */
	printf("la moyenne de ces %d notes est: %.2f\n", a, moyenne); /* on affiche la moyennne */
	printf("\n");
	printf("il y a %d absences.\n", absent); /* on affiche le nombre d'absent */
	printf("la plus petite note est %.2f, la plus grande est %.2f\n", min, max); /* on affiche le minimum et le maximum des notes saisie*/

	/* boucle qui va nous permettre de parcourir le tableau fianl et calculer la varriance */
	for (i = 0; i < NBMAXNOTES - 1; i++)
	{
		if ((note[i] != -2) && (note[i] != -1))
		{
			varriance = varriance + pow((note[i] - moyenne), 2);
		}

	}
	varriance = varriance / (a - 1); /* calcul de la variance */
	ecart_type = sqrt(varriance); /* calcul de l'écart type */
	printf("l'ecart type vaut : %.6f\n", ecart_type); /* affichage de l'écart type */
	printf("\t");
	printf("No note  valeur note\n");

	/* boucle pour affiche le tableau non crié */
	for (i = 0; i < NBMAXNOTES - 1; i++)
	{
		if ((note[i] != -2) && (note[i] != -1) && (note[i] != 0))
		{
			range[i] = indexe[i];
			printf("\t");
			printf("%d \t %.2f\n", indexe[i], note[i]);
		}

	}

	/* boucle pour crier le tableau */
	for (i = 0; i <= NBMAXNOTES - 2; i++)
	{
		for (j = i + 1; j <= NBMAXNOTES - 1; j++)
		{
			if ((note[i] < note[j]) && (note[i] != -2) && (note[i] != -1))
			{
				int tmp1 = note[i];
				note[i] = note[j];
				note[j] = tmp1;
				int tmp2 = indexe[i];
				indexe[i] = indexe[j];
				indexe[j] = tmp2;
				
			}
		}
	}

	printf("\n");
	printf("\t");
	printf("Rang:\t No note    Valeur note\n");
	
	/* boucle pour afficher le tableau crié */
	for (i = 0; i < NBMAXNOTES - 1; i++)
	{
		if ((note[i] != -2) && (note[i] != -1))
		{
			printf("\t");
			printf("%d \t %d \t    %.2f\n", range[i] ,indexe[i], note[i]);
		}

	}

	printf("\n");
	printf("Bye !\n");
	printf("Appuyer sur une touche pour continuer...");
	return 0;
}