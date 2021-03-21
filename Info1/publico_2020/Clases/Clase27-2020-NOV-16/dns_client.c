/*
** client.c -- Ejemplo de cliente de sockets de flujo
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

#define PORT 3490 				// puerto al que vamos a conectar
#define MAXDATASIZE 100 			// maximo numero de bytes que se pueden leer de una vez

int main(int argc, char *argv[])
{
	int sockfd, numbytes;
	char buf[MAXDATASIZE];
	struct sockaddr_in their_addr; // informacion de la direccion de destino
	int puerto = PORT;
	struct hostent *he;

	if (argc < 2 || argc > 3)
	{
		fprintf(stderr,"\nModo de uso: %s direccion [puerto]\n", argv[0]);
		exit(1);
	}

	if ((he = gethostbyname(argv[ 1 ])) == NULL) // obtener dirección IP de la máquina a partir del nombre
	{
		perror("gethostbyname");
		exit(1);
	}

	if (argc == 3)
	{
		puerto = atoi(argv[2]);
	}

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket");
		exit(1);
	}

	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(puerto);	// Me aseguro de ordenarlos en formato "red"
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	memset(&(their_addr.sin_zero), '\0' , 8);	// poner a cero el resto de la estructura

	if ( connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1 )
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
	printf( "\n\nRecibido: %s\n" , buf );

	if ( send( sockfd , "Wellcome!!\n" ,  11 ,  0 ) == -1 )
	{
		perror("send");
		close(sockfd);
		exit(1);
	}

	close(sockfd);

	return 0;
}
