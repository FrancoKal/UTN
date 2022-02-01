#ifndef FECHA_H
#define FECHA_H

using namespace std;
#include <iostream>


class Fecha
{
private:
    int dia_;
    int mes_;
    int anio_;

public:
    Fecha() {dia_=0; mes_=0; anio_=0;}
    Fecha(int d, int m, int a);
    Fecha (const Fecha&);
    ~Fecha(){}

    void setFecha (int, int, int);
    int get_dia () const {return dia_;}
    int get_mes () const {return mes_;}
    int get_anio () const {return anio_;}

    Fecha& operator= (const Fecha& f);
    friend ostream& operator<< (ostream&, const Fecha&);
};

#endif // FECHA_H
