/**
        \file    funcV3.c
        \brief   Archivo de funciones para utilizar con memoria dinámica
        \author  Hecho en clase
        \date    2020.08.24
        \version 1.3.0
*/


//--------------
//-- Includes --
//--------------

#include "funcV3.h"
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
	char aux_nombre [LARGO_N];
	int largo_nombre = 1;

	printf("Ingrese el id del corredor: ");
	scanf("%d", &id_aux);

	if (id_aux > 0)
	{
		listaux = (runner *) malloc (sizeof (runner));
	}

	while ((id_aux > 0) && (listaux) && (largo_nombre))
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
			fgets(aux_nombre, LARGO_N, stdin);

			largo_nombre = (int) strlen(aux_nombre);
			largo_nombre--; //descuento una posición para borrar el '\n'
			aux_nombre[largo_nombre] = '\0';

			(listaux+cant)->nombre = (char *) malloc ((largo_nombre+1)*sizeof(char));

			if ((listaux+cant)->nombre)
			{
				strcpy((listaux+cant)->nombre, aux_nombre);

				printf("Ingrese el tiempo utilizado (min): ");
				scanf("%d", &(listaux+cant)->tiempo);
				printf("Ingrese la distancia recorrida (kmts): ");
				scanf("%f", &(listaux+cant)->distancia);

				cant++;

				printf("Ingrese el id del corredor: ");
				scanf("%d", &id_aux);
			}
			else
			{
				largo_nombre = 0;
			}
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

	int i = 0;
	int largo_nombre = 1;

	*resultado = (velocidad *) malloc (sizeof (velocidad)*cant);

	if (*resultado)
	{
		while ((i < cant) && (largo_nombre))
		{
			((*resultado)+i)->id = (listado+i)->id;
//			velocidad = distancia/(tiempo/60);
			((*resultado)+i)->veloc = (listado+i)->distancia/((listado+i)->tiempo/60.0);

			largo_nombre = (int) strlen((listado+i)->nombre);
			((*resultado)+i)->nombre = (char *) malloc ((largo_nombre+1)*sizeof(char));
			if (((*resultado)+i)->nombre)
			{
				strcpy (((*resultado)+i)->nombre, (listado+i)->nombre);
			}
			else
			{
				largo_nombre = 0;
			}
			i++;
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
        \param  resultado: dirección de memoria del conjunto de datos a ordenar
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

/**
        \fn     limpiar_v
        \brief  Realiza la liberación de memoria del vector de velocidad
        \author  Hecho en clase
        \date    2020.08.10
        \param  resultado: dirección de memoria del conjunto de datos a liberar
        \param  cant: cantidad de corredores a procesar
        \return void
*/

void limpiar_v (velocidad ** resultado, int cant)
{
	int i;

	printf("Liberando memoria del vector de velocidad.\n\n");

	for(i=0; i < cant; i++)
	{
		free ((*resultado)[i].nombre);
//		free (((*resultado)+i)->nombre);

	}

	free(*resultado);

	return;
}

//------------------------------------------------------------------------

/**
        \fn     limpiar_r
        \brief  Realiza la liberación de memoria del vector de corredores
        \author  Hecho en clase
        \date    2020.08.10
        \param  listado: dirección de memoria del conjunto de datos a liberar
        \param  cant: cantidad de corredores a procesar
        \return void
*/

void limpiar_r (runner ** listado, int cant)
{
	int i;

	printf("Liberando memoria del vector de corredor.\n\n");

	for(i=0; i < cant; i++)
	{
		free ((*listado)[i].nombre);
	}

	free(*listado);

	return;
}

//------------------------------------------------------------------------



