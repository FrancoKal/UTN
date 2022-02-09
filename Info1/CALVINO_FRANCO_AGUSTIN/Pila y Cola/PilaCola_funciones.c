#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

/**
	\fn      void mostrar (int * vec, int cant)
	\brief   Muestra el listado de los valores cargados.
	\author  Hecho en clase
	\date    2020.09.11
	\param   vec: dirección del vector donde se encuentran los datos
	\param   cant: cantidad de datos que se encuentran en el vector
*/

void mostrar (int * vec, int cant)
{
	int i;

	printf("Estado del vector:\n");
	for (i = 0; i < cant; i++)
	{
		printf("\tVec[%i]: %i\n", i, *(vec+i));
	}
}

/**
	\fn      int encolar (int ** vec, int * cant, int dato)
	\brief   Agrega el dato recibido al vector. Lo hace como COLA
	\author  Hecho en clase
	\date    2020.09.11
	\param   vec: dirección del vector donde se encuentran los datos
	\param   cant: cantidad de datos que se encuentran en el vector
	\param   dato: dato a agregar en el vector
	\return  OK si se agregó
		 ERROR si no se agregó
*/

int encolar (int ** vec, int * cant, int dato)
{
	int estado = OK;
	
	*vec = (*cant == 0)? (int *) malloc (sizeof(int)) : (int *) realloc (*vec, sizeof(int) * (*cant + 1));
	
	if (*vec != NULL)
	{
		(*vec)[*cant] = dato;
		(*cant)++;
	}
	else estado = ERROR;
	
	return estado;
}

/**
	\fn      int apilar (int ** vec, int * cant, int dato)
	\brief   Agrega el dato recibido al vector. Lo hace como PILA
	\author  Hecho en clase
	\date    2020.09.11
	\param   vec: dirección del vector donde se encuentran los datos
	\param   cant: cantidad de datos que se encuentran en el vector
	\param   dato: dato a agregar en el vector
	\return  OK si se agregó
		 ERROR si no se agregó
*/

int apilar (int ** vec, int * cant, int dato)
{
	int aux = ERROR;
	
	*vec = (*cant == 0)? (int *) malloc (sizeof(int)) : (int *) realloc (*vec, sizeof(int) * (*cant + 1));
	
	if (*vec != NULL)
	{
		for (aux = *cant; aux != 0; aux--)
		{
			(*vec)[aux] = (*vec)[aux - 1]; // Primero tengo que desplazar cada numero 1 posicion mas adelante para dejar lugar para guardar el 0
		}
		
		(*vec)[0] = dato;
		aux = OK;
		(*cant)++;
	}
	
	return aux;
}

/**
	\fn      int quitarB (int ** vec, int * cant, int * dato)
	\brief   Quita el ultimo dato del vector y devuelve el dato que sacó en la variable dato
	\author  Hecho en clase
	\date    2020.09.11
	\param   vec: dirección del vector donde se encuentran los datos
	\param   cant: cantidad de datos que se encuentran en el vector
	\param   dato: dato a agregar en el vector
	\return  OK si se agregó
		 ERROR si no se agregó
*/

int quitarB (int ** vec, int * cant, int * dato)
{
	int estado = OK;
	
	*dato = (*vec)[*cant - 1];
	
	if (*cant == 1)
	{
		free(*vec);
		(*cant)--;
	}
	else
	{
		*vec = (int *) realloc (*vec, sizeof(int) * (*cant - 1));
		(*vec == NULL)? estado = ERROR : (*cant)--;
	}
	
	/*if (*cant > 0)
	{
		*dato = (*vec)[*cant - 1];
		*vec = (int *) realloc (*vec, sizeof(int) * (*cant - 1));
		(*vec == NULL)? estado = ERROR : (*cant)--;
	}*/
		
	return estado;
}

/**
	\fn      int quitarA (int ** vec, int * cant, int * dato)
	\brief   Quita el primer dato del vector y devuelve el dato que sacó en la variable dato
	\author  Hecho en clase
	\date    2020.09.11
	\param   vec: dirección del vector donde se encuentran los datos
	\param   cant: cantidad de datos que se encuentran en el vector
	\param   dato: dato a agregar en el vector
	\return  OK si se agregó
		 ERROR si no se agregó
*/

int quitarA (int ** vec, int * cant, int * dato)
{
	int aux = ERROR;
	
	*dato = (*vec)[0];
	
	if (*cant == 1)
	{
		free(*vec);
		(*cant)--;
	}
	else
	{
		for (aux = 0; aux < *cant; aux++)
		{
			(*vec)[aux] = (*vec)[aux + 1]; //Desplazo todos los numeros 1 posicion menos, pisando el elemento 0
		}
		
		*vec = (int *) realloc (*vec, sizeof(int) * (*cant - 1));
		
		if (*vec == NULL) aux = ERROR;
		else
		{
			aux = OK;
			(*cant)--;
		}	
	}
	
	/*if (*cant > 0)
	{
		*vec = (int *) realloc (*vec, sizeof(int) * (*cant - 1));
		
		if ((*cant) != 1 && (*vec) != NULL)
		{
			for (aux = 0; aux < *cant; aux++)
			{
				(*vec)[aux] = (*vec)[aux + 1]; //Desplazo todos los numeros 1 posicion menos, pisando el elemento 0
			}
			
			aux = OK;
			//(*cant)--;
		}
		
		(*cant)--;
	}*/
	
	return aux;
}

