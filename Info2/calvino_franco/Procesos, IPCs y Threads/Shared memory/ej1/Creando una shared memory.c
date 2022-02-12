/* 
 * Ejemplo de programa que crea o segmento de memoria
 */
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <unistd.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>

#define TAMANIO  	1024	//tamaño arbitrario de la shared mem. en bytes
#define PROJECT_ID	123	//numero arbitrario para ftok


int main()
{
	int shmid; 	// Identificador del segmento memoria
	char *pmen;	// puntero local para acceder a la shared memory	
	key_t key;	// clave del set de recuros obtenida desde ftok()
	
	// genero una clave para el set de recursos system V
	key = ftok("/tmp", PROJECT_ID);

	shmid = shmget(key, TAMANIO, IPC_CREAT | 0666);
	
	if ( shmid == -1 )
	{
		perror("shmget");   //sale por aquí en caso de error
     		exit(EXIT_FAILURE);
     	}
     
  
	printf(" Creado segmento de Memoria Compartida ID = %d\n", shmid);

	// Me engacho al segmento y escribo en el
	if ( (pmen = shmat(shmid,NULL,0)) == -1 )
	{
		perror("shmat"); 	//sale por aquí en caso de error
		exit(EXIT_FAILURE);
	}
 
	// Copio al segmento de memoria compartida un mensaje inicial
	strcpy(pmen,"VALORES INICIALES LA MEMORIA COMPARTIDA\n"); 


	// Me desengancho (DETTACH) al segmento
	shmdt(pmen);
	  
	exit(EXIT_SUCCESS);
}
