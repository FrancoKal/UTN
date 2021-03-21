/*
** server.c -- Ejemplo de servidor de sockets de flujo
*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/socket.h>
#include <netinet/in.h>
#include <arpa/inet.h>
#include <sys/wait.h>
#include <signal.h>

#define MYPORT 	3480 		// Puerto al que conectaran los usuarios
#define BACKLOG 10 		// Cuantas conexiones pendientes se mantienen en cola
#define MAXDATASIZE 100 	// maximo numero de bytes que se pueden leer de una vez

int main(void)
{
	int sockfd, new_fd; 		// Escuchar sobre sock_fd, nuevas conexiones sobre new_fd
	struct sockaddr_in my_addr; 	// informacion sobre mi direccion
	struct sockaddr_in their_addr; 	// informacion sobre la direccion del cliente
	socklen_t sin_size;
	int yes = 1, numbytes;
	char buf[MAXDATASIZE];


	if ( ( sockfd = socket( AF_INET , SOCK_STREAM , 0 ) ) == -1)
	{
		perror("socket");
		exit(1);
	}

	/*En ocasiones, puedes encontrarte con que, al volver a ejecutar bind() en un servidor obtienes
	el error "Address already in use" (La direccion ya se esta usando). Que significa? Bueno, una
	parte de un socket que estuvo conectado, esta todavia colgando en el nucleo y esta
	bloqueando el puerto. Puedes esperar a que se libere (alrededor de un minuto) o aniadirle
	codigo a tu programa permitiendo reutilizar el puerto, de este modo:*/

	if ( setsockopt( sockfd , SOL_SOCKET , SO_REUSEADDR , &yes , sizeof(int) ) == -1)
	{
		perror("setsockopt");
		exit(1);
	}

	my_addr.sin_family = AF_INET;
	my_addr.sin_port = htons( MYPORT ); 			// Me aseguro de ordenarlos en formato "red"
	my_addr.sin_addr.s_addr = htonl( INADDR_ANY ); 	// Rellenar con mi direccion IP
	memset(&(my_addr.sin_zero), '\0', 8); 			// Poner a cero el resto de la estructura

	/* En que puerto estoy? */
	if ( bind( sockfd , (struct sockaddr *)&my_addr, sizeof( struct sockaddr ) ) == -1 ) 
	{
		perror("bind");
		exit(1);
	}

	/* Por favor, que alguien me llame */
	if ( listen( sockfd , BACKLOG ) == -1 ) 
	{
		perror("listen");
		exit(1);
	}

	sin_size = sizeof( struct sockaddr_in );

	printf("Server iniciado. Me pongo a esperar una comunicación.\n");


	while(1)
	{
		// Gracias por llamar al puerto 3490.
		if ( ( new_fd = accept( sockfd , (struct sockaddr *)&their_addr, &sin_size)) == -1) 
		{
			perror("accept");
			exit(1);
		}

		printf("\n\nSERVIDOR: Se recibió una conexión desde %s y del puerto %d\n", inet_ntoa(their_addr.sin_addr), their_addr.sin_port);

		// Hablame, baby!
		if ( send( new_fd , "Hello, world!\n" ,  MAXDATASIZE ,  0 ) == -1 )
		{
			perror("send");
			close(new_fd);
			exit(1);
		}

		if ((numbytes = recv(new_fd, buf, MAXDATASIZE-1, 0)) == -1 )
		{
			perror("recv");
			close(new_fd);
			exit(1);
		}

		buf[numbytes] = '\0';
		printf( "\n\nMensaje recibido: %s\n\n" , buf );

		close(new_fd);
	}

	close(sockfd);

	return 0;
}
