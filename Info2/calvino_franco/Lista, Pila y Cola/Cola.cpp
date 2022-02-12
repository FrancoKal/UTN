#include "Cola.h"

void Cola::copy (const Cola& copia)
{
    NODO *i = copia.header;

    while (i != nullptr)
    {
        Push(i->dato);
        i = i->next;
    }
}

bool Cola::Push (void* x)
{
    NODO *nuevo = nullptr;/* *i = header;*/
    bool returnValue = false;

    nuevo = new NODO;

    if (nuevo != nullptr)
    {
        nuevo->dato = x;
        nuevo->next = nullptr;

        if (header == nullptr) //Si la lista esta vacia
            header = nuevo;
        /*else
        {
            while (i->next != nullptr)
                i = i->next;

            i->next = nuevo;
        }*/
        else last()->next = nuevo; //Recorro la lista hasta el ultimo y le inserto el nuevo valor

        returnValue = true;
    }

    return returnValue;
}

bool Cola::operator<< (int x)
{
	DATO D = {.valor = x};
	
	//return (*this << &D);
    return Push((void*) &D);
}

Cola& Cola::operator= (const Cola& copia)
{
    copy(copia);

    return *this;
}

ostream& operator<< (ostream& out, Cola& cola)
{
    DATO *value = nullptr;
    NODO *i = cola.header;

    out << ">> Imprimo lista desde H hasta nullptr: ";

    /*while (cola.header != nullptr)
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

istream& operator>> (istream& in, Cola& cola)
{
    DATO value;

    in >> value.valor;
    cola << &value;

    return in;
}

