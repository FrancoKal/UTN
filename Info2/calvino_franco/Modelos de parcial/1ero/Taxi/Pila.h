/*
  Name: 
  Copyright: 
  Author: 
  Date: 14/11/10 18:17
  Description: 
*/

#ifndef PILA_H
#define PILA_H

#include "Lista.h"
#include <iostream>

using namespace std;

class Pila : public Lista
{
	public:
    	Pila () : Lista() {}
    	Pila (const Pila& p) : Lista() { copy(p); }
        ~Pila () {}

    	bool Push (void*);//ingreso datos a la PILA

    	bool operator<< (void* x) { return Push(x); }
        friend ostream& operator<< (ostream&, Pila&);   //imprime la Pila desde H hasta el NULL
    	//friend istream& operator>> (istream&, Pila&);   //Permite operaciones de ingreso por teclado que encolan.
        Pila& operator= (const Pila&);  


    private:
        void copy (const Pila&);
};

#endif
