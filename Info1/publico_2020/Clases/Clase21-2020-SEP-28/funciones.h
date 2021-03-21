//--------------------------------------------------------------

/**
	\file    funciones.h
	\brief   Archivo de cabecera correspondiente al funciones.c
	\author  Hecho en clase
	\date    2020.09.28
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------

//-----------------
//-- Estructuras --
//-----------------

struct PROCESOS
{
	int id;			// 4 bytes
	int memoria;		// 4 bytes
	float tiempo;		// 4 bytes
};

typedef struct PROCESOS proc;

//-----------------
//---- Defines ----
//-----------------
#define LARGO 255
#define MAX_NUM 11
//enum FIN {OK, ERR_ARCH, ERR_MEM};
enum FIN {ERR_MEM=-2, ERR_ARCH, OK};

//-----------------
//-- Prototipos ---
//-----------------
void mostrar(proc * listado, int cant);

//(1) int leer_arch(char * nombre, proc ** listado, int * cant);
//Devuelvo el código de error y la cantidad por referencia.

//(2)
int leer_arch(char * nombre, proc ** listado);
//	Código error, con números negativos y 0 o positivo es la cantidad de elementos.

int agregar(proc ** listado, int * cant, proc dato);

int grabar_arch(char * nombre, proc * listado, int cant);

//--------------------------------------------------------------

