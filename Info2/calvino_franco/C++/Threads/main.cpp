#include "thread.h"
#include <iostream>

using namespace std;

void* Hola (void *p)
{
    int *x = (int*) p;
    cout << "¡Holaaa! Soy el 1er thread\n";
    (*x)++;
    cout << "x = " << *x << "\n";

    pthread_exit(x);
}

int main (void)
{
    int x = 0;
    Thread th1(Hola, &x), th2;

    if (th1.startThread() == OK)
        if (th1.joinThread() == OK)
            cout << "En el main, x = " << x << ". Y retval = " << *((int*) th1.getThreadResult()) << "\n";

    return 0;
}
