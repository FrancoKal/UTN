#include "SharedMemory.h"

#define PERMISOS 0666
#define MAX_SIZE 256

int main (int argc, char *argv[])
{
    SharedMemory shm = {.addr = NULL};
    key_t key;
    char data[] = "Holaaaaaa", buffer[MAX_SIZE];

    key = createKey(argv[0], argc + 123);
    shm = createSharedMemory(key, MAX_SIZE * sizeof(char), PERMISOS);

    if (shm.addr != NULL)
    {
        shmWrite(shm, data, sizeof(data));
        shmRead(shm, buffer, sizeof(data));
        printf("Leido: '%s'\n", buffer);
    }

    shmDelete(&shm);
    printf("Ahora shm = %p\n", shm.addr);

    return 0;
}