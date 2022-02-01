#ifndef ALUMNO_H
#define ALUMNO_H

using namespace std;
#include <iostream>
#include <string.h>
#include "fecha.h"
#include "persona.h"

class Alumno : public Persona
{
private:
    Fecha fIngreso_;
    int carrera_;
    long legajo_;

public:
    Alumno();
    Alumno (const Fecha, const int, const long);
    Alumno (const char*, const long, const Fecha&, const Fecha&, const int, const long);
    Alumno (const Alumno&);
    ~Alumno(){}

    void set_Alumno (const char*, const long, const Fecha&, const Fecha&, const int c, const int);

    Fecha get_fIngreso () const {return fIngreso_;}
    int get_carrera () const {return carrera_;}
    long get_legajo () const {return legajo_;}

    Alumno& operator= (const Alumno&);

    friend ostream& operator<< (ostream&, const Alumno&);
    /* NO es necesario declarar la amistad del operator<< de Persona pues ese método (que se encuentra incluido en el operato<< de Alumno), no toca ningún atributo de esta última*/

};

#endif // ALUMNO_H
