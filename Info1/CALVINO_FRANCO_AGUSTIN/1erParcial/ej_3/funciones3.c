/**
	\file    funciones3.c
	\brief   Funciones que utiliza el main3.c
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13 
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <math.h>
#include "funciones3.h"

/**
	\fn     <Prototipo de la función>
	\brief  <Función de la función>
	\author Franco Calvino (francoc.2002@gmail.com)
	\date   2020.07.13
	\param  <Parámetro A>
	\param  <Parámetro B>
	\return <Lo que retorna>
*/

int ingresar_numeros (int *vector)
{
	int resultado = 0;

	do
	{
		scanf("%i", vector);

		if (*vector < 0)
		{
			printf("No ingreses numeros negativos");
			resultado = ERROR_MAX;
		}
		else
		{
			resultado++;
		}
	}
	while (*vector > 0);

	return resultado;

}

unsigned int * raices (int *vector1, unsigned int *vector2)
{
	int i, termino = 0;
	unsigned int *p;

	if (*vector1 > 0)
	{
		while (termino != 1)
		{
			for (i = 0; i <= 10; i++)
			{
				if (((*vector1) / sqrt(*vector1)) == sqrt(*vector1))
				{
					*vector2 = *vector1;
					p = vector2;
					termino = 1;
				}
			}
		}
	}
	else if (*vector1 == 0)
	{
		p = NULL;
	}


	return p;
}
