
/**
        \file    funcbase.h
        \brief   Archivo de cabecera para funciones con memoria dinámica
        \author  Hecho en clase
        \date    2020.08.10
        \version 1.0.0
*/


#ifndef FUNCIONES_H
#define FUNCIONES_H

//-----------------
//-- Estructuras --
//-----------------

struct corredores
{
	int id;
	float distancia;
	int tiempo;
};

typedef struct corredores runner;

struct performance
{
	int id;
	float veloc;
};

typedef struct performance velocidad;

//-----------------
//--- Includes ----
//-----------------

#include <stdio.h>

//-----------------
//---- Defines ----
//-----------------

//-----------------
//-- Prototipos ---
//-----------------

int carga (runner ** listado);
void calculo (runner * listado, velocidad ** resultado, int cant);
void orden (velocidad * resultado, int cant);
void impresion(velocidad * resultado, int cant);

#endif
