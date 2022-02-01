#ifndef AVION_H
#define AVION_H

#include "String.h"

using namespace std;

class Avion
{
    private:
        String Matricula;
        String Cia;

    public:
        Avion(String matricula = "SIN DATOS", String cia = "SIN DATOS") : Matricula(matricula), Cia(cia) {};
        Avion(const Avion& a) : Matricula(a.Matricula), Cia(a.Cia) {};
        ~Avion() {};

        Avion& operator= (const Avion& a);
        friend ostream& operator<< (ostream& out, const Avion& a);
};


#endif // AVION_H
