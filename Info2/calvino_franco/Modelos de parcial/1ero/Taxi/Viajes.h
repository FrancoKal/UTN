#ifndef VIAJES_H
#define VIAJES_H

#include "Taxi.h"
#include "Pila.h"

class Viajes: public Taxi
{
    private:
        Pila pila;

    public:
        Viajes() /*: pila()*/ {}
        Viajes(string Pat, long lic, string ApeNom, int duracion = 0, int precio = 0) : /*pila(),*/ Taxi(Pat, lic, ApeNom) { set_viaje(duracion, precio); }
        ~Viajes() {}

        void set_viaje (int duracion, int precio);
        void liquidacion (int *ganancia_agencia, int *ganancia_chofer);

        friend ostream& operator<< (ostream&, Viajes&);
};

#endif