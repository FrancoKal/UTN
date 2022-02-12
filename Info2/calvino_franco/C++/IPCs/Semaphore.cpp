#include "Semaphore.h"

int Semaphore::createSem(int flags, int nsems)
{
    int result = OK;

    if(keyExists())
    {
        ipc_id = semget(key, nsems, IPC_CREAT | flags);

        if (ipc_id != -1)
            setIdStatus(true);
        else result = COULD_NOT_CREATE_SEMAPHORE;
    }
    else result = KEY_NOT_EXISTS;

    return result;
}

int Semaphore::setSem(int sem_count)
{
    int result = OK;

    if (idExists())
    {
        semaphore.val = sem_count;

        if (semctl(ipc_id, 0, SETVAL, semaphore) == -1)
            result = COULD_NOT_SET_SEMAPHORE;
    }
    else result = ID_NOT_EXISTS;

    return result;
}

int Semaphore::lock()
{
    int result = OK;

    if(idExists())
    {
        if (semop(ipc_id, &Lock, 1) == -1)
            result = COULD_NOT_LOCK_SEMAPHORE;
    }
    else result = ID_NOT_EXISTS;

    return result;
}

int Semaphore::unlock()
{
    int result = OK;

    if(idExists())
    {
        if (semop(ipc_id, &Unlock, 1) == -1)
            result = COULD_NOT_UNLOCK_SEMAPHORE;
    }
    else result = ID_NOT_EXISTS;

    return result;
}

int Semaphore::deleteSem()
{
    int result = OK;

    if (idExists())
    {
        if (semctl(ipc_id, IPC_RMID, 0) == -1)
            result = COULD_NOT_DELETE_SEMAPHORE;
        else setIdStatus(false);

        deleteKey();
    }
    else result = ID_NOT_EXISTS;

    return result;
}
