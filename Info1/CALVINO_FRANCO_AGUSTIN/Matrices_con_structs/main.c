#include <stdio.h>
#include "funciones.h"

int main (void)
{
	int i;
	char simbolo[] = "*= ", *error[] = {"No se pueden multiplicar", "Fila o columna ingresada no valida"};
	matriz mat[3] = {NULL};

	i = pedir_matriz(mat);

	if (i == CANT_MATRICES)
	{
		mat[0].m = pedir_memoria(mat[0].filas, mat[0].columnas);
		mat[1].m = pedir_memoria(mat[1].filas, mat[1].columnas);
		
		if (mat[0].m == NULL || mat[1].m == NULL)
		{
			printf("No hay memoria disponible\n");
		}
		else
		{
			for (i = 0; i < CANT_MATRICES; i++)
			{
				printf("Ingresa la Matriz %i:\n", i + 1);
				ingresar_matriz(mat[i]);
			}
			
			printf("El resultado es:\n");
			mat[2].filas = mat[0].filas;
			mat[2].columnas = mat[1].columnas;
			mat[2].m = producto(mat[0], mat[1]);
			
			for (i = 0; i < CANT_MATRICES + 1; i++)
			{
				imprimir_matriz(mat[i]);
				printf("\n\n  %c\n", simbolo[i]);
				liberar_memoria(&(mat[i].m), mat[i].filas);
			}
		}
		
		
	}
	else printf("\nError. %s\n", error[-i - 1]);

	return 0;
}
