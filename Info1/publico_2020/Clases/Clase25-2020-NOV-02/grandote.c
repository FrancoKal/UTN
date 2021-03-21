#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define POCO 10000
#define MUCHO 10000000

int main (void)
{

	int i;
	FILE * archivo = NULL;

	archivo = fopen("datacito.txt", "w");
	srand(time(NULL));

	if (archivo)
	{
		for (i = 0; i < POCO; i++)
		{

				fprintf(archivo, "%d\n", rand()%POCO*100);
		}

		fclose(archivo);
	}

	archivo = fopen("datazo.txt", "w");

	if (archivo)
	{
		for (i = 0; i < MUCHO; i++)
		{

				fprintf(archivo, "%d\n", rand()%MUCHO*10);
		}

		fclose(archivo);
	}

	return 0;
}
