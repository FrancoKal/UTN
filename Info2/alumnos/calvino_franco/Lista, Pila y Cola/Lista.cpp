#include "Lista.h"
#include <iostream>
#include <string.h>

void Lista::clean ()
{
    while (header != nullptr)
        //delete last(); Esto NO porque ya los elimino en la funcion Pop()
        Pop();
}

NODO*& Lista::last ()
{
    NODO *initialHeader = header; //No debo perder el header
    NODO* &i = header; //Guardo una referencia a NODO*

    while (i->next != nullptr) //Voy hasta el ultimo
        i = i->next;

    header = initialHeader;

    return i;
}

bool Lista::Pop (void* x)
{
    NODO *i = header;
    bool returnValue = false;

    if (header != nullptr)
    {
        if (x != nullptr)
            //x = header->dato; Al hacer esto, guardo en x un puntero que pertenece al header, que luego es eliminado. Por lo que x queda apuntando a la nada
            memcpy(x, header->dato, sizeof(DATO)); //Guardo un dato en x 

        header = header->next; //Paso el header al siguiente
        delete i; //Elimino el header anterior
        returnValue = true;
    }

    return returnValue;
}

Lista& Lista::operator>> (void *x)
{
    Pop(x);

    return *this;
}


