/**
	\file    funciones2.c
	\brief   Funciones que utiliza el main2.c
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13 
	\version 1.1.0
*/


//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <string.h>
#include "funciones2.h"

/**
	\fn     void traducir (char *string, int n)
	\brief  Toma la frase pasada como primer argumento y guarda en un vector la diferencia entre el codigo ASCII de cada letra y el numero pasado como argumento. Si la resta no esta dentro del 			rango definido de caracteres imprimibles, comenzara a restar desde el maximo
	\author Franco Calvino (francoc.2002@gmail.com)
	\date   2020.07.13
	\param  char *string : El string pasado como argumento 1
	\param  int n : El numero pasado como argumento 2
	\return nada. Es un void
*/



void traducir (char *string, int n)
{
	int caract, v[strlen(string) - 1];
	
	for (caract = 0; string[caract] != '\0'; caract++)
	{
		if ((string[caract] - n >= MIN) && (string[caract] - n <= MAX))
		{
			v[caract] = ((int) string[caract]) - n;									
		}
		else if (string[caract] - n < MIN)
		{
			v[caract] = MAX - (n - ((int) string[caract] - MIN));
		}
	}
	
	for (caract = 0; string[caract] != '\0'; caract++)
	{
		printf("v[%i] = %i\n", caract, v[caract]);
	}
	
	printf("En total hay %i caracteres\n", caract);
}

