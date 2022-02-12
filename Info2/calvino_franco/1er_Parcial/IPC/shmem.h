#ifndef SHMEM_H
#define SHMEM_H

#include "ipc.h"
#include <sys/shm.h>
#include <sys/sem.h>
#include <string.h>

struct sembuf Lock = {.sem_num = 0, .sem_op = 1, .sem_flg = SEM_UNDO}; //tomar semaforo
struct sembuf Unlock = {.sem_num = 0, .sem_op = -1, .sem_flg = SEM_UNDO}; //liberar semaforo

union sem_union
{
    int              val;    /* Value for SETVAL */
    struct semid_ds *buf;    /* Buffer for IPC_STAT, IPC_SET */
    unsigned short  *array;  /* Array for GETALL, SETALL */
    struct seminfo  *__buf;  /* Buffer for IPC_INFO (Linux-specific) */
};

#define TAM 256
#define PERMISOS 0666

//enum shm_errors {COULD_NOT_CREATE_SHM = -2, COULD_NOT_DESTROY_SHM = -3, COULD_NOT_DEATTACH = -4, COULD_NOT_ATTACH = -5, SHM_NOT_ALLOCATED = -6, SIZE_OVERFLOW = -7};

class ShMem : public IPC
{
    private:
        int id_shmem, id_sem;
        char *buffer;
        int size;
        sem_union semaforo;

        void bloquearShMem();
        void desbloquearShMem();
        bool shmAttach();
        bool shmDettach();
        bool deleteSem();
        bool setSem(int sem_count);
        bool createSem(int flags, int nsems = 1);
        bool deleteShm();

    public:
        ShMem(char *p = nullptr, char a = 0, int tam = TAM, bool destroy = false);
        ShMem(const ShMem&);
        ~ShMem();

        bool conectar(char*, char);
        bool conectar(char*, char, int);
        int getID(void) const { return id_shmem; }
        int getSize(void) const { return size; }
        bool isEmpty() { return buffer == nullptr; }

        bool esccribirMensaje(void *msj, int cant, int pos = 0);
        int leerMensaje(void *buf, int pos = 0, int cant = TAM);
};

#endif // SHMEM_H
