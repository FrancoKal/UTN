#include "Pila.h"

bool Pila::Push (void *x)
{
    NODO *nuevo = nullptr, *i = header;
    bool returnValue = false;

    nuevo = new NODO;

    if (nuevo != nullptr)
    {
        nuevo->dato = x;
        nuevo->next = header;
        header = nuevo;
        returnValue = true;
    }

    return returnValue;
}

ostream& operator<< (ostream& out, Pila& pila)
{
    DATO *value = nullptr;
    NODO *i = pila.header;

    out << ">> Imprimo lista desde H hasta nullptr: ";

    /*while (cola.header != nullptrptr)
    {
        if (cola.Pop((void*) &value) == true) 
            out << "Valor: " << value.valor << "\n";
    }*/

    while (i != nullptr)
    {
        value = (DATO*) i->dato;
        out << value->valor;
        out << ((i->next == nullptr)? "\n" : ", ");
        i = i->next;
    }

    return out;
}

istream& operator>> (istream& in, Pila& pila)
{
    DATO value;

    in >> value.valor;
    pila << &value;

    return in;
}

void Pila::copy (const Pila& p)
{
    NODO *ultimo = nullptr, *i = nullptr;

    clean();

    do
    {
        i = p.header; //Voy al principio

        while (i->next != nullptr && i->next != ultimo) //Voy al ultimo (la 1era vez) y luego voy hasta 1 menos que la ultima vez
            i = i->next;

        ultimo = i; //Me guardo el ultimo de esta ronda
        Push(i->dato); //Ingreso el ultimo
    }
    while (ultimo != p.header); //Mientras el ultimo no sea el header, entonces tengo aun datos antes por ingresar
}

Pila& Pila::operator= (const Pila &p)
{
    copy(p);

    return *this;
}

