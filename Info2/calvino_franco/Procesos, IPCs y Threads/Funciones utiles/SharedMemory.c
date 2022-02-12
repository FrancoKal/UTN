#include "SharedMemory.h"

/*void createSharedMemory (SharedMemory shm)
{
    shm.ipc_data.ipc_id = shmget(shm.ipc_data.key, shm.size, shm.shmflag);

    if (shm.ipc_data.ipc_id == -1)
    {
        perror("msgget");
        exit(2);
    }

    return OK;
}*/

SharedMemory createSharedMemory (key_t key, size_t size, int flags)
{
    SharedMemory shm = {
        .data.key = key,
        .size = size,
        .data.ipc_id = shmget(key, size, IPC_CREAT | flags) 
    };

    if (shm.data.ipc_id == -1)
    {
        perror("shmget");
        exit(2);
    }

    shm.addr = shmat(shm.data.ipc_id, NULL, 0);

    return shm;
}

void shmWrite (SharedMemory shm, void *data, size_t size)
{
    if (shm.addr != NULL && data != NULL)
        memcpy(shm.addr, data, size <= shm.size ? size : shm.size); //Copio hasta shm.size bytes a shm.addr
}

void* shmRead (SharedMemory shm, void *storage, size_t size)
{
    if (shm.addr != NULL)
        memcpy(storage, shm.addr, size <= shm.size ? size : shm.size);

    return storage;
}

void shmDelete (SharedMemory *shm)
{
    if (shmdt(shm->addr) == -1)
    {
        perror("shmdt");
        exit(4);
    }

    shm->addr = NULL;

    if (shmctl(shm->data.ipc_id, IPC_RMID, NULL) == -1)
    {
        perror("shmctl");
        exit(5);
    }
}