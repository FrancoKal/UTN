/**
	\file    main2.c
	\brief   Rutina principal main del programa
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13
	\version 1.1.0
*/


//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include "funciones2.h"

/**
	\fn      int main (int argumentos, char *argumento[])
	\brief   Toma los argumentos pasados en la consola y llama a la funcion 'traducir'
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13
	\param   int argumentos : Es la cantidad de argumentos que recibe la funcion
	\param   char *argumento[] : El puntero a cada uno de los argumentos
	\return  0
*/

int main (int argumentos, char *argumento[])
{
	if (argumentos != 3)
	{
		printf("Mal usado. Pasame 3 argumentos: <'frase'> <numero>\n");
	}
	else if (atoi(argumento[2]) > MAX)
	{
		printf("El numero debe ser menor a 126");
	}
	else
	{
		traducir(argumento[1], atoi(argumento[2]));
	}


	return 0;
}


