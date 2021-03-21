/**
	\file    main1.c
	\brief   Rutina principal main del programa
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include "funciones1.h"

/**
	\fn      int main (--------------------------)
	\brief   <Función de la función>
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13
	\param   <Parámetro A (si no tiene no se pone)>
	\param   <Parámetro B (si no tiene no se pone)>
	\return  <Lo que retorna>
*/

int main (void)
{
	char *frase = "Hola gente como andan", *separador = "ln" ;
	int **resultado;

	/*printf("Ingresame una frase: ");
	scanf("%s", frase);
	printf("Ahora ingresame una palabra separador");
	scanf("%s", separador);*/

	lugarcito(frase, separador, resultado);



	return 0;
}


