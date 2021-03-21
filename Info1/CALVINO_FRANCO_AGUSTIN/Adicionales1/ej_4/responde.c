#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LARGO_MAX 60
#define PERMISOS 0666
#define EXIT 3

int main (void)
{
	char *chat[] = {"Todo bien, y vos?", "Sabes que el viernes me encontre a tu amigo...", "Chau", "/exit"}, recibo[LARGO_MAX], fifo[] = "conversacion_de_locos.fifo";
	int fd, opcion;
	
	do
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
		if (strcmp(recibo, "/exit") != 0)
		{
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
		}
	}
	while (strcmp(recibo, "/exit") != 0 && opcion != EXIT);
	
	return 0;
}
