/**
	\file    funciones2.c
	\brief   Funciones basicas que utiliza el main2.c
	\author  Calvino, Franco (francoc.2002@gmail.com)
	\date    2020.11.30
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include "funciones2.h"

/**
	\fn     <Prototipo de la función>
	\brief  <Función de la función>
	\author Calvino, Franco (francoc.2002@gmail.com)
	\date   2020.11.30
	\param  <Parámetro A>
	\param  <Parámetro B>
	\return <Lo que retorna>
*/

int solicitar_codigos(int **cods)
{
	int i, cant_cods = ERROR;
	
	printf("¿Cuantos codigos desea? ---> ");
	scanf("%i", &cant_cods);
	
	if (cant_cods > 0)
	{
		*cods = (int*) malloc (sizeof(int) * cant_cods);
	
		if (*cods != NULL)
		{
			for (i = 0; i < cant_cods; i++)
			{
				printf("Codigo %i: ", i);
				scanf("%i", &((*cods)[i]));
			}
		}
	}
	
	return cant_cods;
}

int generacion (int * codigos, int cant_codigos, DATOS ** listado, char * nombre_arch)
{
	FILE *archivo = NULL;
	DATOS buffer, *aux = NULL;
	int i = 0, j = 0;
	
	if (codigos != NULL)
	{
		archivo = fopen(nombre_arch, "r");
		
		if (archivo != NULL)
		{
			do
			{
				fscanf(archivo, "%i,%f,%li", &buffer.codigo, &buffer.peso, &buffer.existencia);
				
				if (feof(archivo) == 0)
				{
					for (i = 0; i < cant_codigos; i++)
					{
						if (buffer.codigo == codigos[i])
						{
							aux = (j == 0)? (DATOS*) malloc (sizeof(DATOS)) : (DATOS*) realloc (aux, sizeof(DATOS) * (j+1));
							
							if (aux != NULL)
							{
								aux[j] = buffer;
								j++;
							}
							else j = ERROR;
						}
					}
				}
			}
			while (feof(archivo) == 0 && j != ERROR);
			
			fclose(archivo);
		}
	}
	
	if (j != ERROR) *listado = aux; //listado = &aux;
	
	return j;
}

