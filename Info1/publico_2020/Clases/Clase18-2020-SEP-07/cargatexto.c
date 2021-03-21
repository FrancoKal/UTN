/**
	\file    cargatexto.c
	\brief   Programa para generar un archivo de texto con los datos ingresados.
	\author  Hecho en clase
	\date    2020.09.07
	\version 1.0.0
*/


//--------------
//--- Define ---
//--------------
#define TAM 255

//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <string.h>

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


/*
Inicialización

Pedir nombre del archivo a guardar y abrir

Leer teclado
Escribir archivo

Cerrar todo
Rajar.
*/


	char buffer[TAM];
	FILE * archivo = NULL;
	int largo;
	int salida = 0;


	printf("Ingrese el nombre del archivo a grabar ---> ");
//	char *fgets(char *s, int tam, FILE *flujo);
	fgets(buffer, TAM, stdin);

	largo = strlen(buffer);
	largo--;
	buffer[largo] = '\0';

//      FILE *fopen(const char *path, const char *mode);
	archivo = fopen (buffer, "a");

	if (archivo != NULL)
	{
		printf("Comience a ingresar el texto a guardar\n");

		do
		{
			fgets(buffer, TAM, stdin);
			largo = strlen(buffer);
			if (largo>1)
			{
//	 	      		size_t fwrite( const void *ptr, size_t tam, size_t nmiemb, FILE *flujo);
				fwrite(buffer, sizeof(char), largo, archivo);
			}
		}
		while (largo>1);

		fclose (archivo);
	}
	else
	{
		printf("Te la debo, no pude abrir el archivo.\n");
		salida = 1;
	}

	return salida;

}
