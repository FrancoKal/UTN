/**
        \file    mainbase.c
        \brief   Archivo principal para la carga de tiempos de carrera (versión con memoria dinámica).
        \author  Hecho en clase
        \date    2020.08.10
        \version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include "funcbase.h"

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

	runner * listado = NULL;
	velocidad * resultado = NULL;
	int cant;

	cant = carga (&listado);

	calculo (listado, &resultado, cant);

	orden (resultado, cant);

	impresion(resultado, cant);

	return 0;

}

//------------------------------------------------------------------------

