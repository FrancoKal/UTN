/**
	\file    funciones1.c
	\brief   Funciones basicas que utiliza el main1.c
	\author  Calvino, Franco (francoc.2002@gmail.com)
	\date    2020.11.30
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include "funciones1.h"

/**
	\fn     int generacion (int * codigos, int cant_codigos, DATOS ** listado, char * nombre_arch)
	\brief  Genera un vector de estructuras en DATOS **listado en base a los codigos pasados por argumento en int *codigos
	\author Calvino, Franco (francoc.2002@gmail.com)
	\date   2020.11.30
	\param  <Parámetro A>
	\param  <Parámetro B>
	\return j: cantidad de elementos generados
*/

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
					
				

