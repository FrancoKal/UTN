#ifndef DATOS_H
#define DATOS_H

    #define ERROR 0
    #define OK 1
    #define MAXDATOS 5
    #define NULL (NODO*)0

   using namespace std;

   struct DATO {
      char N[20];
      int edad;
      float nota;
   };
   
   struct NODO
   {
      DATO d;
      NODO *next;
      NODO *prev;
      NODO(){next=prev=NULL;}
   };

#endif
