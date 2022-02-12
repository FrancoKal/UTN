#include "ipc.h"

IPC::IPC(char *pathname, char id, bool destroy) : llave(0), borrar(false), KeyExists(false)
{
    borrar = destroy;// No se honestamente para que debo usar la variable destroy

    if (pathname != nullptr)
        generateKey(pathname, id);

}
IPC::~IPC()
{
    deleteKey();
}

bool IPC::generateKey(char *pathname, char id)
{
    bool result = OK;

    if (!KeyExists)
    {
       llave = ftok(pathname, id);

       if (llave != (key_t) 0)
        KeyExists = true;
    }
    else result = ERROR;

    return result;
}

bool IPC::deleteKey()
{
    bool result = OK;

    if (KeyExists)
    {
        llave = 0;
        KeyExists = false;
    }
    else result = ERROR;

    return result;
}


