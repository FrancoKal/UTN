#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int pedir_matriz (matriz *mat)
{
	int i;

	for (i = 0; (i < CANT_MATRICES) && (i >= 0); i++)
	{
		printf("Ingresa las filas y las columnas de la matriz %i: ", i + 1);
		scanf("%i %i", &(mat[i].filas), &(mat[i].columnas));
		
		if (mat[i].filas <= 0 || mat[i].columnas <= 0) i = ERROR_DATOS;
	}
	
	if (mat[0].columnas != mat[1].filas) i = ERROR_PRODUCTO;
	
	return i;
}

int ** pedir_memoria (int filas, int columnas)
{
	int **m = NULL, i;
	
	m = (int **) malloc (sizeof(int *) * filas);
	
	if (m != NULL)
	{
		for (i = 0; (i < filas) && (i != SIN_MEMORIA); i++)
		{
			m[i] = (int *) malloc (sizeof(int) * columnas);
			
			if (m[i] == NULL)
			{
				liberar_memoria(&m, i-1); //Si me da NULL, libero la memoria que pedi para las filas anteriores
				i = SIN_MEMORIA;
			}
		}
	}
	
	return m;
}

void ingresar_matriz (matriz mat)
{
	int i, j;

	for (i = 0; i < mat.filas; i++)
	{	
		for (j = 0; j < mat.columnas; j++)
		{
			printf("[%i][%i]: ", i, j);
			scanf("%i", &(mat.m[i][j]));
		}

		printf("\n");
	}
}

void imprimir_matriz (matriz mat)
{
	int i, j;
	
	for (i = 0; i < mat.filas; i++)
	{
		for (j = 0; j < mat.columnas; j++) printf("%i\t", mat.m[i][j]);
		
		printf("\n\n");
	}
}

int ** producto (matriz A, matriz B) 
{
	/* A e R^mxn y B e R^ixj, filas = m, columnas = j y orden = n = i. Asi, la matriz producto queda de la forma mxj, pero necesito saber la cantidad de 
	elementos por fila de las matrices a multiplicar (el orden) para saber hasta donde multiplicar*/
	int i, j, k, **AB = NULL;					
	
	AB = pedir_memoria(A.filas, B.columnas);

	/*for (i = 0; i < A.filas; i++)
	{
		for (j = 0; j < B.columnas; j++)
		{
			AB[i][j] = k = 0;

			while (k != A.columnas) // "k" sirve para marcar hasta cuando se debe sumar para cada elemento de la matriz
			{
				AB[i][j] += (A.m)[i][k] * (B.m)[k][j];
				k++;
			}
		}
	}*/
	
	for (i = 0; i < A.filas; i++)
		for (j = 0; j < B.columnas; j++)
			for(k = AB[i][j] = 0; k < A.columnas; k++) // "k" sirve para marcar hasta cuando se debe sumar para cada elemento de la matriz
				AB[i][j] += A.m[i][k] * B.m[k][j];
	
	
	return AB;
}

void liberar_memoria (int ***m, int filas)
{
	int i;
	
	for (i = 0; i < filas; i++)
	{
		free((*m)[i]);
	}
	
	free(*m);
}



