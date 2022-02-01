#include <IPCs.h>

IPC::~IPC()
{
    deleteKey();
    setIdStatus(false);
}

int IPC::setKey(char*& pathname, int id)
{
    int result = OK;

    if (!KeyExists)
    {
       key = ftok(pathname, id);

       if (key != (key_t) -1)
        KeyExists = true;
    }
    else result = KEY_ALREADY_EXISTS;

    return result;
}

int IPC::deleteKey()
{
    int result = OK;

    if (KeyExists)
    {
        key = -1;
        KeyExists = false;
    }
    else result = KEY_NOT_EXISTS;

    return result;
}

void IPC::setIdStatus(bool status)
{
    IpcIdExists = status;

    if (status == false)
        ipc_id = -1;
}
