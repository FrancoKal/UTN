/**
	\file    mifrasem.c
	\brief   Archivo de prueba previo a utilizar puntero a función
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.07.06
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include "mifrasesf.h"


/**
	\fn      int main (int cuantos, char * argumentos[])
	\brief   Función main que recibe una frase por linea de comando y la pasa a mayuscula o minuscula según parámetro
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.07.06
	\param   int cuantos : cantidad de parámetros recibidos por linea de comando
	\param   char * argumentos [] : Listado de argumentos recibidos por línea de comando.
	\return  int : Código con el resultado del funcionamiento de main.
*/

int main (int cuantos, char * argumentos[])
{

	int mevoy = 0;
	int conver = 0;
	char modo;
	char * resultado = NULL;

	printf("\n");


	if (cuantos != 3)
	{
		mevoy = 1;
	}

	else if ((argumentos[1][0] != '-') && (argumentos[2][0] != '-'))
	{
		mevoy = 1;
	}

	else if (argumentos [2] [0] == '-')
	{
		conver = 1;
		modo = argumentos [2] [1];
	}

	else
	{
		conver = 2;
		modo = argumentos [1] [1];
	}

	if (mevoy == 0)
	{
		switch (modo)
		{
			case 'u':
			case 'U':
				resultado = a_mayusc (argumentos[conver]);
				break;

			case 'l':
			case 'L':
				resultado = a_minusc (argumentos[conver]);
				break;

			default:
				mevoy = 2;
		}

		if ((resultado == NULL) && (mevoy == 0))
		{
			mevoy = 3;
		}

	}

	if (mevoy == 0)
	{
		printf("El resultado de la conversión solicitada es: %s\n", resultado);
		free (resultado);
	}
	else
	{
		switch (mevoy)
		{
			case 1:
				errorarg();
				break;
			case 2:
				errormodo();
				break;
			case 3:
				errorfrase();
				break;
		}
	}

	printf ("\n");

	return mevoy;
}
