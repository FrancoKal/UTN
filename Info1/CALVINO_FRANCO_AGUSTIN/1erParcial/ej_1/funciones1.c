/**
	\file    funciones1.c
	\brief   Funciones que utiliza el main1.c
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13 
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones1.h"

/**
	\fn     <Prototipo de la función>
	\brief  <Función de la función>
	\author Franco Calvino (francoc.2002@gmail.com)
	\date   2020.07.13
	\param  <Parámetro A>
	\param  <Parámetro B>
	\return <Lo que retorna>
*/

int lugarcito (char *frase, char *separador, int **resultado)
{
	int i, j, n = 0;
	char *cambio;
	resultado = (int **) malloc (sizeof(int *) * strlen (frase));

	while (*frase != '\0')
	{
		for (i = 0; i < strlen(separador); i++)
		{
			if (*frase != *(separador + i))
			{
				**(resultado)++;
			}
			else
			{
				n++;
				resultado = (int **) realloc (resultado, sizeof(int *) * n);
				printf("%i ", j);
			}
		}

		frase++;
	}

	while (*frase != '\0')
	{
		if (*frase > *(frase + i))
		{ 

	**resultado = j;

	return **resultado;
}
