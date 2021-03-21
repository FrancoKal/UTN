/*

FUNCIONES BUFFEREADAS

Operacion		Funciones	Le paso			Devuelve
Abrir   	----> 	fopen  ----> 	Nombre, modo    ----> 	puntero a una estructura
Leer		----> 	fread  ---->	FILE *, Lo que quiero leer  ----> la informacion en memoria
Escribir	----> 	fwrite ---->	FILE *, Lo que quiero escribir  ---->  Estado
Cerrar		----> 	fclose ---->	FILE *		---->  Estado

*/

/**
	\file    main.c
	\brief   Programa que muestra por pantalla el contenido de un archivo (similar al cat)
	\author  Hecho en clase
	\date    2020.09.07
	\version 1.0.0
*/


//--------------
//--- Define ---
//--------------
#define TAM 50

//--------------
//-- Includes --
//--------------
#include <stdio.h>

/**
	\fn      int main (void)
	\brief   Programa similar al cat
	\author  Hecho en clase
	\date    2020.09.07
	\return  0: Si todo salió bien
		 1: Si se produjo un error
*/


int main (void)
{

	int salida = 0;
	FILE * archivo = NULL;
	char buffer;
//(1)	char buffer[TAM];


//      FILE *fopen(const char *path, const char *mode);
	archivo = fopen("transistor.txt", "r");

	do
	{
//		size_t fread( void *ptr, size_t tam, size_t nmiemb, FILE *flujo);
		fread (&buffer, sizeof(char), 1, archivo);
//(1)		fread (&buffer, sizeof(char), TAM, archivo);
		printf("%c", buffer);
	}
//	int feof( FILE *flujo);
	while (!feof(archivo));

	return salida;
}
