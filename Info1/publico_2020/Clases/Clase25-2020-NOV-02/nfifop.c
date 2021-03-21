#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include "funcionesf.h"
#include <sys/stat.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>


#define MAX 5
#define TAM 4
#define EMISOR "emisor.fifo"
#define RECEPTOR "receptor.fifo"

int main (void)
{

	int * vector = NULL;
	FILE * origen = NULL;
	int emisor, receptor;
	char * acciones [MAX] = {"pri", "sum", "par", "imp", "dec"};
	void (*ejecutar[MAX])(int *, int, int) = {primos, sumatoria, pares, impares, decenas};
	int i, resu, ejec = -1;
	int cant = 0;
	char comando[TAM];

	origen = fopen("datacito.txt", "r");

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

		printf("Se procesaron %d registros.\n", cant);

		if (vector)
		{

       		resu =  mkfifo (RECEPTOR, 0666);
			if (resu != 0)
			{
				if(errno != EEXIST)
				{
					printf("No se pudo crear el fifo receptor.\n");
				}
				else
				{
					resu = 0;
				}
			}

			if (resu == 0)
			{
	       		resu =  mkfifo (EMISOR, 0666);
				if (resu != 0)
				{
					if(errno != EEXIST)
					{
						printf("No se pudo crear el fifo emisor.\n");
					}
					else
					{
						resu = 0;
					}
				}
			}


			if(!resu)
			{
				receptor = open(RECEPTOR, O_RDONLY);
				emisor = open(EMISOR, O_WRONLY);

				printf("Named pipes abiertos.\n");

				if ((receptor != -1) && (emisor != -1))
				{
					printf("Voy a escuchar.\n");
					read(receptor, comando, sizeof(char)*TAM);
					comando[TAM-1] = '\0';
					printf("Se recibió el comando %s.\n", comando);

				}

				for ( i = 0; i < MAX; i++)
					if (!strcmp(comando, acciones[i])) ejec = i;

				if (ejec == -1)
				{
					printf("Comando invalido recibido.\n");
				}
				else
				{
					ejecutar[ejec] (vector, cant, emisor);
					sleep (10);
				}

			}

		}

	}

	if (origen) fclose(origen);
	if (emisor != -1) close(emisor);
	if (receptor != -1) close(receptor);
	if (vector) free(vector);

	return 0;
}

