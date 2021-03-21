#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

#define LARGO_MAX 10

int main (void)
{
	int i, fd, opcion;
	char fifo[] = "qcyo", buffer[LARGO_MAX], *comando[] = {"/refran", "/cancion", "/pelicula"}, *respuestas[3][3] = {
				{"Mas vale ser cabeza de raton que cola de leon", "Si hay trato, pueden ser amigos hasta perro y gato", "Lo que no te mata te hace mas fuerte"}, //Refranes
				{"'Smooth Criminal'- Michael Jackson ","'Without me'- Eminem", "'Clocks'- Coldplay"}, //Canciones
				{"El caballero de la noche", "Shrek", "Volver al futuro"}}; //Peliculas
				
	fd = open(fifo, O_RDONLY);
	
	if (fd == -1)
	{
		printf("No se pudo abrir el FIFO\n");
	}
	else
	{
		srandom(time(NULL));
		read(fd, buffer, sizeof(buffer));
		
		for (i = 0; i < 3 && strcmp(comando[i], buffer) != 0; i++)
		
		opcion = rand() % 3;
		write(fd, respuestas[i][opcion], sizeof(respuestas[i][opcion]));
		printf("%s\n", respuestas[i][opcion]);
		close(fd);
	}
				

	return 0;
}
