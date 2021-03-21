#include "funciones.h"
#include <stdlib.h>
#include <string.h>

int menu (void)
{
	int opcion;

	printf("0. VIAJES\n1. ACTUALIZACION\n2. SALIR\nElija el numero de operacion:\n");
	scanf("%i", &opcion);

	if (opcion < VIAJES || opcion > SALIR)
	{
		printf("Error. Elija una opcion valida\n");
	}

	return opcion;
}

int ingresar_nuevos (clientes ***v)
{
	int i, cant, estado = OK;
	clientes **nuevos = NULL;
	char buffer_tel[LARGO_MAX], buffer_nom[LARGO_MAX], buffer_dir[LARGO_MAX];
	
	printf("Cantidad de viajes a ingresar ---> ");
	scanf("%i", &cant);
	
	if (cant > 0)
	{
		//printf("Ingrese en el siguiente orden: <TELEFONO> <NOMBRE Y APELLIDO> <DIRECCION> <IMPORTE>\n");
		
		for (i = 0; i < cant && estado == OK; i++)
		{
			nuevos = (i == 0)? (clientes **) malloc (sizeof(clientes *)) : (clientes **) realloc (nuevos, sizeof(clientes *) * (i+1));
			
			if (nuevos != NULL)
			{
				nuevos[i] = (clientes *) malloc (sizeof(clientes));

				if (nuevos[i] != NULL)
				{
					getchar();
					printf("\nTel.: ");
					fgets(buffer_tel, sizeof(buffer_tel), stdin);
					buffer_tel[strlen(buffer_tel) - 1] = '\0';
					printf("Nombre y apellido: ");
					fgets(buffer_nom, sizeof(buffer_nom), stdin);
					buffer_nom[strlen(buffer_nom) - 1] = '\0';
					printf("Direccion: ");
					fgets(buffer_dir, sizeof(buffer_dir), stdin);
					buffer_dir[strlen(buffer_dir) - 1] = '\0';
					(nuevos[i])->tel = (char *) malloc (sizeof(buffer_tel));
					(nuevos[i])->nombre = (char *) malloc (sizeof(buffer_nom));
					(nuevos[i])->direccion = (char *) malloc (sizeof(buffer_dir));
					
					if ((nuevos[i])->tel != NULL && (nuevos[i])->nombre != NULL && (nuevos[i])->direccion != NULL)
					{
						strcpy((nuevos[i])->tel, buffer_tel);//(nuevos[i])->tel = buffer_tel;
						strcpy((nuevos[i])->nombre, buffer_nom);//(nuevos[i])->nombre = buffer_nom;
						strcpy((nuevos[i])->direccion, buffer_dir);//(nuevos[i])->direccion = buffer_dir;
						printf("Importe: ");
						scanf("%f", &((nuevos[i])->importe));
					}
					else estado = ERROR_MEMORIA;
				}
				else estado = ERROR_MEMORIA;
			}
			else estado = ERROR_MEMORIA;
		}
		
		if (estado == OK) *v = nuevos;
	}
	
	return i;	
}

int registrar_viajes (clientes ***v, FILE *archivo)
{
        clientes **aux = NULL, buffer;
        int i = 0;

	do
	{
		//fscanf(archivo, "%s\t%s\t%s\t%i\t%f", &buffer.tel, &buffer.nombre, &buffer.direccion, &buffer.viajes, &buffer.importe);
		fread(&buffer, sizeof(clientes), 1, archivo);

		if (feof(archivo) == 0)
		{
			aux = (i == 0)? (clientes **) malloc (sizeof(clientes *)) : (clientes **) realloc (aux, sizeof(clientes *) * (i+1));

			if (aux != NULL)
			{
				aux[i] = (clientes *) malloc (sizeof(clientes));

				if (aux[i] != NULL)
				{
					(*aux)[i] = buffer;
					i++;
				}
				else i = ERROR_MEMORIA;
			}
			else i = ERROR_MEMORIA;

		}
	}
	while (feof(archivo) == 0 && i != ERROR_MEMORIA);

	if (i != ERROR_MEMORIA) *v = aux; //v = &aux;

	return i;
}

void escribir_nuevos (clientes **nuevos, int cant_nuevos, clientes **listado, int cant, FILE *archivo)
{
	int i, j;
	
	do
	{
		printf("TELEFONO\tNOMBRE Y APELLIDO\tDIRECCION\tIMPORTE\n");
			
		for (i = 0; i < cant_nuevos; i++) // Antes de anotar a un nuevo cliente, debo verificar si ya estaba registrado. Debo revisar todo el vector antes de escribirlo
		{
			for (j = 0; j < cant; j++)
			{
				if (strcmp((nuevos[i])->tel, (listado[j])->tel) == 0 && (listado[j])->viajes == 10) /*Debo tambien fijarme por cada nuevo registro (o actualizacion) la 															cantidad de viajes realizados. Si es 10, el siguiente es gratis*/
				{
					(nuevos[i])->importe = 0;
				}
				
				fprintf(archivo, "%s\t%s\t%s\t%0.2f", (nuevos[i])->tel, (nuevos[i])->nombre, (nuevos[i])->direccion, (nuevos[i])->importe);
				((listado[j])->viajes)++;
				(listado[j])->importe += (nuevos[i])->importe;
			}
		}
	}
	while (feof(archivo) == 0);

}

/*void actualizar (clientes **nuevos, int cant_nuevos, FILE *archivo)
{
	int i, j = 0, cant;
	char tel_buffer[LARGO_MAX];
	FILE *nuevo_archivo = NULL;
	clientes **buffer = NULL;
	
	cant = registrar_viajes(&buffer, archivo);
	fclose(archivo);
	
	if (cant > 0)
	{
		nuevo_archivo = fopen(REGISTROS_FILENAME, "w");
		
		for (j = 0; j < cant; j++)
		{
			for (i = 0; i < cant_nuevos; i++)
			{
				if (strcmp((nuevos[i])->tel, (buffer[j])->tel) == 0)
				{
					fprintf(archivo, "%s\t%s\t%s\t%0.2f", (nuevos[i])->tel, (nuevos[i])->nombre, (nuevos[i])->direccion, (buffer[j])->viajes + 1,
										 (nuevos[i])->importe + (buffer[j])->importe);
				}
			}
		}
	}
}*/

void liberar_nuevos (clientes ***nuevos, int cant_nuevos)
{
	int i;
	
	for (i = 0; i < cant_nuevos; i++)
	{
		free(((*nuevos)[i])->tel);
		free(((*nuevos)[i])->nombre);
		free(((*nuevos)[i])->direccion);
		free((*nuevos)[i]);
	}
	
	free(*nuevos);
}


