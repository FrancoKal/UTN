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

	void prtArr (void) const;
};



#endif // INTARR_H
