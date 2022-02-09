/**
	\file    Pila_Cola.c
	\brief   Archivo principal para la ejecución del menú y llamar a las funciones de apilar, encolar, quitarA y quitarB
	\author  Hecho en clase
	\date    2020.09.14
	\version 1.0.0
*/

#ifndef FUNCIONES_H
#define FUNCIONES_H

//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>

//-----------------
//---- Defines ----
//-----------------
enum estado {OK, ERROR};

//-----------------
//-- Prototipos ---
//-----------------
int apilar (int ** vec, int * cant, int dato);
int encolar (int ** vec, int * cant, int dato);
int quitarA (int ** vec, int * cant, int * dato);
int quitarB (int ** vec, int * cant, int * dato);
void mostrar (int * vec, int cant);

#endif

