#include "funciones.h"

void acargar (char coef [MAXBITS])
{


	coef [0] = 72;
	coef [1] = 79;
	coef [2] = 76;
	coef [3] = 65;
	coef [4] = 32;
	coef [5] = 82;
	coef [6] = 49;
	coef [7] = 48;
	coef [8] = 52;
	coef [9] = 49;
	coef [10] = 33;
	coef [11] = 33;
	coef [12] = 33;
	coef [13] = FIN;
//	coef [13] = 0;




//	return i;
}


void muestro (char coef [MAXBITS])
{
	int i=0;

	while (coef[i] != FIN)
	{
		printf("%d", coef[i]);
		i++;
	}

	printf("\n\n");

//	return;

}

