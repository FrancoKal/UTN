/**
        \file    mk-funciones.c
        \brief   Funciones para utilizar en el ejemplo de Makefile
        \author  Spataro, Hector (hspataro@frba.utn.edu.ar>
        \date    2020.06.30
        \version 1.1.0
*/

//--------------
//-- Includes --
//--------------

#include "mk-funciones.h"

/**
        \fn     void binario (char *s, int dato)
        \brief  Función para convertir un numero en un string binario.
        \author Spataro, Hector (hspataro@frba.utn.edu.ar>
        \date   2020.06.30
        \param  char * s: String donde se guardara el numero convertido.
        \param  int dato: Valor que se convertirá a binario.
*/


void binario (char *s, int dato)
{
	int i;

	for(i=TAM-1; i>=0; i--)
	{
		s[i] = dato%BASE+'0';
		dato/=BASE;			//dato=dato/BASE;
	}

	s[TAM]='\0';				//Agrego el '\0' para terminar el string

	return;
}




