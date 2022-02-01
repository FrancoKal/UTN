#ifndef LISTA_H
#define LISTA_H

   #include <iostream>
   #include <cstdlib>
   #define ERROR 0
   #define OK 1
   #define MAXDATOS 6

   using namespace std;

   typedef struct dato {
      char N[20];
      int edad;
      float nota;
   }DATO;
   
   typedef struct nodo
   {
      DATO d;
      struct nodo *next;
   }NODO;

#endif
