#include "Viajes.h"
#include "Taxi.h"
#include "Pila.h"
#include "Lista.h"
#include <iostream>
#include <string>

using namespace std;

int main (void)
{
    Viajes v1("JUF425", 9800215, "Franco Calvino"), v2(v1);

    cout << v1;
    v1.set_viaje(34, 200);
    v2.set_viaje(120, 550);
    cout << v2;

    return 0;
}