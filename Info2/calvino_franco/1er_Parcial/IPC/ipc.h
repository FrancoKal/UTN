#ifndef IPC_H
#define IPC_H

#include <sys/ipc.h>
#include <sys/types.h>

#define OK true
#define ERROR false

class IPC
{
    protected:
        key_t llave;
        bool borrar;
        bool KeyExists;

        bool generateKey(char *p = nullptr, char a = 0);
        bool deleteKey();

    public:
        IPC(char *p = nullptr, char a = 0, bool destroy = false);
        ~IPC();

        key_t getKey(void) const { return llave; }
        void borrarAlFinal(bool);

        static const int DISCONNECTED = -1;
};

#endif // IPC_H
