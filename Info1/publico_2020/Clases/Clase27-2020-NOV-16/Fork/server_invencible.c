/*
** server.c -- Ejemplo de servidor de sockets de flujo
*/
#include <stdio.h>
#include <time.h>
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

#define MYPORT 	3490 		// Puerto al que conectaran los usuarios
#define BACKLOG 10 		// Cuantas conexiones pendientes se mantienen en cola

/***************************************************************/
void sigchld_handler(int s)
{
	while(waitpid(-1,NULL,WNOHANG)>0);
}
/***************************************************************/

/***************************************************************/
void sigint_likegod(int s)
{
	printf("Yo tengo el poder, no me podés terminar.\n");
}
/***************************************************************/

int main(void)
{
	int sockfd, new_fd; 		// Escuchar sobre sock_fd, nuevas conexiones sobre new_fd
	struct sockaddr_in my_addr; 	// informacion sobre mi direccion
	struct sockaddr_in their_addr;	// informacion sobre la direccion del cliente
	socklen_t sin_size;
	struct sigaction sa;
	int yes = 1;
	int i, numbytes;
	int cant_num, max_num, dato;
	char msgrcv[100] = "";

	srandom(time(NULL));

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
	my_addr.sin_port = htons( MYPORT ); 		// Me aseguro de ordenarlos en formato "red"
	my_addr.sin_addr.s_addr = htonl( INADDR_ANY ); 	// Rellenar con mi direccion IP
	memset(&(my_addr.sin_zero), '\0', 8); 		// Poner a cero el resto de la estructura

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

	sa.sa_handler = sigchld_handler; // Eliminar procesos muertos
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if ( sigaction( SIGCHLD , &sa , NULL ) == -1 ) 
	{
		perror("sigaction");
		exit(1);
	}

	sa.sa_handler = sigint_likegod; // Ignoro el control-c
	sigemptyset(&sa.sa_mask);
	sa.sa_flags = SA_RESTART;
	if ( sigaction( SIGINT , &sa , NULL ) == -1 ) 
	{
		perror("sigaction");
		exit(1);
	}


	printf("Se ha iniciado el servidor para generar números aleatorios. UIJA!!!!!!!\n");

	sin_size = sizeof( struct sockaddr_in );

	while( 1 ) // main accept() loop
	{
		printf("Esperando conexiones....\n\n");

		// Gracias por llamar al puerto 3490.
		if ( ( new_fd = accept( sockfd , (struct sockaddr *)&their_addr, &sin_size)) == -1) 
		{
			perror("accept");
			continue;
		}
		printf("server: Se recibió una conexión del cliente %s\n", inet_ntoa(their_addr.sin_addr));

		if ( !fork( ) ) // Este es el proceso hijo *******************************************
		{
			close(sockfd); 				// El hijo no necesita este descriptor

			if ( send( new_fd , "Usted ha accedido al servidor de generación de números aleatorios\n" , strlen("Usted ha accedido al servidor de generación de números aleatorios\n"), 0) == -1 )
				perror("send");


			if ( ( numbytes = recv(new_fd, (int *) &cant_num, sizeof(int), 0) ) == -1 ) 
			{
				perror("recv");
				exit(1);
			}

			if ( ( numbytes = recv(new_fd, (int *) &max_num, sizeof(int), 0) ) == -1 ) 
			{
				perror("recv 1");
				exit(1);
			}

			for (i=0; i<cant_num; i++)
			{
				dato = random()%max_num;
				if ( ( numbytes = send(new_fd, (int *) &dato, sizeof(int), 0) ) == -1 ) 
				{
					perror("recv 1");
					exit(1);
				}
				sleep(1);
			}

			if ( ( numbytes = recv(new_fd, msgrcv, strlen("Gracias"), 0) ) == -1 ) 
			{
				perror("recv 3");
				exit(1);
			}

			if (strcmp(msgrcv, "Gracias")) printf("Que maleducado\n");
			else printf("server: Se desconectó el cliente %s\n", inet_ntoa(their_addr.sin_addr));

			close(new_fd);

			exit(0); 
		}
		//**************************************************************************************

		close( new_fd ); 				// El proceso padre no lo necesita
	}
	return 0;
}
