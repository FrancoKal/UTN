#include <stdio.h>
#include "funciones.h"

int main (void)
{
	int **A = NULL, orden, det;
	
	printf("Ingresa el orden de la matriz y calculo su determinante: ");
	scanf("%i", &orden);
	
	A = /*(int *) malloc (sizeof(int) * (orden * orden));*/pedir_memoria(orden);
		
	if (A != NULL)
	{	
		printf("Ingresa la matriz:\n");
		ingresar_matriz(A, orden);
		imprimir_matriz(A, orden);
		det = determinante(A, orden);
		printf("|A| = %i\n", det);
		liberar_memoria(&A, orden);
	}
	else printf("No hay memoria disponible\n");

	printf("\n");

	return 0;
}
