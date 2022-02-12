#include <stdio.h>
#include <stdlib.h>
#include <errno.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/wait.h>
#include <unistd.h>

#define MAX_LENGTH 256
#define MY_ID 1234
#define PERMISOS 0666
#define HIJO 0

int main (int argc, char *argv[])
{
    int shmid, msg_length;
    key_t key;
    char *shm_ptr = NULL;
    char data[MAX_LENGTH];
    int pid;

    printf("Vamos a mandar mensajitos de hijo a padre\n");

    key = ftok(argv[0], MY_ID);

    if (key == -1)
    {
        perror("ftok");
        exit(1);
    }

    /*  Creacion de memoria compartida  */
    shmid = shmget(key, sizeof(data), IPC_CREAT | PERMISOS);

    if (shmid == -1)
    {
        perror("shmget");
        exit(2);
    }
    /*  ------------------------------- */

    shm_ptr = (char*) shmat(shmid, NULL, 0);

    if (shm_ptr != NULL)
    {
        printf("Shared memory creada con exito. Comienza el mensajeo de padre a hijo...\n");
        pid = fork();

        switch (pid)
        {
            case -1:
                perror("fork");
                exit(3);
                break;
            
            case HIJO:
                sleep(2);
                printf("Soy el hijo. Escriba un mensaje para el padre...\n");
                fgets(data, sizeof(data), stdin);
                msg_length = strlen(data);
                data[msg_length-1] = '\0';
                memcpy(shm_ptr, data, msg_length);
                
                return 0;

            default:
                printf("Soy el padre, y espero el mensaje del hijo\n");
                wait(NULL);
                memcpy(data, shm_ptr, sizeof(data));
                printf("Recibido '%s'\n", data);
        }
    }

    if (shmdt(shm_ptr) == -1)
    {
        perror("shmdt");
        exit(4);
    }

    if (shmctl(shmid, IPC_RMID, NULL) == -1)
    {
        perror("shmctl");
        exit(5);
    }

    return 0;
}
