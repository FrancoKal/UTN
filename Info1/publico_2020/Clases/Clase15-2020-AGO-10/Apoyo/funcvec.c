/**
	\file    funvec.c
	\brief   Archivo de funciones para utilizar con vectores
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.08.10
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include "funcvec.h"

//-------------------------------------------------------------------------------------------------------------

/**
	\fn     carga
	\brief  Realiza la carga del vector con los datos del entrenamiento
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.08.10
	\param  listado: dirección de memoria del vector a rellenar
	\return void
*/

void carga (corredor * listado)
{
	int i;

	for (i=0; i<CANT; i++)
	{
		printf("Ingrese el ID del corredor: ");
		scanf("%d", &listado[i].ID);
		printf("Ingrese el tiempo empleado (minutos): ");
		scanf("%d", &listado[i].tiempo);
		printf("Ingrese la distancia recorrida (kmts): ");
		scanf("%f", &listado[i].dist);
	}
	return;
}

//-------------------------------------------------------------------------------------------------------------

/**
	\fn     calculo
	\brief  Realiza la carga del vector con los datos de la performance de cada corredor
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.08.10
	\param  listado: dirección de memoria del vector con los datos de los corredores
	\param  performance: dirección de memoria del vector a rellenar
	\return void
*/

void calculo (corredor * listado, velocidad * performance)
{
	int i;

	for (i=0; i<CANT; i++)
	{
		performance[i].ID = listado[i].ID;
		performance[i].veloc = listado[i].dist/(listado[i].tiempo/60.0);
	}

	return;
}

//-------------------------------------------------------------------------------------------------------------

/**
	\fn     ordeno
	\brief  Realiza el ordenamiento de las velocidades de los corredores de menor a mayor
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.08.10
	\param  performance: dirección de memoria del vector a ordenar
	\return void
*/

void ordeno (velocidad * performance)
{
	int i, j=0;
	int bandera;
	velocidad aux;


	do
	{
		bandera = 0;
		for (i=0; i<CANT-1-j; i++)
		{
			if (performance[i].veloc > performance[i+1].veloc)
			{
				aux = performance[i];
				performance[i] = performance[i+1];
				performance[i+1] = aux;
				bandera = 1;
			}

		}
		j++;

	}
	while (bandera);

	return;
}

//-------------------------------------------------------------------------------------------------------------

/**
	\fn     muestro
	\brief  Realiza la impresion de las velocidades de los corredores
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.08.10
	\param  performance: dirección de memoria del vector a imprimir
	\return void
*/

void muestro (velocidad * performance)
{
	int i;

	printf("\nResultado de la carga:\n");

	for (i=0; i<CANT; i++)
	{
		printf("ID Corredor: %d\t Velocidad: %.2f kmts/h\n", performance[i].ID, performance[i].veloc);
	}

	return;
}

//-------------------------------------------------------------------------------------------------------------

