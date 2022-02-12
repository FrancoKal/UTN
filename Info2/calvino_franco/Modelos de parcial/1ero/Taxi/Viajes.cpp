#include "Viajes.h"

#define GANANCIA_AGENCIA 30/100

void Viajes::set_viaje (int duracion, int precio)
{
   DATO nuevo = {
       .duracion_viaje = duracion,
       .precio = precio
    };

    pila << &nuevo; 
}

void Viajes::liquidacion (int *ganancia_agencia, int *ganancia_chofer)
{
    int total = 0;
    DATO buffer;

    while (!pila.isEmpty())
    {
        pila >> &buffer; //Guardo el dato de un viaje en un buffer (y a la vez saco ese dato de la Pila, liberando memoria)
        total += buffer.precio; //Sumo al total el precio de cada viaje obtenido de la pila
    }

    *ganancia_agencia = total * GANANCIA_AGENCIA;
    *ganancia_chofer = total - (*ganancia_agencia);
}

ostream& operator<< (ostream& out, Viajes& viajes)
{
    out << (Taxi&) viajes; // Reutilizo el operator<< ya creado en la clase base Taxi
    out << viajes.pila; // Reutilizo el operator<< ya creado para lla clase Pila

    return out;
}