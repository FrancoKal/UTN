#ifndef REPARACION_H
#define REPARACION_H

#include "Taller.h"

class Reparacion : public Taller
{
    private:
        struct Arreglo
        {
            int Indice, Cant;
        } *Trabajos;

        int cant_arreglos;
        int Costo_tot;

    public:
        Reparacion () : Taller(), Trabajos(nullptr), cant_arreglos(0), Costo_tot(0) {};
        Reparacion (const string& marca, const string& modelo, const string& pat, int hora, int min, int indice, int cant);/* :
            Taller(marca, modelo, pat, hora, min) {};*/

        friend ostream& operator<< (ostream&, Reparacion&);

        void Tarea(int, int);
        int agregar(Arreglo nueva_tarea);
        int getIndice (int posicion) { return Trabajos[posicion].Indice; }
        int getCantRepuestos (int posicion)  { return Trabajos[posicion].Cant; }
        int getCostoTrabajo (int posicion);
};

#endif