#include "Pila.h"

//Este metodo no se utiliza dado que pop vacio la LDE antes de que se ejecute...
Pila::~Pila (void) {
   NODO*q;
   while (H) {
      q=H;
      H=H->next;
      delete q;
   }
}

bool Pila::push (DATO &D) {
   NODO * q;
   if (!(q=new NODO) )
      return ERROR;

   q->d=D;
   q->next=H;
   q->prev=NULL;
   H=q;
   if (q->next)
      q->next->prev = q;
   return OK;
}

bool Pila::pop (DATO &D) {
   NODO * q;
   if (vacio())
      return ERROR;

   D = H->d;
   q = H;           //guardo en q la dir del NODO a eliminar
   H = H->next;     //apunto el encabezador al siguiente
   if (H)           //si la LDE no esta vacia
      H->prev = NULL;  //completo el NODO con el indicador correcto
   delete q;
   return OK;
}

