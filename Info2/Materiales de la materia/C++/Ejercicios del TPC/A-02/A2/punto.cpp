#include "punto.h"


//Punto::Punto ()
//{
//	assignX(0);		//-- Mod A-02 - Garantiza que el valor esta controlado
//	assignY(0);		//-- Mod A-02
//}

Punto::Punto (double coor_x, double coor_y)
{
	assignX(coor_x);		//-- Mod A-02 - otra opcion es invocar a setPunto
	assignY(coor_y);		//-- Mod A-02
}

void Punto::setPunto (double coor_x,double coor_y)
{
	assignX(coor_x);		//-- Mod A-02
	assignY(coor_y);		//-- Mod A-02
}

//------------------------------- Start - Add A-02

void Punto::assignX(float val)
{
    if (val > 1000)
        m_x = 1000;
    else if (val < -1000)
        m_x = -1000;
    else
        m_x = val;
}

void Punto::assignY(float val)
{
    if (val > 1000)
        m_y = 1000;
    else if (val < -1000)
        m_y = -1000;
    else
        m_y = val;
}
//-------------------------------  End  - Add A-02


