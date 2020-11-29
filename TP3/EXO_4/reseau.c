#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include<math.h>

int main()
{
	unsigned int MyAddress_w = 192, MyAddress_x = 168, MyAddress_y = 129, MyAddress_z = 10, adresse = 0, adresse_reseau = 0, adresse_broadcast; /* variables pour la gestion d adresse */
	unsigned long long int IPv4MaskLenght = pow(2, 32) - 1, notmask; /* variables pour masque */
	int n = 24, i; /*compteurs*/


	/* la boucle pour calculer le masque */
	for (i = 0; i < (32 - n); i++)
	{
		IPv4MaskLenght -= pow(2, i);
	}
	notmask = ~IPv4MaskLenght;//L inverse du mask pour calculer l'adresse broadcoast

	/* première partie pour traiter les adresses et afficher l'adresse IPV4 */

	adresse = MyAddress_w; /* on stocke l'adresse dans les variables */
	adresse <<= 8;
	adresse += MyAddress_x;
	adresse <<= 8;
	adresse += MyAddress_y;
	adresse <<= 8;
	adresse += MyAddress_z;

	MyAddress_w = adresse;/*On trie pour recuperer les "octets" pour afficher les adresses*/
	MyAddress_w >>= 24;

	MyAddress_x = adresse;
	MyAddress_x >>= 16;
	MyAddress_x -= MyAddress_w * pow(2, 8);


	MyAddress_y = adresse;
	MyAddress_y >>= 8;
	MyAddress_y -= (MyAddress_w * pow(2, 16) + MyAddress_x * pow(2, 8));

	MyAddress_z = adresse;
	MyAddress_z -= (MyAddress_w * pow(2, 24) + MyAddress_x * pow(2, 16) + MyAddress_y * pow(2, 8));
	printf("adresse   IPV4 = %u.%u.%u.%u / %d\n", MyAddress_w, MyAddress_x, MyAddress_y, MyAddress_z,n); /* affichage adresse IPV4 */


	/* deuxième partie pour traiter les adresses et afficher l'adresse reseau */

	adresse_reseau = (adresse) & (IPv4MaskLenght); /* affectation adresse reseau */
	MyAddress_w = adresse_reseau; /* on stocke l'adresse reseau dans nos variables */
	MyAddress_w >>= 24;

	MyAddress_x = adresse_reseau;
	MyAddress_x <<= 8;
	MyAddress_x >>= 24;

	MyAddress_y = adresse_reseau;
	MyAddress_y <<= 16;
	MyAddress_y >>= 24;

	MyAddress_z = adresse_reseau;
	MyAddress_z <<= 24;
	MyAddress_z >>= 24;

	printf("adresse du reseau = %u.%u.%u.%u / %d\n", MyAddress_w, MyAddress_x, MyAddress_y, MyAddress_z,n); /* affichage adresse reseau */

	/* troisième  partie pour traiter les adresses et afficher l'adresse broadcast */

	adresse_broadcast = adresse_reseau | notmask; /* affectation adresse broadcast */
	MyAddress_w = adresse_broadcast;/* on stoke l'adresse reseau dans nos variables */
	MyAddress_w >>= 24;

	MyAddress_x = adresse_broadcast;
	MyAddress_x <<= 8;
	MyAddress_x >>= 24;

	MyAddress_y = adresse_broadcast;
	MyAddress_y <<= 16;
	MyAddress_y >>= 24;

	MyAddress_z = adresse_broadcast;
	MyAddress_z <<= 24;
	MyAddress_z >>= 24;

	printf("adresse broadcoast = %u.%u.%u.%u", MyAddress_w, MyAddress_x, MyAddress_y, MyAddress_z); /* on affiche l'adresse de broadcoast */

	return 0;
	
}