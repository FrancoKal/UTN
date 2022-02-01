/*
   Nombre: STRING.CPP
   Compilado sobre: QtCreator 2.1.0
   Autor: Marcelo Horacio Giura
   Fecha:   02/06/09

   Descripción: Declaración de la clase STRING.
*/
# ifndef _MYSTRING_H_
# define _MYSTRING_H_

   #include <iostream>
   #include <cstring>
   #include <iomanip>
   #include <cstdlib>
   #include <cstdio>

   using namespace std;

   class String
   {
    private:
        char *p;
        int len;
    public:
        String();
        String (const char *);
        String (const String&);
        ~String();

        //operadores que DEBEN ser miembros
        String&   operator=  (const String&);
        String&   operator=  (const char *);
        String    operator+  (const String&);
        String&   operator+= (const String&);
        String&   operator+= (const char*& s); //NO ES NECESARIO ¿porqué?
         char&     operator[] (int);   //ej: car = objeto[7];
        char*     operator() (char); //ej: puntero = objeto('m');

        //funciones 'friend'
        friend String operator+ (const char*, const String&);
        friend ostream& operator<< (ostream& , const String& );
        friend int operator== (const String&, const String&);
        friend int operator!= (const String&, const String&);
   };
#endif

   
   
   
   
   
   
   
   
   
