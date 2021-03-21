/**
	\file    mifrasem.c
	\brief   Archivo de prueba para utilizar puntero a función
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.07.06
	\version 2.0.0
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
	char modo = 0;
	char * resultado = NULL;

	void (* perrores[]) (void) = {NULL, errorarg, errormodo, errorfrase};
//(1)	void (* perrores[]) (void) = {errorarg, errormodo, errorfrase};

	char * (* convierto) (char *);


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
		if ((modo == 'u') || (modo == 'U'))
		{
			convierto = a_mayusc;
		}
		else if ((modo == 'l') || (modo == 'L'))
		{
			convierto = a_minusc;
		}
		else
		{
			mevoy = 2;
		}
	}

	if (mevoy == 0)
	{
		resultado = convierto (argumentos[conver]);
	}

	if ((resultado == NULL) && (mevoy == 0))
	{
		mevoy = 3;
	}

	if (mevoy == 0)
	{
		printf("El resultado de la conversión solicitada es: %s\n", resultado);
		free (resultado);
	}
	else
	{
		perrores[mevoy] ();
//(1)		perrores[mevoy-1] ();
	}

	printf ("\n");

	return mevoy;
}
