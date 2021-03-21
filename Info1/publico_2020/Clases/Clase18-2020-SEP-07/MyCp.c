/*

FUNCIONES BUFFEREADAS

Operacion		Funciones	Le paso			Devuelve
Abrir   	----> 	fopen  ----> 	Nombre, modo    ----> 	puntero a una estructura
Leer		----> 	fread  ---->	FILE *, Lo que quiero leer  ----> la informacion en memoria
Escribir	----> 	fwrite ---->	FILE *, Lo que quiero escribir  ---->  Estado
Cerrar		----> 	fclose ---->	FILE *		---->  Estado

*/

/**
	\file    MyCp.c
	\brief   Programa para copiar archivos
	\author  Hecho en clase
	\date    2020.09.07
	\version 1.0.0
*/


//--------------
//--- Define ---
//--------------

//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <string.h>

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

int main (int cant, char ** param)
{
	int salida = 0;
	FILE * arch_or = NULL;
	FILE * arch_de = NULL;
	char buffer;

	if (cant == 3)
	{


		if (strcmp(param[1], param[2]) != 0)
		{

//			FILE *fopen(const char *path, const char *mode);
			arch_or = fopen(param[1], "r");
			arch_de = fopen(param[2], "w");

			if ((arch_or != NULL) && (arch_de != NULL))
			{
				do
				{
//					size_t fread( void *ptr, size_t tam, size_t nmiemb, FILE *flujo);
					fread (&buffer, sizeof(char), 1, arch_or);
					if (!feof(arch_or))
					{
						fwrite (&buffer, sizeof(char), 1, arch_de);
					}
				}
//				int feof( FILE *flujo);
				while (!feof(arch_or));

				fclose(arch_or);
				fclose(arch_de);
			}
			else
			{
				printf("Problema abriendo los archivos.\n");
			}
		}
		else
		{
			printf("El archivo origen y destino es el mismo.\n");
		}
	}
	else
	{
		printf("Modo de uso: %s <origen> <destino>\n", param[0]);

	}

	return salida;
}
