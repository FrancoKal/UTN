#include "funciones.h"
#include <math.h>

void pedirMemoria (VECTOR *vec)
{
    if (vec->length > 0)
        vec->v = (int*) malloc (sizeof(int) * vec->length);
}

void copiarVector (VECTOR original, VECTOR nuevo)
{
    int i;

    nuevo.length = original.length;

    for (i = 0; i < original.length; i++)
        nuevo.v[i] = original.v[i];
}

bool esPrimo (unsigned long x)
{
	int i;
    unsigned long sqrt_x = sqrt(x); // No es necesario probar hasta x/2. Con probar hasta sqrt(x) alcanza para determinar si es primo o no
    bool primo = false;

    if (x % 2 == 0)
        primo = true;
    else
    {
        for (i = 3; i <= sqrt_x /*x/2*/ && primo == false; i += 2)
	    {
		    if (x % i == 0)
                primo = true;
	    }
    }

	return primo;
}

void llenarVector(VECTOR *vec)
{
    int i;

    pedirMemoria(vec);

    if (vec->v != NULL)
    {
        srandom(time(NULL));

        for (i = 0; i < vec->length; i++)
            vec->v[i] = rand() % (MAX_LIMIT + 1);
    }
}

void escribir(VECTOR vec, FILE *file)
{
    int i;

    for (i = 0; i < vec.length; i++)
        fprintf(file, "%i\n", vec.v[i]);
}

int Sumar (VECTOR vec)
{
    int i, suma = 0;

    for (i = 0; i < vec.length; i++)
        suma += vec.v[i];

    return suma;
}

int Maximo (VECTOR vec)
{
    int i, maximo = vec.v[0];

    for (i = 1; i < vec.length; i++)
        if (maximo < vec.v[i])
            maximo = vec.v[i];

    return maximo;
}

VECTOR Primos (VECTOR vec)
{
    int i, j;
    VECTOR primos = {.v = NULL};

    for (i = j = 0; i < vec.length; i++)
    {
        if (esPrimo(vec.v[i]))
        {
            primos.v = (j == 0)? (int*) malloc (sizeof(int)) : (int*) realloc (primos.v, sizeof(int) * (j+1));

            if (primos.v == NULL)
            {
                free(primos.v);
                break;
            }
                
            primos.v[j] = vec.v[i];
            j++;
        }
    }

    if (primos.v != NULL)
        primos.length = j;

    return primos;
}

VECTOR Ordenar (VECTOR vec)
{
    int i = 0, aux = 0;
    VECTOR ordenado = {.v = NULL, .length = vec.length};

    pedirMemoria(&ordenado);

    if (ordenado.v != NULL)
    {
        copiarVector(vec, ordenado);

        while (aux == 0)
        {
            aux = 1;

            for (i = 0; i < ordenado.length-1; i++)
            {
                if (ordenado.v[i] > ordenado.v[i+1])
                {
                    aux = ordenado.v[i];
                    ordenado.v[i] = ordenado.v[i+1];
                    ordenado.v[i+1] = aux;
                    aux = 0;
                }
            }
        }
    }

    return ordenado;
}