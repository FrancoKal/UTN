#include <stdio.h>

#define LARGO_MAX 255

enum estado {SIN_MEMORIA = -1};

struct numeros
{
	int *datos, cant;
};

typedef struct numeros lista;

lista * leer_numeros (FILE *archivo);
lista * ordenar (lista *vector, int opcion);
void liberar_memoria(lista **vector);
void mostrar (lista *vector);
void escribir (lista *ordenado, FILE *archivo);

