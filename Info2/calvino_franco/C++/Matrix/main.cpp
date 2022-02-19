#include "matrix.h"

/*
using std::cout;
using std::cin;
*/
using namespace std;

int main()
{
    matrix<float> M[3];
    int i, det, rows, cols;

    for (i = 0; i < 2; i++)
    {
        cout << "Ingresa las filas y columnas para la matriz " << i+1 << ": ";
        cin >> rows >> cols;
        M[i].setMatrix(rows, cols);
        matrixScan(&M[i]);
    } 

    M[2] = M[0] * M[1];
    cout << M[2];
    det = Determinant(M[2]);
    cout << "|C| = " << det << "\n";
    (M[0])(rows-1, cols-1) = 100;
    cout << M[0];

    return 0;
}
