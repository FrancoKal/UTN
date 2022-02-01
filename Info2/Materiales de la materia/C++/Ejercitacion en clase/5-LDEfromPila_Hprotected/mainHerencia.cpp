/* Realizo un LDE a partir de una Pila con su H protected. Eso permite
 * acceder a él (en la clase derivada) directamente desde un objeto LDE.
 * Al cambiar el tipo de dato (LDE) debo cambiar también la clase PILA
 */

#include "datos.h"
#include "LDE.h"

DATO DatosPrueba[]= //base de datos de prueba
{
  //nombre, edad, nota 
   "juan"   , 32 , 5.5   , 
   "pepe"   , 23 , 7.5   ,
   "sara"  , 38 , 3.4   ,
   "anibal" , 46 , 8.0   ,
   "soledad", 22 , 0.8   
};

int main(void) {
  bool salida;
  LDE A; 
  DATO auxD;
  int i;
  
  cout<< "impresión de los datos crudos desde  DatosPrueba\n";
  for (i=0;i<MAXDATOS;i++)
  {
      cout  << DatosPrueba[i].N << "\t" << DatosPrueba[i].edad << "\t" << DatosPrueba[i].nota << endl;
  }
  cin.get();

  for (i=0;i<MAXDATOS;i++)
  {
     salida = A.enlisto(DatosPrueba[i]);
     if(salida==ERROR)
       return -1;
  } 
 
   cout << A; //impresión de la lista
   cin.get();
   
   cout >> A;   //impresión de la lista de atras para adelante
   cin.get();

   cout << A; //impresión de la lista
   cin.get();

   cout << "\n\nAplico el metodo pop a la lista...\n" ;
   while(A.pop(auxD))           //solo para verificar que la heredé.!!
        cout<<auxD.N <<"\t" << auxD.edad<< "\t" << auxD.nota << "\n";

   return 0;
}
