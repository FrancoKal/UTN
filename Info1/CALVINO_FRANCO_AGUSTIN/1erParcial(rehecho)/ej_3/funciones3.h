/**
	\file    funciones3.h
	\brief   Prototipos de las funciones que utiliza el funciones3.c
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13
	\version 1.1.0
*/


#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>

enum errores {SIN_MEMORIA = -1, FINALIZO = -2, ERROR_DATOS = -3};

#define LARGO_MAX 8 // Escribi aca la cantidad de elementos del vector 1 para no pisar posiciones de memoria


//----------------
//-- Prototipos --
//----------------

int raices (int *v1, unsigned int **v2);


#endif


