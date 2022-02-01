#ifndef COLA_H
#define COLA_H

#include "Pila.h"


class Cola : public Pila
{
public:
    bool Push (const DATO& D);
    friend istream& operator>> (istream&, Cola&);   //Permite operaciones de ingreso por teclado que encolan.

};

#endif // COLA_H
