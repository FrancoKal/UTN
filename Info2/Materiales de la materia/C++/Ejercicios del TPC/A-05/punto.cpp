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

//------------------------------- Start - Add A-05

Punto Punto::operator+ (const Punto& p)
{
	Punto aux;
	aux.assignX(m_x+p.m_x);	// se podr�a realizar mediante la Macro
	aux.assignY(m_y+p.m_y);

return aux;
}

Punto Punto::operator- (const Punto& p)
{
	Punto aux;
	aux.assignX(m_x-p.m_x);	// se podr�a realizar mediante la Macro
	aux.assignY(m_y-p.m_y);

return aux;
}



//-------------------------------  End  - Add A-05

