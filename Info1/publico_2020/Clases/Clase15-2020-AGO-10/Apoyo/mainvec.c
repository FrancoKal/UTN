/**
	\file    maindyn.c
	\brief   Archivo principal para la carga de tiempos de carrera (versión con vectores).
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.08.10
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include "funcvec.h"

//-------------------------------------------------------------------------------------------------------------

/**
	\fn      main
	\brief   funcion principal
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.08.10
	\return  0: si todo salió bien
*/

int main (void)
{
	corredor listado[CANT];
	velocidad performance[CANT];

	carga (listado);
	calculo (listado, performance);
	ordeno (performance);

	muestro (performance);

	return 0;
}

//-------------------------------------------------------------------------------------------------------------
