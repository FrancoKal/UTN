/*
   Nombre del Archivo: 2-Herencia.cpp
   Compilado sobre: Qt Creator
   Autor: Marcelo Horacio Giura
   Fecha: 24/08/11
   Claves:  Práctica sobre funcionamiento de constructores al instanciar una
   clase derivada.

   Descripción: Se define una CB con un constructor parametrizado con default y
   a partir de ella se define una CD con 4 contructores: Uno parametrizado con
   transferencia de valores al constructor de la CB, otro parametrizado con
   valores de la CD, otro que solo recibe valores para la CB y otro x default.
   Observar el modo en que se ejecutan los destructores.
*/

#include <iostream>
using namespace std;

// ---------------------- DECLARACION DE LAS CLASES ---------------------------
class ClaseBase{	//definición de la Clase Base (CB)
 protected:
    int b1 ;
    int b2 ;
 public:
    int b3 ;
    ClaseBase(int a=0,int b=0,int c=0); //constructor parametrizado con default
};

class ClaseDerivada : public ClaseBase{ //Definición de la Clase Derivada (CD)
 private:			        //Hereda de manera 'pública' a la CB
    float s1 ;
    char s2 ;
 public:
     ClaseDerivada();                  //constructor x defecto (inicializo en 0)
     ClaseDerivada(float d, char e);   //constructor parametrizado para la CD

     //constructor parametrizado con valores para CB y CD (en ese orden)
     ClaseDerivada(int a,int b,int c,float d, char e);
     ClaseDerivada(int a,int b,int c);
     ~ClaseDerivada ();
};

// ----------------- DEFINICION DE LOS METODOS CONSTRUCTORES ------------------
// ------------- Contructor parametrizado de la CB
ClaseBase::ClaseBase (int a,int b,int c){
    b1=a; b2=b; b3=c;
    cout<<"\nConstructor parametrizado con default de la ClaseBase ("
        << this << ")" << endl;
    cout<<"b1= "<<b1<<"\tb2= "<<b2<<"\tb3= "<<b3<<endl;
}
// ------------- Contructor por default de la CD
ClaseDerivada::ClaseDerivada (){
    s1=0; s2='0';
    cout<<"\nConstructor x default ClaseDerivada("
       << this << ")" << endl;
    cout<<"s1= "<<s1<<"\ts2= "<<s2<<endl;
}
// --- Contructor parametrizado de CD SIN transferencia a los miembros de la CB
ClaseDerivada::ClaseDerivada(float d,char e){
    s1=d; s2=e;
    cout<<"\nConstructor de la CD s/transferencia a la CB("
       << this << ")" << endl;
    cout<<"s1= "<<s1<<"\ts2= "<<s2<<endl;
}
//Definición del contructor parametrizado de CD que transfiere valores de
//parámetros al constructor de la CB.
ClaseDerivada::ClaseDerivada(int a,int b,int c,float d,char e)
        :ClaseBase (a, b, c){
    s1=d; s2=e;
    cout<<"\nConstructor de la CD c/transferencia a la CB (COMPLETO)("
       << this << ")" << endl;
    cout<<"s1= "<<s1<<"\ts2= "<<s2<<endl;
}

ClaseDerivada::ClaseDerivada(int a,int b,int c)
        :ClaseBase (a, b, c){
    s1=0; s2='B';
    cout<<"\nConstructor de la CD que SOLO recibe valores para transferir a la CB("
       << this << ")" << endl;
    cout<<"s1= "<<s1<<"\ts2= "<<s2<<endl;
}

ClaseDerivada::~ClaseDerivada(){
    cout<<"\nSoy el Destructor de la CD. Mi objeto es: "
        << this <<endl;
}



// ------------------------------ función main  --------------------------------
//
// ----------------------------------------------------------------------------
int main (void){

   cout << "1ro.) ClaseDerivada od1 (8.2, 'A');";
   ClaseDerivada od1 (8.2, 'A'); //creo el objeto 'od1' del tipo ClaseDerivada
   cout << "\nOprima ENTER para continuar\n" ;
   cin.get();  //idem getchar()


   cout << "\n\n2do.) ClaseDerivada od2 (3, 4, 5, 23.9, 'Z');";
   ClaseDerivada od2 (3, 4, 5, 23.9, 'Z');
   cout << "\nOprima ENTER para continuar\n" ;
   cin.get();

   cout << "\n\n3ro.) ClaseDerivada od3; (constructores por defecto)";
   ClaseDerivada od3;
   cout << "\nOprima ENTER para continuar\n" ;
   cin.get();

   cout << "\n\n4to.) ClaseDerivada od4 (1,2,3)";
   ClaseDerivada od4 (1,2,3);

   cout << "\nOprima ENTER para FINALIZAR" ;
   cin.get();

   return 0;
}
// ---------------------------  FIN función main  -----------------------------
