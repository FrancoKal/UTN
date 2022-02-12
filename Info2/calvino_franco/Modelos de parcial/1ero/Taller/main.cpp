#include "Reparacion.h"

int main (void)
{
    Reparacion M1("Citroen", "C3", "ABX642", 8, 45, 1, 4);
    Reparacion M2("Ford", "Fiesta", "LOY457", 9, 20, 2, 2);

    cout << "----- M1 -----\n";
    cout << M1;
    M1.Tarea(3,1);
    M1.Tarea(2,2);
    cout << M1;
    cout << "\n----- M2 -----\n";
    cout << M2;
    M2.Tarea(1, 1);
    cout << M2;

    return 0;

}