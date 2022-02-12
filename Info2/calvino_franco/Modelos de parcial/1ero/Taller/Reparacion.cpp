#include "Reparacion.h"

Reparacion::Reparacion (const string& marca, const string& modelo, const string& pat, int hora, int min, int indice, int cant) :
    Taller(marca, modelo, pat, hora, min), Trabajos(nullptr), cant_arreglos(0), Costo_tot(0)
{
    Tarea(indice, cant);
}

void Reparacion::Tarea (int indice, int cant_repuestos)
{
    Arreglo nueva_tarea = {.Indice = indice, .Cant = cant_repuestos};

    agregar(nueva_tarea);
    Costo_tot += Costo[indice] * cant_repuestos;
    //cout << *this;
}

int Reparacion::agregar (Arreglo nueva_tarea) // Agrega nueva tarea al arreglo
{
    int i, previousSize = cant_arreglos;
    Arreglo *t = nullptr;

    t = new Arreglo[cant_arreglos + 1];

    if (t != nullptr)
    {
        for(i = 0; i < cant_arreglos; i++)
            t[i] = Trabajos[i];

        t[cant_arreglos] = nueva_tarea;
        cant_arreglos++;

        if (Trabajos != nullptr)
            delete Trabajos;

        Trabajos = t;
    }

    return previousSize;
}

int Reparacion::getCostoTrabajo (int posicion)
{
    int index = 0, cost = 0;

    if (posicion >= 0 && posicion < cant_arreglos)
    {
        index = Trabajos[posicion].Indice; // getIndice(posicion);
        cost = Costo[index] * Trabajos[posicion].Cant; // Costo[index] * getCantRepuestos(posicion)
    }

    return cost;
}

ostream& operator<< (ostream& out, Reparacion& r)
{
    int i, index;

    out << (Taller&) r;

    for (i = 0; i < r.cant_arreglos; i++)
    {
        index = r.getIndice(i);
        cout << "\tTarea realizada: " << Taller::Tarea[index] << "\t|\t Costo parcial: " << r.getCostoTrabajo(i) << "\n";
    }

    return out;
}