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
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>

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
//	proc dato;

	archivo = fopen(nombre, "w");
//		  open

  	if (archivo != NULL)
 	{

		fwrite(listado, sizeof(proc), cant, archivo);
//		write

  		fclose(archivo);
//		close

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
//	FILE * archivo = NULL;
	int fd;

  	proc dato;
	int estado = OK;
	int cant = 0;
	int leido;

//  	archivo = fopen(nombre, "r");
	fd = open (nombre, O_RDONLY);

  	if (fd != -1)
  	{
    		do
    		{

//			fread(&dato, sizeof(dato), 1, archivo);
//			ssize_t read(int fd, void *buf, size_t nbytes);
			leido = read(fd, &dato, sizeof(dato)*1);

			if (leido != 0)
      			{
	  			estado = agregar (listado, &cant, dato);
      			}
    		}
    		while(leido != 0 && estado == OK);

//    		fclose(archivo);
		close(fd);
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
