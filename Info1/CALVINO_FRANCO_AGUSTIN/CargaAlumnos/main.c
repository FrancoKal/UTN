#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main (void)
{
	int cantidad;
	alumno **lista = NULL, **ordenado = NULL;

	printf("Ingresa la lista de alumnos (maximo de 100)\n");
	lista = (alumno **) malloc (sizeof(alumno *));
	
	if (lista != NULL)
	{
		cantidad = cargar(&lista);
		
		if (cantidad <= 100)
		{
			ordenado = ordenar(lista, cantidad);
			mostrar(ordenado, cantidad);
		}
		
		liberar_lista(&lista, cantidad);
		free(ordenado);
	}
	
	return 0;
}
