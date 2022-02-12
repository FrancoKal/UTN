#ifndef TALLER_H
#define TALLER_H

#include <string>
#include <iostream>
#include "Hora.h"

using namespace std;

class Taller
{
    private:
        string Marca, Modelo, Patente;
        Hora h;

    public:
        static const string Tarea[20];
        static const int Costo[20];

        //Taller() : Marca("SIN DATOS"), Modelo("SIN DATOS"), Patente("SIN DATOS"), h() {};
        Taller(const string& marca = "SIN DATOS", const string& modelo = "SIN DATOS", const string& pat = "SIN DATOS", int hora = 0, int min = 0) :
            Marca(marca), Modelo(modelo), Patente(pat), h(hora, min) {};

        friend ostream& operator<< (ostream&, Taller&);
};

#endif