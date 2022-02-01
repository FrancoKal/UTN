#include <cstdlib>
#include <iostream>

#include "IntArr.h"
#include "mem.h"

using std::cout;
using std::cin;
using std::endl;
using std::bad_alloc;

// - cosntructor - recibe el tamaño del array
IntArr::IntArr (int sz)
{
	used=0;
	size=sz;
	p=new int[sz];
}

// - constructor - recibe el tamaño del array, cant, array
IntArr::IntArr (int sz,int qtty, int*vec)
{
	if (qtty>sz)sz=qtty;	//verificación base

    p=new int[sz];
    size=sz;
	used=qtty;	

    memcpy(p,vec,used*sizeof(int));
}

IntArr::~IntArr ()
{
	delete (p);
}

void IntArr::prtArr (void) const
{

	cout <<"> Array:";

	if (!used)
	{
		cout <<" Vacio !!!"<<endl;
		return;
	}

	cout << p[0];

	for (int i=1;i<used;i++)
        cout << " ; " << p[i];

	cout <<endl;

}


