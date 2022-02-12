#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <errno.h>
#include <sys/wait.h>

#include <unistd.h>
#define SHM_SIZE 102  /* redondea a  1024 */

int ConectarSharedMemori( char ** Vagon)
{
    int shmid , key;

    /* Obtenemos la key para generar IPC System V*/
    if (( key = ftok( "/home" , 'B')) == -1)
    {
        perror("ftok");
        return -1;
    }

    // Crea el segmento y falla si ya existe (IPC_CREAT | IPC_ECL)
    shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT| IPC_EXCL);

    // Si ya existe crea otro segmento
    if ( errno==EEXIST )
    {
        if ((shmid = shmget(key, SHM_SIZE, 0644 | IPC_CREAT)) < 0 )
            return -1;
    }

    /* Enganchar el segmento a nuestro puntero */
    *Vagon = shmat( shmid , NULL , 0 );
    if ( *Vagon == (char *) (-1) )
    {
        perror("shmat");
        return -1;
    }

    return shmid;
}
