/**
	\file    main3.c
	\brief   Rutina principal (main) del programa
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.10.26
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include "funciones3.h"


/**
	\fn      int main (---------)
	\brief   <Función de la función>
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.10.26
	\param   <Parámetro A (si no tiene no se pone)>
	\param   <Parámetro B (si no tiene no se pone)>
	\return  0 
*/

int main (void)
{
	int operacion, n;
	float resultado, (*oper[]) (int) = {raiz, cuadrado, modulo, signo};
	
	printf("Ingrese un numero: ");
	scanf("%i", &n);
	printf("¿Que operacion desea realizar?\n0. Raiz cuadrada\n1. Elevar al cuadrado\n2. Modulo\n3. Cambio de signo\n---> ");
	scanf("%i", &operacion);
	
	if (operacion >= 0 && operacion <= 3)
	{
		resultado = (*oper[operacion]) (n);
		
		printf("resultado = %0.2f\n", resultado);
	}
	else printf("Opcion mal elegida\n");

	return 0;
}

