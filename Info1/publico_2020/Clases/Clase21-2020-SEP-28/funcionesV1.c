//--------------------------------------------------------------

/**
	\file    funciones.c
	\brief   Archivo de funciones para el manejo de archivos
	\author  Hecho en clase
	\date    2020.09.28
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

//--------------------------------------------------------------

void mostrar(proc * listado, int cant)
{
	int i;

	printf("Listado de procesos.\n------- -- ---------\n");

	for (i = 0; i < cant; i++)
	{
		printf("ID: %5d\tMem: %10d\tTiempo: %.02f\n", (listado+i)->id, (listado+i)->memoria, (listado+i)->tiempo);
	}
	printf("------- -- ---------\nProcesados: %d\n\n", i);

	return;
}

//--------------------------------------------------------------

int grabar_arch(char * nombre, proc * listado, int cant)
{
// (1) y (2)	int i;
	int salida;
	FILE * archivo = NULL;

	archivo = fopen(nombre, "w");

  	if (archivo != NULL)
 	{

// size_t fwrite( const void *ptr, size_t tam, size_t nmiemb, FILE *flujo);

/*(1)
	  	for (i = 0; i < cant; i++)
		{
			fwrite(&listado[i].id, sizeof(proc.id), 1, archivo);
			fwrite(&listado[i].memoria, sizeof(proc.memoria), 1, archivo);
			fwrite(&listado[i].tiempo, sizeof(proc.tiempo), 1, archivo);
	  	}
*/

/*(2)
	  	for (i = 0; i < cant; i++)
		{
			fwrite(&listado[i], sizeof(proc), 1, archivo);
	  	}
*/

//(3)
		fwrite(&listado, sizeof(proc), cant, archivo);

  		fclose(archivo);
		salida = OK;
 	}
	else
 	{
	    salida = ERR_ARCH;
	}

	return salida; 
}

//--------------------------------------------------------------

int leer_arch(char * nombre, proc ** listado)
{
	FILE* archivo = NULL;
//(1)	char buffer[LARGO];
  	proc dato;
//(1)  	int largo, 
	int estado = OK;
	int cant = 0;

  	archivo = fopen(nombre, "r");

  	if (archivo != NULL)
  	{
    		do
    		{
//(1)		    	fgets(buffer, LARGO, archivo);
//(2)
			fscanf(archivo, "%d", &(dato.id));


			if (feof(archivo) == 0)
      			{
//(1)      				largo = strlen(buffer) - 1;
//      				buffer[largo] = '\0';
//        			dato.id = atoi(buffer);
//        			fgets(buffer, LARGO, archivo);
//      				largo = strlen(buffer) - 1;
//      				buffer[largo] = '\0';
//        			dato.memoria = atoi(buffer);
//        			fgets(buffer, LARGO, archivo);
//       				largo = strlen(buffer) - 1;
//      				buffer[largo] = '\0';
//        			dato.tiempo = atof(buffer);

				fscanf(archivo, "%d", &(dato.memoria));
				fscanf(archivo, "%f", &(dato.tiempo));

	  			estado = agregar (listado, &cant, dato);
      			}
    		}
    		while(feof(archivo) == 0 && estado == OK);

    		fclose(archivo);
  	}
 	else 
	{
		estado = ERR_ARCH;
	}

	if (estado == OK)
	{
		estado = cant;
	}

	return estado;
}

//--------------------------------------------------------------

int agregar(proc ** listado, int * cant, proc dato)
{
	int devuelve;
	proc * aux = NULL;

  	*cant = (*cant) + 1;

	if (*cant == 1)
	{
		aux = (proc *) malloc(sizeof(proc));
	}
	else
	{
		aux = (proc *) realloc(*listado, (*cant) * (sizeof(proc)));
	}

	if (aux != NULL)
	{
	    *listado = aux;
//(1)	    (*listado)[cant].id = dato.id;
//	    (*listado)[cant].memoria = dato.memoria;
//	    (*listado)[cant].tiempo = dato.tiempo;
//(2)
	    (*listado)[(*cant)-1] = dato;

	    devuelve = OK;
  	}
	else
	{
	  	devuelve = ERR_MEM;
  	}

	return devuelve;
}

//--------------------------------------------------------------
