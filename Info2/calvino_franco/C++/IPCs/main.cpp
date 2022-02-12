#include <iostream>
#include "SharedMemory.h"
#include "MessageQueue.h"

#define PERMISOS 0666

using namespace std;

int main(int argc, char *argv[])
{
    SharedMemory shm;
    MessageQueue msgq;
    MyMsgbuf buf;
    char data[256], result[256];

    /*  clase SharedMemory  */
    cout << "------- SharedMemory ---------\n";
    if (shm.setKey(argv[0], argc + 100) == OK)
    {
        cout << "keyExists: " << shm.keyExists() << "\n";

        if (shm.setShm(sizeof(data), 0666) == OK)
            cout << "isEmpty: " << shm.isEmpty() << "\n";

        cout << "Ingresa datos para copiar a la Shared Memory: ";
        cin.get(data, sizeof(data), '\n');
        cout << "Ingresaste: " << data << "\n";
        shm.shmWrite((void*) data, (size_t) strlen(data));
        shm.shmRead((void*) result);
        cout << "Resultado: " << result << "\n";
    }
    /*  ------------------- */

    cin.get();

    /*  clase MessageQueue  */
    cout << "------- MessageQueue ---------\n";
    if (msgq.setKey(argv[0], argc + 101) == OK)
    {
        cout << "keyExists: " << msgq.keyExists() << "\n";

        if (msgq.setMsgq(PERMISOS) == OK)
        {
            cout << "Ingresa datos para copiar a la Message Queue: ";
            cin.get(data, sizeof(data), '\n');
            cout << "Ingresaste: " << data << "\n";
            strcpy(buf.dato.msg, data);
            msgq.msgSend(&buf, sizeof(DATO));
            msgq >>&buf;
            cout << "Resultado: " << buf.dato.msg << "\n";
        }
    }
    /*  ------------------- */

    return 0;
}
