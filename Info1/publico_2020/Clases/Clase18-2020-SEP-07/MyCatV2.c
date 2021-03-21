/*

FUNCIONES BUFFEREADAS

Operacion		Funciones	Le paso			Devuelve
Abrir   	----> 	fopen  ----> 	Nombre, modo    ----> 	puntero a una estructura
Leer		----> 	fread  ---->	FILE *, Lo que quiero leer  ----> la informacion en memoria
Escribir	----> 	fwrite ---->	FILE *, Lo que quiero escribir  ---->  Estado
Cerrar		----> 	fclose ---->	FILE *		---->  Estado

*/

/**
	\file    MyCatV2.c
	\brief   Programa que muestra por pantalla el contenido de un archivo (similar al cat)
	\author  Hecho en clase
	\date    2020.09.07
	\version 1.2.0
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
	\fn      int main (int cant, char ** param)
	\brief   Programa similar al cat
	\author  Hecho en clase
	\date    2020.09.07
	\param	 cant: Cantidad de argumentos recibidos (incluido el programa)
	\param	 param: Puntero a los strings de los argumentos recibidos
	\return  0: Si todo salió bien
		 1: Si se produjo un error
*/


/*
./MyCat transistor.txt
cant: 2
param -->	[0]: ./MyCat
		[1]: transistor.txt


*/

int main (int cant, char ** param)
{
	int salida = 0;
	FILE * archivo = NULL;
	char buffer;
	int i;

	if (cant > 1)
	{

		for (i = 1; i < cant; i++)
		{
//		      	FILE *fopen(const char *path, const char *mode);
			archivo = fopen(param[i], "r");

			if (archivo != NULL)
			{
				do
				{
//					size_t fread( void *ptr, size_t tam, size_t nmiemb, FILE *flujo);
					fread (&buffer, sizeof(char), 1, archivo);
					if (!feof(archivo))
					{
						printf("%c", buffer);
					}
				}
//				int feof( FILE *flujo);
				while (!feof(archivo));

				fclose(archivo);
			}
			else
			{
				printf("%s: %s: No existe el archivo o el directorio\n", param[0], param[i]);
			}
		}
	}

	return salida;
}
