#include "conversof.h"

void telopaso (int tempo, char coef [MAXBITS])
{
	int i=0;

	while (tempo >= BASE)
	{
		coef [i] = tempo % BASE;
		tempo = tempo / BASE;
		i=i+1;  //i++;
	}

	coef[i] = tempo;
	coef[i+1] = BASE;

//	return i;
}


void muestro (char coef [MAXBITS])
{
	int i=0;

	while (coef[i] != BASE)
	{
		i++;
	}

	for ( i = i-1 ;i >= 0; i--)
	{
		printf("%d", coef[i]);
	}

	printf("\n\n");

//	return;

}

