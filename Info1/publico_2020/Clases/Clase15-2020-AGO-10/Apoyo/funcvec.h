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

#define CANT 10

//-----------------
//-- Prototipos ---
//-----------------

void carga (corredor * listado);
void calculo (corredor * listado, velocidad * performance);
void ordeno (velocidad * performance);
void muestro (velocidad * performance);

#endif
