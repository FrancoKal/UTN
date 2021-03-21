#include <stdio.h>

enum errores {ERROR_PRODUCTO = -1, ERROR_DATOS = -2, SIN_MEMORIA = -3};

#define CANT_MATRICES 2

struct matrices
{
	int **m, filas, columnas;
};

typedef struct matrices matriz;

int pedir_matriz (matriz *puntero);
int ** pedir_memoria (int filas, int columnas);
void ingresar_matriz (matriz A);
void imprimir_matriz (matriz A);
int ** producto (matriz A, matriz B);
void liberar_memoria (int ***m, int filas);

