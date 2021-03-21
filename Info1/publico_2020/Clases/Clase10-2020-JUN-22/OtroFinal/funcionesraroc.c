#include "funciones.h"

void acargar (char coef [MAXBITS])
{


	coef [0] = 72;
	coef [1] = 0117;
	coef [2] = 0x4c;
	coef [3] = 'A';
	coef [4] = 32;
	coef [5] = 0122;
	coef [6] = 0x31;
	coef [7] = '0';
	coef [8] = 52;
	coef [9] = 061;
	coef [10] = 0x21;
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
		printf("%c", coef[i]);
		i++;
	}

	printf("\n\n");

//	return;

}

