/**
	\file    funciones2.c
	\brief   Funciones basicas que utiliza el main2.c
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.10.26
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include <stdlib.h>
#include <time.h>
#include "funciones2.h"

/**
	\fn     <Prototipo de la función>
	\brief  <Función de la función>
	\author Franco Calvino (francoc.2002@gmail.com)
	\date   2020.10.26 
	\param  <Parámetro A>
	\param  <Parámetro B>
	\return <Lo que retorna>
*/

int crear_vec (int *v1, int **v2, int cant)
{
	int cant2 = 0;
	
	if (cant != 0)
	{
		//v2 = (int **) malloc (sizeof(int *)); Ya vi mi error, esto no iba
		*v2 = pedir_vec(v1, cant, &cant2);		
	}
	
	if (cant2 == ERROR)
	{ 
		printf("Error al reservar memoria\n");
		liberar_memoria(v2);
	}
	
	return cant2;
}

int * pedir_vec (int *v1, int cant1, int *cant2)
{
	int i = 0, *v2 = NULL;
	
	if (cant1 != 0)
	{
		while (i < cant1 && v1[i] != FINALIZO && *cant2 != ERROR)
		{
			srandom(time(NULL));
				
			if (v1[i] > rand() % MAX)
			{
				v2 = (*cant2 == 0)? (int *) malloc (sizeof(int)) : (int *) realloc (v2, sizeof(int) * (*cant2+1));
				
				if (v2 != NULL)
				{
					v2[*cant2] = v1[i];
					(*cant2)++;
				}
				else *cant2 = ERROR;
			}
		
			i++;
		}
	}
	
	return v2;
}

void liberar_memoria (int **v)
{
	free(*v);
	v = NULL;
}



