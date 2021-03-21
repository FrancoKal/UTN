/**
	\file    funciones.h
	\brief   Archivo de cabecera para funciones con manejo de archivos
	\author  Hecho en clase
	\date    2020.09.07
	\version 1.0.0
*/


#ifndef FUNCIONES_H
#define FUNCIONES_H

//-----------------
//---- Defines ----
//-----------------

#define MAX_ELEM 1000
#define LARGO 255

//-----------------
//-- Estructuras --
//-----------------

struct CONJUNTO
{
	int entero;
	float real;
	int otroent;
};

typedef struct CONJUNTO conjunto;

/*
-------------------------------------------
typedef struct
{
	int entero;
	float real;
	int otroent;
} conjunto;
-------------------------------------------

typedef struct CONJUNTO
{
	int entero;
	float real;
	int otroent;
} conjunto;
-------------------------------------------

*/

//-----------------
//-- Prototipos ---
//-----------------

//Recibe un puntero al vector de estructuras, y lo tiene que completar con los datos del archivo
//La función tiene que preguntar el nombre del archivo.
int cargar (conjunto * listado);
//Recibe un puntero al vector de estructuras, y lo tiene que escribir en un archivo
//La función tiene que preguntar el nombre del archivo.
void grabar (conjunto * listado, int cant);
//Recibe un vector y lo tiene que mostrar por pantalla
void mostrar (conjunto * listado, int cant);
char menu (void);
int agregar (conjunto * listado);

#endif


