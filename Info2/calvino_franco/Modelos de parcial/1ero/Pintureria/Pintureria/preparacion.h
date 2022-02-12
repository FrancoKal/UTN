#ifndef PREPARACION_H
#define PREPARACION_H

#include "color.h"

class Preparacion : public Color
{
    private:
        float costo; //Costo total de la preparacion
        int litros;
        static int cant;

    public:
        Preparacion() : Color(), costo(0), litros(0) {};
        Preparacion(const Preparacion& prep) { *this = prep; }
        Preparacion(const Color& c, int l = 0) : Color(c), costo(0), litros(l) {};
        Preparacion(int rojo, int verde, int azul, char *nombre, float precio, int l) : Color(rojo, verde, azul, nombre, precio), litros(l) {};
        ~Preparacion();

        void set_costo(float);
        float get_litros() { return litros; }

        Preparacion& operator= (const Preparacion&);
        Preparacion& operator++(); //Pre-incremento
        Preparacion operator++(int); //Post-incremento
        friend istream& operator>> (istream&, Preparacion&);
};

#endif // PREPARACION_H
