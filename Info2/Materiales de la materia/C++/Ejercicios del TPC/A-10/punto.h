#ifndef __PUNTO_H__
#define __PUNTO_H__

#include <iostream>


class Punto
{
private:
	double m_x,m_y;

	static int m_cc;
	static int m_ce;

	static float m_sup;
	static float m_inf;

	void assignX(float);
	void assignY(float);

public:
	Punto (double coor_x=0, double coor_y=0);

	Punto (const Punto&);
	~Punto();

	void setX (double coor_x) {assignX(coor_x);}
	inline void setY (double);

	double getX (void) const{return m_x;};
	inline double getY (void) const;

	void setPunto (double,double);
	void setPunto (const Punto&);

	inline Punto& getPunto (void);

	static void setLimites (double ,double);
	static float getLimiteSup (void) {return m_sup;};
	static float getLimiteInf (void) {return m_inf;};

	friend Punto operator+ (const Punto&,const Punto&);
	friend Punto operator- (const Punto&,const Punto&);

	friend std::ostream& operator<< (std::ostream&, const Punto&);
	friend std::istream& operator>> (std::istream&, Punto&);

	friend bool operator== (const Punto&, const Punto&);
	friend bool operator!= (const Punto&, const Punto&);
	friend bool operator> (const Punto&, const Punto&);
	friend bool operator< (const Punto&, const Punto&);


	Punto operator++ ();		// Add - A-10
	Punto operator++ (int j);	// Add - A-10


	static int getCantCreada ()  {return m_cc;};
	static int getCantExistente (){return m_ce;};


};


// ---- implementaciones tipo inline ---
inline void Punto::setY (double coor_y)
{
	assignY(coor_y);
}

inline double Punto::getY (void) const{return m_y;}

inline Punto& Punto::getPunto (void){return (*this);}


#endif
