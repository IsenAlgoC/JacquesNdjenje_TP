#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

int main()
{
    float longueur, largeur, epaisseur; 
    bool verification = false; /* la variable qui va nous permettre de vérifier les 3  valeurs entrées */
    bool boucle = false; /* la variable qui va nous permettre de traiter le cas d'un autre colis sans devoisn être relancé*/
    int oui; /* la variable qui va nous permettre de connaitre si l'utilisateur veut tester ses bagages avec 1 pour oui et non pour 0 */

    do
    {

        printf("Voulez vous tester un bagage, si oui taper 1, si non taper 0\n"); 
        scanf_s("%d", &oui);
        if (oui == 1)
        {
            do
            {
                printf("Entrer la longeur de votre bagage\n");
                scanf_s("%f", &longueur);

                printf("Entrer la largeur de votre bagage\n");
                scanf_s("%f", &largeur);

                printf("Entrer la hauteur de votre bagage\n");
                scanf_s("%f", &epaisseur);

                if (longueur < 1 || longueur > 150 || largeur < 1 || largeur > 150 || epaisseur < 1 || epaisseur > 150)
                {
                    printf("NON VALIDE\n"); /* message d'erreur */
                    printf("Une ou plusieurs dimmensions est inferieur a 0 ou superieur a 150 cm \n");
                }
                else
                {
                    if (longueur > 55 || largeur > 35 || epaisseur > 25)
                    {
                       
                        verification = true;
                        printf("votre bagage est trop grand\n");
                        printf("NON VALIDE\n");
                        
                    }
                    else
                    {
                        verification = true;
                        printf("bagage valide\n");
                    }
                }

            } while (verification == false);
        }
        else
        {
            boucle = true;
        }

    } while (boucle == false);

    
    return 0;
}