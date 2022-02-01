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
	// Punto ();	Delete - A-03
	Punto (double coor_x=0, double coor_y=0);	// Mod - A-03

	void setX (double coor_x) {assignX(coor_x);}
    void setY (double coor_y) {assignX(coor_y);}

	double getX (void) const{return m_x;};
    double getY (void) const {return m_y;}

	void setPunto (double,double);
	void setPunto (const Punto&);

    inline Punto& getPunto (void) {
        return (*this); //this apunta al objeto. *this ES el objeto
   }
};

#endif
