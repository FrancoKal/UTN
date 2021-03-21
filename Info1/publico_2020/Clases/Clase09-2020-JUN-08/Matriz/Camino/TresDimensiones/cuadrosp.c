/**
	\file cuadros.c
	\brief función principal que muestra por pantalla la matriz binaria
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.17
	\version 1.2.0
*/

/**
	\fn int main (void);
	\brief función principal que muestra por pantalla la matriz binaria
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.17
	\return Devuelve un 0 si termina en forma exitosa
*/



#include "funciones.h"
#include <stdlib.h>


int main (void)
{


//	char imagen [CUADROS*MAX*MAX];
	char * imagen=NULL;

	int filas, colu;

	imagen = malloc(sizeof(char)*CUADROS*MAX*MAX);

	CargaDatos (imagen, &filas, &colu);

	MostrarDatos(imagen, filas, colu);

	free (imagen);

	return  0;

}
