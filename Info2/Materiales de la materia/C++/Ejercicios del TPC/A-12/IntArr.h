#ifndef INTARR_H
#define INTARR_H

class IntArr
{
private:

	int * p;	// Array Dinamico de int

	int size;	// tamaño del array
	int used;	// espacio usado del array

public:
	IntArr (int sz);// tamaño
	IntArr (int sz,int qtty,int *vec);// tamaño, cant,array inicial

	~IntArr();

	void prtArr (void) const;
};



#endif // INTARR_H
