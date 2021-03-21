/**
        \file    funcV2.c
        \brief   Archivo de funciones para utilizar con memoria dinámica
        \author  Hecho en clase
        \date    2020.08.24
        \version 1.2.0
*/


//--------------
//-- Includes --
//--------------

#include "funcV2.h"
#include <string.h>

/**
        \fn     carga
        \brief  Realiza la carga de los datos del entrenamiento en el vector
        \author  Hecho en clase
        \date    2020.08.24
        \param  listado: dirección de la dirección de memoria del listado a generar y rellenar
        \return void
*/

int carga (runner ** listado)
{
	int cant = 0;
	int id_aux;
	runner * listaux = NULL;
	char buffer;

	printf("Ingrese el id del corredor: ");
	scanf("%d", &id_aux);

	if (id_aux > 0)
	{
		listaux = (runner *) malloc (sizeof (runner));
	}

	while ((id_aux > 0) && (listaux))
	{
		if (cant != 0)
		{
			listaux = (runner *) realloc (*listado, sizeof (runner)*(cant+1));
		}

		if (listaux)
		{
			*listado = listaux;

			(listaux+cant)->id = id_aux;

			scanf("%c", &buffer);

			printf("Ingrese nombre del corredor: ");
//			scanf("%s", (listaux+cant)->nombre);
			fgets((listaux+cant)->nombre, LARGO_N, stdin);

			printf("Ingrese el tiempo utilizado (min): ");
			scanf("%d", &(listaux+cant)->tiempo);
			printf("Ingrese la distancia recorrida (kmts): ");
			scanf("%f", &(listaux+cant)->distancia);

			cant++;

			printf("Ingrese el id del corredor: ");
			scanf("%d", &id_aux);

		}

	}

	return cant;
}
//------------------------------------------------------------------------


/**
        \fn     calculo
        \brief  Realiza la generación y carga del listado los datos de la performance de cada corredor
        \author  Hecho en clase
        \date    2020.08.10
        \param  listado: dirección de memoria con los datos de los corredores
        \param  resu: dirección de la dirección de memoria del listado a generar y rellenar
        \param  cant: cantidad de corredores a procesar
        \return void
*/

void calculo (runner * listado, velocidad ** resultado, int cant)
{

	int i;

	*resultado = (velocidad *) malloc (sizeof (velocidad)*cant);

	if (resultado)
	{
		for (i = 0; i < cant; i++)
		{
			((*resultado)+i)->id = (listado+i)->id;
//			velocidad = distancia/(tiempo/60);
			((*resultado)+i)->veloc = (listado+i)->distancia/((listado+i)->tiempo/60.0);
			strcpy (((*resultado)+i)->nombre, (listado+i)->nombre);
		}
	}

	return;
}
//------------------------------------------------------------------------

/**
        \fn     orden_v
        \brief  Realiza el ordenamiento de las velocidades de los corredores de menor a mayor
        \param  resultado: dirección de memoria del conjunto de datos a ordenar
        \param  cant: cantidad de corredores a procesar
        \return puntero al indice ordenado.
*/

velocidad ** orden_v (velocidad * resultado, int cant)
{

	int i = 0, j = 0, bandera = 1;
	velocidad aux;
	velocidad ** indice = NULL;

	indice = (velocidad **) malloc (sizeof(velocidad *) * cant);

	if (indice)
	{
		for ( i = 0; i < cant; i++)
		{
			*(indice+i) = (resultado+i);
		}

		while (bandera)
		{
			bandera = 0;

			for (i = 0; i < cant-1-j; i++)
			{
				if ((*(indice+i))->veloc > (*(indice+i+1))->veloc)
				{
					aux = *(*(indice+i));
					*(*(indice+i)) = *(*(indice+i+1));
					*(*(indice+i+1)) = aux;
					bandera = 1;
				}

			}
			j++;
		}
	}
	return indice;
}
//------------------------------------------------------------------------
/**
        \fn     orden_n
        \brief  Realiza el ordenamiento de las velocidades de los corredores de menor a mayor
        \param  resultado: dirección de memoria del conjunto de datos a ordenar
        \param  cant: cantidad de corredores a procesar
        \return puntero al indice ordenado.
*/

velocidad ** orden_n (velocidad * resultado, int cant)
{

	int i = 0, j = 0, bandera = 1;
	velocidad aux;
	velocidad ** indice = NULL;

	indice = (velocidad **) malloc (sizeof(velocidad *) * cant);

	if (indice)
	{
		for ( i = 0; i < cant; i++)
		{
			*(indice+i) = (resultado+i);
		}

		while (bandera)
		{

			bandera = 0;

			for (i = 0; i < cant-1-j; i++)
			{
				if (strcmp ((*(indice+i))->nombre, (*(indice+i+1))->nombre) > 0)
				{
					aux = *(*(indice+i));
					*(*(indice+i)) = *(*(indice+i+1));
					*(*(indice+i+1)) = aux;
					bandera = 1;
				}

			}
			j++;
		}
	}

	return indice;
}
//------------------------------------------------------------------------


/**
        \fn     impresion
        \brief  Realiza la impresion de las velocidades de los corredores
        \author  Hecho en clase
        \date    2020.08.10
        \param  resu: dirección de memoria del conjunto de datos a ordenar
        \param  cant: cantidad de corredores a procesar
        \return void
*/

void impresion(velocidad ** resultado, int cant)
{
	int i;

	printf("El resultado de las pruebas fue:\n\n");

	for(i=0; i < cant; i++)
	{
		printf("El corredor %d - %s tuvo una velocidad de %f\n",(*resultado[i]).id, (*resultado[i]).nombre, (*resultado[i]).veloc);
	}

	printf("Cantidad de corredores procesados: %d\n\n", cant);

	return;
}

//------------------------------------------------------------------------



