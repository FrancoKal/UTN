#ifndef __PUNTO_H__
#define __PUNTO_H__

#include <iostream>

/*========================================================================
---------------------- Punto --------------------------------
m_x: coordenada en x
m_y: coordenada en y

========================================================================*/
class Punto
{
private:
	double m_x,m_y;    // coordenadas x e y;

public:
	Punto ();
	Punto (double , double);
    // Punto (double v) {m_y = v;}

	void setX (double coor_x)	{m_x=coor_x;};	// inline implicito
	inline void setY (double );

    double getX (void) const {return m_x;};      // inline implicito
	inline double getY (void) const;

	void setPunto (double ,double );

    inline Punto& getPunto (void);

};

// implementaciones tipo inline 

inline void Punto::setY (double coor_y)
{
	m_y=coor_y;
}

inline double Punto::getY (void) const{return m_y;}

inline Punto& Punto::getPunto (void){return (*this);}


#endif
