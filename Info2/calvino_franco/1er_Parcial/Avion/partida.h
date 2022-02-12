#ifndef PARTIDA_H
#define PARTIDA_H

#include "avion.h"
#include "String.h"
#include "Hora.h"

class Partida : public Avion
{
    private:
        String Destino;
        int Puerta;
        Hora H;

    public:
        Partida(const Partida& part) : Avion() { *this = part; }
        Partida(String dest = "a definir", int puerta = -1) : Avion(), Destino(dest), Puerta(puerta), H() {};
        Partida(String dest, int puerta, Hora h) : Avion(), Destino(dest), Puerta(puerta), H(h) {};
        ~Partida() {};

        void set_destino (const String& dest) { Destino = dest; }

        Partida& operator=(const Partida&);
        friend ostream& operator<< (ostream&, const Partida&);
};

#endif // PARTIDA_H
