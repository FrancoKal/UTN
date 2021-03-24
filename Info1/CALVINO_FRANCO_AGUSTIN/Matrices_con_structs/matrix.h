#include <stdio.h>
#include <stdlib.h>

enum errores {ERROR_PRODUCTO = -1, ERROR_DATOS = -2, SIN_MEMORIA = -3};

#define CANT_MATRICES 2
#define iMatrix_Printf(A) (iMatrix_Fprintf (A, stdout))
#define iMatrix_Scanf(A) (iMatrix_Fscanf (A, stdin))

typedef struct
{
	int **mat, rows, cols;
} iMatrix;

void iMatrix_Malloc (iMatrix *A);
void iMatrix_Fprintf (iMatrix A, FILE* file);
void iMatrix_Fscanf(iMatrix *A, FILE* file);
int iMatrix_Det (iMatrix A);
iMatrix iMatrix_Product (iMatrix A, iMatrix B);
iMatrix iMatrix_ScalarProduct (iMatrix A, int k);
void iMatrix_Free (iMatrix *A);