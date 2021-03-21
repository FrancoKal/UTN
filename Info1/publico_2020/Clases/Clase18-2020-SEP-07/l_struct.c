/**
	\file    l_struct.c
	\brief   Programa para leer un archivo de estructuras generado por c_struct
	\author  Hecho en clase
	\date    2020.09.07
	\version 1.0.0
*/


//-------------------
//--- Estructuras ---
//-------------------
struct COMPUESTO
{
	int dato_i;
	float dato_f;
	int dato_i2;
};

typedef struct COMPUESTO compuesto;

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
	compuesto dato;
	int salida = 0;


	printf("Ingrese el nombre del archivo a leer ---> ");
//	char *fgets(char *s, int tam, FILE *flujo);
	fgets(buffer, TAM, stdin);

	largo = strlen(buffer);
	largo--;
	buffer[largo] = '\0';

//      FILE *fopen(const char *path, const char *mode);
	archivo = fopen (buffer, "r");

	if (archivo != NULL)
	{

		printf("Te muestro el archivo\n");

		do
		{
				fread(&dato.dato_i, sizeof(int), 1, archivo);
				fread(&dato.dato_f, sizeof(float), 1, archivo);
				fread(&dato.dato_i2, sizeof(int), 1, archivo);

//				fread(&dato, sizeof(compuesto), 1, archivo);

			if (!feof(archivo))
			{
				printf("Entero: %d, Real: %f, Entero: %d\n", dato.dato_i, dato.dato_f, dato.dato_i2);
			}
		}
		while (!feof(archivo));

		fclose (archivo);
	}
	else
	{
		printf("Te la debo, no pude abrir el archivo.\n");
		salida = 1;
	}

	return salida;

}
