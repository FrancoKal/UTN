#include <cstdlib>
#include <iostream>
#include "punto.h"

using std::cout;
using std::endl;
#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();

int main(int argc, char *argv[])
{
	Punto p(12.34,-56.78);
	Punto r(p);

    Punto q=p;

	cout <<"1. punto p: ("<<p.getX()<<";"<<p.getY()<<")"<<endl;
	cout <<"2. punto r: ("<<r.getX()<<";"<<r.getY()<<")"<<endl;
	cout <<"3. punto q: ("<<q.getX()<<";"<<q.getY()<<")"<<endl;

	PRESS_KEY;
}

