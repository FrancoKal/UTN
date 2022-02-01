#ifndef COMPLEJO_H
#define COMPLEJO_H

    #include <iostream>
    using namespace std;

    class Complejo {
        protected://al declararlas protegidas,cuando se hereda públicamente siguen siendo
            double re, im; //protegidas en la clase derivada
        public:
            Complejo(double =0, double =0); /*Esta clase no tiene constructor por
defecto. A cambio tiene este constructor parametrizado con valores por defecto y
otro de copia. Recordar que los valores por defecto van siempre a la derecha de la lista.
En este caso, si hago Complejo(3), el compilador se lo asignará al primer argumento
quedando el 2do.argumento en cero.*/
            Complejo(const Complejo &c);

            //asignacion:
            Complejo& operator=(const Complejo &c);

            //suma: complejo+complejo
            Complejo operator+(const Complejo &c) const;
            //suma: double+complejo
            friend Complejo operator+(double d, const Complejo &c);

            //resta: complejo-complejo
            Complejo operator-(const Complejo &c) const;
            //resta: double-complejo
            friend Complejo operator-(double d, const Complejo &c);

            //producto: complejo*complejo
            Complejo operator*(const Complejo &c) const;
            //producto: double*complejo
            friend Complejo operator*(double d, const Complejo &c);

            //operador de cambio de signo:
            Complejo operator-() const;

            //operador de salida:
            friend ostream & operator<<(ostream &o, const Complejo &c);
    };

#endif // COMPLEJO_H








