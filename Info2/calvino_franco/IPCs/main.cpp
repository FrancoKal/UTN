#include <iostream>
#include <SharedMemory.h>

using namespace std;

int main(int argc, char *argv[])
{
    SharedMemory shm;
    char data[256], result[256];

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

    return 0;
}
