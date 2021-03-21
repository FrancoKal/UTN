#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "funciones.h"

int cargar (alumno ***lista)
{
	int i = 0, buffer;
	char buffer_nombre[LARGO_NOM];
	
	if (lista != NULL)
	{
		printf("Para salir, ingrese un 0 en 'ID'\n");
		
		do
		{
			printf("ID[%i]: ", i);
			scanf("%i", &buffer);
			getchar();

			if (buffer != 0)
			{
				*lista = (alumno **) realloc (*lista, sizeof(alumno *) * (i+1)); //No debo hacer el malloc inicial porque ya lo hice el main. Si lo hago, pierdo el puntero
				
				if (*lista != NULL)
				{
					(*lista)[i] = (alumno *) malloc (sizeof(alumno));

					if ((*lista)[i] != NULL)
					{
						(*lista)[i]->id = buffer;
						printf("Nombre: ");
						fgets(buffer_nombre, LARGO_NOM, stdin);
						buffer = strlen(buffer_nombre);
						buffer_nombre[buffer - 1] = '\0'; //Le resto el espacio de mas que me genera el fgets
						(*lista)[i]->nombre = (char *) malloc (sizeof(char) * buffer);

						if ((*lista)[i]->nombre != NULL)
						{
							strcpy((*lista)[i]->nombre, buffer_nombre);
							printf("Fecha de ingreso (ingrese 'dia' 'mes' 'año'): ");
							scanf("%i %i %i", &((*lista)[i]->fe.dia), &((*lista)[i]->fe.mes), &((*lista)[i]->fe.anio));
							printf("Edad: ");
							scanf("%i", &((*lista)[i]->edad));
							i++;
						}
						else buffer = SIN_MEMORIA;

						printf("\n");
					}
					else buffer = SIN_MEMORIA;
				}
				else buffer = SIN_MEMORIA;
			}
			else buffer = SIN_MEMORIA;
		}
		while (buffer > 0 && i < CANT_MAX);
	}

	return i;
}

alumno ** ordenar (alumno **lista, int cant)
{
	int i = 0, j, k = 0;
	alumno **ordenado = NULL, *aux = NULL;

	ordenado = (alumno **) malloc (sizeof(alumno *) * cant);

	if (ordenado != NULL)
	{
		for (j = 0; j < cant; j++)
		{
			ordenado[j] = lista[j];
		}
		
		while (i != SALIDA)
		{
			i = SALIDA;

			for (j = 0; j < cant - 1 - k; j++)
			{
				if (strcmp((lista[j])->nombre, (lista[j+1])->nombre) > 0)
				{
					aux = ordenado[j];
					ordenado[j] = ordenado[j+1];
					ordenado[j+1] = aux;
					i = 0;
				}
			}
			
			k++;
		}
	}

	return ordenado;
}

void mostrar (alumno **ordenado, int cant)
{
	int i;

	printf("ID\t\tNOMBRE\t\tFECHA DE INGRESO\t\tEDAD\n");

	for (i = 0; i < cant; i++)
	{
		printf("%i\t\t%s\t\t%i/%i/%i\t\t%i\n", (ordenado[i])->id, (ordenado[i])->nombre, (ordenado[i])->fe.dia, (ordenado[i])->fe.mes, (ordenado[i])->fe.anio, (ordenado[i])->edad);	
	}
}

void liberar_lista (alumno ***lista, int cant)
{
	int i;
	
	for (i = 0; i < cant; i++)
	{
		free((*lista)[i]->nombre);
		free((*lista)[i]);	
	}
	
	free(*lista);
}



