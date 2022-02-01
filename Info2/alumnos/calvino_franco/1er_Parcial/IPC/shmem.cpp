#include "shmem.h"

ShMem::ShMem(char *pathname, char id, int tam, bool destroy) : IPC(pathname, id, destroy), id_shmem(IPC::DISCONNECTED), id_sem(IPC::DISCONNECTED), buffer(nullptr), size(0)
{
    borrar = destroy; // No se honestamente para que debo usar la variable destroy

    if (conectar(pathname, id, tam) == OK)
        borrar = true;
}

ShMem::~ShMem()
{
    if (borrar == true)
    {
        deleteSem();
        shmDettach();
        deleteShm();
        borrar = false;
    }
}

bool ShMem::conectar(char *pathname, char id, int sz)
{
    bool result = OK;

    if (id_shmem == IPC::DISCONNECTED)
    {
        if (!KeyExists) //Como la llave ya es generada al inicializar el IPC, no necesariamente debo crearla de nuevo
            result = generateKey(pathname, id);

        if(result == OK)
        {
            id_shmem = shmget(llave, sz, IPC_CREAT | PERMISOS);

            if(id_shmem != -1 && createSem(PERMISOS) == OK)
            {
                size = sz;

                if (shmAttach() == OK && setSem(1) == OK)
                    desbloquearShMem();
                else result = ERROR;
            }
            else result = ERROR;
        }
    }
    else result = ERROR;

    return result;
}

bool ShMem::shmAttach()
{
    bool result = OK;

    if (isEmpty())
    {
        buffer = (char*) shmat(id_shmem, nullptr, 0);

        if (buffer == (void*) -1)
        {
            result = ERROR;
        }
    }
    else result = ERROR;

    return result;
}

bool ShMem::shmDettach()
{
    bool result = OK;

    if (!isEmpty())
    {
        if (shmdt(buffer) == -1)
            result = ERROR;
        else buffer = nullptr;
    }
    else result = ERROR;

    return result;
}

bool ShMem::createSem(int flags, int nsems)
{
    bool result = OK;

    if(id_sem == IPC::DISCONNECTED)
    {
        id_sem = semget(llave, nsems, IPC_CREAT | flags);

        if (id_sem == -1)
            result = ERROR;
    }
    else result = ERROR;

    return result;
}

bool ShMem::setSem(int sem_count)
{
    bool result = OK;

    if (id_sem != IPC::DISCONNECTED)
    {
        semaforo.val = sem_count;

        if (semctl(id_sem, 0, SETVAL, semaforo) == -1)
            result = ERROR;
    }
    else result = ERROR;

    return result;
}

void ShMem::bloquearShMem()
{
    if(id_shmem != IPC::DISCONNECTED && id_sem != IPC::DISCONNECTED)
        semop(id_sem, &Lock, 1);
}

void ShMem::desbloquearShMem()
{
    if(id_shmem != IPC::DISCONNECTED && id_sem != IPC::DISCONNECTED)
        semop(id_sem, &Unlock, 1);
}

bool ShMem::deleteSem()
{
    bool result = OK;

    if (id_sem != IPC::DISCONNECTED)
    {
        if (semctl(id_sem, IPC_RMID, 0) == -1)
            result = ERROR;
        else id_sem = IPC::DISCONNECTED;
    }
    else result = ERROR;

    return result;
}

bool ShMem::deleteShm()
{
    bool result = OK;

    if (id_shmem != IPC::DISCONNECTED)
    {
        if (shmctl(id_shmem, IPC_RMID, 0) == -1)
            result = ERROR;
        else id_shmem = IPC::DISCONNECTED;
    }
    else result = ERROR;

    return result;
}
