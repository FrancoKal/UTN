/*
  Nombre: CLASEempleadoFecha-Composicion.cpp
  Compilado sobre QTCreator 2.1.0
  Autor: Deitel&Deitel adaptado por mhGiura
  Fecha: 31/jul/11
  Claves:
  Descripción: Demonstrating composition--an object with member objects.
  */

#include <iostream>
using namespace std;
#include "Employee.h" // Employee class definition

int main()
{
   Date birth( 7, 24, 1949 );
   Date hire( 3, 12, 1988 );
   Employee manager( "Bob", "Blue", birth, hire );

   cout << endl;
   manager.print();

   cout << "\nTest Date constructor with invalid values:\n";
   Date lastDayOff( 14, 35, 1994 ); // invalid month and day
   cout << endl;
   return 0;
} // end main
