#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

#define LARGO_MAX 60
#define PERMISOS 0666
#define EXIT 3

int main (void)
{
	char *chat[] = {"Hola ¿que tal?", "Ayer almorce ravioles", "¿Cual es el colmo de un mecanico?", "/exit"}, recibo[LARGO_MAX], fifo[] = "conversacion_de_locos.fifo";
	int estado, fd, opcion;// fifo_options[] = {O_WRONLY, O_RDONLY};
	//int (*accion[]) (int) = {escribir, leer};
	
	//mknod(fifo, S_IFIFO|PERMISOS,0);
	if (mkfifo(fifo, PERMISOS) != 0) //Si es distinto a 0, hubo algun error
	{
		if (errno != EEXIST)
		{
			printf("Error. No se pudo generar el FIFO\n");
			estado = -1;
		}
		else estado = 0;
	}
	
	if (estado == 0)
	{
		do
		{
			/*for (i = 0; i < 2 && opcion != EXIT; i++)
			{
				fd = open(fifo, fifo_options[i]);
				(fd == -1)? printf("No se pudo abrir el FIFO\n") : opcion = (accion[i])(fd);
			}*/
			
			fd = open(fifo, O_WRONLY);

			if (fd == -1)
			{
				printf("No se pudo abrir el FIFO\n");
			}
			else
			{
				srandom(time(NULL));
				opcion = rand() % 4;
				sleep(3);
				write(fd, chat[opcion], sizeof(chat[opcion])+1);
				close(fd);
				printf("%s\n", chat[opcion]);
			}
			
			if (opcion != EXIT)
			{		
				fd = open(fifo, O_RDONLY);
					
				if (fd == -1)
				{
					printf("No se pudo abrir el FIFO\n");
				}
				else
				{
					read(fd, recibo, sizeof(recibo));
					close(fd);
				}
			}
		}
		while (strcmp(recibo, "/exit") != 0 && opcion != EXIT);
	}

	return 0;
}
