#include <SharedMemory.h>

int SharedMemory::setShm(size_t size, int flags)
{
    int result = OK;

    if(keyExists())
    {
        ipc_id = shmget(key, size, IPC_CREAT | flags);

        if (ipc_id != -1)
        {
            setIdStatus(true);
            max_size = size;
            addr = shmat(ipc_id, nullptr, 0);

            if (addr == (void*) -1)
            {
                shmDelete();
                result = COULD_NOT_CREATE_SHM;
            }
        }
        else result = COULD_NOT_CREATE_SHM;
    }
    else result = KEY_NOT_EXISTS;

    return result;
}

int SharedMemory::deleteId()
{
    int result = OK;

    if (idExists())
    {
        if (shmctl(ipc_id, IPC_RMID, nullptr) == -1)
            result = COULD_NOT_DESTROY_SHM;
        else setIdStatus(false);
    }
    else result = ID_NOT_EXISTS;

    return result;
}

int SharedMemory::shmDettach()
{
    int result = OK;

    if (!isEmpty())
    {
        if (shmdt(addr) == -1)
            result = COULD_NOT_DEATTACH;
        else addr = nullptr;
    }
    else result = SHM_NOT_ALLOCATED;

    return result;
}

int SharedMemory::shmDelete()
{
    int result = shmDettach();

    if (result == OK)
    {
        result = deleteId();

        if (result == OK)
            result = deleteKey();
    }

    max_size = 0;

    return result;
}

int SharedMemory::shmWrite(void* data, size_t size)
{
    int result = OK;

    if (!isEmpty())
    {
        if (size < max_size)
            memcpy(addr, data, size);
        else result = SIZE_OVERFLOW;
    }
    else result = SHM_NOT_ALLOCATED;

    return result;
}

void* SharedMemory::shmRead(void *storage, size_t size)
{
    void *result = nullptr;

    if (storage != nullptr && !isEmpty())
        result =  memcpy(storage, addr, size);

    return result;
}

SharedMemory& SharedMemory::operator<< (void* data)
{
    shmWrite(data);

    return *this;
}
SharedMemory& SharedMemory::operator>>(void* storage)
{
    shmRead(storage);

    return *this;
}

