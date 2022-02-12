#include "Cola.h"
#include "Pila.h"

using namespace std;

int main (void)
{
    Cola A, B;
    Pila C, D;
    DATO a = {.valor = 5}, b = {.valor = 1}, c;

    if (A.isEmpty())
        cout << "La cola esta vacia!!\n";

    cout << "\t--- Probando la clase Cola ---\n";
    A << (void*) &a; //cola.Push((void*) &a);
    A << (void*) &b; //cola.Push((void*) &b);
    cout << "A " << A;
    cout << "Copio cola A a B con B = A\n";
    B = A;
    cout << "B " << B;
    cout << "Saco un dato de B: ";
    B.Pop(&c); //B >> &c;
    cout << c.valor << "\n";
    cout << B;

    cout << "\n\t--- Probando la clase Pila ---\n";
    C << &a;
    C << &b;
    //C << &c;
    cout << C;
    cout << "Copio pila C a D con D = C\n";
    D = C;
    cout << D;
    cout << "Saco un dato de C: ";
    C >> &c;
    cout << c.valor << "\n";
    cout << C;

    return 0;
}