#include "IntArr.h"


void IntArr::setArr (int sz)
{
    p = NULL;
    size = used = 0;

    if (sz > 0)
    {
        p = new int [sz];

        if (p != NULL)
            size = sz;
    }
}

IntArr::IntArr (int sz)
{
    setArr(sz);
}

IntArr::IntArr (const IntArr& copia)
{
    setArr(copia.size);

    if (p != NULL)
    {
        used = copia.used;
        copyFromVec(0, used, copia.p, p);
    }
}

IntArr::IntArr (int sz,int qtty,int *vec)
{
    if (qtty > sz)
        sz = qtty;

    setArr(sz);

    if (qtty > 0)
    {
        if (qtty > size)
            qtty = size;

        used = qtty;
        copyFromVec(0, qtty, vec, p);
    }
}

void copyFromVec (int pos, int n, int *oldVec, int *newVec)
{
    int i;

    if (newVec != NULL && oldVec != NULL)
        for (i = 0; i < n; i++)
            newVec[pos + i] = oldVec[i];
}

void IntArr::cleanArr ()
{
    /*if (p != NULL) //No hace falta verificar esto, el delete [] p lo hace por su cuenta
    {
        delete [] p;
        p = NULL;
        size = used = 0;
    }*/

    /*delete [] p;
    p = NULL;
    size = used = 0;*/
}

IntArr::~IntArr()
{
    cleanArr();
}

void IntArr::prtArr (int n)
{
    int i, N = checkPosition(n);

    cout << "> Array: ";

    if (N == 0)
        cout << "Vacio!!!";
    else
    {   
        for (i = 0; i < N - 1; i++)
            cout << p[i] << " ; ";

        cout << p[i];
    }

    cout << "\n";
}

void IntArr::prtArr ()
{
    prtArr(used);
}

double IntArr::getAvg() const
{
    int i;
    double sum = 0;

    for (i = 0; i < used; i++)
        sum += p[i];

    return sum / used;
}

void IntArr::growArr (int increment)
{
    int *aux = NULL;

    aux = new int [size + increment + BACKUP_EXTRA_SPACE];

    if (aux != NULL)
    {
        copyFromVec(0, size, p, aux);
        cleanArr();
        p = aux;
        size += increment + BACKUP_EXTRA_SPACE;
    }

    //p = (int*) realloc (p, sizeof(int) * size); No funciona bien el realloc
}

int IntArr::checkPosition (int pos)
{
    int checkedPos = pos;

    if (checkedPos > used)
        checkedPos = used;
    else if (checkedPos < 0)
        checkedPos = 0;

    return checkedPos;
}

void IntArr::concatenateFromArr (int qtty, int *vec)
{
    copyFromVec(used, qtty, vec, p);
}

void IntArr::concatenateArr(IntArr &v)
{
    concatenateFromArr(v.used, v.p);
}

int* IntArr::splitArrFrom (int pos)
{
    return p + checkPosition(pos);
}

void IntArr::addElement (int pos, int xx)
{
    addElement(pos, 1, &xx);
}

void IntArr::addElement (int pos, int qtty, int *vec)
{
    int *offset = splitArrFrom(pos); //Tomo el array desde la posicion pos hasta el final
    int *new_p = NULL;
    int checkedPos = checkPosition(pos), checkedQtty = checkPosition(qtty), previousSize = size, previousUsed = used;

    //cout << "pos = " << pos;

    if (used + checkedQtty > previousSize) //Si used+qtty supera al tamaño original del array, debo pedir memoria extra
         new_p = new int [previousSize + checkedQtty];
    else
        new_p = new int [previousSize];

    if (new_p != NULL)
    {
        copyFromVec(0, checkedPos, p, new_p); //Copio la primera parte de p en new_p hasta pos
        copyFromVec(checkedPos, checkedQtty, vec, new_p); //Copio qtty elementos de vec en new_p a partir de pos
        copyFromVec(checkedPos + checkedQtty, previousSize - (checkedPos /*+ checkedQtty*/), offset, new_p); //Copio el array original a partir del offset
        cleanArr();
        p = new_p;
        used = previousUsed + checkedQtty;
        size = previousSize + checkedQtty;
    }
}

IntArr IntArr::operator+ (const IntArr& u)
{
    IntArr v(*this);

    v.addElement(used, u.used, u.p);

    return v;
}

IntArr& IntArr::operator= (const IntArr& u)
{
    if (p != u.p) //Si apuntan a la misma direccion, obviamente van a ser iguales y no hace falta hacer nada
    {
        cleanArr();
        addElement(0, u.used, u.p);
    }

    return *this;
}

IntArr& IntArr::operator+= (const IntArr& v)
{
    //return operator=(operator+(v));
    return (*this) = (*this) + v;
}

ostream& operator<< (ostream& out, IntArr& v)
{
    out << "Array <size: " << v.size << "> - <used: " << v.used << ">\n";
    v.prtArr();

    return out;
}
