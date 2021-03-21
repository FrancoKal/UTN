
/**
        \file    funcV1.h
        \brief   Archivo de cabecera para funciones con memoria dinámica
        \author  Hecho en clase
        \date    2020.08.24
        \version 1.1.0
*/


#ifndef FUNCIONES_H
#define FUNCIONES_H

//-----------------
//---- Defines ----
//-----------------

#define LARGO_N 31

//-----------------
//-- Estructuras --
//-----------------

struct corredores
{
	int id;
	float distancia;
	int tiempo;
	char nombre [LARGO_N];
};

typedef struct corredores runner;

struct performance
{
	int id;
	float veloc;
	char nombre [LARGO_N];
};

typedef struct performance velocidad;

//-----------------
//--- Includes ----
//-----------------

#include <stdio.h>

//-----------------
//-- Prototipos ---
//-----------------

int carga (runner ** listado);
void calculo (runner * listado, velocidad ** resultado, int cant);
void orden_v (velocidad * resultado, int cant);
void orden_n (velocidad * resultado, int cant);
void impresion(velocidad * resultado, int cant);

#endif
