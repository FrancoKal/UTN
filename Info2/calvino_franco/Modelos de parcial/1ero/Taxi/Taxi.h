#ifndef TAXI_H
#define TAXI_H

#include <string>
#include <iostream>

using namespace std;

class Taxi
{
    private:
        string Patente;
        long Licencia;
        string ApeNomChofer;

    /*protected:
        void mostrar_datos();*/

    public:
        Taxi() {};
        Taxi(Taxi& t) { *this = t; };
        Taxi(string Pat, long lic, string ApeNom) { set_datos(Pat, lic, ApeNom); }
        ~Taxi() {};

        void set_datos(string Pat, long lic, string ApeNom);
        Taxi& operator= (Taxi& t);
        friend ostream& operator<< (ostream&, Taxi&);
};

#endif