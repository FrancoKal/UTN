/**
	\file    c_struct.c
	\brief   Programa para generar un archivo con estructuras
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

	char buffer[TAM];
	FILE * archivo = NULL;
	int largo;
	compuesto dato;
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
		do
		{
			printf("Ingrese primer entero: ");
			scanf("%d",&dato.dato_i);
			if (dato.dato_i>0)
			{
				printf("Ingrese el real: ");
				scanf("%f",&dato.dato_f);
				printf("Ingrese segundo entero: ");
				scanf("%d",&dato.dato_i2);

/*				fwrite(&dato.dato_i, sizeof(int), 1, archivo);
				fwrite(&dato.dato_f, sizeof(float), 1, archivo);
				fwrite(&dato.dato_i2, sizeof(int), 1, archivo);
*/
				fwrite(&dato, sizeof(compuesto), 1, archivo);

			}
		}
		while (dato.dato_i>0);

		fclose (archivo);
	}
	else
	{
		printf("Te la debo, no pude abrir el archivo.\n");
		salida = 1;
	}

	return salida;

}
