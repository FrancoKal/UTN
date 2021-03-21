/**
	\file    funciones1.h
	\brief   Prototipos de las funciones del funciones1.c
	\author  Calvino, Franco (francoc.2002@gmail.com)
	\date    2020.11.30
	\version 1.0.0
*/


#ifndef FUNCIONES_H
#define FUNCIONES_H

#include <stdio.h>
#include <stdlib.h>

#define ERROR -1
#define FILENAME "datos.csv"

typedef struct
{
	int codigo;
	float peso;
	long existencia;
} DATOS;

//----------------
//-- Prototipos --
//----------------
int generacion (int * codigos, int cant_codigos, DATOS ** listado, char * nombre_arch);

#endif


