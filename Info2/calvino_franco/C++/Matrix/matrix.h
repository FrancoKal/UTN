#ifndef MATRIX_H
#define MATRIX_H

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
         template <typename T> friend matrix<T> operator+ (const matrix<T>& A, const matrix<T>& B);
         template <typename T> friend matrix<T> operator- (const matrix<T>& A, const matrix<T>& B) { return A + (-1)*B; }
         template <typename T> friend matrix<T> operator* (float k, const matrix<T>& A);
         template <typename T> friend matrix<T> operator* (const matrix<T>& A, float k) { return k * A; }
         template <typename T> friend matrix<T> operator* (const matrix<T>& A, const matrix<T>& B);
         matrix<type>& operator= (const matrix<type>& A);
         matrix<type>& operator+= (const matrix<type>& A) { return *this = (*this) + A; }
         matrix<type>& operator-= (const matrix<type>& A) { return *this = (*this) - A; }
         matrix<type>& operator*= (const matrix<type>& A) { return *this = (*this) * A; }
         type& operator() (int i, int j) { return m[i][j]; }

         /* ------------------------------------------------------- */

    private:
        int rows_, cols_;

        void matrixCopy (const matrix& A);
        //void forEveryElement (int (*func));

};

template <typename type>
void matrixPrint (matrix<type>& A);

template <typename type>
void matrixScan (matrix<type>* A);

#endif // MATRIX_H
