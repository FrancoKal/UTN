/*
  Name: 
  Copyright: 
  Author: 
  Date: 14/11/10 18:17
  Description: 
*/

#ifndef PILA_H
#define PILA_H

    #include "datos.h"

    class Pila { 

        public:  
          Pila () {H=NULL; }
          ~Pila ();	//libero la PILA
          bool Push (DATO &D);//ingreso datos a la PILA
          bool Pop (DATO &D); //extraigo datos de la PILA

          friend ostream& operator<< (ostream&, Pila&);   //imprime la Pila desde H hasta el NULL
          friend istream& operator>> (istream&, Pila&);   //Permite operaciones de ingreso por teclado que encolan.

        protected:
          //función utilitaria. No podré usarla al heredar
          bool vacio (void) const {return H==NULL;}
          NODO *H;
    };

#endif
