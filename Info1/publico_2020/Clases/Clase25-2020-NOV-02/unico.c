#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "funciones.h"

#define MAX 5

int main (void)
{

	int * vector = NULL;
	FILE * origen = NULL;
	char * resultado [MAX] = {"primos.txt", "sumatoria.txt", "pares.txt", "impares.txt", "decenas.txt"};
	void (*ejecutar[MAX])(int *, int, char *) = {primos, sumatoria, pares, impares, decenas};
	int tpo_ini, tpo_fin;
	int i;
	int cant = 0;


	origen = fopen("datazo.txt", "r");

	vector = (int *) malloc (sizeof(int));

	if(vector && origen)
	{
		do
		{
			fscanf(origen,"%d", (vector+cant));
			if (!feof(origen))
			{
				cant++;
				vector = (int *) realloc(vector, sizeof(int)*(cant+1));	//no valido el realloc porque si no tengo memoria, me voy. No me importa lo que ya cargó.
			}
		}
		while (!feof(origen) && vector);

		printf("Se procesaron %d registros.\n", cant);

		tpo_ini = time(NULL);

		if (vector)
		{
			for (i = 0; i < MAX; i++)
			{
				ejecutar[i] (vector, cant, resultado[i]);
			}
		}

		tpo_fin = time(NULL);

		printf("Tiempo utilizado: %d\n", tpo_fin-tpo_ini);

	}

	if (origen) fclose(origen);

	if (vector) free(vector);

	return 0;
}
