/**
        \file    mainV4.c
        \brief   Archivo principal para la carga de tiempos de carrera (versión con memoria dinámica).
	\brief	 Ordena por dos criterios pero utilizando un vector de indices y ocupa el espacio justo para el nombre
	\brief	 Pidiendo memoria por estructura en lugar de usar un vector
        \author  Hecho en clase
        \date    2020.08.10
        \version 1.4.0
*/


//--------------
//-- Includes --
//--------------

#include "funcV4.h"
#include <ctype.h>
#include <stdlib.h>

/**
        \fn      main
        \brief   funcion principal
        \author  Hecho en clase
        \date    2020.08.10
        \return  0: si todo salió bien
                 1: si se produjo algún error
*/

int main (void)
{

	runner ** listado = NULL;
	velocidad ** resultado = NULL;
	velocidad ** indice = NULL;
	int cant;
	char orden;

	cant = carga (&listado);

	if ((listado != NULL) && (cant > 0))
	{
		calculo (listado, &resultado, cant);
		if (resultado != NULL)
		{

			printf("¿Como desea ver los resultados?\n Por nombre (N) o por velocidad (V) o como se cargo (cualquier otra tecla).\n --> ");
			scanf(" %c", &orden);

			if (toupper(orden) == 'N')
			{
				indice = orden_n (resultado, cant);
			}
			else if (toupper(orden) == 'V')
			{
				indice = orden_v (resultado, cant);
			}
			else
			{
				indice = resultado;
			}

			if (indice != NULL)
			{
				impresion(indice, cant);
				if (indice != resultado) 
				{
					free (indice);
				}
			}
			limpiar_v (&resultado, cant);
		}
		else
		{
			printf("Hubo problemas en el calculo, me voy a torrar.\n");
		}
		limpiar_r (&listado, cant);
	}
	else
	{
		printf("Hubo problemas en la carga, me voy a torrar.\n");
	}


	return 0;

}

//------------------------------------------------------------------------








