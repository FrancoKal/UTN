#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
using namespace std;

template <typename type = int>
class matrix
{
    public:
        type **m;

         matrix (int rows = 0, int cols = 0) : m(nullptr), rows_(rows), cols_(cols) { setMatrix(rows, cols); };
         matrix (const matrix<type>& A) : matrix<type>(A.rows_, A.cols_) { matrixCopy(A); }
         ~matrix ();

         int rows () { return rows_; }
         int cols () { return cols_; }
         void setMatrix (int rows, int cols);
         void clean (); //Reseteo las filas, columnas y la matriz, pero sin eliminar el objeto
         template <typename T> friend matrix<T> Minor (const matrix<T>& A, int row, int col);
         template <typename T> friend float Determinant (const matrix<T>& A);

         /* ------------ Sobrecarga de operadores --------------    */
         template <typename T> friend ostream& operator<< (ostream& out, const matrix<T>& A);
//         template <typename T> friend istream& operator>> (istream& in, const matrix<T>& A);
         template <typename T, typename U> friend matrix<T> operator+ (const matrix<T>& A, const matrix<U>& B);
         template <typename T, typename U> friend matrix<T> operator- (const matrix<T>& A, const matrix<U>& B) { return A + (-1)*B; }
         template <typename T> friend matrix<T> operator* (float k, const matrix<T>& A);
         template <typename T> friend matrix<T> operator* (const matrix<T>& A, float k) { return k * A; }
         template <typename T, typename U> friend matrix<T> operator* (const matrix<T>& A, const matrix<U>& B);
         matrix<type>& operator= (const matrix<type>& A);
         matrix<type>& operator+= (const matrix<type>& A) { return *this = (*this) + A; }
         matrix<type>& operator-= (const matrix<type>& A) { return *this = (*this) - A; }
         matrix<type>& operator*= (const matrix<type>& A) { return *this = (*this) * A; }
         type& operator() (int i, int j) { return m[i][j]; }

         /* ------------------------------------------------------- */

    private:
        int rows_, cols_;

        void matrixCopy (const matrix<type>& A);
        //void forEveryElement (int (*func));

};

template <typename type>
void matrixPrint (matrix<type>& A);

template <typename type>
void matrixScan (matrix<type>* A);


/*
 * Para que los template funcionen, las declaraciones de las funciones deben estar en el mismo lugar que las definiciones de las mismas.
 * Caso contrario, habra un error de linkeo al linkear los archivos objeto
 */

/*
matrix::matrix (const matrix& A)
{
    setMatrix(A.rows_, A.cols_);
    matrixCopy(A);
}*/

template <typename type>
matrix<type>::~matrix ()
{
    /*  El destructor, ademas de llamar a clean(), llama a otras funciones que destruyen el objeto por defecto.
        Para evitar destruir el objeto en caso de solo querer limpiar la matriz, separo las funciones   */
    clean();
}

template <typename type>
void matrix<type>::clean ()
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

template <typename type>
void matrix<type>::matrixCopy (const matrix<type>& A)
{
    int i, j;

    if (rows_ == A.rows_ && cols_ == A.cols_)
        for (i = 0; i < rows_; i++)
            for (j = 0; j < cols_; j++)
                m[i][j] = A.m[i][j];
}

template <typename type>
void matrix<type>::setMatrix (int rows, int cols)
{
    int i;

    if (rows > 0 && cols > 0 && m == NULL)
    {
        rows_ = rows;
        cols_ = cols;
        m = new type* [rows_];

        if (m != NULL)
        {
            for (i = 0; i < rows_; i++)
            {
                m[i] = new type [cols_];

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

template <typename T, typename U>
matrix<T> operator+ (const matrix<T>& A, const matrix<U>& B)
{
    int i, j;
    matrix<T> C;

    if (A.rows_ == B.rows_ && A.cols_ == B.cols_)
    {
        C.setMatrix(A.rows_, A.cols_);

        if (C.m != NULL)
            for (i = 0; i < C.rows_; i++)
                for (j = 0; j < C.cols_; j++)
                    C.m[i][j] = A.m[i][j] + B.m[i][j];
    }

    return C;
}

/*
template <typename T, typename U>
matrix<T> operator- (const matrix<T>& A, const matrix<U>& B)
{
    int i, j;
    matrix<T> C;

    if (A.rows_ == B.rows_ && A.cols_ == B.cols_)
    {
        C.setMatrix(A.rows_, A.cols_);

        if (C.m != NULL)
            for (i = 0; i < C.rows_; i++)
                for (j = 0; j < C.cols_; j++)
                    C.m[i][j] = A.m[i][j] - B.m[i][j];
    }

    return C;
}*/

template <typename type>
matrix<type> operator* (float k, const matrix<type>& A)
{
    int i, j;
    matrix<type> B(A.rows_, A.cols_);

    if (B.m != NULL)
        for (i = 0; i < A.rows_; i++)
            for (j = 0; j < A.cols_; j++)
                B.m[i][j] = A.m[i][j] * k;

    return B;
}

template <typename T, typename U>
matrix<T> operator* (const matrix<T>& A, const matrix<U>& B)
{
    int i, j, k;
    matrix<T> AxB;

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

template <typename type>
matrix<type>& matrix<type>::operator= (const matrix<type>& A)
{
    if (rows_ != A.rows_ || cols_ != A.cols_)
    {
        clean();
        setMatrix(A.rows_, A.cols_);
    }

    matrixCopy(A);

    return *this;
}

template <typename type>
float Determinant (const matrix<type>& A)
{
    int i, sign = 1, det = 0;
    matrix<type> minor;

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

template <typename type>
matrix<type> Minor (const matrix<type>& A, int row, int col)
{
    int i, j, m, n;
    matrix<type> minor;

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

template <typename type>
void matrixScan (matrix<type> *A)
{
    int i, j, A_rows = A->rows(), A_cols = A->cols();

    for (i = 0; i < A_rows; i++)
    {
        for (j = 0; j < A_cols; j++)
            cin >> A->m[i][j];

        cout << "\n\n";
    }
}

template <typename type>
ostream& operator<< (ostream& out, matrix<type>& A)
{
    int i, j, A_rows = A.rows(), A_cols = A.cols();

    for (i = 0; i < A_rows; i++)
    {
        for (j = 0; j < A_cols; j++)
            out << A.m[i][j] << "\t";

        out << "\n\n";
    }

    return out;
}

#endif // MATRIX_H
