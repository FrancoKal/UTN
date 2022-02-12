#ifndef MATRIX_H
#define MATRIX_H

class matrix
{
    public:
        int **m;

         matrix (int rows = 0, int cols = 0) : m(nullptr), rows_(rows), cols_(cols) { setMatrix(rows, cols); };
         matrix (const matrix& A) : matrix(A.rows_, A.cols_) { matrixCopy(A); }
         ~matrix ();

         int rows () { return rows_; }
         int cols () { return cols_; }
         void setMatrix (int rows, int cols);
         void clean (); //Reseteo las filas, columnas y la matriz, pero sin eliminar el objeto
         friend matrix Minor (const matrix& A, int row, int col);
         friend int Determinant (const matrix& A);

         /* ------------ Sobrecarga de operadores --------------    */
         friend matrix operator+ (const matrix& A, const matrix& B);
         friend matrix operator- (const matrix& A, const matrix& B) { return A + (-1)*B; }
         friend matrix operator* (int k, const matrix& A);
         friend matrix operator* (const matrix& A, int k) { return k * A; }
         friend matrix operator* (const matrix &A, const matrix& B);
         matrix& operator= (const matrix& A);
         matrix& operator+= (const matrix& A) { return *this = (*this) + A; }
         matrix& operator-= (const matrix& A) { return *this = (*this) - A; }
         matrix& operator*= (const matrix& A) { return *this = (*this) * A; }
         int& operator() (int i, int j) { return m[i][j]; }

         /* ------------------------------------------------------- */

    private:
        int rows_, cols_;

        void matrixCopy (const matrix& A);
        //void forEveryElement (int (*func));

};

void matrixPrint (matrix& A);
void matrixScan (matrix* A);

#endif // MATRIX_H
