
#include "creonumfunc.h"

int main (void)
{

	int i=0;
	char vec[MAX];

	printf("Vamos a completar el vector........\n\n");

	cargando (vec);

	printf("Los valores elegidos son:\n");

	while (vec[i]!= FIN)
	{
		printf("%c",vec[i]);
		i++;
	}

	printf("\n\n");

	return 0;

}

