/**
	\file    micros.c
	\brief   Programa para el manejo de un listado de microprocesadores
	\brief	 Utilizará structs, archivos formato csv y memoria dinámica.
	\author  Hecho en clase
	\date    2020.09.14
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//-----------------
//-- Estructuras --
//-----------------
struct	MICRO
{
	int id;
	char * nombre;
	int nucleos;
	int hilos;
	float frec;
	int uni_frec;
	float precio;
};

typedef struct MICRO micro;

//-----------------
//-- Enumeracion --
//-----------------

enum errores {OK, ERR_MEM, ERR_ARCH_L, ERR_ARCH_E};

//-------------
//-- Defines --
//-------------
#define LARGO 256

//----------------
//-- Prototipos --
//----------------



/**
	\fn      int main (void);
	\brief   Función principal
	\author  Hecho en clase
	\date    2020.09.14
	\return  OK: Si anduvo todo bien.
		 ERROR: Si tuvo problemas en la ejecución.
*/


/*
Pedir nombre del archivo a leer (está)
Abro y leo el archivo. (está)
Lo cargo en el vector. (está)
Cierro el archivo de lectura. (está)
Muestro el vector. 
Pido nombre del archivo a escribir.
Genero el registro CSV
Escribo el archivo.
Cierro el archivo de escritura.
Libero memoria.
Salgo.
*/

int main (void)
{
	int salida = OK;
        int largo, i, cant = 0;
        char nom_arch[LARGO];
        char buffer[LARGO];
        FILE * archivo = NULL;
	micro * dato = NULL;
	micro ** listado = NULL;
	micro ** aux = NULL;
	char * tempo;

        printf("Ingrese el nombre del archivo \t----> ");
        fgets(nom_arch,LARGO,stdin);

        largo = strlen(nom_arch);
        largo--;
        nom_arch[largo]='\0';

        archivo = fopen(nom_arch, "r");

        if(archivo != NULL)
        {
		do
                {
			fgets(buffer,LARGO,archivo);
			if (!feof(archivo))
			{

				if (cant == 0)
				{
					aux = (micro **) malloc(sizeof(micro *));
				}
				else
				{
					aux = (micro **) realloc(listado, sizeof(micro*)*(cant+1));
				}

				dato = (micro *) malloc (sizeof(micro));
				if ((dato != NULL) && (aux != NULL))
				{

					listado = aux;

//					char *strtok(char *s, const char *delim);
					dato->id = atoi(strtok(buffer, ","));

					tempo = strtok(NULL, ",");
					largo  = strlen (tempo);

					dato->nombre = (char *) malloc (largo+1);
					if (dato->nombre != NULL)
					{
						strcpy(dato->nombre, tempo);
						dato->nucleos = atoi(strtok(NULL, ","));
						dato->hilos = atoi(strtok(NULL, ","));
						dato->frec = atof(strtok(NULL, ","));
						strtok(NULL, ",");
						dato->uni_frec = 1000;
//						dato->uni_frec = convert(strtok(NULL, ","));
						dato->precio = atof(strtok(NULL, ","));
						*(listado+cant) = dato;
						cant++;
					}
					else
					{
						salida = ERR_MEM;
					}
				}
				else
				{
					salida = ERR_MEM;
				}
			}
                }
                while ((!feof(archivo)) && (salida == OK));
                fclose(archivo);

		for (i = 0; i < cant; i++)
		{
			printf("ID: %d\t", (listado[i])->id);
			printf("Nombre: %s\t", (listado[i])->nombre);
			printf("Nucleos: %d\t", (listado[i])->nucleos);
			printf("Frec: %f %d\t", (listado[i])->frec, listado[i]->uni_frec);
			printf("Precio: %f\n", (listado[i])->precio);
		}

        }
        else
        {
                printf("No se pudo abrir el archivo\n");
        }

	return salida;
}





