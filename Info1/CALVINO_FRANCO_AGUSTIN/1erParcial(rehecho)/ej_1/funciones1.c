/**
	\file    funciones1.c
	\brief   Funciones que utiliza el main1.c
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13 
	\version 1.1.0
*/


//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "funciones1.h"

/**
	\fn     int lugarcito (char *frase, char *separador, int **resultado)
	\brief  Cuenta la cantidad de lugares en la frase entre cada separador, y los ordena de menor a mayor
	\author Franco Calvino (francoc.2002@gmail.com)
	\date   2020.07.13
	\param  char *frase : Es la frase (array) pasada como argumento
	\param  char *separador : Es el conjunto de caracteres que sirven como separador
	\param	int **resultado : Vector de enteros donde se guardaran los lugares contados entre cada separador 
	\return EXITO en caso de que la funcion no haya tenido ningun problema. Caso contrario, retornara ERROR
*/

int generar_vector (char *frase, char *separador, int ***resultado);
void ordenar_vector (int cantidad, int ***resultado);

int lugarcito (char *frase, char *separador, int **resultado)
{
	int i, contador;
	char *mensaje_error[] = {"No hay memoria disponible", "Ingrese una frase o separador valido"};

	if ((strlen(frase) != 0) && (strlen(separador) != 0))
	{
		contador = generar_vector(frase, separador, &resultado);
		
		if (contador != SIN_MEMORIA)
		{
			ordenar_vector(contador, &resultado);
			printf("Ordenado: {");

			for (i = 0; i < contador; i++)
			{
				printf("%i ", (*resultado)[i]);
			}
		
			printf("}\n");
			contador = EXITO;
		}
	}
	else contador = ERROR;

	if (contador < 0) printf("%s\n", mensaje_error[-contador - 1]);

	return contador;
}

int generar_vector (char *frase, char *separador, int ***resultado)
{
	int i = 0, j, contador = 0, aux = 0;
	
	while ((frase[i] != '\0') && (contador != SIN_MEMORIA)) // Voy recorriendo la frase letra por letra
	{
		j = 0;

		while ((separador[j] != '\0') && (aux != 0) && (contador != SIN_MEMORIA)) // Para cada letra de la frase, la comparo con la del separador
		{
			if (frase[i] == separador[j]) /*Si son iguales, tomo la cantidad de lugares contados por 'aux' y la guardo en el resultado. Y despues reinicio 'aux' antes de seguir contando*/
			{
				**resultado = (contador == 0)? (int *) malloc (sizeof(int)) : (int *) realloc (**resultado, sizeof(int) * (contador + 1));
					
				if (**resultado != NULL)
				{
					(**resultado)[contador] = aux;
					aux = 0;
					printf("resultado[%i] = %i\n", contador, (**resultado)[contador]);
					contador++;
				}
				else contador = SIN_MEMORIA;
			}

			j++;
		}

		i++;
		aux++;
	}
	
	return contador;
}

void ordenar_vector (int cant, int ***resultado)
{
	int i = 0, aux = 0;
	
	while (aux != 1) //Aca ordeno todo
	{
			aux = 1;

			for (i = 0; i < cant - 1; i++)
			{
				if ((**resultado)[i] > (**resultado)[i+1])
				{
					aux = (**resultado)[i+1];
					(**resultado)[i+1] = (**resultado)[i];
					(**resultado)[i] = aux;
					aux = 0;
				}
			}
	}
}
