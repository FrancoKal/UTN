#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>
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
	int pid, result;


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
		while (!feof(origen) && vector );

		if (origen) fclose(origen);

		printf("Se procesaron %d registros.\n", cant);

		tpo_ini = time(NULL);

		if (vector)
		{
			for (i = 0; i < MAX; i++)
			{
				pid = fork();
				if (!pid)
				{
					ejecutar[i] (vector, cant, resultado[i]);

					printf("Tarea: %s - ", resultado[i]);
					i = MAX;
				}
				else if (pid == -1)
				{
					printf("No se pudo generar el hijo %d correspondiente.\n", i);
				}
			}
		}

	}

	if (vector) free(vector);

	tpo_fin = time(NULL);

	printf("Tiempo utilizado: %d\n", tpo_fin-tpo_ini);
	printf("Valor de pid: %d\n", pid);

	if (!pid) return 0;
//	{

		i = 0;

    	while (i < MAX)
		{
			result = waitpid(-1,NULL,WNOHANG);
			if (result)
			{
				i++;
			}
		}

		tpo_fin = time(NULL);

		printf("Tiempo utilizado total: %d\n", tpo_fin-tpo_ini);
//	}

	return 0;
}

