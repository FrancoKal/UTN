#include <cstdlib>
#include <iostream>
#include <cstring>

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

void IntArr::prtArr (void) const
{
    prtArr(used);
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


//--------------------------------------- Add - A-14 Start
#define ARR_NN 5

void IntArr::addElement (int d)
{
	addElement (1, &d);

}


void IntArr::addElement (int cant, int *vv)
{
    int aux=used;

    used+=cant;

    if (used>size)	// desborde del array
    {
        int *p_aux;

        size = used + ARR_NN;
        p_aux = new int[size];

/*primero copio el array original dentro del auxiliar con nuevo tamanio. Luego "concateno"
 * los nuevos elementos a continuación siempre dentro del auxiliar*/
        memcpy(p_aux, p, used*sizeof(int));         //agregue
        memcpy(p_aux+aux, vv, cant*sizeof(int));    //modifique

        delete (p); //borro la memoria pedida del array original pues ya no la necesito
        p = p_aux;  //ahora le cargo a p la dirección de comienzo del array "corregido"
    }

    else
        memcpy(p+aux,vv,cant*sizeof(int));

}

//--------------------------------------- Add - A-14 End
