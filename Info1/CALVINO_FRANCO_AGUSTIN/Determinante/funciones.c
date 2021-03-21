#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int ** menor (int **men, int orden, int n);

int ** pedir_memoria (int orden)
{
	int **m = NULL, i = OK;
	
	m = (int **) malloc (sizeof(int *) * orden);
	
	if (m != NULL)
	{
		for (i = 0; (i < orden) && (i != SIN_MEMORIA); i++)
		{
			m[i] = (int *) malloc (sizeof(int) * orden);
			
			if (m[i] == NULL)
			{
				liberar_memoria(&m, i-1); //Si me da NULL, libero la memoria que pedi para las filas anteriores
				i = SIN_MEMORIA;
			}
		}
	}
	else i = SIN_MEMORIA;
	
	return m;
}
			
void ingresar_matriz (int **m, int orden)
{
	int i, j;

	for (i = 0; i < orden; i++)
	{	
		for (j = 0; j < orden; j++)
		{
			printf("[%i][%i]: ", i, j);
			scanf("%i", &(m[i][j]));
		}

		printf("\n");
	}
}

void imprimir_matriz (int **m, int orden)
{
	int i, j;
	
	for (i = 0; i < orden; i++)
	{
		for (j = 0; j < orden; j++) printf("%i\t", m[i][j]);
		
		printf("\n\n");
	}
}

int determinante (int **A, int orden)
{	
	int i, **men = NULL, det = 0, signo = 1;
		
	if (orden == 2) det = A[0][0] * A[1][1] - A[0][1] * A[1][0];
	
	else if (orden > 2)
	{
		for (i = 0; i < orden; i++)
		{
			men = menor(A, orden, i);
			det += A[0][i] * signo * determinante(men, orden-1); //Desarrollo el determinante por la fila 1
			liberar_memoria(&men, orden-1);
			signo *= -1;
		}
	}
	
	return det;
}

int ** menor (int **men, int orden, int n) // "n" es el numero de columna que se "ignora" para calcular el menor (usando la regla de Laplace)
{
	int **aux = NULL, i, j, columna;
	
	aux = pedir_memoria(orden-1);
	
	if (aux != NULL)
	{
		for (i = 1; i < orden; i++) //Empiezo por la fila 1 ya que desarrollo el determinante por ahi, me la salteo
		{
			for (j = columna = 0; j < orden; j++)
			{
				if (j != n)
				{
					aux[i-1][columna] = men[i][j];
					printf("aux[%i][%i] = %i\n", i-1, columna, aux[i-1][columna]);
					columna++; 
				}
			}
		}
	}
	
	return aux;
}

void liberar_memoria (int ***m, int orden)
{
	int i;
	
	for (i = 0; i < orden; i++)
	{
		free((*m)[i]);
	}
	
	free(*m);
}






