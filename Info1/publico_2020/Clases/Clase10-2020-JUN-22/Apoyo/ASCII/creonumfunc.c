
#include "creonumfunc.h"

void cargando (char * vector)
{
	int i, largo, intervalo;

	srand(time(NULL));

	largo = (rand()%MAX)-1;
	intervalo = SUP-INF;

	for (i=0; i < largo; i++)
	{
		*(vector+i) = rand()%intervalo+INF;
	}

	*(vector+i) = FIN;

	return;
}
