/**
	\file    main2.c
	\brief   Rutina principal (main) del programa
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.10.26
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include "funciones2.h"


/**
	\fn      int main (---------)
	\brief   <Función de la función>
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.10.26
	\param   <Parámetro A (si no tiene no se pone)>
	\param   <Parámetro B (si no tiene no se pone)>
	\return  0 
*/

int main (void)
{
	int i, j, v1[] = {7432, 5789, 3611, 123, 0}, *v2 = NULL;
	
	j = crear_vec(v1, &v2, 5);

	if (j != ERROR)
	{
		printf("j = %i\n", j);
	
		for (i = 0; i < j; i++)
		{
			printf("v2[%i] = %i\n", i, v2[i]);
		}
		
		liberar_memoria(&v2);
	}

	return 0;
}

