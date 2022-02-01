using namespace std;
#include <iostream>
#include "fecha.h"
#include "persona.h"
#include "alumno.h"

Alumno::Alumno()
    :Persona(), fIngreso_()
{
    carrera_ = 0;
    legajo_ = 0;
}

Alumno::Alumno (const Fecha f, const int c, const long leg)
    :Persona(), fIngreso_(f){
    carrera_ = c;
    legajo_ = leg;
}

Alumno::Alumno (const char* nya, const long dni, const Fecha& fCumple, const Fecha& fInicio, const int c, const long leg):Persona(nya, dni, fCumple), fIngreso_(fInicio){
    carrera_ = c;
    legajo_ = leg;
}

Alumno::Alumno (const Alumno& a):Persona (a), fIngreso_(a.fIngreso_){
    carrera_ = a.carrera_;
    legajo_ = a.legajo_;
}

void Alumno::set_Alumno (const char* nya, const long dni, const Fecha& fCumple, const Fecha& fInicio, const int c, const int leg){
    Persona::setPersona(nya, dni, fCumple);
    fIngreso_ = fInicio;
    carrera_ = c;
    legajo_ = leg;
}

Alumno& Alumno::operator =(const Alumno& a){
    Persona::operator= (a);
    fIngreso_ = a.fIngreso_;
    carrera_ = a.carrera_;
    legajo_ = a.legajo_;
    return *this;
}

ostream& operator<< (ostream& o, const Alumno& a){
    o << (Persona&) a;
    o << "\tCarrera: " << a.carrera_<< endl;
    o << "\tLegajo:  " << a.legajo_ << endl;
    o << "\tFecha de ingreso: " << a.fIngreso_ << endl;
    return o;
}

