#include "punto.h"

int Punto::m_cc=0;		// Add - A-08
int Punto::m_ce=0;		// Add - A-08


Punto::Punto (double coor_x, double coor_y)
{
	m_cc++;		// Add - A-08
	m_ce++;		// Add - A-08
	assignX(coor_x);
	assignY(coor_y);
}

//------------------------------- Start - Add A-08

Punto::~Punto ()
{
	m_ce--;
}


Punto::Punto (const Punto& p)
{
	m_cc++;
	m_ce++;
	assignX(p.m_x);
	assignY(p.m_y);
}


//-------------------------------  End  - Add A-08


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
	std::cout<< std::endl;

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

#define MOD(x) (x.m_x*x.m_x+x.m_y*x.m_y)
bool operator> (const Punto&a, const Punto&b)
{
	return (MOD(a)>MOD(b));
}
bool operator< (const Punto&a, const Punto&b)
{
	return (MOD(a)<MOD(b));
}


