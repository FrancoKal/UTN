#ifndef SHAREDMEMORY_H
#define SHAREDMEMORY_H

#include <IPCs.h>
#include <sys/shm.h>
#include <string.h>

enum shm_errors {COULD_NOT_CREATE_SHM = -5, COULD_NOT_DESTROY_SHM = -6, COULD_NOT_DEATTACH = -7, SHM_NOT_ALLOCATED = -8, SIZE_OVERFLOW = -9};

class SharedMemory: public IPC
{
    public:
        SharedMemory() : addr(nullptr), max_size(0) {};
        ~SharedMemory() { shmDelete(); }

        int setShm(size_t size, int flags);
        bool isEmpty() { return addr == nullptr; }
        int shmWrite(void* data, size_t size);
        int shmWrite(void* data) { return shmWrite(data, max_size); }
        void* shmRead(void *storage, size_t size);
        void* shmRead(void *storage) { return shmRead(storage, max_size); }
        //void* shmRead();

    private:
        void *addr;
        size_t max_size;

        int deleteId();
        int shmDettach();
        int shmDelete();
};

#endif // SHAREDMEMORY_H
