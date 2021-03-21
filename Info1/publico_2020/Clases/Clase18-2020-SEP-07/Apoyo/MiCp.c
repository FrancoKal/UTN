/**
	\file    MiCp.c
	\brief   Programa para copiar un archivo
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

/**
	\fn      int main (int argc, char ** argv)
	\brief   Muestra el archivo por pantalla
	\author  Hecho en clase con amor
	\date    2020.09.07
	\param	 argc: cantidad de argumentos (incluyendo el nombre del programa)
	\param	 argv: Nombre de los archivos origen y destino de la copia
	\return  0 si no hubo errores
		 1 si no pudo abrir el archivo
*/

int main (int argc, char ** argv)
{


	FILE * p_arch_o = NULL;
	FILE * p_arch_d = NULL;
	int salida = OK;
	char tubuffer;

	if (argc == 3)
	{
		p_arch_o = fopen(argv[1], "r");
		p_arch_d = fopen(argv[2], "w");

		if ((p_arch_o != NULL) && (p_arch_d != NULL))
		{

			do
			{
				fread(&tubuffer,sizeof(char),1,p_arch_o);
				if(!feof(p_arch_o))
				{
					fwrite(&tubuffer,sizeof(char),1,p_arch_d);
				}

			}
			while(!feof(p_arch_o));

			fclose (p_arch_o);
			fclose (p_arch_d);
		}
	 	else
		{
			printf("No se pudo abrir uno de los archivos. Sorry gordo.\n");
			salida = ERROR;
		}
	}
	else
	{
		printf("El uso del programa es %s <archivo_origen> <archivo_destino>\n", argv[0]);
		salida = ERROR;
	}

	return salida;
}
