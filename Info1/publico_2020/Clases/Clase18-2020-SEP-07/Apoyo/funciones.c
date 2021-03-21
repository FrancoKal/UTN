/**
	\file    funciones.c
	\brief   Archivo de funciones para el manejo de archivos
	\author  Hecho en clase
	\date    2020.09.07
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "funciones.h"

//-------------------------------------------------------------------------------------------------------------

/**
	\fn      char menu (void)
	\brief   Muestra el menu y devuelve la letra ingresada
	\author  Hecho en clase
	\date    2020.09.07
	\return  letra del menú ingresada
*/

char menu (void)
{

	int flag = 1;
	char opcion;
	char buffer;

	do
	{
		printf("Que desea hacer\n");
		printf("\tCargar datos del archivo (C) o (c)\n");
		printf("\tGrabar datos al archivo (G) o (g)\n");
		printf("\tMostrar datos (M) o (m)\n");
		printf("\tAgregar datos (A) o (a)\n");
		printf("\tSalir (S) o (s)\n");
		printf("\t----> ");

		scanf(" %c", &opcion);
		scanf("%c", &buffer);
		opcion = toupper(opcion);

		switch (opcion)
		{
			case 'C':
			case 'G':
			case 'M':
			case 'A':
			case 'S':
				flag = 0;
				break;
			default:
				printf("Opción invalida. Pruebe otra vez.\n");
		}
	}
	while (flag);

	return opcion;
}

//-------------------------------------------------------------------------------------------------------------

/**
	\fn      int agregar (conjunto * listado)
	\brief   Permite la carga de los datos desde el teclado
	\author  Hecho en clase
	\date    2020.09.07
	\param   listado: dirección del vector donde se van a cargar los datos
	\return  cantidad de datos cargados
*/

int agregar (conjunto * listado)
{
	int entero;
	int cantidad = 0;

	printf("Ingrese un número entero (0 para salir): ");
	scanf ("%d", &entero);

	while (entero)
	{
		(listado+cantidad)->entero = entero;
		printf("Ingrese un número real: ");
		scanf ("%f", &((listado+cantidad)->real));
		printf("Ingrese otro número entero: ");
		scanf ("%d", &((listado+cantidad)->otroent));

		cantidad++;

		printf("Ingrese un número entero (0 para salir): ");
		scanf ("%d", &entero);
	}

	return cantidad;
}

//-------------------------------------------------------------------------------------------------------------

/**
	\fn      int cargar (conjunto * listado)
	\brief   Permite la carga de los datos desde un archivo
	\author  Hecho en clase
	\date    2020.09.07
	\param   listado: dirección del vector donde se van a cargar los datos
	\return  cantidad de datos cargados
*/

int cargar (conjunto * listado)
{

	int cant = 0;
	int largo;
	char nom_arch[LARGO];
	FILE * archivo;

	printf("Ingrese el nombre del archivo\n\t----> ");
	fgets(nom_arch,LARGO,stdin);

	largo = strlen(nom_arch);
	largo--;
	nom_arch[largo]='\0';

	archivo = fopen(nom_arch, "r");

//	if(archivo)
	if(archivo != NULL)
	{

  		do
		{
/*
  			fread(*(listado+cant)->entero,sizeof(int),1,archivo);
			fread(*(listado+cant)->real,sizeof(float),1,archivo);
			fread(*(listado+cant)->otroent,sizeof(int),1,archivo);
*/
  			fread((listado+cant),sizeof(conjunto),1,archivo);
			cant++;
		}
		while(!feof(archivo));
		cant--;
		fclose(archivo);
	}
	else
  	{
	  	printf("No se pudo abrir el archivo\n");
	}

	return cant;
}

//-------------------------------------------------------------------------------------------------------------

/**
	\fn      void grabar (conjunto * listado, int cant)
	\brief   Guarda los datos cargados en un archivo
	\author  Hecho en clase
	\date    2020.09.07
	\param   listado: dirección del vector donde se encuentran los datos
	\param   cant: cantidad de datos a escribir
	\return  void
*/

void grabar (conjunto * listado, int cant)
{
	int i = 0;
	int largo;
	char nom_arch[LARGO];
	FILE * archivo;

	if ((cant > 0) && (listado != NULL))
	{
		printf ("Ponele un nombre a tu archivo\n\t----> ");
		fgets (nom_arch, LARGO, stdin);

		largo = strlen(nom_arch);
		largo--;
		nom_arch[largo]='\0';

		archivo = fopen(nom_arch,"w");

		if(archivo != NULL)
	    	{
    			for( i = 0 ; i < cant ; i++)
			{
		      		fwrite((listado+i),sizeof(conjunto),1,archivo);
			}

			fclose (archivo);
		}
		else
		{
		  	printf("No se pudo abrir el archivo\n");
    		}

  	}
}

//-------------------------------------------------------------------------------------------------------------

/**
	\fn      void mostrar (conjunto * listado, int cant)
	\brief   Muestra los datos cargados por pantalla
	\author  Hecho en clase
	\date    2020.09.07
	\param   listado: dirección del vector donde se encuentran los datos
	\param   cant: cantidad de datos a escribir
	\return  void
*/

void mostrar (conjunto * listado, int cant)
{
	int i;
	for(i=0 ;i < cant; i++)
	{
		printf("entero: %d\tReal: %f\tOtro entero: %d \n", (listado+i)->entero, (listado+i)->real, (listado+i)->otroent);
	}

}

//-------------------------------------------------------------------------------------------------------------

