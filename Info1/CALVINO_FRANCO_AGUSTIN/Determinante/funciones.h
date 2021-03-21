#include <stdio.h>

enum estado {OK = 0, SIN_MEMORIA = -1};

int ** pedir_memoria (int orden);
void ingresar_matriz (int **matriz, int orden);
void imprimir_matriz (int **matriz, int orden);
int determinante (int **matriz, int orden);
void liberar_memoria (int ***matriz, int orden);
