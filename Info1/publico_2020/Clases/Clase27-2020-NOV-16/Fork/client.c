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
#define COLU 8

int main(int argc, char *argv[])
{
	int sockfd, numbytes, i;
	char buf[MAXDATASIZE];
	struct hostent *he;
	struct sockaddr_in their_addr; // informacion de la direccion de destino
	FILE * resu;
	int cant_num, max_num, dato;
	char nombre[256];

	if (argc != 2)
	{
		fprintf(stderr,"\nusage: client hostname\n");
		exit(1);
	}

	sprintf(nombre,"numeros_%d.dat",getpid());

	resu = fopen(nombre,"w");
	if(!resu) 
	{
		perror("abriendo archivo");
		exit(1);
	}

	printf("Bienvenido al cliente de generación de archivo con número aleatorios.\n");
	printf("Ingrese la cantidad de números aleatorios que desea: ");
	scanf("%d",&cant_num);
	printf("Ingrese el valor máximo: ");
	scanf("%d",&max_num);

	if ((he = gethostbyname(argv[ 1 ])) == NULL) // obtener dirección IP de la máquina a partir del nombre
	{
		perror("gethostbyname");
		exit(1);
	}

	if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
	{
		perror("socket");
		exit(1);
	}

	their_addr.sin_family = AF_INET;
	their_addr.sin_port = htons(PORT);	// Me aseguro de ordenarlos en formato "red"
	their_addr.sin_addr = *((struct in_addr *)he->h_addr);
	memset(&(their_addr.sin_zero), 0 , 8);	// poner a cero el resto de la estructura

	if ( connect(sockfd, (struct sockaddr *)&their_addr, sizeof(struct sockaddr)) == -1 )
	{
		perror("connect");
		exit(1);
	}

	if ( ( numbytes = recv(sockfd, (char *) buf, MAXDATASIZE-1, 0) ) == -1 ) 
	{
		perror("recv");
		exit(1);
	}

	buf[numbytes] = '\0';
	printf( "\n\nReceived: %s\n" , buf );

	if ( ( numbytes = send(sockfd, (int *) &cant_num, sizeof(int), 0) ) == -1 ) 
	{
		perror("send");
		exit(1);
	}

	if ( ( numbytes = send(sockfd, (int *) &max_num, sizeof(int), 0) ) == -1 ) 
	{
		perror("send 1");
		exit(1);
	}

	for (i=0; i<cant_num; i++)
	{
		if ( ( numbytes = recv(sockfd, (int *) &dato, sizeof(int), 0) ) == -1 ) 
		{
			perror("recv 1");
			exit(1);
		}

		printf("%d: %d\t", i+1, dato);
		fflush(stdout);
		if (!(i%COLU)&&(i>0)) printf("\n");
		fprintf(resu,"%d: %d\n", i+1, dato);
	}

	printf("\n\n\n\nAgradezco y me voy\n");
	sleep(5);
	if ( ( numbytes = send(sockfd, "Gracias", strlen("Gracias"), 0) ) == -1 ) 
	{
		perror("send 3");
		exit(1);
	}

	close(sockfd);
	fclose(resu);

	return 0;
}
