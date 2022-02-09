#include "funciones.h"

int main (void)
{
	FILE *fp = NULL;
	dato **lista = NULL;
	int fd, cant;
	
	mkfifo(FIFO_NAME, 0660);
	printf("Esperando escritores...\n");	
	fd = open(FIFO_NAME, O_RDONLY);
		
	if (fd != -1)
	{
		cant = CrearListadeFIFO(&lista, fd);
		
		if ((fp = fopen(FILE_NAME, "a")) != NULL)
		{
			Escribir(lista, cant, fp);
			fclose(fp);
		}
		
		liberar(&lista, cant);
	}
	
	close(fd);

	return 0;
}
