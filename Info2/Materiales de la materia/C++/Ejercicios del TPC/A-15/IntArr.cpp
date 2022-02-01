#include <cstdlib>
#include <iostream>

#include "IntArr.h"
#include "mem.h"

using std::cout;
using std::cin;
using std::endl;
using std::bad_alloc;

// - cosntructor - recibe el tama�o del array
IntArr::IntArr (int sz)
{
	used=0;
	size=sz;
	p=new int[sz];
}

// - constructor - recibe el tama�o del array, cant, array
IntArr::IntArr (int sz,int qtty, int*vec)
{
	if (qtty>sz)sz=qtty;	//verificaci�n base
	size=sz;
	used=qtty;

	p=new int[sz];

	memcpy(p,vec,size*sizeof(int));

}

IntArr::~IntArr ()
{
	if (p)
		delete (p);
}

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


void IntArr::prtArr (int cant)	const
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

void IntArr::prtArr (void) const
{
	prtArr(used);
}

//--------------------------------------- Mod - A-15 Start
#define ARR_NN 5

void IntArr::addElement (int pos,int d)
{
	addElement (pos,1, &d);

}

void IntArr::addElement (int pos,int cant, int *vv)
{
    int aux=used;

	// se acota el valor de pos.
    if (pos<0)
            pos=0;
    if (pos>used)
            pos=used;

	used+=cant;

	if (used>size)	// desborde del array
	{
		int *p_aux;
		size=used+ARR_NN;
		p_aux=new int[size];

		// Copia la primer parte

		memcpy(p_aux,p,pos*sizeof(int));

		// Copia la segunda parte dejando el espacio intermedio

		memcpy(p_aux+pos+cant,p+pos,(aux-pos)*sizeof(int));

		delete (p);
		p=p_aux;
	}
	else
	{
		// hace el espacio para copiar los datos
		memcpy(p+pos+cant,p+pos,aux*sizeof(int));
	}

	memcpy(p+pos,vv,cant*sizeof(int));

}

//--------------------------------------- Mod - A-15 End
