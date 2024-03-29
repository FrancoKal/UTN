#ifndef LISTA_H
#define LISTA_H

#include "datos.h"

typedef struct nodo
{
	void *dato;
	struct nodo *next;
} NODO;

class Lista
{
    protected:
        NODO *header;

        NODO*& last ();
        void clean ();

    public:
        Lista() : header(nullptr) {};
        //Lista(const Lista&) : header(nullptr) {};
        ~Lista() { clean(); }

        bool Pop (void* x = nullptr);
        Lista& operator>> (void *x);
        bool isEmpty() const { return header == nullptr; }
};

#endif
