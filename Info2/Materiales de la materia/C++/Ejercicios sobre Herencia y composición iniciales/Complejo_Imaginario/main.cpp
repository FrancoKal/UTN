/*
  Nombre Proyecto: Imaginario
  Compilado sobre QTCreator 2.1.0
  Autor: Marcelo Horacio Giura
  Fecha: 01SET2011
  Claves: Herencia - sobrecarga operadores (miembros y friend) - sobrecarga cout
  
  Descripción: A partir de una clase llamada Complejo para la cual se ha defini-
  do numerosas sobrecarga de operadores, e realiza la herencia a una clase lla-
  mada Imaginario (parte real=0) y se comprueba la herencia en la sobrecarga.
  Observar el uso de las listas inicializadoras de miembros para transferir
  argumentos entre los objetos de la clase heredada y el constructor de la clase
  base
*/

using namespace std;
#include "imaginario.h"

int main()
{
    Complejo a(4,-2);
    cout << "Complejo a = " << a << endl;
    cout << a << " + " << 3.0 << " = " << a+3.0 << endl;
    cout << 3.0 << " + " << a << " = " << 3.0+a << endl << endl;

    Imaginario b = -2;
    cout << "Imaginario b = " << b << endl;
    cout << b << " + " << b << " = " << b+b << endl;
    cout << a << " - " << b << " = " << a-b << endl << endl;

    Complejo Z;
    cout << "Complejo Z = " << Z << endl;
    Z = b;
    cout << "Complejo Z (luego de Z=b) = " << Z << endl;
    Z = a;
    cout << "Complejo Z (luego de Z=a) = " << Z << endl;

}

//------------------------------------------------------------------------------
