/**
        \file    mainbase.c
        \brief   Archivo principal para la carga de tiempos de carrera (versión con memoria dinámica).
        \brief   Se agregsa el nombre para el corredor y dos criterios de ordenamiento
        \author  Hecho en clase
        \date    2020.08.24
        \version 1.1.0
*/


//--------------
//-- Includes --
//--------------

#include "funcV1.h"
#include <ctype.h>
#include <stdlib.h>

/**
        \fn      main
        \brief   funcion principal
        \author  Hecho en clase
        \date    2020.08.24
        \return  0: si todo salió bien
                 1: si se produjo algún error
*/

int main (void)
{

	runner * listado = NULL;
	velocidad * resultado = NULL;
	int cant;
	char orden;

	cant = carga (&listado);

	if (( cant > 0 ) && (listado))
	{
		calculo (listado, &resultado, cant);

		printf("En que orden lo quiere mostrar.\nCon 'N' muestra por nombre, cualquier otra letra por velocidad.\n---> ");
		scanf(" %c",&orden);

//		if( (orden == 'N') || (orden == 'n'))
		if( toupper(orden) == 'N')
		{
			orden_n (resultado, cant);
		}
		else
		{
			orden_v (resultado, cant);
		}

		impresion(resultado, cant);
		free (resultado);
		free (listado);
	}
	else
	{
		printf("No hay corredores para mostrar.\n");

	}
	return 0;

}

//------------------------------------------------------------------------

