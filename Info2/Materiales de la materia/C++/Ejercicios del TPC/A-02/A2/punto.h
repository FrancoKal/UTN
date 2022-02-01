#ifndef __PUNTO_H__
#define __PUNTO_H__

#include <iostream>

class Punto
{
private:
	double m_x,m_y;    // coordenadas x e y;

	void assignX(float);	//-- Add A-02
	void assignY(float);	//-- Add A-02

public:
    //Punto ();
    Punto (double=0, double=0);

	void setX (double coor_x) {assignX(coor_x);}		//-- Mod A-02
    void setY (double coor_y) {assignY(coor_y);}        //-- Mod A-02

	double getX (void) const{return m_x;};
    double getY (void) const {return m_y;}

	void setPunto (double ,double);

    Punto& getPunto (void) {
        return (*this); //this apunta al objeto. *this ES el objeto
   }

};

#endif
