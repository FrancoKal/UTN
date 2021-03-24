#include "matrix.h"

void iMatrix_Malloc (iMatrix *A)
{
	int i;
	iMatrix aux = {.mat = NULL, .rows = A->rows, .cols = A->cols};
	
	if (aux.cols > 0 && aux.rows > 0)
	{
		aux.mat = (int**) malloc (sizeof(int*) * aux.rows);
		
		if (aux.mat != NULL)
		{
			for (i = 0; i < aux.rows; i++)
			{
				aux.mat[i] = (int*) malloc (sizeof(int) * aux.cols);
				
				if (aux.mat[i] == NULL) //Si no hay memoria disponible, debo liberar las filas anteriores
				{
					aux.rows = i; //El numero de filas a liberar sera las que el contador i llego hasta el momento
					iMatrix_Free(&aux);
					break;
				}
			}

			A->mat = aux.mat;
		}
	}
}

void iMatrix_Free (iMatrix *A)
{
	int i;

	for (i = 0; i < A->rows; i++)
		free(A->mat[i]);

	free(A->mat);
}

iMatrix iMatrix_Product (iMatrix A, iMatrix B)
{
	int i, j, k;
	iMatrix AxB = {.mat = NULL, .rows = A.rows, .cols = B.cols};

	iMatrix_Malloc(&AxB);

	if (AxB.mat != NULL)
		for (i = 0; i < A.rows; i++)
			for (j = 0; j < B.cols; j++)
				for(k = AxB.mat[i][j] = 0; k < A.cols /*B.rows tambien sirve*/; k++)
					// "k" sirve para marcar hasta cuando se debe sumar para cada elemento de la matriz
					AxB.mat[i][j] += A.mat[i][k] * B.mat[k][j];

	return AxB;
}

iMatrix iMatrix_ScalarProduct (iMatrix A, int k)
{
	int i, j;

	for (i = 0; i < A.rows; i++)
		for (j = 0; j < A.cols; j++)
			A.mat[i][j] *= k;

	return A;
}

void iMatrix_Fprintf (iMatrix A, FILE* file)
{
	int i, j;

	for (i = 0; i < A.rows; i++)
	{
		for (j = 0; j < A.cols; j++)
			fprintf(file, "%i\t", A.mat[i][j]);

		fprintf(file, "\n");
	}
}

void iMatrix_Fscanf (iMatrix *A, FILE* file)
{
	int i, j;

	for (i = 0; i < A->rows; i++)
	{
		for (j = 0; j < A->cols; j++)
			fscanf(file, "%i", &A->mat[i][j]);

		fprintf(file, "\n");
	}
}




