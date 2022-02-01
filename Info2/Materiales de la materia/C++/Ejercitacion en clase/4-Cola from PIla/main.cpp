#include "cola.h"
#include <stdlib.h>

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
  Cola A; DATO auxD;
  int i;

/***************************************/
/***INGRESO DE DATOS PARA LA PRUEBA***/
  for (i=0;i<MAXDATOS;i++) 
  {
      cout << i+1 <<") "<< DatosPrueba[i].N <<"\t"
           << DatosPrueba[i].edad<< "\t" << DatosPrueba[i].nota << "\n";

      salida = A.Push(DatosPrueba[i]);

      if(salida==false){
         cout << "\nERROR. Adios.";
         exit (1);
      }
  }
/***************************************/

   cout << "<\nVaciamos la Cola usando Pop:\n";
   while(A.Pop(auxD))
     cout << auxD.N <<"\t" << auxD.edad<< "\t" << auxD.nota << "\n";

   cout << "\nImprimo Cola: ";
   cout << A;
   cin.get ();

   DATO d;
   cout << "\nIngrese Nombre y Apellido, Edad y Calificación separado por ENTER:\n";
   cin >> d.N >> d.edad >> d.nota;
   A.Push (d);
   cout << A;
   cin.get ();

   cout << "Ahora usamos el operador '>>' para ingresar tres nuevos dato a la Pila: \n";
   cin >> A >> A >> A;
   cout << A;
   cin.get ();cin.ignore (); //ignore es para CR LF

   cout << "volvemos a vaciar la lista usando pop:\n";
   while(A.Pop(auxD))
     cout << auxD.N <<"\t" << auxD.edad<< "\t" << auxD.nota << "\n" ;

  return 0;
}








