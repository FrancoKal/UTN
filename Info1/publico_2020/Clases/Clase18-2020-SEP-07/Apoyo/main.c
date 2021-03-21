/**
	\file    main.c
	\brief   Archivo principal para la ejecución del menú y llamar a las funciones de carga, impresión y muestra.
	\author  Hecho en clase
	\date    2020.09.07
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
	\fn      main
	\brief   funcion principal
	\author  Hecho en clase
	\date    2020.09.07
	\return  0: si todo salió bien
		 1: si se produjo algún error
*/

int main (void)
{

	char opcion;
	conjunto * listado;
	int cantidad = 0;

	listado = (conjunto *) malloc (sizeof(conjunto)*MAX_ELEM);
	if (listado)
	{
		do
		{
			opcion = menu();

			if (opcion == 'C')
			{
				cantidad = cargar(listado);
			}
			else if (opcion == 'G')
			{
				grabar(listado, cantidad);
			}
			else if (opcion == 'M')
			{
				mostrar(listado, cantidad);
			}
			else if (opcion == 'A')
			{
				cantidad = agregar (listado);
			}
		}
		while (opcion != 'S');

		free (listado);
	}
	else
	{
		printf("No se pudo asignar memoria.\n");
	}
	return 0;
}

//-----------------------------------------------------------------------------------------
