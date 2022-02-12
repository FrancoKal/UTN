#include "Taxi.h"

void Taxi::set_datos (string Pat, long lic, string ApeNom)
{
    Patente = Pat;
    Licencia = lic;
    ApeNomChofer = ApeNom;
}

Taxi& Taxi::operator= (Taxi& t)
{
    set_datos(t.Patente, t.Licencia, t.ApeNomChofer);

    return *this;
}

ostream& operator<< (ostream& out, Taxi& t)
{
    out << ">> Nombre del chofer: " << t.ApeNomChofer << "\n";
    out << ">> Patente: " << t.Patente << "\n";
    out << ">> Licencia: " << t.Licencia << "\n";

    return out;
}