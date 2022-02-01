#include <cstdlib>
#include <iostream>
#include "punto.h"

using std::cout;
using std::endl;
#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();

int main(int argc, char *argv[])
{
	Punto p(12.34,-56.78);
	Punto r(1,4);
	Punto q;

	cout <<"1. punto p= ("<<p.getX()<<";"<<p.getY()<<")"<<endl;
	cout <<"2. punto r= ("<<r.getX()<<";"<<r.getY()<<")"<<endl;

    q=p+r;      //q=p.operator+(r);
	cout <<"3. punto p+r: q= ("<<q.getX()<<";"<<q.getY()<<")"<<endl;
    PRESS_KEY;

    q=p-r;      //q=p.operator-(r);
	cout <<"4. punto p-r: q= ("<<q.getX()<<";"<<q.getY()<<")"<<endl;
    PRESS_KEY;

	Punto s(990,-990);
	cout <<"5. punto s= ("<<s.getX()<<";"<<s.getY()<<")"<<endl;

	q=s+p;
	cout <<"6. punto s+p: q= ("<<q.getX()<<";"<<q.getY()<<")"<<endl;
    PRESS_KEY;

	q=r+47;
	cout <<"7. punto r+47: q= ("<<q.getX()<<";"<<q.getY()<<")"<<endl;

//	PRESS_KEY;
}

