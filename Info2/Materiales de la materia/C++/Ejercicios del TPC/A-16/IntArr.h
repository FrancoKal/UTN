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
	IntArr (const IntArr&);			//Add A-16

	IntArr& operator= (const IntArr&);//Add A-16

	friend std::ostream& operator<< (std::ostream&, const IntArr&);	//Add A-16

	~IntArr();

    int getSize () const {return size;}
    int getUsed () const {return used;}

	double getAvg () const;


	void prtArr (void) const;
	void prtArr (int) const;

	void addElement (int,int);
	void addElement (int,int, int *);
	IntArr operator+ (const IntArr&);	//Add A-16
	IntArr& operator+= (const IntArr&);	//Add A-16

};



#endif // INTARR_H
