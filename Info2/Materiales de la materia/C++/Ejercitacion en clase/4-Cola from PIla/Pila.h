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
          bool Push (const DATO &D);//ingreso datos a la PILA
          bool Pop (DATO &D); //extraigo datos de la PILA

          friend ostream& operator<< (ostream&, const Pila&);   //imprime la Pila desde H hasta el NULL
          friend istream& operator>> (istream&, Pila&);   //Permite operaciones de ingreso por teclado que encolan.

//        private:
          //función utilitaria. No podré usarla al heredar



        protected:
          NODO *H;
          bool vacio (void) const {return H==NULL;}
    };

#endif
