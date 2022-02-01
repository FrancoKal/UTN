/*Programa de prueba de composición y herencia*/

using namespace std;
#include <iostream>
#include <string.h>
#include "fecha.h"
#include "persona.h"
#include "alumno.h"

int main(void)
{
    Fecha f1;
    Fecha f2(5,7,1964);
    Fecha f3 (f2);
    cout << "f1-" << f1 << "f2-" << f2 << "f3-" << f3 << endl;
    cin.get();
//---------------------------------------------
    f1.setFecha(9,8,1973);
    cout << "f1-" << f1 << endl;
    cin.get();
//---------------------------------------------
    Persona p1;
    Persona p2 ("Marcelo", 16566899, 5, 7, 1964);
    Persona p3 ("Gabriel", 21587779, f1);
    cout << endl;
    cout << "Persona1-> " << p1 << "Persona2-> " << p2
         << "Persona3-> " << p3<< endl;
    cin.get();
//---------------------------------------------
    Alumno a1;
    f1.setFecha(29, 2, 1996);
    f2.setFecha(15, 9, 2013);
    Alumno a2 (f2, 2, 135235);
    Alumno a3 ("Pepe", 32455788, f1, f2, 5, 134899);
    cout << endl;
    cout << "Alumno1-> " << a1 << "Alumno2-> " << a2
         << "Alumno3-> " << a3 << endl;
    cin.get();
//---------------------------------------------
    a2.setPersona("Manuel", 37852963, f1); //uso método heredado de Persona
    cout << endl;
    cout << "Alumno2-> " << a2 << endl;
    cin.get();
//---------------------------------------------
    a1 = a3;
    cout << endl;
    cout << "Alumno1-> " << a1 << endl;
    cin.get();
//---------------------------------------------
    return 0;
}
