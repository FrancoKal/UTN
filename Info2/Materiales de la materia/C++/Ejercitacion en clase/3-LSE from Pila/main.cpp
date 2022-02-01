#include "lse.h""
#include <stdlib.h>
#include <iostream>

using namespace std;

DATO DatosPrueba[]=
{ /*Para inicializar estáticamente un objeto hay que estáticamente inicializar
  cada uno de sus campos.*/
   {"juancho" , 32  , 5.5}  ,
   {"pepito"  , 23 , 7.5 } ,
   {"marcela"  , 98 , 3.4 } ,
   {"mariana" , 22 , 0.8 } ,
   {"franco" , 20 , 10}  ,
   {"karina" , 21 , 9}
};

int main(void)
{
  bool salida;
  LSE A; DATO auxD;
  int i;

/***************************************/
/***INGRESO DE DATOS PARA LA PRUEB***/
  for (i=0;i<MAXDATOS;i++) 
  {
      cout << i+1 <<") "<< DatosPrueba[i].N <<"\t"
           << DatosPrueba[i].edad<< "\t" << DatosPrueba[i].nota << "\n";

      salida = A.enlistar(DatosPrueba[i]);

      if(salida==false){
         cout << "\nERROR. Adios.";
         exit (1);
      }
  }
/***************************************/

//   cout << "<\nVaciamos la lista usando Pop:\n";
//   while(A.Pop(auxD))
//     cout << auxD.N <<"\t" << auxD.edad<< "\t" << auxD.nota << "\n";

   cout << "\nImprimo lista: ";
   cout << (Pila&) A;
   cin.get ();

   DATO d;
   cout << "\nIngrese Nombre y Apellido, Edad y Calificación separado por ENTER:\n";
   cin >> d.N >> d.edad >> d.nota;
   A.enlistar (d);
   cout << (Pila&)A;
   cin.get ();

   cout << "Ahora usamos el operador '>>' para ingresar un nuevo dato a la Pila: \n";
   cin >> A;
   cout << (Pila&)A;
   cin.get ();cin.ignore (); //ignore es para CR LF

   cout << "Vaciamos la LSE usando pop:\n";
   while(A.Pop(auxD))
     cout << auxD.N <<"\t" << auxD.edad<< "\t" << auxD.nota << "\n" ;

  return 0;
}








