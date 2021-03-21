/**
	\file    funciones1.h
	\brief   Prototipos de las funciones que utiliza el funciones1.c
	\author  Franco Calvino (francoc.2002@gmail.com)
	\date    2020.07.13
	\version 1.1.0
*/


#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>

enum estado {SIN_MEMORIA = -1, ERROR = -2, EXITO = 1};

//----------------
//-- Prototipos --
//----------------

int lugarcito (char *frase, char *separador, int **resultado);

#endif


