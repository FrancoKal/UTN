/**
	\file    main1.c
	\brief   Rutina principal main del programa
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13
	\version 1.1.0
*/


//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <stdlib.h>
#include "funciones1.h"

/**
	\fn      int main (void)
	\brief   LLama a la funcion "lugarcito", que se encarga de todo el trabajo
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13
	\return  0
*/

int main (void)
{
	char frase[] = "La puta madre esta dificil este ejercicio", separador[] = "al" ;
	int *resultado = NULL;//, i;

	lugarcito(frase, separador, &resultado);

	/*for (i = 0; i < 5; i++)
	{
		printf("resultado[%i] = %i\n", i, *(resultado + i));
	}*/
	
	free(resultado);

	return 0;
}


