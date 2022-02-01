#include "punto.h"

int Punto::m_cc=0;
int Punto::m_ce=0;

float Punto::m_sup=1000;
float Punto::m_inf=-1000;


void Punto::setLimites (double inf,double sup)
{
	if (inf<sup)
	{
		m_sup=sup;
		m_inf=inf;
	}
}

Punto::Punto (double coor_x, double coor_y)
{
	m_cc++;
	m_ce++;
	assignX(coor_x);
	assignY(coor_y);
}


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


#define SET_VAL(a,b) if (a>m_sup) b=m_sup; else if (a< m_inf) b=m_inf; else b=a;

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

//---------------------------------------------- Start - Add - A-10

Punto Punto::operator++ ()	// Pre-incremento
{
	m_x++;
	m_y++;
	return (*this);
}

Punto Punto::operator++ (int j) // Pos-incremento
{
	Punto aux=*this;
	m_x++;
	m_y++;

	return (aux);
}


//----------------------------------------------  End  - Add - A-10

