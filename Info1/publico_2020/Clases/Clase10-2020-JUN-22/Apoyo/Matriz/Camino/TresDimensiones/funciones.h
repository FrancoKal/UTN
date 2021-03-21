/**
        \file    funciones.h
        \brief   Contiene los prototipos de las funciones para carga, conversión y muestra de una matriz binaria.
	\brief	 Además contiene las constantes simbólicas a utilizar en la definición de la matriz y su muestra.
	\author Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date 2019.05.17
        \version 1.0.0
*/



#ifndef FUNCIONES_H
#define FUNCIONES_H

	#define PRENDIDO 1
	#define MAX 100
	#define CARACTER "#"
	#define VACIO " "
	#define ESPERO 250000
	#define VUELTAS 100
	#define CUADROS 12

	#include <stdio.h>

	void CargaDatos (char * matriz, int * Cfila, int * Ccol);
	void PasoBin (char * EnBin, int EnDec, int digitos);
	void MostrarDatos(char * matriz, int cFila, int cColu);

#endif
