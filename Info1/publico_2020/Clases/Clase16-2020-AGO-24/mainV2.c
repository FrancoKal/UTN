/**
        \file    mainV2.c
        \brief   Archivo principal para la carga de tiempos de carrera (versión con memoria dinámica).
        \brief   Se agrega el nombre para el corredor y dos criterios de ordenamiento
        \brief   El ordenamiento se hace por indices
        \author  Hecho en clase
        \date    2020.08.24
        \version 1.2.0
*/


//--------------
//-- Includes --
//--------------

#include "funcV2.h"
#include <ctype.h>

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
	velocidad ** indice = NULL;
	int cant;
	char orden;

	cant = carga (&listado);

	if (( cant > 0 ) && (listado))
	{
		calculo (listado, &resultado, cant);

		if (resultado)
		{
			printf("En que orden lo quiere mostrar.\nCon 'N' muestra por nombre, cualquier otra letra por velocidad.\n---> ");
			scanf(" %c",&orden);

//			if( (orden == 'N') || (orden == 'n'))
			if( toupper(orden) == 'N')
			{
				indice = orden_n (resultado, cant);
			}
			else
			{
				indice = orden_v (resultado, cant);
			}

			if (indice)
			{
				impresion(indice, cant);
				free (indice);
			}
			else
			{
				printf("Problema en la generación del indice.\n");
			}
			free (resultado);
		}
		else
		{
			printf("Problema en el calculo de las velocidades.\n");
		}
		free (listado);
	}
	else
	{
		printf("No hay corredores para mostrar.\n");

	}
	return 0;

}

//------------------------------------------------------------------------

