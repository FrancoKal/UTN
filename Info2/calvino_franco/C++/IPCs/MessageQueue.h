#ifndef MESSAGEQUEUE_H
#define MESSAGEQUEUE_H

#include "IPCs.h"
#include <sys/msg.h>

typedef struct
{
    char msg[256];
} DATO;

typedef struct
{
    long mtype;
    DATO dato;
} MyMsgbuf;

enum msgq_errors {COULD_NOT_CREATE_MSGQ = -10, COULD_NOT_GET_MSGQ = -11, COULD_NOT_SEND_MSG = -12, COULD_NOT_RECV_MSG = -13, COULD_NOT_DESTROY_MSGQ = -14};

class MessageQueue: public IPC
{
    public:
        MessageQueue() : IPC(), max_size(sizeof(DATO)) {};
        ~MessageQueue() { msgqDelete(); }

        int setMsgq(int flags);
        int getMsgq(key_t new_key);
        //bool isEmpty();
        int msgSend(MyMsgbuf *data, size_t size, int flags = 0);
        int msgSend(DATO *data, size_t size, int flags = 0);
        int msgSend(MyMsgbuf *data) { return msgSend(data, max_size); }
        int msgSend(DATO *data) { return msgSend(data, max_size); }
        ssize_t msgRecv(MyMsgbuf *storage, size_t size, long type = 0, int flags = 0);
        ssize_t msgRecv(MyMsgbuf *storage) { return msgRecv(storage, max_size); }

        MessageQueue& operator<< (MyMsgbuf* data);
        MessageQueue& operator<< (DATO *data);
        MessageQueue& operator>>(MyMsgbuf* storage);

    private:
        size_t max_size;

        int deleteId();
        int msgqDelete();
};

#endif // MESSAGEQUEUE_H
