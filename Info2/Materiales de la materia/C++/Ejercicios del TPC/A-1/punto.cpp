#include "punto.h"

Punto::Punto ()
{	
	m_x=0;
	m_y=0;
}

Punto::Punto (double coor_x, double coor_y)
{
	m_x=coor_x;
	m_y=coor_y;
}

void Punto::setPunto (double coor_x,double coor_y)
{
	m_x=coor_x;
	m_y=coor_y;
}
