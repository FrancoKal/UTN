/**
	\file    MiCat.c
	\brief   Programa para mostrar un archivo por pantalla
	\author  Hecho en Clase
	\date    2020.09.07
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include <stdio.h>


#define OK 0
#define ERROR 1
#define CANT 25

/**
	\fn      int main (void)
	\brief   Muestra el archivo por pantalla
	\author  Hecho en clase con amor
	\date    2020.09.07
	\return  0 si no hubo errores
		 1 si no pudo abrir el archivo
*/

int main (void)
{

/*   fopen - fread - fwrite - fclose  

Abro el archivo a leer: fopen
Lo  leo: fread
Escribo por pantalla: printf
Cerrar el archivo: fclose

*/

	FILE * p_arch = NULL;
	int salida = OK;
// (1)	char mibuffer[CANT];
	char tubuffer;

	p_arch = fopen("transistor.txt", "r");

	if (p_arch != NULL)
	{

		do
		{
			fread(&tubuffer,sizeof(char),1,p_arch);
			if(!feof(p_arch))
			{
				printf("%c", tubuffer);
			}
/* (1)
			fread(mibuffer,sizeof(char),CANT-1,p_arch);
			mibuffer[CANT-1] = '\0';
			fprintf("%s", mibuffer);
*/

		}
		while(!feof(p_arch));

		fclose (p_arch);

	}
 	else
	{
		printf("No se pudo abrir el archivo. Sorry gordo.\n");
		salida = ERROR;
	}

	return salida;
}
