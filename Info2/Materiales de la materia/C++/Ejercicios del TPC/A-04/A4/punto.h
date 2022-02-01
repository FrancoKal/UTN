#ifndef __PUNTO_H__
#define __PUNTO_H__

#include <iostream>

class Punto
{
private:
	double m_x,m_y;

	void assignX(float);
	void assignY(float);

public:
	Punto (double coor_x=0, double coor_y=0);

	void setX (double coor_x) {assignX(coor_x);}
	inline void setY (double);

	double getX (void) const{return m_x;};
	inline double getY (void) const;

	void setPunto (double,double);
	void setPunto (const Punto&);

	inline Punto& getPunto (void);

};

// ---- implementaciones tipo inline ---
inline void Punto::setY (double coor_y)
{
	assignY(coor_y);
}

inline double Punto::getY (void) const{return m_y;}

inline Punto& Punto::getPunto (void){return (*this);}


#endif
