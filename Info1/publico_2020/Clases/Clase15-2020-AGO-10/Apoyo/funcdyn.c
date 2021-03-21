/**
	\file    fundyn.c
	\brief   Archivo de funciones para utilizar con memoria dinámica
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.08.10
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include "funcdyn.h"

//-------------------------------------------------------------------------------------------------------------

/**
	\fn     carga
	\brief  Realiza la carga de los datos del entrenamiento
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.08.10
	\param  listado: dirección de la dirección de memoria del listado a generar y rellenar
	\return void
*/

int carga (corredor ** listado)
{
	int cant = 0;
	int id_aux;
	int error = NO;
	corredor * aux;

	do
	{
		printf("Ingrese el ID del corredor: ");
		scanf("%d", &id_aux);
		if (id_aux>0)
		{
			if (cant == 0)
			{
				*listado = malloc (sizeof (corredor));
				if (!(*listado)) error = SI;
			}
			else
			{
				aux = realloc (*listado, (1+cant)*sizeof (corredor));
				if (!aux) error = SI;
				else *listado = aux;
			}

			if (!error)
			{
				((*listado)+cant)->ID = id_aux;
				printf("Ingrese el tiempo empleado (minutos): ");
				scanf("%d", &((*listado)+cant)->tiempo);
				printf("Ingrese la distancia recorrida (kmts): ");
				scanf("%f", &((*listado)+cant)->dist);
				cant++;
			}
		}
	}
	while ((id_aux>0) && !error);

	return cant;
}

//-------------------------------------------------------------------------------------------------------------

/**
	\fn     calculo
	\brief  Realiza la generación y carga del listado los datos de la performance de cada corredor
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.08.10
	\param  listado: dirección de memoria con los datos de los corredores
	\param  performance: dirección de la dirección de memoria del listado a generar y rellenar
	\return void
*/

void calculo (corredor * listado, velocidad ** performance, int cant)
{
	int i;

	*performance = malloc(cant*sizeof(velocidad));

	if (*performance)
	{
		for (i=0; i<cant; i++)
		{
			((*performance)+i)->ID = (listado+i)->ID;
			((*performance)+i)->veloc = (listado+i)->dist/((listado+i)->tiempo/60.0);
		}
	}

	return;
}

//-------------------------------------------------------------------------------------------------------------

/**
	\fn     ordeno
	\brief  Realiza el ordenamiento de las velocidades de los corredores de menor a mayor
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.08.10
	\param  performance: dirección de memoria del conjunto de datos a ordenar
	\return void
*/

void ordeno (velocidad * performance, int cant)
{
	int i, j=0;
	int bandera;
	velocidad aux;

	do
	{
		bandera = 0;
		for (i=0; i<cant-1-j; i++)
		{
			if ((performance+i)->veloc > (performance+i+1)->veloc)
			{
				aux = *(performance+i);
				*(performance+i) = *(performance+i+1);
				*(performance+i+1) = aux;
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
	\param  performance: dirección de memoria del conjunto de datos a imprimir
	\return void
*/

void muestro (velocidad * performance, int cant)
{
	int i;

	printf("\nResultado de la carga:\n");

	for (i=0; i<cant; i++)
	{
		printf("ID Corredor: %d\t Velocidad: %.2f kmts/h\n", (performance+i)->ID, (performance+i)->veloc);
	}

	return;
}

//-------------------------------------------------------------------------------------------------------------
