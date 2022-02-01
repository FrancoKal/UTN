#include "complejo.h"
using namespace std;

Complejo::Complejo(double r, double i) : re(r), im(i) { }

Complejo::Complejo(const Complejo &c) : re(c.re), im(c.im) { }

Complejo& Complejo::operator=(const Complejo &c) {
    re=c.re; im=c.im;
    return *this;
}

Complejo Complejo::operator+(const Complejo &c) const {
    return Complejo(re+c.re, im+c.im);
}

//función global friend
Complejo operator+(double d,const Complejo &c) {
    return Complejo(d) + c;  //promuevo 'd' a Complejo (parte imag=0)
}                            // y luego sumo c.

Complejo Complejo::operator-(const Complejo &c) const {
    return Complejo(re-c.re, im-c.im);
}

Complejo operator-(double d,const Complejo &c) {
    return Complejo(d) - c;  //promuevo 'd' a Complejo (parte imag=0)
}                            // y luego resto c.

Complejo Complejo::operator*(const Complejo &c) const {
    return Complejo(re*c.re - im*c.im, re*c.im + c.re*im);
}

Complejo operator*(double d, const Complejo &c) {
    return Complejo(d) * c;  //promuevo 'd' a Complejo (parte imag=0 ver constructor)
}                            // y luego multiplico con c.

Complejo Complejo::operator-() const {
    return Complejo(-re, -im);
}

ostream & operator<<(ostream & canal, const Complejo & c) {
    canal << '(' << c.re;
    (c.im >= 0) ? canal << "+" : canal << " ";
    canal << c.im << "i" << ')' ;
    return canal;
}





















