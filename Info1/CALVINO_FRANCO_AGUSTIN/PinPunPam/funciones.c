#include "funciones.h"

int CargarDatos (dato ***lista)
{
	int i = 0;
	dato buffer;
	
	do
	{
		printf("Pid ---> ");
		scanf("%i", buffer.pid);
		printf("Productos ---> ");
		fgets(buffer.productos, 32, stdin);
		buffer.productos[strlen(buffer.productos) -1] = '\0';
		//getchar();
		printf("Cantidad vendida ---> ");
		scanf("%i", buffer.cantVendida);
		
		if (strcmp(buffer.productos, "STOP") != 0 && buffer.cantVendida != 0)
		{
			if (i == 0)
			{
				*lista = (dato**) malloc (sizeof(dato*));
			}
			else
			{
				*lista = (dato**) realloc (*lista, sizeof(dato*) * (i+1));
			}
			
			if (*lista != NULL)
			{
				(*lista)[i] = (dato*) malloc (sizeof(dato));
				
				if ((*lista)[i] != NULL)
				{
					*((*lista)[i]) = buffer;
					i++;
				}
			}
		}
	}
	while (strcmp(buffer.productos, "STOP") != 0 && buffer.cantVendida != 0);

	return i;
}

int CrearListadeFIFO (dato ***lista, int fd)
{
	dato buffer;
	int num, i = 0;
	
	do
	{
		if (strcmp(buffer.productos, "STOP") != 0 && buffer.cantVendida != 0)
		{
			if ((num = read(fd, &buffer, 1)) == -1)
			{
				perror("read");
			}
			else
			{
				if (i == 0)
				{
					*lista = (dato**) malloc (sizeof(dato*));
				}
				else
				{
					*lista = (dato**) realloc (*lista, sizeof(dato*) * (i+1));
				}
			
				if (*lista != NULL)
				{
					(*lista)[i] = (dato*) malloc (sizeof(dato));
				
					if ((*lista)[i] != NULL)
					{
						*((*lista)[i]) = buffer;
						i++;
					}
				}
			}
		}
	}
	while (strcmp(buffer.productos, "STOP") != 0 && buffer.cantVendida != 0);
	
	return i;

}

void Escribir (dato **lista, int cant, FILE *fp)
{
	int i;

	for (i = 0; i < cant; i++)
	{
		fprintf(fp, "%i, %s, %i", (*lista)[i].pid, (*lista)[i].productos, (*lista)[i].cantVendida);
	}
}

void liberar (dato ***lista, int cant, FILE *fp)
{
	int i;
	
	for (i = 0; i < cant; i++)
	{
	
	}

