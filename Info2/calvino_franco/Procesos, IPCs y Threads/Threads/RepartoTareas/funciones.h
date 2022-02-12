#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <pthread.h>

typedef enum {true = 0, false = 1} bool;
#define MAX_LIMIT 10000

typedef struct
{
    int *v;
    int length;
} VECTOR;

typedef struct
{
    pthread_t thread;
    pthread_attr_t attr;
    pthread_key_t key;
    pthread_mutex_t mutex;
    void* (*routine) (void*);
    void *params;
    void *returnValue;
} THREAD;


void pedirMemoria (VECTOR *vec);
void copiarVector (VECTOR original, VECTOR nuevo);
bool esPrimo (unsigned long x);
int generar_numero_aleatorio (int min, int max);
void llenarVector(VECTOR*);
void escribir(VECTOR, FILE*);
int Sumar (VECTOR vec);
int Maximo (VECTOR vec);
VECTOR Primos (VECTOR vec);
VECTOR Ordenar (VECTOR vec);
