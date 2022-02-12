#include <iostream>
#include "punto.h"
#include "IntArr.h"

using namespace std;

/*#define isGreater(p,q) ((p) > (q)? "true" : "false")
#define muestroPunto(p) cout << "p = " << (p) << "\n";
#define MUESTRO_DATOS cout << "Creados  = " << Punto::getCantCreada() << ", Existentes = " << Punto::getCantExistente() << "\n";
#define MUESTRO_LIMITES cout << "Limites: min = " << Punto::getLimiteInf() << ", max = " << Punto::getLimiteSup() << "\n"; 

int main(void)
{
    Punto p, q; //Inicializo en (0,0)
    Punto r(-3, 2009.21), s(2.718), t;
    float min, max;
    //Punto r(2.718); Error de Sintaxis buscado

    MUESTRO_LIMITES
    muestroPunto(p)
    muestroPunto(r)
    muestroPunto(s)
    cout << "Ingresa 2 valores para q: ";
    cin >> q;
    muestroPunto(q)
    q = r;
    muestroPunto(q)
    p = r + s + 21;
    cout << "p = r+s+21 = " << p << "\n";
    q = p - 1 - r;
    cout << q << "\n";
    cout << "p > q = " << isGreater(p,q) << "\n";
    p.~Punto();
    MUESTRO_DATOS
    cout << "Ingresa los nuevos limites: ";
    cin >> min >> max;
    cout << "min = " << min << ", max = " << max << "\n";
    Punto::set_limites(min, max);
    MUESTRO_LIMITES
    t = r+1;
    //muestroPunto(t++) NO funciona
    muestroPunto(++t)

    return 0;
}*/

#define showSizeAndUsed(v) cout << " size:" << v.getSize() << endl << " used:" << v.getUsed() << endl;
#define SZ_VEC(x) (sizeof(x)/sizeof(x[0]))

int main()
{
    int v1[]= {0,5,10,15,20,25,30,35,40};
    int v2[]= {1,2,3,4,5,6};

    cout<<"\n==================> Inicio <==================\n";
    IntArr A(10,SZ_VEC(v1),v1);
    IntArr B(10,SZ_VEC(v2),v2);
    IntArr C=B;
    B.addElement(0,99);
    A.prtArr();
    cout<<"\n> Array B\n"<<B;
    cout<<"\n> Array C\n"<<C;
    cout<<"\n==================> Medio <==================\n";
    A=B+C;
    cout<<"\n> Array A=B+C\n"<<A;
    IntArr D(10,SZ_VEC(v1),v1);
    D=D;
    cout<<"\n> Array A\n"<<A;
    cout<<"\n==================> Medio <==================\n";
    D+=B;
    cout<<"\n> Array D+=B\n"<< D;

    return 0;
}
