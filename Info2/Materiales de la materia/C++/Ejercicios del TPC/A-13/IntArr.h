#ifndef INTARR_H
#define INTARR_H

class IntArr
{
private:

	int * p;	// Array Dinamico de int

	int size;	// tama�o del array
	int used;	// espacio usado del array

public:
	IntArr (int sz);// tama�o
	IntArr (int sz,int qtty,int *vec);// tama�o, cant,array inicial

	~IntArr();

	int getSize () const {return size;};	//Add A-13
	int getUsed () const {return used;};	//Add A-13

	double getAvg () const;	//Add A-13


	void prtArr (void) const;
	void prtArr (int) const;	//Add A-13
};



#endif // INTARR_H
