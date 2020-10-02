#include <stdio.h>
#include <stdlib.h>
main() {

	int Nbre = 2868838400;
	int octet;
	octet = sizeof(Nbre);
	int test;
	int i;

	printf(" le nombre d'octets est %d \n", octet);

	octet = octet * 8;

	printf("le nombre de bit est de %d \n", octet);

	for (i = 0; i <= 31; i++)
	{
		test = Nbre & 1;
		if (test == 1)
		{
			printf("bits %2d", i);
			printf("--ON \n");
		}
		else
		{
			printf("bit %2d", i);
			printf("--OFF \n");

		}
		Nbre >>= 1;

		printf("bon vous pouvez vous casser!\n");

	}

	return 0;
}