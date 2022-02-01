#include "Pila.h"


Pila::~Pila () {
   NODO*q;
   while (H) {
      q=H;
      H=H->next;
      delete q;
   }
}     


bool Pila::Push (const DATO & D) {
   NODO * q;

   if (!(q = new NODO) )
      return false;
   
   q->d=D;
   q->next=H;
   H=q;

   return true;
}

bool Pila::Pop (DATO &D) {
   NODO * q;
   if (! (vacio()))   //si no esta vacío
   {
       D=H->d;
       q=H;
       H=H->next;
       delete q;
       return true;
   }
   else return false;
}

ostream& operator<< (ostream& sal, const Pila& c)
{
    NODO *i;
    i = c.H;
    sal << ">> Imprimo Pila desde H hasta el NULL: " << endl;

    if(c.vacio ()){
        cout << "\nLISTA VACIA.";
        return sal;
    }
    while(i) {
        sal << "Nombre y Apellido: " << i->d.N << endl
            << "Edad: " << i->d.edad << endl
            << "Calificacion: " << i->d.nota << endl;
        i = i->next;
    }
    sal << "-----------------------------------" << endl;
    return sal;
}

istream& operator>>(istream& in, Pila& c)
{
    DATO d;
    cout << "\nIngrese Nombre y Apellido, Edad y Calificacion separado por ENTER:\n";
    cin >> d.N >> d.edad >> d.nota;

    if(!c.Push(d)){
       cout << "\nERROR. Adios.";
       exit (1);
    }
    return in;
}

