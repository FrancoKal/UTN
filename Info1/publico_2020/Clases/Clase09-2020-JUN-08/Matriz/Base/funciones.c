
/**
	\file funciones.c
	\brief función para convertir un número en binario (pero sobre base 10)
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.27 
	\version 1.0.0 
*/ 

/**
	\fn lon long aBinario (int decimal);
	\brief Convierte un decimal en binario (sobre base 10)
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.27
	\param Parámetro A número decimal a convertir
	\return Devuelve el numero convertido
*/


#include "funciones.h"

long long aBinario (int decimal)
{

	long long binario = 0;
	int resto, peso = 1;
//	int exp=0;

	while (decimal >= base)
	{
		resto = decimal % base;
		decimal = decimal / base;
		binario = binario + resto * peso;
		peso = peso * based;

/*		peso = pow ( 10, exp);
		exp++;
*/
	}

	binario = binario + decimal * peso;

	return binario;
}

