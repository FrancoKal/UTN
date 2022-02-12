#include <MessageQueue.h>

int MessageQueue::setMsgq(int flags)
{
    int result = OK;

    if(keyExists())
    {
        ipc_id = msgget(key, IPC_CREAT | flags);

        if (ipc_id != -1)
            setIdStatus(true);
        else result = COULD_NOT_CREATE_MSGQ;
    }
    else result = KEY_NOT_EXISTS;

    return result;
}

int MessageQueue::getMsgq(key_t new_key)
{
    int result = OK;

    ipc_id = msgget(new_key, 0);

    if (ipc_id != -1)
    {
        key = new_key;
        setIdStatus(true);
    }
    else result = COULD_NOT_GET_MSGQ;

    return result;
}

int MessageQueue::msgSend(MyMsgbuf *data, size_t size, int flags)
{
    int result = OK;

    if (idExists())
    {
        if (size > max_size || msgsnd(ipc_id, data, (size < max_size)? size : max_size, flags) == -1)
            result = COULD_NOT_SEND_MSG;
    }
    else result = ID_NOT_EXISTS;

    return result;
}

int MessageQueue::msgSend(DATO *data, size_t size, int flags)
{
    MyMsgbuf buf = {.mtype = 1, .dato = *data};

    return msgSend(&buf, size, flags);
}

ssize_t MessageQueue::msgRecv(MyMsgbuf *storage, size_t size, long type, int flags)
{
    ssize_t result = OK;

    if (idExists())
    {
        if (storage != nullptr && size < max_size)
        {
            result = msgrcv(ipc_id, storage, size, type, flags);

            if (result == -1)
                result = COULD_NOT_RECV_MSG;
        }
        else result = COULD_NOT_RECV_MSG;
    }
    else result = ID_NOT_EXISTS;

    return result;
}

int MessageQueue::deleteId()
{
    int result = OK;

    if (idExists())
    {
        if (msgctl(ipc_id, IPC_RMID, nullptr) == -1)
            result = COULD_NOT_DESTROY_MSGQ;
        else setIdStatus(false);
    }
    else result = ID_NOT_EXISTS;

    return result;
}

int MessageQueue::msgqDelete()
{
    int result = deleteId();

    if (result == OK)
        result = deleteKey();

    max_size = 0;

    return result;
}

MessageQueue& MessageQueue::operator<< (MyMsgbuf* data)
{
    msgSend(data);

    return *this;
}

MessageQueue& MessageQueue::operator<< (DATO *data)
{
    msgSend(data);

    return *this;
}

MessageQueue& MessageQueue::operator>>(MyMsgbuf* storage)
{
    msgRecv(storage);

    return *this;
}
