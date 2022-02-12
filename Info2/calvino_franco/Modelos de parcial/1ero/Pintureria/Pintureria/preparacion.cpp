#include "preparacion.h"

int Preparacion::cant = 0;

void Preparacion::set_costo(float precio)
{
    Color::set_costo(precio);
    Preparacion::costo = get_costo() * litros;
}

Preparacion& Preparacion::operator= (const Preparacion& prep)
{
    (Color&) *this = (Color&) prep; // Color::operator=(prep);
    litros = prep.litros;
    Preparacion::costo = prep.Preparacion::costo;

    return *this;
}
Preparacion& Preparacion::operator++() //Pre-incremento
{
    litros++;

    return *this;
}

Preparacion Preparacion::operator++(int) //Post-incremento
{
    Preparacion aux(*this);

    litros++;

    return aux;
}

istream& operator>> (istream& in, Preparacion& prep)
{
    in >> (Color&) prep;
    cout << "\tLitros de preparacion: ";
    in >> prep.litros;

    return in;
}
