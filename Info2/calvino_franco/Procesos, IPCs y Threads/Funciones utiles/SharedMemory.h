#include "IPCs.h"
#include <sys/shm.h>

typedef struct
{
    IPC_data data;
    size_t size;
    int shmflag;
    void *addr;
} SharedMemory;

//void createSharedMemory (SharedMemory shm);
SharedMemory createSharedMemory (key_t key, size_t size, int flags);
void shmWrite (SharedMemory shm, void *data, size_t size);
void* shmRead (SharedMemory shm, void *storage, size_t size);
void shmDelete (SharedMemory *shm);