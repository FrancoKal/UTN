#include "imaginario.h"

Imaginario::Imaginario(double i) : Complejo(0,i)
{}

Imaginario::Imaginario(const Imaginario & c) : Complejo(0, c.im)
{}

//Lo tengo que hacer pues NO SE HEREDA
Imaginario& Imaginario::operator=(const Imaginario &c)
{
    re=0;
    im=c.im;
    return *this;
}

