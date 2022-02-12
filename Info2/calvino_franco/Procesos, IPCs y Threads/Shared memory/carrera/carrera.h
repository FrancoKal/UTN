#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/sem.h>
#include <sys/wait.h>
#include <unistd.h>

struct sembuf lock = {.sem_num = 0, .sem_op = 1, .sem_flg = SEM_UNDO}; //tomar semaforo
struct sembuf unlock = {.sem_num = 0, .sem_op = -1, .sem_flg = SEM_UNDO}; //liberar semaforo

#define MY_ID 1234
#define PERMISOS 0666
#define HIJO 0
#define LOCK(semid) semop(semid, &lock, 1)
#define UNLOCK(semid) semop(semid, &unlock, 1)

union sem_union
{
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};

/*struct sembuf
{
    ushort sem_num;
    short sem_op;
    short sem_flag;
};*/