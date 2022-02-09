#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int may_a_men (lista *vec, lista **ordenado);
int divisor (lista *vec, lista **ordenado);
//lista * par_e_impar (lista *aux, int opcion);
//lista * por_param (lista *aux, int opcion);


lista * leer_numeros (FILE *archivo)
{
	lista *vec = NULL;
	int buffer;

	vec = (lista *) malloc (sizeof(lista));

	if (vec != NULL)
	{
		vec->cant = 0;
		
		do
		{
			fscanf(archivo, "%i", &buffer);
			
			if (feof(archivo) == 0)
			{
				vec->datos = (vec->cant == 0)? (int *) malloc (sizeof(int)) : (int *) realloc (vec->datos, sizeof(int) * (vec->cant+1));

				if (vec->datos != NULL)
				{
					vec->datos[vec->cant] = buffer;
					(vec->cant)++;
				}
				else vec->cant = SIN_MEMORIA;
			}
		}
		while (feof(archivo) == 0 && vec->cant != SIN_MEMORIA);
		
	}
	else vec->cant = SIN_MEMORIA;

	return vec;
}

lista * ordenar (lista *vec, int opcion)
{
	lista *ordenado = NULL;
	int estado;
	int (*metodo[]) (lista *, lista **) = {may_a_men, divisor/*, par_e_impar, por_param*/};
	
	ordenado = (lista *) malloc (sizeof(lista));

	if (ordenado != NULL)
	{
		estado = (*metodo[opcion])(vec, &ordenado);
		
		if (estado == SIN_MEMORIA)
		{
			liberar_memoria(&ordenado);
			ordenado = NULL;
		}
	}
	
	return ordenado;
}

int may_a_men (lista *vec, lista **ordenado)
{
	int i, j, mayor;

	(*ordenado)->cant = vec->cant;
	(*ordenado)->datos = (int *) malloc (sizeof(int) * (*ordenado)->cant);
	
	if ((*ordenado)->datos != NULL)
	{	
		for (i = 0; i < (*ordenado)->cant; i++)
		{
			(*ordenado)->datos[i] = vec->datos[i];
		}

		for (i = 0; i < (*ordenado)->cant; i++)
		{
			mayor = (*ordenado)->datos[i];
				
			for (j = i+1; j < (*ordenado)->cant; j++)
			{
				if (mayor < (*ordenado)->datos[j])
				{
					mayor = (*ordenado)->datos[j];
					(*ordenado)->datos[j] = (*ordenado)->datos[i];
					(*ordenado)->datos[i] = mayor;
				}
			}
		}
	}
	else i = SIN_MEMORIA;

	return i;
}

int divisor (lista *vec, lista **ordenado)
{
	int i, div;

	printf("¿Que divisor comun queres?---> ");
	scanf("%i", &div);
		
	for (i = 0; (i < vec->cant) && (i != SIN_MEMORIA); i++)
	{
		if ((vec->datos[i] % div) == 0)
		{
			(*ordenado)->datos = (i == 0)? (int *) malloc (sizeof(int)) : (int *) realloc ((*ordenado)->datos, sizeof(int) * (i+1));
				
			if ((*ordenado)->datos != NULL)
			{
				(*ordenado)->datos[i] = vec->datos[i];
				((*ordenado)->cant)++;
			}
			else i = SIN_MEMORIA;
		}
	}

	return i;
}

void mostrar (lista *v)
{
	int i;
	
	for (i = 0; i < v->cant; i++)
	{
		printf("datos[%i] = %i\n", i, v->datos[i]);
	}
}

void escribir (lista *v, FILE *archivo)
{
	int i = 0;
	
	while (i < v->cant)
	{
		fprintf(archivo, "%i\n", v->datos[i]);
		i++;
	}
	
	//fwrite(v->datos, sizeof(int), v->cant, archivo); genera un archivo no ejecutable
}


void liberar_memoria (lista **v)
{
	free((*v)->datos);
	free(*v);
}
			
	
	
