#include "punto.h"

//Los debo inicializar en el .cpp para que no se creen multiples copias de las variables al incluir el .h mas de una vez
size_t Punto::CantCreada = 0, Punto::CantExistente = 0;
float Punto::min_ = -DEFAULT_LIMIT, Punto::max_ = DEFAULT_LIMIT;

Punto::Punto(double x, double y)
{
    setPunto(x,y);
    CantCreada++;
    CantExistente++;
}

Punto::Punto(const Punto& p)
{
    setPunto(p);
    CantCreada++;
    CantExistente++;
}

void Punto::setPunto(const Punto& p)
{
    setPunto(p.mx, p.my);
}

Punto& Punto::operator= (const Punto &p)
{
    setPunto(p);

    return *this;
}

Punto Punto::operator+ (const Punto& p)
{
    return Punto(mx + p.mx, my + p.my);
}

Punto Punto::operator- (const Punto& p)
{
    return Punto(mx - p.mx, my - p.my);
}

Punto& Punto::operator++ () //pre-incremento ++p
{
    //mx++; Si hago esto, no verifico los limites, y podria pasarme
    //my++;
    setPunto(mx + 1, my + 1);

    return *this;

}

Punto Punto::operator++ (int) //pos-incremento p++
{
    Punto p(*this); //Creo una copia

    ++(*this); //setPunto(mx + 1, my + 1);

    return p; //Retorno la copia con el valor anterior
}

bool Punto::operator== (const Punto& p)
{
    return (mx == p.mx && my == p.my);
}

bool Punto::operator!= (const Punto& p)
{
    return !(*this == p);
}

bool Punto::operator> (const Punto& p)
{
    return distance(mx, my) > distance(p.mx, p.my);
}

bool Punto::operator< (const Punto& p)
{
    return !(*this > p);
}

ostream& operator<< (ostream& out, Punto& p)
{
    out << "< " << p.mx << " ; " << p.my << " >";

    return out;
}

istream& operator>> (istream& in, Punto& p)
{
    double x, y;
    in >> x;
    in >> y;
    p.setPunto(x, y);

    return in;
}

double Punto::CheckInput(double x)
{
    if (x > (double) max_)
        x = (double) max_;
    else if (x < (double) min_)
        x = (double) min_;

    return x;
}

float distance (double x, double y)
{
    return sqrt(x*x + y*y);
}

void Punto::set_limites (float min, float max)
{
    if (max > min)
    {
        min_ = min;
        max_ = max;
    }
}
