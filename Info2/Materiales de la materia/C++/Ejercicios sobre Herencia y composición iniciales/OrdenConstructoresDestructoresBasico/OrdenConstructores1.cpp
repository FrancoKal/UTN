/*
   Nombre del Archivo: 1-Herencia.cpp
   Compilado sobre: Qt Creator 2.4.1
   Autor: Marcelo Horacio Giura
   Fecha: 01/09/12

   Descripción: Declaramos un objeto 'pepe' de una clase derivada 'B' que surgió
   de una clase base 'A'. Comprobamos el orden de ejecución de los constructores
   y los destructores.
*/

#include <iostream>
#include <iomanip>
using namespace std;

class A{ //la clase A solo tiene un constructor y un destructor
    public:
        A() {cout<< "constructor de la CB A"<<endl;}
        ~A() {cout<< "destructor de la CB A"<<endl;}
};

class B : public A{ //heredo públicamente la clase A
    public:    //la clase B solo tiene un constructor y un destructor
        B() {cout<< "constructor de la CD B"<<endl;}
        ~B() {cout<< "destructor de la CD B"<<endl;}
};

// -----------------------------------------------------------------------------
int main ( ){
   B pepe;     //solo construyo el objeto pepe.

   cout << endl;

   return 0;
}
















