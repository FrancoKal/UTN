/**
	\file    funcdyn.h
	\brief   Archivo de cabecera para funciones con memoria dinámica
	\author  Spataro, Hector (hspataro@frba.utn.edu.ar)
	\date    2020.08.10
	\version 1.0.0
*/


#ifndef FUNCIONES_H
#define FUNCIONES_H


//-----------------
//-- Estructuras --
//-----------------

struct Corredor
{
	int ID;
	int tiempo;
	float dist;
};

typedef struct Corredor corredor;


/*
OTRAS FORMAS DE DEFINICION

typedef struct Corredor
{
	int ID;
	int tiempo;
	float dist;
} corredor;

typedef struct
{
	int ID;
	int tiempo;
	float dist;
} corredor;

*/


struct Velocidad
{
	int ID;
	float veloc;
};

typedef struct Velocidad velocidad;

//-----------------
//--- Includes ----
//-----------------

#include <stdio.h>
#include <stdlib.h>

//-----------------
//---- Defines ----
//-----------------

#define SI 1
#define NO 0

//-----------------
//-- Prototipos ---
//-----------------

int carga (corredor ** listado);
void calculo (corredor * listado, velocidad ** performance, int cant);
void ordeno (velocidad * performance, int cant);
void muestro (velocidad * performance, int cant);

#endif





