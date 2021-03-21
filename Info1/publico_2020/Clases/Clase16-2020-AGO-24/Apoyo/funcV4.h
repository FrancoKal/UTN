/**
        \file    funcV4.h
        \brief   Archivo de cabecera para funciones con memoria dinámica
        \author  Hecho en clase
        \date    2020.08.10
        \version 1.4.0
*/


#ifndef FUNCIONES_H
#define FUNCIONES_H

//-----------------
//---- Defines ----
//-----------------

#define LARGO_N 255

//-----------------
//-- Estructuras --
//-----------------

struct corredores
{
	int id;
        char * nombre;
	float distancia;
	int tiempo;
};

typedef struct corredores runner;

struct performance
{
	int id;
        char * nombre;
	float veloc;
};

typedef struct performance velocidad;

//-----------------
//--- Includes ----
//-----------------

#include <stdio.h>

//-----------------
//-- Prototipos ---
//-----------------

int carga (runner *** listado);
void calculo (runner ** listado, velocidad *** resultado, int cant);
velocidad ** orden_n (velocidad ** resultado, int cant);
velocidad ** orden_v (velocidad ** resultado, int cant);
void impresion(velocidad ** resultado, int cant);
void limpiar_r (runner *** listado, int cant);
void limpiar_v (velocidad *** resultado, int cant);

#endif
