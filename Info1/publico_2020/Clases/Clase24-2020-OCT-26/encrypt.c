/*
Programa de encriptación.
-------- -- ------------
Realizar un programa que reciba por linea de comando el nombre de un archivo de texto y un
número.
Primero deberá verificar el correcto uso del programa, en cuanto a la cantidad de parámetros
y que el número sea mayor o igual a 32 y menor o igual a 126.
El programa deberá leer el archivo recibido y al dato (caracter) del archivo le restará el valor
pasado como parámetro.
Si el resultado es negativo, deberá continuar a partir de 127.
Ej. Leo del archivo el caracter 'A', cuyo valor ascii es 65, y le paso el código de encripción
72.
Entonces en el archivo encriptado debo guardar el número (65-72 = -7 ==> 127 - 7 =) 120.
Además, en la primer parte del archivo deberá guardar una estructura con la siguiente
información:

Byte1 ==> Valor fijo igual a = 'C'
Byte2 ==> Valor fijo igual a = 'R'
Byte3 ==> Valor fijo igual a = 'Y'
Clave ==> Valor utilizado para encriptar.
Cantidad ==> Cantidad de caracteres que tiene el archivo origen.
Check ==> Suma de todos los caracteres (valor ascii) previa la conversión.

El nombre del archivo encriptado deberá ser el nombre del archivo original con el agregado de
.cryp
*/

//------------------------------------------------------------------------------------------------------------

//----------------
//-- Prototipos --
//----------------

int checkArg(int argc, char* argv);
int encriptado(char* file, char* key);
int calcCant(char* file);
int calcSuma(char* file);

//--------------
//-- Includes --
//--------------

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-------------
//-- Defines --
//-------------

#define ERROR 	-1
#define OK 		 0
#define TAM		 1

//---------------------------------------------------------------------------------------------------------------


int main (int argc, char ** argv)
{

	if (checkArg(argc, argv[2]) == 0)
	{
    	if (encriptado(argv[1], argv[2]) == 0)
		{
    		printf("Salio todo bien\n");
    	}
	    else
		{
			printf("Salio todo mal\n");
    	}
  	}
	else
	{
  		printf("Modo de uso:\n\t %s <nombre_archivo> <clave>\n", argv[0]);
  	}

	return 0;
}


//---------------------------------------------------------------------------------------------------------------

/**
	\fn     	int checkArg(int argc, char* argv);
	\brief  	Chequea si son validos los argumentos
	\author  	Osorio, Joaquín joaquinosorio55@gmail.com
	\date    	26-10-2020
	\param  	argc (cantidad de argumentos), argv (argumento "numerico")
	\return 	retorna 0 si los argumentos son validos
*/

int checkArg(int argc, char * argv)
{

	int r = ERROR;
  	int n;

	if (argc == 3)
	{
  		n = atoi(argv);
	    if (n >= 32 && n <= 126)
		{
    		r = OK;
	    }
  	}
  	return r;
}

/* ------------------------------------------------------------------------------------------------------------ */

/**
	\fn     	int encriptado(char* file, char* key, char** result);
	\brief  	encripta el archivo
	\author  	Osorio, Joaquín joaquinosorio55@gmail.com
	\date    	26-10-2020
	\param  	file (archivo de origen), key (clave), result (texto encriptado)
	\return 	retorna 0 si los argumentos son validos
*/

int encriptado(char * file, char * key)
{
	int r = ERROR;
  	FILE * origen = NULL;
  	FILE * destino = NULL;
	int clave = 0;
  	int cantidad, suma;
  	char buffer;
  	char * destFile = NULL;
	char letra[3] = {'C','R','Y'};

  	destFile = (char*) malloc(sizeof(char) * (strlen(file) + 6));

  	strcpy(destFile, file);
  	strcat(destFile, ".cryp");

  	clave = atoi(key);

  	cantidad = calcCant(file);
  	suma = calcSuma(file);

  	origen = fopen(file, "r");
 	destino = fopen(destFile, "w");

  	if (origen != NULL && destino != NULL)
	{
  		fwrite(letra, sizeof(letra), TAM, destino);
	    fwrite(&clave, sizeof(int), TAM, destino);
	    fwrite(&cantidad, sizeof(int), TAM, destino); //Calcular la cantidad
    	fwrite(&suma, sizeof(int), TAM, destino); // calcular la suma

    	do
		{
			fread (&buffer, sizeof(char), TAM, origen);
			if (!feof(origen))
			{
					buffer = buffer - clave;

					if (buffer < 0)
					{
						buffer = 127 + buffer;
					}

					fwrite(&buffer, sizeof(char), TAM, destino);
			}
		}
		while (!feof(origen));

    	fclose(origen);
		fclose(destino);

    	r = OK;
    }

  	return r;
}

/* ------------------------------------------------------------------------------------------------------------------------------------ */

/**
	\fn     	int calcCant(char* file);
	\brief  	calcula la cantidad de caracteres en un archivo
	\author  	Osorio, Joaquín joaquinosorio55@gmail.com
	\date    	26-10-2020
	\param  	char* file
	\return 	retorna la cantidad de caracteres
*/

int calcCant(char * file)
{
  	FILE * archivo = NULL;
  	int cant = 0;
  	char buffer;

	archivo = fopen(file, "r");

   	do
	{
		fread (&buffer, sizeof(char), TAM, archivo);
		if (!feof(archivo))
		{
			cant++;
		}
	}
	while (!feof(archivo));

  	fclose(archivo);

  	return cant;
}

/* ------------------------------------------------------------------------------------------------------------------------------------- */

/**
	\fn			int calcSuma(char* file);
	\brief  	calcula la suma de todos los caracteres
	\author  	Osorio, Joaquín joaquinosorio55@gmail.com
	\date    	26-10-2020
	\param  	char* file
	\return 	retorna la suma de todos los caracteres
*/

int calcSuma(char * file)
{

	FILE * archivo = NULL;
  	int suma = 0;
  	char buffer;

  	archivo = fopen(file, "r");

   	do
	{
		fread (&buffer, sizeof(char), TAM, archivo);
		if (!feof(archivo))
		{
			suma = suma + (int) buffer;
		}
	}
	while (!feof(archivo));

  	fclose(archivo);

  	return suma;
}
