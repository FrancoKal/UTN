/**
	\file    main1.c
	\brief   Rutina principal (main) del programa
	\author  Calvino, Franco (francoc.2002@gmail.com)
	\date    2020.11.30
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include "funciones1.h"


/**
	\fn      int main (---)
	\brief   <Función de la función>
	\author  Calvino, Franco (francoc.2002@gmail.com)
	\date    2020.11.30
	\param   <Parámetro A (si no tiene no se pone)>
	\param   <Parámetro B (si no tiene no se pone)>
	\return  0
*/

int main (void)
{
	int cod[] = {38349, 80125, 0, 19069}, cant_codigos = 4, cant, i;
	DATOS *listado = NULL;
	
	cant = generacion(cod, cant_codigos, &listado, FILENAME);
	
	if (cant != ERROR)
	{
		for (i = 0; i < cant; i++)
		{
			printf("Cod: %i, Peso: %f, Existencia: %li\n", (listado[i]).codigo, (listado[i]).peso, (listado[i]).existencia); 
		}
	}

	free(listado);
	
	return 0;
}

