#ifndef SEMAPHORE_H
#define SEMAPHORE_H

#include "IPCs.h"
#include <sys/sem.h>

enum sem_errors {COULD_NOT_CREATE_SEMAPHORE = -15, COULD_NOT_SET_SEMAPHORE = -16,  COULD_NOT_LOCK_SEMAPHORE = -17, COULD_NOT_UNLOCK_SEMAPHORE = -18, COULD_NOT_DELETE_SEMAPHORE = -19};

union sem_union
{
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux specific) */
};

static struct sembuf Lock = {.sem_num = 0, .sem_op = 1, .sem_flg = SEM_UNDO}; //tomar semaforo
static struct sembuf Unlock = {.sem_num = 0, .sem_op = -1, .sem_flg = SEM_UNDO}; //liberar semaforo

class Semaphore: public IPC
{
    public:
        Semaphore() : IPC() {};
        ~Semaphore() {};

        int createSem(int flags, int nsems = 1);
        int setSem(int sem_count); //sem_count es el numero de procesos que podran acceder a la vez al recurso
        int deleteSem();
        int lock();
        int unlock();

    private:
        union sem_union semaphore;
};

#endif // SEMAPHORE_H
