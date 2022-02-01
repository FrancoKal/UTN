#include "avion.h"

ostream& operator<< (ostream& out, const Avion& a)
{
    out << ">> Matricula: " << a.Matricula << "\tCia: " << a.Cia << "\n";

    return out;
}

Avion& Avion::operator= (const Avion& a)
{
    Matricula = a.Matricula;
    Cia = a.Cia;

    return *this;
}
