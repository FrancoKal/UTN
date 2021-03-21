/**
	\file    funcionesord.c
	\brief   Funciones de ordenamiento
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar
	\date    2020.07.06 
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include "funcionesord.h"

//----------------------------------------------------------------------------------------------

/**
	\fn      void imprimir (int * V, int largo)
	\brief   Saca por pantalla el vector de enteros
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar
	\date    2020.07.06 
	\param   int * V : Vecor de enteros a imprimir
	\param   int largo : Longitud del vector de enteros
*/

void imprimir (int * V, int largo)
{
	int i;

	printf("-------------------------------------------------------\n");

	for (i=0; i< largo; i++)
	{
		printf("| %d ", V[i]);
	}

	printf("|\n");
	printf("-------------------------------------------------------\n");

	return;
}

//----------------------------------------------------------------------------------------------

/**
	\fn      void seleccion (int * V, int largo)
	\brief   Ordena el vector de enteros utilizando el metodo de selección
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar
	\date    2020.07.06 
	\param   int * V : Vecor de enteros a imprimir
	\param   int largo : Longitud del vector de enteros
*/

void seleccion (int * V, int largo)
{
	int aux;
	int j;
	int i;

	for (j=0; j<largo-1; j++)
	{
		for (i=j+1; i<largo ; i++)
		{
			if (V[j] > V[i]) 
			{
				aux = V[j];
				V[j] = V[i];
				V[i] = aux;
			}

		}
	}

	return;
}

//----------------------------------------------------------------------------------------------

/**
	\fn      void burbuja (int * V, int largo)
	\brief   Ordena el vector de enteros utilizando el metodo de burbuja
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar
	\date    2020.07.06 
	\param   int * V : Vecor de enteros a imprimir
	\param   int largo : Longitud del vector de enteros
*/

void burbuja (int * V, int largo)
{

	int j;
	int i;
	int aux;

	for (j=0; j<largo-1 ; j++)
	{
		for (i=0; i<largo-1-j ; i++)
		{
			if (V[i] > V[i+1])
			{
				aux = V[i+1];
				V[i+1] = V[i];
				V[i] = aux;
			}
		}
	}

	return;
}

//----------------------------------------------------------------------------------------------

/**
	\fn      void burbuja_mas (int * V, int largo)
	\brief   Ordena el vector de enteros utilizando el metodo de burbuja y detectando cuando está ordenado
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar
	\date    2020.07.06 
	\param   int * V : Vecor de enteros a imprimir
	\param   int largo : Longitud del vector de enteros
*/

void burbuja_mas (int * V, int largo)
{
	int aux;
	int flag;
	int j;
	int i;

	j=0;
	flag = 1;

	while (flag == 1)
	{
		j++;
		flag = 0;

		for (i=0; i<largo-j ; i++)
		{
			if (V[i] > V[i+1]) 
			{
				aux = V[i+1];
				V[i+1] = V[i];
				V[i] = aux;
				flag = 1;
			}
		}
	}

	return;
}

//----------------------------------------------------------------------------------------------
