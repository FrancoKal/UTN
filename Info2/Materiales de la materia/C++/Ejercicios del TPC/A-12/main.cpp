#include <cstdlib>
#include <iostream>
#include "IntArr.h"


using std::cout;
using std::cin;
using std::endl;
//#define PRESS_KEY std::cout<<"\nPresione Enter para continuar . . .\n";std::cin.get();


int main(int argc, char *argv[])
{
	IntArr A(30);

	int v_aux[]={23,4,54,634,6677,32,56};

	IntArr B(40,sizeof(v_aux)/sizeof(int),v_aux);

	A.prtArr();
	B.prtArr();

//	PRESS_KEY;
}
