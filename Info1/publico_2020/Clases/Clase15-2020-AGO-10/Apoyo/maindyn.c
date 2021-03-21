/**
	\file    maindyn.c
	\brief   Archivo principal para la carga de tiempos de carrera (versión con memoria dinámica).
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.08.10
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include "funcdyn.h"

/**
	\fn      main
	\brief   funcion principal
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.08.10
	\return  0: si todo salió bien
		 1: si se produjo algún error
*/


int main (void)
{

	corredor * listado;
	velocidad * performance;
	int cant;
	int error = NO;

	cant = carga (&listado);
	if (cant)
	{
		if (listado)
		{
			calculo (listado, &performance, cant);
			if (performance)
			{
				ordeno (performance, cant);
				muestro (performance, cant);
			}
			else
			{
				printf("Error en la generación de los resultados.\n");
				error = SI;
			}
		}
		else
		{
			printf("Error en la generación de los datos.\n");
			error = SI;
		}
	}
	else
	{
		printf("No se cargaron datos\n");
		error = SI;
	}

	if (listado) free(listado);
	if (performance) free(performance);

	return error;
}

