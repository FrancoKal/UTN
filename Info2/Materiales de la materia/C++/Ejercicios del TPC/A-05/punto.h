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
                                                        //    Punto () {m_x = m_y = 0;}
    void setX (double coor_x) {assignX(coor_x);}
    void setY (double coor_y) {assignY(coor_y);}

    double getX (void) const {return m_x;}
    double getY (void) const {return m_y;}

	void setPunto (double,double);
	void setPunto (const Punto&);

    Punto& getPunto (void) {return (*this);}

	Punto operator+ (const Punto&);	// Add - A-05
	Punto operator- (const Punto&);	// Add - A-05


};

#endif
