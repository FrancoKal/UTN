#include "funciones.h"

#define LENGTH(x) sizeof(x) / sizeof(x[0])

void* BuscarPrimos (void* p)
{
    VECTOR primos = Primos(*((VECTOR*) p));
    FILE *file = NULL;

    file = fopen("primos.txt", "w");

    if (primos.v == NULL)
        printf("ES NULL!!!!\n");

    if (file != NULL)
    {
        escribir(primos, file);
        fclose(file);
    }

    free(primos.v);
    pthread_exit(NULL); //return NULL;
}

void* SumarVector (void *p)
{
    int *suma = NULL;

    suma = (int*) malloc (sizeof(int));

    if (suma != NULL)
        *suma = Sumar(*((VECTOR*) p));

    pthread_exit(suma); //return suma;
}

void* OrdenarVector (void *p)
{
    VECTOR ordenado = Ordenar(*((VECTOR*) p));
    FILE *file = NULL;

    file = fopen("ordenado.txt", "w");

    if (ordenado.v == NULL)
        printf("ES NULL!!!!\n");

    if (file != NULL)
    {
        escribir(ordenado, file);
        fclose(file);
    }

    free(ordenado.v);
    pthread_exit(NULL); //return NULL;
}

void* BuscarMaximo (void *p)
{
    int *maximo = NULL;

    maximo = (int*) malloc (sizeof(int));

    if (maximo != NULL)
        *maximo = Maximo(*((VECTOR*) p));

    pthread_exit(maximo); //return maximo;
}


int main (void)
{
    int i, *suma = NULL, *maximo = NULL, pthreadCreadoConExito;
    VECTOR  vec = {.v = NULL, .length = 10000};
    pthread_t threads[4];
    FILE *datos = NULL;
    void* (*routines[4]) (void*) = {BuscarPrimos, SumarVector, OrdenarVector, BuscarMaximo};

    llenarVector(&vec);

    if (vec.v != NULL)
    {
        datos = fopen("datos.txt", "w");

        if (datos != NULL)
        {
            escribir(vec, datos);
            fclose(datos);
            
            for (i = 0; i < 4; i++)
            {
                pthreadCreadoConExito = pthread_create(&threads[i], NULL, routines[i], &vec);

                if (pthreadCreadoConExito)
                {
                    perror("pthread_create");
                    exit(1);
                }

                printf("Creado el thread %i, ahora me dispongo a esperar su finalizacion...\n", i+1);
            }

            if (pthread_join(threads[0], NULL) != 0)
            {
                perror("pthread_join");
                exit(2);
            }

            if (pthread_join(threads[1], (void**) &suma) != 0)
            {
                perror("pthread_join");
                exit(2);
            }

            if (pthread_join(threads[2], NULL) != 0)
            {
                perror("pthread_join");
                exit(2);
            }

            if (pthread_join(threads[3], (void**) &maximo) != 0)
            {
                perror("pthread_join");
                exit(2);
            }

            printf("Suma = %i\n", *suma);
            printf("Maximo = %i\n", *maximo);

            if (suma != NULL) free(suma);
            if (maximo != NULL) free(maximo);
        }

        free(vec.v);
    }

    return 0;
}