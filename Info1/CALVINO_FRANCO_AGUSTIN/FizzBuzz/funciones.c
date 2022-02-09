#include "funciones.h"

int pedirRango (int *min, int *max)
{
	int estado = OK;

	printf("Ingresa 2 numeros mayores a 0\n");
	scanf("%i %i", min, max);

	if (min < 0 || max < 0 || max < min)
	{
		printf("Error. Ingrese un rango valido\n");
		estado = ERROR;
	}

	return estado;
}

int CrearVector (int min, int max, char ***strings)
{
	int i, j = 0, rango = max - min;

	*strings = (char **) malloc (sizeof(char*) * rango);

	if (*strings != NULL)
	{
		for (i = min; i != max; i++)
		{
			if (i % 3 == 0 && i % 5 == 0)
			{
				(*strings)[j] = (char *) malloc (sizeof("FizzBuzz"));

				if ((*strings)[j] != NULL)
					strcpy((*strings)[j], "FizzBuzz");
			}
			else if (i % 3 == 0)
			{
				(*strings)[j] = (char *) malloc (sizeof("Fizz"));

                                if ((*strings)[j] != NULL)
                                	strcpy((*strings)[j], "Fizz");
			}
			else if (i % 5 == 0)
			{
				(*strings)[j] = (char *) malloc (sizeof("Buzz"));

                                if ((*strings)[j] != NULL)
                                	strcpy((*strings)[j], "Buzz");
			}
			else
			{
				(*strings)[j] = (char *) malloc (sizeof(char));

                                if ((*strings)[j] != NULL)
                                	*((*strings)[j]) = (char) i;
			}

			j++;
		}
	}

	return rango;
}

void imprimir (char **strings, int rango)
{
	int i;

	for (i = 0; i < rango; i++)
	{
		printf("string[%i] = %s\n", i, strings[i]);
	}
}

void liberar (char ***strings, int rango)
{
	int i;

	for (i = 0; i < rango; i++)
	{
		free((*strings)[i]);
	}

	free(*strings);
}
