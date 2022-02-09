#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define OK 0
#define ERROR -1

int pedirRango (int *min, int *max);
int CrearVector (int min, int max, char ***strings);
void imprimir (char **strings, int rango);
void liberar (char ***strings, int rango);
