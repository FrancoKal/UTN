#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/sem.h>
#include "semaforos.h"

struct sembuf p = { 0, -1, SEM_UNDO};
struct sembuf v = { 0, +1, SEM_UNDO};

int InicializarSemaforos( void )
{

    int key;

    /* Obtenemos la key para generar IPC System V*/
    if (( key = ftok( "/home" , 'C')) == -1)
    {
        perror("ftok");
        return -1;
    }

    /* Creacion del set de semaforos con solo 1  semaforo*/
    int id = semget( key, 1, 0666 | IPC_CREAT);
    union semun u;                                      /*Union para manippular el semaforo con semctl()*/

    if(id < 0)
    {
        perror("semget");
        return 1;
    }

    u.val = 1;

    /*Voy a inicializar el semaforo 0 del set creado con el valor 1*/
    if( semctl( id , 0 , SETVAL, u ) < 0 )
    {
        perror("semctl");
        return 1;
    }
    return id;
}
