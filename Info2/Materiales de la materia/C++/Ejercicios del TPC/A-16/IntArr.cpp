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

//--------------------------------------- Add - A-16 Start
// - constructor - de copia

IntArr::IntArr (const IntArr &ia)
{
	size=ia.size;
	used=ia.used;

	p=new int[size];

	memcpy(p,ia.p,size*sizeof(int));

}

//--------------------------------------- Add - A-16 End


IntArr::~IntArr ()
{
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

//--------------------------------------- Add - A-16 Start

std::ostream& operator<< (std::ostream& co, const IntArr&ia)
{

	co<< "Array (size:"<<ia.getSize()<<")-(used:"<<ia.getUsed()<<")\n";
	ia.prtArr ();


return co;
}

//--------------------------------------- Add - A-16 End



#define ARR_NN 5

void IntArr::addElement (int pos,int d)
{
	addElement (pos,1, &d);

}

void IntArr::addElement (int pos,int cant, int *vv)
{
int aux=used;

	// se acota el valor de pos.
	if (pos<0) pos=0;
	if (pos>used) pos=used;

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

//--------------------------------------- Add - A-16 Start

IntArr IntArr::operator+ (const IntArr& a)
{
	IntArr b(*this);

	b.addElement(used,a.getUsed(),a.p);
return b;
}

IntArr& IntArr::operator+= (const IntArr& a)
{
	this->addElement(used,a.getUsed(),a.p);

return *this;
}

IntArr& IntArr::operator= (const IntArr& ia)
{
	if(this == &ia) // Auto-igualacion - se podria verificar tambien contenidos
		return *this;

	delete(p);

	size=ia.size;
	used=ia.used;

	p=new int[size];

	memcpy(p,ia.p,size*sizeof(int));

return *this;
}

//--------------------------------------- Add - A-16 End
