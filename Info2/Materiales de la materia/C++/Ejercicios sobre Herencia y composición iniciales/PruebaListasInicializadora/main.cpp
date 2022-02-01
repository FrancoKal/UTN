#include "clases.h"


int main()
{
    cout << "Prueba listas inicializadoras!" << endl;
    ClaseBase CB1;
    ClaseBase CB2(1, 2, 3);
    ClaseBase CB3(4,5);
    //ClaseBase CB4(6);   //NO FUNCIONA!! error: no matching function for call to 'ClaseBase::ClaseBase(int)'

    ClaseDerivada CD1;
    ClaseDerivada CD2(5.6, 84);
    ClaseDerivada CD3 (4, 5, 6, 8.2, 35);  //dec 35 = ASCII '#'
//    ClaseDerivada CD4 (4, 5, 8.2, 36);   //error: no matching function for call to 'ClaseDerivada::ClaseDerivada(int, int, double, int)'
    //ClaseDerivada CD5 (8.2, 35, 4, 5, 6); //FUNCIONA pero asigna mal.
    //ClaseDerivada CD6 (4, 5, 6);          //NO FUNCIONA!! error: no matching function for call to 'ClaseDerivada::ClaseDerivada(int, int, int)'

    cout << "\n--------------------" << endl;

    cout << "CB1: " << CB1 << endl;
    cout << "CB2 (1, 2, 3): " << CB2 << endl;
    cout << "CB3 (4, 5): " << CB3 << endl;

    cout << "CD1: " << CD1 << endl;
    cout << "CD2 (5,6, 84): " << CD2 << endl;
    cout << "CD3 (4, 5, 6): " << CD3 << endl;

    CD3 = CD2 = CD1;

    system ("pause");
    return 0;
}
