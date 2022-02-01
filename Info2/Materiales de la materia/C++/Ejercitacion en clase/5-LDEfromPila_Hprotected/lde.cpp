#include "LDE.h"
#include <cstring>
#include <iostream>
using namespace std;

bool LDE :: insert (NODO* i, DATO &D) {
   NODO *q;
   if ( !( q = new NODO) )
      return ERROR;
   q->d = D;                //almaceno el dato en el NODO
   q->next = i->next;       //enlazo
   q->prev = i;             //enlazo
   i->next = q;             //enlazo
   return OK;
}

bool LDE :: enlisto (DATO &D) {
   NODO *i = H;

   //no puedo usar el metodo vacio() pues era private en Pila y ahora esta oculto.
   // Observar que accedo a H directamente pues la heredé protegida
   if( H == NULL/*LDE::vacio() no puedo usarla*/ || (strcmp( H->d.N, D.N)>0) )
      return push(D); //Si esta vacia o va al principio...... uso push()

   //busco donde insertarlo...
   while (i->next) {         //pregunto por i->next para no caerme
      if( strcmp ( D.N, i->next->d.N )<0) //si el que voy a poner va antes del que estoy apuntando
               break;                   //corto el ciclo
      i=i->next;                    //sino, incremento
   }
   return insert (i,D);
}

ostream& operator<< (ostream& out, LDE& l){
        out<< "IMPRESION DE LA LDE"<<endl;
        NODO *i = l.H; //no necestito un metodo consultor pues H es protected en Pila y por ende en LDE...
        while (i){
            out     << "Nombre: " << i->d.N << "\tEdad: " << i->d.edad
                    << "\tNota: " << i->d.nota << endl;
            i = i->next;
        }
        out << "\n\n";
        return out;
}

ostream& operator>> (ostream& out, LDE& l){
        out<< "\n\nIMPRESION DE LA LDE de ATRAS para ADELANTE"<<endl;
        NODO *i = l.H; //no necestito un metodo consultor pues H es protected en Pila y por ende en LDE...
        while (i->next)
            i = i->next;
        while (i) {
            out     << "Nombre: " << i->d.N << "\tEdad: " << i->d.edad
                    << "\tNota: " << i->d.nota << endl;
            i = i->prev;
        }
        out <<endl <<endl;
        return out;
}

