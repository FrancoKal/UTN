#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <errno.h>

int main (void)
{
	char *comando[] = {"/refran", "/cancion", "/pelicula"}, fifo[] = "qcyo";
	int fd, opcion;
	
	//mknod(fifo, S_IFIFO|PERMISOS,0);
	if (mkfifo(fifo, PERMISOS) != 0) //Si es distinto a 0, hubo algun error
	{
		if (errno != EEXIST)
		{
			printf("Error. No se pudo generar el FIFO\n");
		}
		else
		{
			fd = open(fifo, O_WRONLY);
	
			if (fd == -1)
			{
				printf("No se pudo abrir el FIFO\n");
			}
			else
			{
				srandom(time(NULL));
				opcion = rand() % 3;
				write(fd, comando[opcion], sizeof(comando[opcion])+1);
				close(fd);
				printf("%s\n", comando[opcion]);
			}	
		}
	}

	return 0;
}
