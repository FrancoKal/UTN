#include <cstdlib>
#include <iostream>
#include "punto.h"

using std::cout;
using std::cin;
using std::endl;
//#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();

void ff (void)
{
	Punto p,q,w;
	Punto h(34);
	Punto r=h;
	cout <<"a. Puntos Creados:"<<Punto::getCantCreada()<< " - Existentes:"<< r.getCantExistente()<<endl;
}

int main(int argc, char *argv[])
{
	cout <<"1. Puntos Creados:"<<Punto::getCantCreada()<< " - Existentes:"<< Punto::getCantExistente()<<endl;
	Punto p(12.34,-56.78);
	cout <<"2. Puntos Creados:"<<p.getCantCreada()<< " - Existentes:"<< p.getCantExistente()<<endl;
	Punto h(p);
	cout <<"3. Puntos Creados:"<<Punto::getCantCreada()<< " - Existentes:"<< Punto::getCantExistente()<<endl;
	ff();
	cout <<"4. Puntos Creados:"<<Punto::getCantCreada()<< " - Existentes:"<< Punto::getCantExistente()<<endl;
//	PRESS_KEY;
}




