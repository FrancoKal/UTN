/**
	\file    main2.c
	\brief   Rutina principal (main) del programa
	\author  Calvino, Franco (francoc.2002@gmail.com)
	\date    2020.11.30
	\version 1.0.0
*/


//--------------
//-- Includes --
//--------------
#include "funciones2.h"


/**
	\fn      int main (---)
	\brief   <Función de la función>
	\author  Calvino, Franco (francoc.2002@gmail.com)
	\date    2020.11.30
	\param   <Parámetro A (si no tiene no se pone)>
	\param   <Parámetro B (si no tiene no se pone)>
	\return  0
*/

int main (int cant_args, char* arg[])
{
	int cant_cods_pedida, cant_recibidos, *cods = NULL, puerto = DEFAULT_PORT, sockfd, numbytes, i, num_recibido;
	char mensaje[LARGO_MAX];
	DATOS *listado = NULL, buffer_final = {0, 0, 0};
	struct in_addr direc;
	struct sockaddr_in destino;
	
	if (cant_args < 3 || cant_args > 4)
	{
		fprintf(stderr,"\nModo de uso: %s <archivo> <IP o server_name> [puerto]\n", arg[0]);
		exit(1);
	}

	if (inet_aton(arg[2], &direc) == 0)
	{
		fprintf(stderr, "Dirección invalida\n");
		exit(1);
	}
	
	if (cant_args == 4) puerto = atoi(arg[3]);
	
	cant_cods_pedida = solicitar_codigos(&cods);
		
	if (cant_cods_pedida > 0 && cods != NULL)
	{
		cant_recibidos = generacion (cods, cant_cods_pedida, &listado, arg[1]);
		free(cods);
			
		if (cant_recibidos > 0 && listado != NULL)
		{
			if ((sockfd = socket(AF_INET, SOCK_STREAM, 0)) == -1)
			{
				perror("socket");
				exit(1);
			}
	
			destino.sin_family = AF_INET;
			destino.sin_port = htons(puerto);
			destino.sin_addr = direc;
			memset(&destino.sin_zero, '\0' , 8);
	
			if (connect(sockfd, (struct sockaddr *) &destino, sizeof(struct sockaddr)) == -1)
			{
				perror("connect");
				exit(1);
			}
					
			if ((numbytes = recv(sockfd, mensaje, LARGO_MAX-1, 0)) == -1) 
			{
				perror("recv");
				exit(1);
			}
	
			mensaje[LARGO_MAX-1] = '\0';
			
			if (strcmp(mensaje, "OK") == 0)
			{
				printf("\nRecibido: %s. Comienza la transmision de datos...\n" , mensaje);
				
				for (i = 0; i < cant_recibidos; i++)
				{
					if (send(sockfd, &(listado[i]) , sizeof(DATOS), 0) == -1 )
					{
						perror("send");
						exit(1);
					}
					
					if ((numbytes = recv(sockfd, &num_recibido, sizeof(int), 0)) == -1) 
					{
						perror("recv");
						exit(1);
					}
					
					printf("Enviado: cod: %i, importe: %f, existencia: %li\tRecibido: %i\n", (listado+i)->codigo, (listado+i)->peso, (listado+i)->existencia, num_recibido);
				}
				
				if (send(sockfd, &buffer_final , sizeof(DATOS), 0) == -1 )
				{
					perror("send");
					exit(1);
				}
					
				if ((numbytes = recv(sockfd, mensaje, LARGO_MAX-1, 0)) == -1) 
				{
					perror("recv");
					exit(1);
				}
				
				mensaje[LARGO_MAX-1] = '\0';
					
				if (strcmp(mensaje, "Transmision finalizada") == 0)
				{
					printf("Finalizada la transmision de datos\n");
					sleep(5);
				}
					
				close(sockfd);
			}
			
			free(listado);
		}
	}
	
	return 0;
}

