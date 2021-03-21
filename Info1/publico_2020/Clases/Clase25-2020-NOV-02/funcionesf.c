#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include "funcionesf.h"

#define MAXIMUS 500

void pares (int * vector, int cant, int archivo)
{

	int i, cuenta = 0;

	printf("Ingreso a la función pares\n");

	if (archivo != -1)
	{
		for (i = 0; i < cant; i++)
		{
			if(!((*(vector+i))%2))
			{
				write(archivo, (vector+i), sizeof(int));
				cuenta++;
			}
		}

		i = -1;
		write(archivo, &i, sizeof(int));

		printf("De los %d registros, se enviaron %d pares\n", cant, cuenta);

	}

	return;
}

void impares (int * vector, int cant, int archivo)
{

	int i, cuenta = 0;

	printf("Ingreso a la función impares\n");

	if (archivo != -1)
	{
		for (i = 0; i < cant; i++)
		{
			if((*(vector+i))%2)
			{
				write(archivo, (vector+i), sizeof(int));
				cuenta++;
			}
		}

		i = -1;
		write(archivo, &i, sizeof(int));

		printf("De los %d registros, se enviaron %d impares\n", cant, cuenta);

	}

	return;
}

void primos (int * vector, int cant, int archivo)
{

	int i, j, primito, cuenta = 0;

	printf("Ingreso a la función primos\n");

	if (cant > MAXIMUS) cant = MAXIMUS;

	if (archivo != -1)
	{
		for (i = 0; i < cant; i++)
		{
			primito = 0;
			for ( j = 2; j < i/2; j++)
			{
					if (!(i % j)) primito++;
			}

			if(!primito)
			{
				write(archivo, (vector+i), sizeof(int));
				cuenta++;
			}
		}

		i = -1;
		write(archivo, &i, sizeof(int));

		printf("De los %d registros, se enviaron %d primos\n", cant, cuenta);

	}

	return;
}

void decenas (int * vector, int cant, int archivo)
{

	int i, cuenta = 0;

	printf("Ingreso a la función decenas\n");

	if (archivo != -1)
	{
		for (i = 0; i < cant; i++)
		{
			if(!((*(vector+i))%10))
			{
				write(archivo, (vector+i), sizeof(int));
				cuenta++;
			}
		}

		i = -1;
		write(archivo, &i, sizeof(int));

		printf("De los %d registros, se enviaron %d decenas\n", cant, cuenta);

	}

	return;
}

void sumatoria (int * vector, int cant, int archivo)
{

	int i, j, cuenta = 0;
	long int sumadito;

	printf("Ingreso a la función sumatoria\n");

	if (cant > MAXIMUS) cant = MAXIMUS;

	if (archivo != -1)
	{
		for (i = 0; i < cant; i++)
		{
			sumadito = 0;
			for ( j = 1; j <= *(vector+i); j++)
			{
					sumadito += j;
			}

			write(archivo, &sumadito, sizeof(long int));
			cuenta++;
		}

		sumadito = -1;
		write(archivo, &sumadito, sizeof(long int));

		printf("De los %d registros, se envió la sumatoria de %d\n", cant, cuenta);

	}

	return;
}

