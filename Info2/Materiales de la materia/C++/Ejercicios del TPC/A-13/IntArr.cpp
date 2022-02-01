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
	size=sz;
	used=qtty;

	p=new int[sz];

	memcpy(p,vec,size*sizeof(int));

}

IntArr::~IntArr ()
{
	delete (p);
}

//--------------------------------------- Add - A-13 Start

double IntArr::getAvg () const
{
double sum=0;
int i;
	if (!used)
		return 0;

	for (i=0;i<used;i++)
		sum+=p[i];

	return sum/i;
}


void IntArr::prtArr (int cant)	const // cantidad de elementos a imprimir
{

	cout <<"> Array:";

	// -- verifica que la cantidad solicitada no sea mayor a used
	if (cant>used)
		cant=used;

	if (!cant)
	{
		cout <<" Vacio !!!"<<endl;
		return;
	}

	cout << p[0];

	for (int i=1;i<cant;i++)
		cout << " ; " << p[i];

	cout <<endl;

}

//--------------------------------------- Add - A-13 End

//--------------------------------------- Modif - A-13 Start

void IntArr::prtArr (void) const
{
	prtArr(used);
}

//--------------------------------------- Modif - A-13 End

