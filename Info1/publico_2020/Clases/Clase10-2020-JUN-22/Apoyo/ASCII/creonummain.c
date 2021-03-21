
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
		printf("%d\n",vec[i]);
		i++;
	}

	printf("\n");

	return 0;

}

