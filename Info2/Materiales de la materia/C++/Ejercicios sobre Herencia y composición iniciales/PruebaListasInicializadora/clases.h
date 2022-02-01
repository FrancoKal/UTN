#ifndef CLASES_H
#define CLASES_H

#include <iostream>
#include <iomanip>
using namespace std;

class ClaseBase{
 private:
    int b1;
    int b2;

 public:
    int b3;
    ClaseBase() {b1=0; b2=0; b3=0;
                 cout<< "\nSoy el CONSTRUCTOR x DEFECTO de la CB "<<" - Dirección: " << this;}
    ClaseBase (int ,int ,int=0 );

    ~ClaseBase();
    //métodos para acceder a b1 y b2........
    friend ostream& operator << (ostream&, const ClaseBase&);
 };

class ClaseDerivada : public ClaseBase {
 private:
    float s1;
    char s2;

 public:
    ClaseDerivada(float d=3.2, char e='X');
    ClaseDerivada (int a, int b, int c, float d, char e);
//    ClaseDerivada (int a, int b, float d, char e);

    ~ClaseDerivada();

    //métodos para acceder a s1 y s2........
    friend ostream& operator << (ostream&, const ClaseDerivada&);
};

#endif // CLASES_H
