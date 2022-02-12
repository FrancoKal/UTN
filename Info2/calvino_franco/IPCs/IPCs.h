#ifndef IPCS_H
#define IPCS_H
#define OK 0

#include <errno.h>
#include <sys/types.h>
#include <sys/ipc.h>

enum key_errors {KEY_ALREADY_EXISTS = -1, KEY_NOT_EXISTS = -2};
enum ipc_id_errors {ID_ALREADY_EXISTS = -3, ID_NOT_EXISTS = -4};

class IPC
{
    public:
        IPC() : key(-1), ipc_id(-1), KeyExists(false), IpcIdExists(false) {};
        ~IPC();

        int setKey(char*& pathname, int id);
        key_t getKey() { return KeyExists ? key : (key_t) KEY_NOT_EXISTS; }
        int getId() { return IpcIdExists ? ipc_id : ID_NOT_EXISTS; }
        bool keyExists() { return KeyExists; }
        bool idExists() { return IpcIdExists; }

    protected:
        key_t key;
        int ipc_id;

        int deleteKey();
        void setIdStatus(bool status);

    private:
        bool KeyExists;
        bool IpcIdExists;
};

#endif // IPCS_H
