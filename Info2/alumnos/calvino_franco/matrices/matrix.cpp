#include "matrix.h"
#include <iostream>

using namespace std;


/*matrix::matrix (const matrix& A)
{
    setMatrix(A.rows_, A.cols_);
    matrixCopy(A);
}*/

matrix::~matrix ()
{
    /*  El destructor, ademas de llamar a clean(), llama a otras funciones que destruyen el objeto por defecto.
        Para evitar destruir el objeto en caso de solo querer limpiar la matriz, separo las funciones   */
    clean();
}

void matrix::clean ()
{
    int i;

    if (m != NULL)
    {
        for (i = 0; i < rows_; i++)
            delete[] m[i];

        delete[] m;
        m = NULL;
    }

    rows_ = cols_ = 0;
}

void matrix::matrixCopy (const matrix& A)
{
    int i, j;

    if (rows_ == A.rows_ && cols_ == A.cols_)
        for (i = 0; i < rows_; i++)
            for (j = 0; j < cols_; j++)
                m[i][j] = A.m[i][j];
}

void matrix::setMatrix (int rows, int cols)
{
    int i;

    if (rows > 0 && cols > 0 && m == NULL)
    {
        rows_ = rows;
        cols_ = cols;
        m = new int* [rows_];

        if (m != NULL)
        {
            for (i = 0; i < rows_; i++)
            {
                m[i] = new int [cols_];

                if (m[i] == NULL) //Si no hay memoria disponible, debo liberar las filas anteriores
                {
                    rows_ = i; //El numero de filas a liberar sera las que el contador i llego hasta el momento
                    clean();
                    break;
                }
            }
        }
    }
}

matrix operator+ (const matrix& A, const matrix& B)
{
    int i, j;
    matrix C;

    if (A.rows_ == B.rows_ && A.cols_ == B.cols_)
    {
        C.setMatrix(A.rows_, A.cols_);

        if (C.m != NULL)
            for (i = 0; i < C.rows_; i++)
                for (j = 0; j < C.cols_; j++)
                    B.m[i][j] = A.m[i][j] + B.m[i][j];
    }

    return C;
}

/*matrix operator- (const matrix& A, const matrix& B)
{
    int i, j;
    matrix C;

    if (A.rows_ == B.rows_ && A.cols_ == B.cols_)
    {
        C.setMatrix(A.rows_, A.cols_);

        if (C.m != NULL)
            for (i = 0; i < C.rows_; i++)
                for (j = 0; j < C.cols_; j++)
                    B.m[i][j] = A.m[i][j] - B.m[i][j];
    }

    return C;
}*/

matrix operator* (int k, const matrix& A)
{
    int i, j;
    matrix B(A.rows_, A.cols_);

    if (B.m != NULL)
        for (i = 0; i < A.rows_; i++)
            for (j = 0; j < A.cols_; j++)
                B.m[i][j] = A.m[i][j] * k;

    return B;
}

matrix operator* (const matrix& A, const matrix& B)
{
    int i, j, k;
    matrix AxB;

    if (A.cols_ == B.rows_)
    {
        AxB.setMatrix(A.rows_, B.cols_);

        if (AxB.m != NULL)
            for (i = 0; i < A.rows_; i++)
                for (j = 0; j < B.cols_; j++)
                    for(k = AxB.m[i][j] = 0; k < A.cols_ /*B.rows_ tambien sirve*/; k++)
                        // "k" sirve para marcar hasta cuando se debe sumar para cada elemento de la matriz
                        AxB.m[i][j] += A.m[i][k] * B.m[k][j];
    }

    return AxB;
}

matrix& matrix::operator= (const matrix& A)
{
    if (rows_ != A.rows_ || cols_ != A.cols_)
    {
        clean();
        setMatrix(A.rows_, A.cols_);
    }

    matrixCopy(A);

    return *this;
}

int Determinant (const matrix& A)
{
    int i, sign = 1, det = 0;
    matrix minor;

    if (A.rows_ == A.cols_ && A.m != NULL)
    {
        if (A.rows_ == 2)
            det = A.m[0][0] * A.m[1][1] - A.m[0][1] * A.m[1][0];
        else
        {
            for (i = 0; i < A.cols_; i++)
            {
                minor = Minor(A, 0, i); //Desarrollo el determinante por la primera fila

                if (minor.m == NULL)
                    break;

                det += sign * A.m[0][i] * Determinant(minor);
                sign *= -1;
            }

            minor.clean();
        }
    }

    return det;
}

matrix Minor (const matrix& A, int row, int col)
{
    int i, j, m, n;
    matrix minor;

    if (A.rows_ == A.cols_)
    {
        minor.setMatrix(A.rows_-1, A.cols_-1);

        if (minor.m != NULL)
            for (i = m = 0; i < A.rows_; i++)
            {
                if (i != row)
                {
                    for (j = n = 0; j < A.cols_; j++)
                    {
                        if (j != col)
                        {
                            minor.m[m][n] = A.m[i][j];
                            n++;
                        }
                    }

                    m++;
                }
            }
    }

    return minor;
}

void matrixScan (matrix *A)
{
    int i, j, A_rows = A->rows(), A_cols = A->cols();

    for (i = 0; i < A_rows; i++)
    {
        for (j = 0; j < A_cols; j++)
            cin >> A->m[i][j];

        cout << "\n\n";
    }
}

void matrixPrint (matrix& A)
{
    int i, j, A_rows = A.rows(), A_cols = A.cols();

    for (i = 0; i < A_rows; i++)
    {
        for (j = 0; j < A_cols; j++)
            cout << A.m[i][j] << "\t";

        cout << "\n\n";
    }
}
