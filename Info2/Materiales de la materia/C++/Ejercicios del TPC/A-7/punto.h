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

    double getX (void) const {return m_x;};
	inline double getY (void) const;

	void setPunto (double,double);
	void setPunto (const Punto&);

	inline Punto& getPunto (void);

	friend Punto operator+ (const Punto&,const Punto&);
	friend Punto operator- (const Punto&,const Punto&);

	//------------------------------- Start - Add A-07
	friend std::ostream& operator<< (std::ostream&, const Punto&);
	friend std::istream& operator>> (std::istream&, Punto&);

	friend bool operator== (const Punto&, const Punto&);
	friend bool operator!= (const Punto&, const Punto&);
	friend bool operator> (const Punto&, const Punto&);
	friend bool operator< (const Punto&, const Punto&);

	//-------------------------------  End - Add A-07

};

// ---- implementaciones tipo inline ---
inline void Punto::setY (double coor_y)
{
	assignY(coor_y);
}

inline double Punto::getY (void) const{return m_y;}

inline Punto& Punto::getPunto (void){return (*this);}


#endif
