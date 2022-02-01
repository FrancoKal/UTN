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
    IntArr (int sz,int qtty,int *vec);   // tama�o, cant,array inicial

	~IntArr();

    int getSize () const {return size;}
    int getUsed () const {return used;}

	double getAvg () const;


	void prtArr (void) const;
	void prtArr (int) const;

    void addElement (int,int);       		//Mod A-15
    void addElement (int,int, int *);    	//Mod A-15


};



#endif // INTARR_H
