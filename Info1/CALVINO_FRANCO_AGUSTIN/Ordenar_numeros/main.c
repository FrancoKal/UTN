#include <stdio.h>
#include <string.h>
#include "funciones.h"

int main (void)
{
	FILE *archivo = NULL;
	char buffer_nombre[LARGO_MAX];
	int opcion;
	lista *aux = NULL, *ordenado = NULL;

	printf("Decime el nombre del archivo y te ordeno los numeros\nNombre---> ");
	fgets(buffer_nombre, LARGO_MAX, stdin);
	buffer_nombre[strlen(buffer_nombre) - 1] = '\0';
	archivo = fopen(buffer_nombre, "r");

	if (archivo != NULL)
	{
		aux = leer_numeros(archivo);
		fclose(archivo);
		archivo = NULL;
		printf("¿Como los queres ordenar?\n0. Mayor a menor\n1. Por divisor comun\nOpcion---> ");
		scanf("%i", &opcion);
		getchar();

		if (opcion >= 0 && opcion <= 3)
		{
			ordenado = ordenar(aux, opcion);
			
			if (ordenado != NULL)
			{	
				mostrar(ordenado);
				printf("¿Donde desea escribir el resultado? (escriba el nombre del archivo o '-n' para salir) ---> ");
				fgets(buffer_nombre, LARGO_MAX, stdin);
				buffer_nombre[strlen(buffer_nombre) - 1] = '\0';
				
				if (strcmp(buffer_nombre, "-n") != 0)
				{
					archivo = fopen(buffer_nombre, "w");
					
					if (archivo != NULL)
					{
						escribir(ordenado, archivo);
						fclose(archivo);
					}
				}
				
				liberar_memoria(&ordenado);
			}
		}
		else printf("Opcion mal elegida. Reintente\n");
		
		liberar_memoria(&aux);
	}

	return 0;
}
