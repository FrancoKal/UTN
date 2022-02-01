#include "Hora.h"

void Hora::addMinutes (int m)
{
    /*while (m >= 60)
    {
        m -= 60;
        hora++;
    }
    
    if (m > 0)
        min += m;*/
    
    min += m % 60; //Le sumo a min el resto de la division por 60

    if (min >= 60)
    {
        min -= 60;
        addHours(); //hours++;
    }

    addHours(m/60); //hora += m / 60; Le sumo a hora la cantidad de veces que se puede dividir m por 60
}

void Hora::addHours (int h)
{
    hora += h % 24;

    if (hora >= 24)
        hora -= 24;
}

void Hora::setTime (int h, int m)
{
    hora = min = 0;
    addMinutes(m);
    addHours(h);
}

ostream& operator<< (ostream& out, const Hora& h)
{
    out << h.hora << ":" << h.min;

    return out; 
}

Hora& Hora::operator= (const Hora& h)
{
	setTime(h.hora, h.min);
	
	return *this;
}

Hora Hora::operator++(int) //Posincremento
{
	Hora h(*this);
	
	h.hora++;
	
	return h;
}
Hora& Hora::operator++() //Preincremento
{
	hora++;
	
	return *this;
}
