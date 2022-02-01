#ifndef LSE_H
#define LSE_H

#include "Pila.h"

class LSE : public Pila
{
public:
//    LSE();
    bool enlistar (DATO&);
//    friend istream& operator>>(istream& , LSE&);
    friend ostream& operator<< (ostream&, const LSE&);   //imprime la Pila desde H hasta el NULL


private:
    bool insertar (NODO*, DATO&);
};

#endif // LSE_H
