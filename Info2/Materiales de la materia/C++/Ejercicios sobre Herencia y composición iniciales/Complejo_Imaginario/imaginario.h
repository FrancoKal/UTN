#ifndef IMAGINARIO_H
#define IMAGINARIO_H

    #include "complejo.h"
// Observar que no hay métodos para tratar a los miembros heredados.
    class Imaginario: public Complejo {
        public:
            Imaginario(double = 0);
            Imaginario(const Imaginario &);

            //hay que definir el operator= pues NO SE HEREDA!!!
            Imaginario& operator=(const Imaginario &);

            //no es necesario redefinir la sobrecarga del operador '<<' pues
            //un Imaginario es IGUAL a un Complejo (y lo heredó)
    };

#endif // IMAGINARIO_H
