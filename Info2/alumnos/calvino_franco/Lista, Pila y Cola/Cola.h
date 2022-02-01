#ifndef COLA_H
#define COLA_H

#include <iostream>
#include "Lista.h"

using namespace std;

class Cola : public Lista
{
    public:
        Cola () : Lista() {}/*{ header = nullptr; };*/
        Cola (const Cola& copia) : Lista() { copy(copia); };
        ~Cola () {};

        bool Push (void* x);
        bool operator<< (void* x) { return Push(x); }
        bool operator<< (int x);
        Cola& operator= (const Cola&);

        friend ostream& operator<< (ostream& out, Cola& cola);
        friend istream& operator>> (istream& in, Cola& cola);

    private:
        void copy (const Cola&);
};

#endif // COLA_H
