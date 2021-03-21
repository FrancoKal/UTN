/**
	\file    funciones2.c
	\brief   Funciones que utiliza el main2.c
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
	\fn     <Prototipo de la función>
	\brief  <Función de la función>
	\author Franco Calvino (francoc.2002@gmail.com)
	\date   2020.07.13
	\param  <Parámetro A>
	\param  <Parámetro B>
	\return <Lo que retorna>
*/

void traducir (char *p, int n)
{
	int caracteres = 0;

	while (*p != '\0')
	{
		/* Si el codigo ascii de la letra esta comprendido entre MIN y MAX inclusive, restar n. Si esta entre esos valores y la 'z' o la 'Z' le resto 13. Sino
		procedo a imprimir el caracter como esta sin alterarlo */ 

		if (((atoi(p) - n) >= MIN) && ((atoi(p) - n) <= MAX))
		{
			*(p) -= n;
		}
		else if ((atoi(p) - n) < MIN)
		{
			*(p) += MAX - n;
		}
 
		printf("%i ", *p);
		p++;
		caracteres++;
	}

	printf("\nEn total hay %i caracteres\n", caracteres); 

}
