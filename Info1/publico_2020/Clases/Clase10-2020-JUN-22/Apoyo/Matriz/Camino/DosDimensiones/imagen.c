/**
	\file imagen.c
	\brief función principal que muestra por pantalla la matriz binaria
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.17
	\version 1.1.0
*/

/**
	\fn int main (void);
	\brief función principal que muestra por pantalla la matriz binaria
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.17
	\return Devuelve un 0 si termina en forma exitosa
*/


#include "funciones.h"

int main (void)
{

	char imagen [MAX*MAX];
	int filas, colu;

	CargaDatos(imagen, &filas, &colu);

	printf ("\n\n");

	MostrarDatos(imagen, filas, colu);

	return  0;

}


