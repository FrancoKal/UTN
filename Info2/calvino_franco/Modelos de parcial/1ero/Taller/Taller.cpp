#include "Taller.h"

const string Taller::Tarea[] = {
    "C_Bujias",
    "Afinacion",
    "Embrague",
    "C_Amortiguadores"
};

const int Taller::Costo[20] = {
    2000,
    5000,
    8800,
    3500
};

ostream& operator<< (ostream& out, Taller& t)
{
    out << ">> Marca: " << t.Marca << "\n";
    out << ">> Modelo: " << t.Modelo << "\n";
    out << ">> Patente: " << t.Patente << "\n";
    out << ">> Hora de ingreso: " << t.h << "\n";

    return out;
}