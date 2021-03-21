#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <sys/types.h>
#include <unistd.h>
#include "funciones.h"

#define MAXIMUS 80

void pares (int * vector, int cant, char * nombre)
{

	int i, cuenta = 0;
	FILE * archivo = NULL;

	archivo = fopen(nombre, "w");

	if (archivo)
	{
		for (i = 0; i < cant; i++)
		{
			if(!((*(vector+i))%2))
			{
				fprintf(archivo, "%d\n", *(vector+i));
				cuenta++;
			}
		}

		printf("De los %d registros, %d son pares\n", cant, cuenta);

		fclose(archivo);
	}

	return;
}

void impares (int * vector, int cant, char * nombre)
{

	int i, cuenta = 0;
	FILE * archivo = NULL;

	archivo = fopen(nombre, "w");

	if (archivo)
	{
		for (i = 0; i < cant; i++)
		{
			if((*(vector+i))%2)
			{
				fprintf(archivo, "%d\n", *(vector+i));
				cuenta++;
			}
		}

		printf("De los %d registros, %d son impares\n", cant, cuenta);

		fclose(archivo);
	}

	return;
}

void primos (int * vector, int cant, char * nombre)
{

	int i, j, primito, cuenta = 0;
	FILE * archivo = NULL;

	if (cant > MAXIMUS) cant = MAXIMUS;

	archivo = fopen(nombre, "w");

	if (archivo)
	{
		for (i = 0; i < cant; i++)
		{
			primito = 0;
			for ( j = 2; j < (*(vector+i))/2; j++)
			{
					if (!((*(vector+i)) % j)) primito++;
			}

			if(!primito)
			{
				fprintf(archivo, "%d\n", *(vector+i));
				cuenta++;
			}
		}

		printf("De los %d registros, %d son primos\n", cant, cuenta);

		fclose(archivo);
	}

	return;
}

void decenas (int * vector, int cant, char * nombre)
{

	int i, cuenta = 0;
	FILE * archivo = NULL;

	archivo = fopen(nombre, "w");

	if (archivo)
	{
		for (i = 0; i < cant; i++)
		{
			if(!((*(vector+i))%10))
			{
				cuenta++;
				fprintf(archivo, "%d\n", *(vector+i));
			}
		}

		printf("De los %d registros, %d son decenas\n", cant, cuenta);

		fclose(archivo);
	}

	return;
}

void sumatoria (int * vector, int cant, char * nombre)
{

	int i, j, cuenta = 0;
	long int sumadito;
	FILE * archivo = NULL;

	if (cant > MAXIMUS) cant = MAXIMUS;

	archivo = fopen(nombre, "w");

	if (archivo)
	{
		for (i = 0; i < cant; i++)
		{
			sumadito = 0;
			for ( j = 1; j <= *(vector+i); j++)
			{
					sumadito += j;
			}

			fprintf(archivo, "%ld\n", sumadito);
			cuenta++;
		}

		printf("De los %d registros, se calculo la sumatoria de %d\n", cant, cuenta);

		fclose(archivo);
	}

	return;
}

