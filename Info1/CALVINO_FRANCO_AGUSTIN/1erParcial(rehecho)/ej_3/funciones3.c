/**
	\file    funciones3.c
	\brief   Funciones que utiliza el main3.c
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13 
	\version 1.1.0
*/


//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones3.h"

/**
	\fn     int raices (int *v1, int *v2)
	\brief  Crea un vector con las raices del vector de enteros pasado como argumento
	\author Franco Calvino (francoc.2002@gmail.com)
	\date   2020.07.13
	\param  int *v1 : Es el vector de enteros pasados como argumento 1
	\param  int *v2 : Es el vector de enteros creado a partir de las raices del primero
	\return EXITO si todo salio bien. FINALIZO si no hay memoria disponible o si alguno de los enteros del v1 es 0. ERROR_DATOS si alguno de los enteros del v1 es negativo
*/

int raices (int *v1, unsigned int **v2)
{
	int i, contador = 0;
	char *error[] = {"No hay memoria dispoinible", "0 encontrado", "Numero negativo encontrado"};
	
	/*Aca tuve que definir LARGO_MAX, que es el la cantidad de elementos del vector 1, para saber donde frenar la funcion y que no pise posiciones de memoria*/ 
	  
	for (i = 0; /*(i != ERROR_DATOS) && (i != FINALIZO) && (i != SIN_MEMORIA)*/(i >= 0) && (i < LARGO_MAX); i++) // Puedo poner (i >= 0) en lugar de las otras condiciones ya que los valores de 																error son todos negativos 		
	{
		if ((v1[i] > 0) && (v1[i] / sqrt(v1[i]) == sqrt(v1[i])))
		{
			*v2 = (contador == 0)? (unsigned int *) malloc (sizeof(int)) : (unsigned int *) realloc (*v2, sizeof(int) * (contador + 1));

			if (*v2 != NULL)
			{
				(*v2)[contador] = sqrt(v1[i]);
				printf("v2[%i] = %i\n", contador, (*v2)[contador]);
				contador++;
			}
			else i = SIN_MEMORIA;

		}
		else if (v1[i] == 0)
		{
			//v2 = NULL;
			free(*v2);
			*v2 = NULL; // Retorno NULL y finalizo
			i = FINALIZO;
		}
		else if (v1[i] < 0) i = ERROR_DATOS;
	}

	if (i < 0) printf("Error. %s\n", error[-i]); // Lo escribo como -i ya que las constantes simbolicas son negativas, y las necesito positivas
	
	return contador;
}
