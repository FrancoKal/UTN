/**
	\file    mifrasesf.c
	\brief   Funciones a utilizar para el programa mifrases
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar
	\date    2020.07.06 
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include "mifrasesf.h"


//----------------------------------------------------------------------------------------------

/**
	\fn     void errorarg (void)
	\brief  Muestra el mensje de error cuando se pasaron mal los argumentos.
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar
	\date    2020.07.06 
*/

void errorarg (void)
{
	printf("Ha utilizado mal la función!!!!!!  No sea vago, lea el manual.\n");
	return;
}

//----------------------------------------------------------------------------------------------

/**
	\fn      void errormodo (void)
	\brief   Muestra el mensje de error cuando se pasó una opción invalida.
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar
	\date    2020.07.06 
*/

void errormodo (void)
{
	printf("Tiraste fruta con el tipo de conversión!!!!!!  No sea vago, lea el manual.\n");
	return;
}

//----------------------------------------------------------------------------------------------

/**
	\fn      void errorfrase (void)
	\brief   Muestra el mensje de error cuando no hay memoria disponible.
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar
	\date    2020.07.06 
*/

void errorfrase (void)
{
	printf("Esta vez es culpa del programa!!!!!!  Me voy a leer el manual.\n");
	return;
}

//----------------------------------------------------------------------------------------------

/**
	\fn      char * a_mayusc (char * frase)
	\brief   A partir de una frase recibida, genera una frase nueva con todas las letras minusculas convertidas a mayusculas
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar
	\date    2020.07.06 
	\param   char * frase : Es la frase que se va a pasar a mayuscula
	\return  char * : Frase en mayusucula
*/

char * a_mayusc (char * frase)
{

	int largo = 0;
	int i;
	char * resultado = NULL;

	largo = longitud (frase);

	resultado = (char *) malloc ((sizeof(char)*largo)+1);
	if (resultado != NULL)
	{
		for (i = 0; i < largo; i++)
		{
			if ((*(frase+i) >= 'a') && (*(frase+i) <= 'z'))
			{
				*(resultado+i) = *(frase+i) - 'a' + 'A';
			}
			else
			{
				*(resultado+i) = *(frase+i);
			}
		}

		*(resultado+i) = '\0';
	}

	return resultado;
}

//----------------------------------------------------------------------------------------------

/**
	\fn      char * a_minusc (char * frase)
	\brief   A partir de una frase recibida, genera una frase nueva con todas las letras mayusculas convertidas a minusculas
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar
	\date    2020.07.06 
	\param   char * frase : Es la frase que se va a pasar a minuscula
	\return  char * : Frase en minuscula
*/

char * a_minusc (char * frase)
{
	int largo = 0;
	int i;
	char * resultado = NULL;

	largo = longitud (frase);

	resultado = (char *) malloc ((sizeof(char)*largo)+1); //Agrego uno para guardar el '\0'
	if (resultado != NULL)
	{
		for (i = 0; i < largo; i++)
		{
			if ((*(frase+i) >= 'A') && (*(frase+i) <= 'Z'))
			{
				*(resultado+i) = *(frase+i) - 'A' + 'a';
			}
			else
			{
				*(resultado+i) = *(frase+i);
			}
		}

		*(resultado+i) = '\0';
	}

	return resultado;
}

//----------------------------------------------------------------------------------------------

/**
	\fn      int longitud (char * frase)
	\brief   Devuelve la longitud de una frase recibida
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar
	\date    2020.07.06 
	\param   char * frase : Es la frase para averiguar su longitud
	\return  int : longitud de la frase recibida
*/

int longitud (char * frase)
{

	int largo = 0;

	while (*(frase+largo) != '\0')
	{
		largo++;
	}

	return largo;
}

//----------------------------------------------------------------------------------------------
