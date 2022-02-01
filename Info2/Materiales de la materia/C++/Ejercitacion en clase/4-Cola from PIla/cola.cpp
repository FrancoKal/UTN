#include "cola.h"

bool Cola::Push(const DATO &D)
{
    NODO *i = H;
    NODO *q = new NODO;
    if (q == NULL)
        return false;
    q->next = NULL;
    q->d = D;
    //tengo armado el nodo a pushear

    if (!H){
        H = q;
        return true;
      }

    while (i->next)
        i = i -> next;
    //llegue al final. Apunto al útimo

    i->next = q;

    return true;
}

istream& operator>> (istream& in, Cola& c){
    DATO d;
    cout << "\nIngrese Nombre y Apellido, Edad y Calificacion separado por ENTER:\n";
    cin >> d.N >> d.edad >> d.nota;

    if(!c.Push(d)){
       cout << "\nERROR. Adios.";
       exit (1);
    }
    return in;
}
