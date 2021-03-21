/*
Enunciado:
Realizar un programa que lea un archivo de texto que contiene la información de los procesos que
se ejecutan en una computadora.

La información a leer es:
Un entero con el número de proceso.
Un entero con la cantidad de bytes de memoria utilizada.
Un real con el tiempo ocupado por el proceso (en segundos pero con presición de centésimas)

Esos datos deberán incluirse en un vector de estructuras que ocupará solamente el espacio
necesario.
Finalizado el armado del vector, se mostrará por pantalla y luego se grabará nuevamente el
archivo.

Los nombres de los archivos (para leer y para escribir) se recibirán por argumento de main.
Además se deberán desarrollar las funciones de carga, de agregar y de grabar.
carga:    	Abre el archivo, interpreta los datos y llama a la función agregar para incluir
el dato al vector. 
agregar:	Agrega el dato al final del vector.
grabar:		Abre el archivo (si existe lo trunca) y lo escribe con los datos del vector.
main:		valida que haya recibido los argumentos necesarios, llama a las funciones,
		libera la memoria y finaliza.

Todas las funciones deberán detectar los errores posibles.
*/

/*
Grupo 1: Camila, Franco y Joaquin
leer, agregar

Grupo 2: Lucas, Romina
main, grabar
*/


//--------------------------------------------------------------

/**
	\file    main.c
	\brief   Archivo principal para la lectura del archivo, mostrar en pantalla y grabar.
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

/**
	\fn      main
	\brief   funcion principal
	\author  Hecho en clase
	\date    2020.09.28
	\param	 argc: Cantidad de argumentos recibidos
	\param	 argv[1]: Nombre del archivo a leer
	\param	 argv[2]: Nombre del archivo a escribir
	\return  0: si todo salió bien
		 != 0: si se produjo algún error

	ejec arch1.txt arch2.txt ==> argc = 3
*/

int main (int argc, char * argv[])
{
	proc * listado = NULL;
	int cant = 0;
	int estado = OK;

	if (argc != 3)
	{
		printf("Ingrese %s <Nombre del texto 1> <Nombre del texto 2>\n", argv[0]);
	}
	else
	{
	  	cant = leer_arch(argv[1], &listado);

		if (cant > 0)
		{
			mostrar(listado, cant);
		    	estado = grabar_arch(argv[2], listado, cant);
			free(listado);
	    	}
		else if (cant == ERR_MEM)
		{
			printf("Problemas asignando memoria\n");
			estado = cant;
		}
  	}

	if ((estado == ERR_ARCH) || (cant == ERR_ARCH))
	{
		printf("Problemas abriendo el archivo\n");
		estado = cant;
	}

	return estado;
}



