/**
	\file    funciones1.c
	\brief   Funciones basicas que utiliza el main1.c
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.10.26
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include "funciones1.h"

/**
	\fn     <Prototipo de la función>
	\brief  <Función de la función>
	\author Franco Calvino (francoc.2002@gmail.com)
	\date   2020.10.26 
	\param  <Parámetro A>
	\param  <Parámetro B>
	\return <Lo que retorna>
*/

int mi_strcmp (const char *s1, const char *s2)
{
	int i;
	
	for (i = 0; s1[i] == s2[i] && s1[i] != '\0' && s2[i] != '\0'; i++);

	return (int) (s1[i] - s2[i]);
}


void ordenar (char **palabras)
{
	char *aux[CANT_PALABRAS], *mayor = NULL;
	int i, j;// buffer2 = CONTINUO;
	
	for (i = 0; i < CANT_PALABRAS; i++)
	{
			aux[i] = palabras[i+1];
	}

	for (i = 0; i < CANT_PALABRAS/* && buffer2 == CONTINUO*/; i++)
	{
		mayor = aux[i];
		//buffer2 = SIN_CAMBIO;
				
		for (j = i+1; j < 5; j++)
		{
			/*cambio(&(aux[i]), &(aux[j]));
			buffer2 = cambio(&(aux[j-1]), &(aux[j]));*/
		
			if (mi_strcmp(mayor, aux[j]) > 0)
			{
				mayor = aux[j];
				aux[j] = aux[i];
				aux[i] = mayor;
			}
			
			/*if (mi_strcmp(aux[j-1], aux[j]) > 0)
			{
				buffer1 = aux[j];
				aux[j] = aux[j-1];
				aux[j-1] = buffer1;
				buffer2 = CONTINUO;
			}*/
		}
		
		printf("%i. %s\n", i+1, aux[i]);
	}

	/*for (i = 0; i < CANT_PALABRAS; i++)
	{
		printf("%i. %s\n", i+1, aux[i]);
	}*/
}

/*int cambio (char **s1, char **s2)
{
	char *buffer = NULL;
	int estado = SIN_CAMBIO;	
	
	if (mi_strcmp(*s1, *s2) > 0)
	{
		buffer = *s2;
		*s2 = *s1;
		*s1 = buffer;
		estado = CONTINUO;
	}
	
	return estado;
}*/
	
	
