/**
        \file    mk-main.c
        \brief   Programa para utilizar la función que recibe un string y un valor entero y que vuelque en el string 
	\brief	 la representación binaria del entero. Completa siempre la representación en 32 bits.
        \brief   Ejercicio para practicar el uso de Makefile
        \author  Spataro, Hector (hspataro@frba.utn.edu.ar>
        \date    2020.06.30
        \version 1.1.0
*/


//--------------
//-- Includes --
//--------------

#include "mk-funciones.h"

/**
        \fn      int main (void)
        \brief   Función main probar la función binario en un ejemplo de Makefile
        \author  Spataro, Hector (hspataro@frba.utn.edu.ar>
        \date    2020.06.30
        \return  retorna 0 si todo salió bien.
*/

int main (void)
{
	char enbinario[TAM+1];		//Tamaño del numero binario mas un lugar para el '\0'
	int  valor;

	printf("Ingresa un valor:");
	scanf("%d", &valor);

	binario(enbinario, valor);

	printf("El número %d es %s.\n", valor, enbinario);

	return 0;
}

//----------------------------------------------------------------------------------

