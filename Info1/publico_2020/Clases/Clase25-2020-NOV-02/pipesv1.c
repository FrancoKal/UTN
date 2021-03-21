#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include "funcionesp.h"

#define MAX 5

int main (void)
{

	int * vector = NULL;
	FILE * origen = NULL;
	char * resultado [MAX] = {"primos.txt", "sumatoria.txt", "pares.txt", "impares.txt", "decenas.txt"};
	void (*ejecutar[MAX])(int *, int, char *, int) = {primos, sumatoria, pares, impares, decenas};
	time_t tpo_ini, tpo_fin;
	time_t tpo_pr, tpo_su, tpo_pa, tpo_im, tpo_de;
	int i;
	int cant = 0;
	int pid, pipefd;

	int pipepr[2];
	int pipesu[2];
	int pipepa[2];
	int pipeim[2];
	int pipede[2];

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

		tpo_ini = time(NULL);

		printf("Se procesaron %d registros.\n", cant);

		if (vector)
		{

			pipe (pipepr);
			pipe (pipesu);
			pipe (pipepa);
			pipe (pipeim);
			pipe (pipede);

			for (i = 0; i < MAX; i++)
			{
				pid = fork();
				if (!pid)
				{

					if (i == 0)
					{
						close(pipepr[0]);
						pipefd = pipepr[1];
					}
					else if (i == 1)
					{
						close(pipesu[0]);
						pipefd = pipesu[1];
					}
					else if (i == 2)
					{
						close(pipepa[0]);
						pipefd = pipepa[1];
					}
					else if (i == 3)
					{
						close(pipeim[0]);
						pipefd = pipeim[1];
					}
					else if (i == 4)
					{
						close(pipede[0]);
						pipefd = pipede[1];
					}

					ejecutar[i] (vector, cant, resultado[i], pipefd);

					return 0;
				}

			}
		}

	}

	close(pipepr[1]);
	close(pipesu[1]);
	close(pipepa[1]);
	close(pipeim[1]);
	close(pipede[1]);

	read(pipepr[0], &tpo_pr, sizeof(time_t));
	printf("Tarea: %s - Tiempo utilizado: %ld\n", resultado[0], tpo_pr-tpo_ini);
	read(pipesu[0], &tpo_su, sizeof(time_t));
	printf("Tarea: %s - Tiempo utilizado: %ld\n", resultado[1], tpo_su-tpo_ini);
	read(pipepa[0], &tpo_pa, sizeof(time_t));
	printf("Tarea: %s - Tiempo utilizado: %ld\n", resultado[2], tpo_pa-tpo_ini);
	read(pipeim[0], &tpo_im, sizeof(time_t));
	printf("Tarea: %s - Tiempo utilizado: %ld\n", resultado[3], tpo_im-tpo_ini);
	read(pipede[0], &tpo_de, sizeof(time_t));
	printf("Tarea: %s - Tiempo utilizado: %ld\n", resultado[4], tpo_de-tpo_ini);

	tpo_fin = time(NULL);
	printf("Tiempo utilizado total: %ld\n", tpo_fin-tpo_ini);

	close(pipepr[0]);
	close(pipesu[0]);
	close(pipepa[0]);
	close(pipeim[0]);
	close(pipede[0]);


	if (origen) fclose(origen);
	if (vector) free(vector);


	return 0;
}

