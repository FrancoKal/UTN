#ifndef INTARR_H
#define INTARR_H

#include <iostream>
#include <stdlib.h>

using namespace std;

#define BACKUP_EXTRA_SPACE 5 //Espacio extra a pedir en caso de que se desee hacer crecer el array y no haya espacio suficiente

class IntArr
{
    private:
        int * p;
        int size;
        int used;

        void setArr (int sz);
        void growArr (int increment);
        void cleanArr ();
        void concatenateFromArr (int qtty, int *vec);
        int checkPosition (int pos);
        int* splitArrFrom (int pos); //Retorna el puntero a partir de la posicion 'pos' (es decir, separa el vector en 2 y retorna la 2da parte)
        void concatenateArr (IntArr& v);

    public:

        /*      Constructores       */
        IntArr (int sz);
        IntArr (int sz,int qtty,int *vec);
        IntArr (const IntArr&);
        /*  ----------------------  */

        ~IntArr();

        /*      Geteadores      */
        int getSize() const { return size; }
        int getUsed() const { return used; }
        double getAvg() const;
        /*  ------------------- */

        /*      Sobrecargas de operadores       */
        IntArr operator+ (const IntArr&);
        IntArr& operator= (const IntArr&);
        IntArr& operator+= (const IntArr&);
        friend ostream& operator<< (ostream& out, IntArr&);
        /*  ---------------------------------   */

        void prtArr(int n);
        void prtArr ();
        void addElement (int pos, int xx);
        void addElement(int pos, int qtty, int *vec);
};

void copyFromVec (int pos, int n, int *oldVec, int *newVec); //Copia 'n' elementos de 'oldVec' en 'newVec' a partir de la posicion 'pos'


#endif // INTARR_H
