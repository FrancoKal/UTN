#include "partida.h"

Partida& Partida::operator=(const Partida& part)
{
    /*(Avion&) *this = (const Avion&) part;*/ Avion::operator=((Avion&) part);
    Destino = part.Destino;
    Puerta = part.Puerta;
    H = part.H;

    return *this;
}

ostream& operator<< (ostream& out, const Partida& part)
{
    out << (Avion&) part;
    out << "\tDestino: " << part.Destino << "\n";
    out << "\tPuerta: " << part.Puerta << "\n";
    out << "\tHora: " << part.H << "\n"; // Me olvide agregar esto

    return out;
}
