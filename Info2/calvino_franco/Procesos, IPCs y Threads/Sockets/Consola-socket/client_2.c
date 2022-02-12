/*
** client.c -- Ejemplo de cliente de sockets de flujo
** Ingresar por línea de comando la dirección 127.0.0.1
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <netdb.h>
#include <sys/types.h>
#include <netinet/in.h>
#include <sys/socket.h>
#include <arpa/inet.h>

#define PORT 3490 					// puerto al que vamos a conectar
#define MAXDATASIZE 100 			// máximo número de bytes que se pueden leer de una vez

int main(int argc, char *argv[])
{
	struct in_addr addr;
	int sockfd, numbytes;
	char buf[MAXDATASIZE];
	struct sockaddr_in their_addr; // información de la dirección de destino
	
	if (argc != 2) 
	{
		fprintf(stderr,"usage: client hostname\n");
		exit(1);
	}
	
        if (inet_aton(argv[1], &addr) == 0) //Convierte la dirección IP dada en la notación de cifras y puntos en un unsigned long
	{
               fprintf(stderr, "Invalid address\n");
               exit(EXIT_FAILURE);
        }

	if ( (sockfd = socket(AF_INET, SOCK_STREAM, 0) ) == -1 ) 
	{
		perror("socket");
		exit(1);
	}

	//************** PREPARO LA ESTRUCTRA sockaddr_in ******************************************	
	their_addr.sin_family = AF_INET; 						// Ordenación de bytes de la máquina
	their_addr.sin_port = htons(PORT);						// short, Ordenación de bytes de la red
	their_addr.sin_addr = addr;
	memset(&(their_addr.sin_zero), 0 , 8); 						// poner a cero el resto de la estructura
	
	if ( connect( sockfd , (struct sockaddr *)&their_addr,	sizeof(struct sockaddr)) == -1 ) 
	{
		perror("connect");
		exit(1);
	}
	if ( ( numbytes = recv(sockfd, buf, MAXDATASIZE-1, 0) ) == -1 ) 
	{
		perror("recv");
		exit(1);
	}
	buf[numbytes] = '\0';
	printf( "Received: %s" , buf );
	close(sockfd);
	
	return 0;
}





