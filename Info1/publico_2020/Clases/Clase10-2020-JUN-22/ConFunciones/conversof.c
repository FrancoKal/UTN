#include "conversof.h"


//int telopaso (int tempo, char * coef)
//int telopaso (int tempo, char coef [])
int telopaso (int tempo, char coef [MAXBITS])
{
	int i=0;

	while (tempo >= BASE)
	{
		coef [i] = tempo % BASE;
		tempo = tempo / BASE;
		i=i+1;  //i++;
	}

	coef[i] = tempo;

	return i;
}


void muestro (int largo, char coef [MAXBITS])
{
	int i;

	for ( i=largo ;i >= 0; i--)
	{
		printf("%d", coef[i]);
	}

	printf("\n\n");

//	return;

}


