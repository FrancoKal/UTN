#include <iostream>
#include "matrix.h"

using namespace std;

int main()
{
    matrix M[3];
    int i, det, rows, cols;

    for (i = 0; i < 2; i++)
    {
        cout << "Ingresa las filas y columnas para la matriz " << i+1 << ": ";
        cin >> rows >> cols;
        M[i].setMatrix(rows, cols);
        matrixScan(&M[i]);
    } 

    M[2] = M[0] * M[1];
    matrixPrint(M[2]);
    det = Determinant(M[2]);
    cout << "|C| = " << det << "\n";
    (M[0])(2, 2) = 100;
    matrixPrint(M[0]);

    /*for (i = 0; i < 3; i++)
        M[i].~matrix();*/

    return 0;
}
