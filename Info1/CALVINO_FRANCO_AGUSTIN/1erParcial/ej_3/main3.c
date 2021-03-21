/**
	\file    main3.c
	\brief   Rutina principal main del programa
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <stdlib.h>
#include "funciones3.h"

/**
	\fn      int main (--------------------------)
	\brief   <Función de la función>
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13
	\param   <Parámetro A (si no tiene no se pone)>
	\param   <Parámetro B (si no tiene no se pone)>
	\return  <Lo que retorna>
*/

int main (void)
{
	int **vector1 = NULL;
	unsigned int **vector2 = NULL, numeros, i;

	printf("Ingresa numeros para el vector 1. Cuando ingresas 0 se corta el vector\n ");
	numeros = raices (vector1, vector2);
	
	vector1 = (int *) malloc(sizeof(int) * numeros);
	vector2 = (unsigned int *) malloc(sizeof(unsigned int) * numeros);

	if ((vector1 != NULL) && (vector2 != NULL))
	{
		printf("\nY las raices enteras son:\n");

		for (i = 0; i < numeros; i++)
		{
			vector2 = raices(vector1, vector2);
			vector1++;
			vector2++;
		}
	}
	else
	{
		printf("No hay memoria disponible");
	}


	return 0;
}


