/**
	\file    main2.c
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
#include "funciones2.h"

/**
	\fn      int main (--------------------------)
	\brief   <Función de la función>
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13
	\param   <Parámetro A (si no tiene no se pone)>
	\param   <Parámetro B (si no tiene no se pone)>
	\return  <Lo que retorna>
*/

int main (int cuanto, char *frase[])
{
	if ((atoi(frase[2]) < MIN) || (atoi(frase[2]) > MAX))
	{
		printf("El numero tiene que estar entre 32 y 126");
	}
	else
	{
		traducir(frase[1], atoi(frase[2]));
	}



	return 0;
}


