#include <cstdlib>
#include <iostream>

#include "IntArr.h"


using std::cout;
using std::cin;
using std::endl;
//#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();


int main(int argc, char *argv[])
{
	int v_aux[]={0,5,10,15,20,25,30,35,40};

	IntArr A(10,sizeof(v_aux)/sizeof(int),v_aux);

	cout<<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
	A.prtArr();

	A.addElement(77);
    cout <<endl << "agrego elemento 77:" << endl <<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
	A.prtArr();

	A.addElement(11);
    cout <<endl << "agrego elemento 11 pero no alcanza el espacio:" << endl
         <<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
	A.prtArr();

    //AGREGUE este bloque para mejorar la prueba
    A.addElement(333);
    cout <<endl << "agrego elemento 333 y SI alcanza pues lo amplie antes:" << endl
         <<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
    A.prtArr();

	A.addElement(8,v_aux);
    cout <<endl << "agrego elemento 8 y SI alcanza pues lo amplié:" << endl
         <<" size:"<<A.getSize()<<endl<<" used:"<<A.getUsed()<<endl;
	A.prtArr();

//	PRESS_KEY;
}
