#include "Pila.h"


Pila::~Pila () {
   NODO*q;
   while (H) {
      q=H;
      H=H->next;
      delete q;
   }
}     


bool Pila::Push (DATO &D) {
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

ostream& operator<< (ostream& sal, Pila& c)
{
    NODO *i;
    i = c.H;
    sal << ">> Imprimo la EaD desde H hasta el NULL: " << endl;

//    if(c.vacio ()){
//        cout << "\nLISTA VACIA.";
//        return sal;
//    }
    while(i) {
        sal << "Nombre y Apellido: " << i->d.N << '\t'
            << "Edad: " << i->d.edad << '\t'
            << "Calificacion: " << i->d.nota << endl;
        i = i->next;
    }
    sal << "-----------------------------------" << endl;
    return sal;
}
//ostream& operator<< (ostream& out , Pila& p){
//    out << "\n\nImprimo la lista...\n";
//    NODO* i = p.H;
//    while (i){
//        out << i->d.N <<"\t" << i->d.edad<< "\t" << i->d.nota << "\n";
//        i = i->next;
//    }
//    return out;
//}
istream& operator>>(istream& in, Pila& c)
{
    DATO d;
    cout << "\nIngrese Nombre y Apellido, Edad y Calificacion separado por ENTER:\n";
    cin >> d.N >> d.edad >> d.nota; cin.ignore ();

    if(!c.Push(d)){
       cout << "\nERROR. Adios.";
       exit (1);
    }
    return in;
}

