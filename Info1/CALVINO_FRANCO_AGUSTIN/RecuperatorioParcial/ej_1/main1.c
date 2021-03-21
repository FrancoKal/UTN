/**
	\file    main1.c
	\brief   Rutina principal (main) del programa
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
	\fn      int main (---------)
	\brief   <Función de la función>
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.10.26
	\param   <Parámetro A (si no tiene no se pone)>
	\param   <Parámetro B (si no tiene no se pone)>
	\return  0 
*/

int main (int cant, char *arg[])
{
	if (cant != CANT_PALABRAS + 1)
	{
		printf("Error. Dame 5 palabras\n");
	}
	else
	{
		ordenar(arg);
	}

	return 0;
}

