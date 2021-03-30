#include "matrix.h"

/*size_t type_size (type VarType)
{
	size_t result = 0;

	switch(VarType)
	{
		case INT:
			result = sizeof(int);
			break;
		case CHAR:
			result = sizeof(char);
			break;
		case LONG:
			result = sizeof(long);
			break;
		case DOUBLE:
			result = sizeof(double);
			break;
	}

	return result;
}*/

iMatrix iMatrix_Malloc (int rows, int cols)
{
	int i;
	iMatrix aux = {.mat = NULL};
	
	if (cols > 0 && rows > 0)
	{
		aux.rows = rows;
		aux.cols = cols;
		aux.mat = malloc (sizeof(int*) * rows);
		
		if (aux.mat != NULL)
		{
			for (i = 0; i < rows; i++)
			{
				aux.mat[i] = malloc (sizeof(int) * cols);
				
				if (aux.mat[i] == NULL) //Si no hay memoria disponible, debo liberar las filas anteriores
				{
					aux.rows = i; //El numero de filas a liberar sera las que el contador i llego hasta el momento
					iMatrix_Free(&aux);
					break;
				}
			}
		}
	}

	return aux;
}

/*iMatrix iMatrix_Malloc (int rows, int cols, type VarType)
{
	int i;
	iMatrix A = {.mat = NULL, .VarType = VarType};
	
	if (A.cols > 0 && A.rows > 0)
	{
		A.rows = rows;
		A.cols = cols;
		//A.mat = (int**) malloc (sizeof(int*) * A.rows);
		A.mat = malloc (sizeof(void*) * A.rows);
		
		if (A.mat != NULL)
		{
			for (i = 0; i < A.rows; i++)
			{
				//A.mat[i] = (int*) malloc (sizeof(int) * A.cols);
				A.mat[i] = malloc (type_size(VarType) * A.cols);
				
				if (A.mat[i] == NULL) //Si no hay memoria disponible, debo liberar las filas anteriores
				{
					A.rows = i; //El numero de filas a liberar sera las que el contador i llego hasta el momento
					iMatrix_Free(&A);
					break;
				}
			}
		}
	}

	return A;
	
}*/

void iMatrix_Free (iMatrix *A)
{
	int i;

	for (i = 0; i < A->rows; i++)
		free(A->mat[i]);

	free(A->mat);
	A->mat = NULL;
}

iMatrix iMatrix_Product (iMatrix A, iMatrix B)
{
	int i, j, k;
	iMatrix AxB = {.mat = NULL};

	if (A.cols == B.rows)
	{
		AxB = iMatrix_Malloc(A.rows, B.cols);

		if (AxB.mat != NULL)
			for (i = 0; i < A.rows; i++)
				for (j = 0; j < B.cols; j++)
					for(k = AxB.mat[i][j] = 0; k < A.cols /*B.rows tambien sirve*/; k++)
						// "k" sirve para marcar hasta cuando se debe sumar para cada elemento de la matriz
						AxB.mat[i][j] += A.mat[i][k] * B.mat[k][j];
	}

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

		fprintf(file, "\n\n");
	}
}

void iMatrix_Fscanf (iMatrix *A, FILE* file)
{
	int i, j;

	for (i = 0; i < A->rows; i++)
	{
		for (j = 0; j < A->cols; j++)
			fscanf(file, "%i", &A->mat[i][j]);

		fprintf(file, "\n\n");
	}
}

int iMatrix_Det (iMatrix A)
{
	int i, sign = 1, det = 0;
	iMatrix minor = {.mat = NULL};

	if (A.rows == A.cols)
	{
		if (A.rows == 2)
			det = A.mat[0][0] * A.mat[1][1] - A.mat[0][1] * A.mat[1][0];
		else
		{
			for (i = 0; i < A.cols; i++)
			{
				minor = iMatrix_Minor(A, 0, i); //Desarrollo el determinante por la primera fila

				if (minor.mat == NULL)
					break;

				det += sign * A.mat[0][i] * iMatrix_Det(minor);
				iMatrix_Free(&minor);
				sign *= -1;
			}
		}
	}

	return det;
}

iMatrix iMatrix_Minor (iMatrix A, int row, int col)
{
	int i, j, m, n;
	iMatrix minor = {.mat = NULL};

	if (A.rows == A.cols)
	{
		minor = iMatrix_Malloc(A.rows-1, A.cols-1);

		if (minor.mat != NULL)
			for (i = m = 0; i < A.rows; i++)
			{
				if (i != row)
				{
					for (j = n = 0; j < A.cols; j++)
					{
						if (j != col)
						{
							minor.mat[m][n] = A.mat[i][j];
							n++;
						}
					}

					m++;
				}
			}
	}

	return minor;
}
