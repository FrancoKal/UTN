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
    #include <iostream>

    class Pila { 
    protected:
        NODO *H;

        public:  
          Pila (void) {H=NULL; }
          ~Pila (void);	//libero la PILA
          bool push (DATO &D);//ingreso datos a la PILA
          bool pop (DATO &D); //extraigo datos de la PILA
       
        private:
          bool vacio (void) {return H==NULL;} //función utilitaria. No podré usarla al heredar
};


#endif
