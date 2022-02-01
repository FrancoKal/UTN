#include "punto.h"

Punto::Punto (double coor_x, double coor_y)
{
	assignX(coor_x);
	assignY(coor_y);
}

void Punto::setPunto (double coor_x,double coor_y)
{
	assignX(coor_x);
	assignY(coor_y);
}

void Punto::setPunto (const Punto& p)
{
	assignX(p.m_x);
	assignY(p.m_y);
}


#define SET_VAL(a,b) if (a>1000) b=1000; else if (a< -1000) b=-1000; else b=a;

void Punto::assignX(float val)
{
	SET_VAL (val,m_x);
}

void Punto::assignY(float val)
{
	SET_VAL (val,m_y);
}

Punto operator+ (const Punto& r,const Punto& p)
{
	Punto aux;
	aux.assignX(r.m_x+p.m_x);
	aux.assignY(r.m_y+p.m_y);

return aux;
}

Punto operator- (const Punto& r,const Punto& p)
{
	Punto aux;
	aux.assignX(r.m_x-p.m_x);
	aux.assignY(r.m_y-p.m_y);

return aux;
}


//------------------------------- Start - Add A-07
std::ostream& operator<< (std::ostream& co, const Punto&p)
{
	co << " ( " << p.m_x <<" ; "<<p.m_y<< " )";
return co;
}

std::istream& operator>> (std::istream& ci, Punto&p)
{
	float f;
	std::cout << "x:";
	ci >> f;
	p.assignX(f);
	std::cout << "y:";
	ci >> f;
	p.assignY(f);

	ci.get();	// Elimina el Enter de más que se genera.

return ci;
}


bool operator== (const Punto&a, const Punto&b)
{
	if (a.m_x==b.m_x && a.m_y==b.m_y)
		return true;
	return false;
}

bool operator!= (const Punto&a, const Punto&b)
{
	if (a.m_x!=b.m_x || a.m_y!=b.m_y)
		return true;
	return false;
}

// como se usa solo para comparar entre si, no se require la raiz.
#define MOD(x) (x.m_x*x.m_x+x.m_y*x.m_y)

bool operator> (const Punto&a, const Punto&b)
{
	return (MOD(a)>MOD(b));
}
bool operator< (const Punto&a, const Punto&b)
{
	return (MOD(a)<MOD(b));
}


//-------------------------------  End  - Add A-07


