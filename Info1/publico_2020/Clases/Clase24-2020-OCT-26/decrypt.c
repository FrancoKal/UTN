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

Programa de desencriptación.
-------- -- ---------------
Realizar un programa que reciba por línea de comando un nombre de archivo.
Primero deberá verificar que el nombre del archivo termine en .cryp
En caso afirmativo continúa con la operación, caso contrario informa que es un formato no válido.
Luego deberá abrir ese archivo, leer los primeros n bytes correspondientes a la estructura
indicada en el enunciado de encriptación y verificará si los primeros tres bytes corresponden a
las letras 'C', 'R' e 'Y'. En caso afirmativo continúa con la operación.
Caso contrario informa que es un formato no válido.
Luego deberá desencriptar el archivo realizando el proceso inverso a la encriptación.
Finalizada la desencriptación, deberá verificar que la cantidad de caracteres desencriptados y
la suma de los mismos corresponde con los valores indicadas en los campos 5 y 6 de la
estructura.
Sino coincide presentará un mensaje de "La información ha sido vulnerada".
Los mensajes de error se mostraran por pantalla.
Si no hubo errores generará un archivo con el nombre original (nombre recibido sin el .cryp),
si hubo errores no debe generar nada.

Ej. Leo del archivo el caracter 'A', cuyo valor ascii es 65, y le paso 
el código de encripción 72.
Entonces en el archivo encriptado debo guardar el número 
(65-72 = -7 ==> 127 - 7 =) 120.

147 (g minuscula) ==> 147 - 72 = [75] ===> 75+72 = 147.
65-72 = -7 ==> 127 - 7 = [120]  ==> 120 + 72 = 192 ==> 192-127 = 65

*/

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define ERROR -1
#define OK 1
#define CANT 2
#define LEER 1


int main (int argc, char ** argv)
{
	int i, j,  aux, validacion = 0;
	FILE * archivo = NULL;
	FILE * archivod = NULL;
	unsigned char buffer;
	char val[] = "CRY";
	char val2[5] = {'\0','\0','\0','\0','\0'};
	int  cuentaf, chequeof, clave;
	int  cuenta = 0, chequeo = 0;
	char * nom_arch = NULL;

	if (argc == CANT)
	{
		j = strlen(argv[1]);

		for (i = 0; i < j; i++)
		{
			if (argv[1][i] == '.') //transistores.txt.cryp
			{
				val2[0] = argv[1][i + 1];
				val2[1] = argv[1][i + 2];
				val2[2] = argv[1][i + 3];
				val2[3] = argv[1][i + 4];
				aux = strcmp(val2, "cryp");

				if (aux == 0)
				{
//					printf("Todo correcto\n");
					nom_arch = (char *) malloc (sizeof(char)*(i+1));
					if (nom_arch != NULL)
					{
						strncpy(nom_arch, argv[1], i);
						nom_arch[i+1] = '\0';
						validacion = OK;

					}
					else
					{
						validacion = ERROR;
					}
					i = j;
				}
				else
				{
					validacion = ERROR;
				}
			}
		}

		if (validacion != ERROR)
		{
			archivo = fopen (argv[1] , "r");
			if (archivo != NULL)
			{
				for (i = 0; i < 3; i++)
				{
					if (feof(archivo) == 0)
					{
						fread(&buffer, sizeof(char), LEER, archivo);
						if(buffer != val[i])
						{
							printf("Archivo incorrecto\n");
							validacion = ERROR;
							i = 3;
						}
					}
				}

				if (validacion != ERROR)
				{

					fread(&clave, sizeof(int), LEER, archivo);
					fread(&cuentaf, sizeof(int), LEER, archivo);
					fread(&chequeof, sizeof(int), LEER, archivo);

					archivod = fopen (nom_arch, "w");
					if (archivod == NULL)
					{
						validacion = ERROR;
					}
					else
					{

			    		do
						{
							fread (&buffer, sizeof(char), LEER, archivo);
							if (!feof(archivo))
							{
								buffer = buffer + clave;
								if (buffer > 127)
								{
									buffer = buffer - 127;
								}

								cuenta++;
								chequeo += buffer;  // chequeo = chequeo + buffer;

								fwrite(&buffer, sizeof(char), LEER, archivod);
							}
						}
						while (!feof(archivo));

						fclose(archivo);
						fclose(archivod);


						if ((cuenta != cuentaf) || (chequeo != chequeof))
						{
							printf("La información se encuentra comprometida.\n");
							remove (nom_arch);
						}
						else
						{
							printf("Se generó el archivo origen.\n");
						}
					}
				}
			}
		}
		else
		{
			printf("archivo no valido\n");
		}
	}
	else
	{
		printf("Ingrese solamente un archivo\n");
	}
	return 0;
}

