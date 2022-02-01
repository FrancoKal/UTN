#include "clases.h"

ClaseBase::ClaseBase (int a,int b,int c ): b1(a), b2(b), b3(c)  //uso lista inicializadora no obligado
{
//    b1 = a;
//    b2 = b;
//    b3 = c;
    cout << "\nSoy el CONSTRUCTOR PARAMETRIZADO SIMPLE de la CB con un valor por defecto "
         <<" - Dirección: " << this;
}

ClaseBase::~ClaseBase()
{
    cout << "\nSoy el DEStructor de la CB " << this <<  "   "
         << b1 <<  " " << b2 <<  " " << b3
         << "\n";
}

ClaseDerivada::ClaseDerivada(float d, char e): s1(d), s2(e)  //uso lista inicializadora no obligado
{
//    s1 = d;
//    s2 = e;
    cout << "\nSoy el CONSTRUCTOR SIMPLE de la CD " << this <<  "\n";
}

ClaseDerivada::ClaseDerivada (int a, int b, int c, float d, char e) : ClaseBase (a, b, c)
{                   //uso lista inicializadora OBLIGADO invocando adecuadamente al Ctor de la CB
    s1=d;
    s2=e;
    cout << "\nSoy el CONSTRUCTOR PARAMETRIZADO COMPLETO de la CD "<<this << "\n";
}

ClaseDerivada::~ClaseDerivada()
{
    cout << "\nSoy el DEStructor de la CD " << this <<  "   "
            << s1 <<  " " << s2 <<  "\n";
}

//ClaseDerivada::ClaseDerivada (int a, int b, float d, char e) : ClaseBase (a, b)
//{          //uso lista inicializadora OBLIGADO invocando adecuadamente al Ctor de la CB
//    s1=d;
//    s2=e;
//    cout << "\nSoy el CONSTRUCTOR PARAMETRIZADO COMPLETO de la CD "<<this << "\n";
//}

ostream& operator << (ostream& co, const ClaseBase& cb){
    co << "b1 = " << cb.b1 << "\tb2 = " << cb.b2 << "\tb3 = " << cb.b3 << '\n';
}

ostream& operator << (ostream& co, const ClaseDerivada& cd){
    co << '\n' << "ClaseBase: " << (ClaseBase) cd;
    co << "ClaseDerivada: s1 = " << cd.s1 << "\ts2 = " << cd.s2 << '\n';
}
