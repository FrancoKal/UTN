#include <stdio.h>

enum errores {ERROR_PRODUCTO = -1, ERROR_DATOS = -2, SIN_MEMORIA = -3};

#define CANT_MATRICES 2

/*struct matrices
{
	int **m, filas, columnas;
};

typedef struct matrices matriz;

int pedir_matriz (matriz *puntero);
int ** pedir_memoria (int filas, int columnas);
void ingresar_matriz (matriz A);
void imprimir_matriz (matriz A);
int ** producto (matriz A, matriz B);
void liberar_memoria (int ***m, int filas);*/

typedef struct
{
	int **mat, rows, cols;
} int_matrix;

void int_matrixMalloc (int_matrix ***A);
void int_matrixPrint (int_matrix **A);
int int_matrixDet (int_matrix **A);
int_matrix** int_matrixProduct (int_matrix **A, int_matrix **B);
void int_matrixFree (int_matrix ***A);


