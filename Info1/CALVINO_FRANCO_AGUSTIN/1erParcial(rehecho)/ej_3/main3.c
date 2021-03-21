/**
	\file    main3.c
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
#include "funciones3.h"

/**
	\fn      int main (void)
	\brief   Llama a la funcion 'raices'
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13
	\return  0
*/

int main (void)
{
	int v1[] = {1,3,9,4,25,-3,144,81};//, i;
	unsigned int *v2 = NULL;

	raices(v1, &v2);
	
	/*for (i = 0; i < 5; i++)
	{
		printf("v2[%i] = %i\n", i, *(v2 + i));
	}*/
	
	free(v2);

	return 0;
}





