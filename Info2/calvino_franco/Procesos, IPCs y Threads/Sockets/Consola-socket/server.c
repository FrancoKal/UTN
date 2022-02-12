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

#define MYPORT 	3490 					// Puerto al que conectar�n los usuarios
#define BACKLOG 10 					// Cu�ntas conexiones pendientes se mantienen en cola

void sigchld_handler(int s)
{
	while(wait(NULL) > 0);//cada vez que llega la se�al SIGCHLD, se ejecutar� esta rutina que ir� "matando" a los procesos zombies
}

int main(void)
{
	int sockfd, new_fd; 				// Escuchar sobre sock_fd, nuevas conexiones sobre new_fd
	struct sockaddr_in my_addr; 		// informaci�n sobre mi direcci�n
	struct sockaddr_in their_addr; 		// informaci�n sobre la direcci�n del cliente
	socklen_t sin_size;
	struct sigaction sa;
	int yes = 1;
	
	//************** ABRO EL SOCKET **************************************	
	if ( ( sockfd = socket( AF_INET , SOCK_STREAM , 0 ) ) == -1) 
	{
		perror("socket");
		exit(1);
	}

	//************** PROTECCION ******************************************
	/*En ocasiones, puedes encontrarte con que, al volver a ejecutar bind() en un servidor obtienes
	el error "Address already in use" (La direcci�n ya se est� usando). �Qu� significa? Bueno, una
	parte de un socket que estuvo conectado, est� todav�a colgando en el n�cleo y est�
	bloqueando el puerto. Puedes esperar a que se libere (alrededor de un minuto) o a�adirle
	c�digo a tu programa permitiendo reutilizar el puerto, de este modo:*/	
	
	if ( setsockopt( sockfd , SOL_SOCKET , SO_REUSEADDR , &yes , sizeof(int) ) == -1) 
	{
		perror("setsockopt");
		exit(1);
	}
	//************** PROTECCION ******************************************

	//************** PREPARO LA ESTRUCTRA sockaddr_in ******************************************
	my_addr.sin_family = AF_INET; 					// Ordenaci�n de bytes de la m�quina
	my_addr.sin_port = htons( MYPORT ); 				// short, Ordenaci�n de bytes de la red
	my_addr.sin_addr.s_addr = htonl( INADDR_ANY ); 		// INADDR_ANY coloca nuestra direcci�n IP autom�ticamente
	memset(&(my_addr.sin_zero), '\0', 8); 				// Poner a cero el resto de la estructura
	
	
	/* �En qu� puerto estoy? *******************************************************/
	if ( bind( sockfd , (struct sockaddr *)&my_addr, sizeof( struct sockaddr ) ) == -1 ) 
	{
		perror("bind");
		exit(1);
	}
	
	/* Por favor, que alguien me llame *********************************************/
	if ( listen( sockfd , BACKLOG ) == -1 ) 
	{
		perror("listen");
		exit(1);
	}

	//************** PREPARO LA INTERCEPCION DE LA SE�AL DEL HIJO QUE MUERE*****************
	sa.sa_handler = sigchld_handler; 	// Eliminar procesos zombies o detenidos
	sigemptyset(&sa.sa_mask);			// pone la mascara en cero
	sa.sa_flags = SA_RESTART;			/*Este flag controla qu� ocurre cuando la se�al llega mientras el proceso o el hilo 
	est�n dentro de ciertas llamadas al sistema como open(),read() o write(). Al estar activo permite que esas funciones
	continuen su ejecuci�n luego de procesada la se�al. SIno, sale por error.*/
	
	//************** INTERCEPTO LA SIGNAL *****************
	if ( sigaction( SIGCHLD , &sa , NULL ) == -1 ) 
	{
		perror("sigaction");
		exit(1);
	}
		
	while( 1 ) 
	{ 		
		sin_size = sizeof( struct sockaddr_in );	
		
		// Gracias por llamar al puerto 3490.
		if ( ( new_fd = accept( sockfd , (struct sockaddr *)&their_addr, &sin_size)) == -1) 
		{
			perror("accept");
			continue;
		}
		printf("server: got connection from %s\n",
		
		inet_ntoa(their_addr.sin_addr));
		
		if ( !fork( ) ) // Este es el proceso hijo *******************************************
		{ 	
			
			close(sockfd); 				// El hijo no necesita este descriptor
			
			// �H�blame, baby!
			if ( send( new_fd , "Hello, world!\n" ,  14 ,  0 ) == -1 )
				perror("send");
			
			close(new_fd);
			
			exit(0); 
		}
		//**************************************************************************************
		
		close( new_fd ); 				// El proceso padre no lo necesita
	}
	return 0;
}
