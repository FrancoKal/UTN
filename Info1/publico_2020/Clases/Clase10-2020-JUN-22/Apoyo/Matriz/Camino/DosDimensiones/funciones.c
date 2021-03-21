/**
        \file    funciones.c
        \brief   Contiene las funciones para carga, conversión y muestra de una matriz binaria
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.17
        \version 1.0.0
*/


#include <math.h>
#include "funciones.h"

/**
	\fn void CargaDatos (int * matriz, int * Cfila, int * Ccol);
	\brief Función que pide los latos de cada línea de la matriz y la arma.
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.17
        \param  puntero al comienzo de la matriz donde almacenar los números binarios.
        \param  puntero a la variable que contiene la cantidad de filas de la matriz.
        \param  puntero a la variable que contiene la cantidad de columnas de la matriz.
	\return No devuelve nada 
*/


void CargaDatos (char * matriz, int * Cfila, int * Ccol)
{

	int parapasar, i;

	printf("Ingresa el tamaño de la matriz.\n Filas: ");
	scanf("%d", Cfila);
	printf("Columnas: ");
	scanf("%d", Ccol);

	for (i=0; i<*Cfila; i++) {
		printf("Ingresa la linea %d de la imagen: ", i);
		scanf("%d", &parapasar);
		if (parapasar>=pow(2,*Ccol)) printf("Valor fuera de rango. Ingrese nuevamente la linea %d.\n********\n", i--); 
		else PasoBin ((matriz+(i*(*Ccol))), parapasar, *Ccol);
	}

	return;
}


//----------------------------------------------------------------------------------

/**
	\fn void PasoBin (int * EnBin, int EnDec, int digitos)
	\brief Función que recibe un numero decimal y lo descompone en binario con la cantidad de digitos pedida.
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.17
        \param  puntero al comienzo de la matriz donde almacenar los números binarios.
        \param  puntero a la variable que contiene la cantidad de filas de la matriz.
        \param  puntero a la variable que contiene la cantidad de columnas de la matriz.
	\return No devueve nada
*/

void PasoBin (char * EnBin, int EnDec, int digitos)
{

	int j;

	for (j=digitos-1;j>0;j--) {
		*(EnBin+j) = EnDec % 2;
		EnDec = EnDec/2;
	}
	*(EnBin+j) = EnDec;

	return;
}


//----------------------------------------------------------------------------------

/**
	\fn void MostrarDatos(int * matriz, int cFila, int cColu);
	\brief Función que barre la matriz y muestra por pantalla los caracteres que están encendidos.
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.17
        \param  puntero al comienzo de la matriz donde buscar los números binarios.
        \param  puntero a la variable que contiene la cantidad de filas de la matriz.
        \param  puntero a la variable que contiene la cantidad de columnas de la matriz.
	\return No devuelve nada
*/

void MostrarDatos(char * matriz, int cFila, int cColu)
{
	int i, j;

	for (i=0; i<cFila; i++) {
		printf("%2d: ", i);
		for (j=0; j<cColu; j++) {
			if (*(matriz+(i*cColu)+j) == PRENDIDO) printf(CARACTER);
			else printf(VACIO);
		}
		printf ("\n");
	}

	printf("\n    ");
	for(j=cColu-1; j>=0; j--)
		printf("¨");

	printf("\n    ");
		for(j=cColu-1; j>=0; j--)
			printf("%d", j%10);

	printf("\n\n--------------------------------------\n\n");
	for (i=0; i<cFila; i++) {
		printf ("%d: ",i); 
		for (j=0; j<cColu; j++) {
			printf ("%d", *(matriz+(i*cColu)+j));
		}
		printf ("\n");
	}
}

//----------------------------------------------------------------------------------
