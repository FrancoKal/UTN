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

//------------------------------- Start - Mod A-06

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



//-------------------------------  End  - Mod A-06


