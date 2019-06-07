//
// Created by JonathanSum on 5/16/2019.
//

#include "matrix.h"
/*****************************************************
 *
 *   Matrix<T>::Matrix(): Class Matrix
 ________________________________________________
 *   This method add the first node in linked list.
 ________________________________________________
 *   PRE-CONDITIONS
 *   same
 *   POST-CONDITIONS
 *   It initialize an empty Matrix.
*****************************************************/
template<class T>
Matrix<T>::Matrix() {
    T array[MAXROWS][MAXCOLS];
}

/*****************************************************
 *
 *   void Matrix<T>::printMatrix() const: Class Matrix
 ________________________________________________
 *   This function displays
 *   all of the elements of the array row by row.
 ________________________________________________
 *   PRE-CONDITIONS
 *   same
 *   POST-CONDITIONS
 *   displays all of the elements of the array row by row.
*****************************************************/
template<class T>
void Matrix<T>::printMatrix() const {
    for (int i = 0; i < MAXROWS; i++) {
        for (int j = 0; j < MAXCOLS; j++) {
            cout << array[i][j] << "   ";
        }
        cout << endl;
    }
}


/*****************************************************
 *
 *   void Matrix<T>::setElement(int row, int col, T value)
 ________________________________________________
 *   This function displays
 *   This function sets the appropriate element in the Matrix to the value passed in.
 ________________________________________________
 *   PRE-CONDITIONS
 *   same
 *   POST-CONDITIONS
 *   element in the Matrix is changed to the value passed in.
*****************************************************/
template<class T>
void Matrix<T>::setElement(int row, int col, T value) {
    //PROCESSING - setting the element in passed in row and column to the
    //passed in element.
    array[row][col]=value;
}


/*****************************************************
 *
 *   void Matrix<T>::setMatrix(const T m[])
 ________________________________________________
 *   This function displays
 *   This function copies the elements in a 1d array
 *   and stores it into the 2d matrix.
 ________________________________________________
 *   PRE-CONDITIONS
 *   same
 *   POST-CONDITIONS
 *   An matrix is created
*****************************************************/
template <class T>
void Matrix<T>::setMatrix(const T m[]) {
    //PROCESSING - setting all elements in the matrix
    for (int i = 0; i < MAXROWS; i++) {
        for (int j = 0; j < MAXCOLS; j++) {
            array[i][j]=m[i*(MAXCOLS)+j];
        }
    }
}

/*****************************************************
 *
 *   void Matrix<T>::setMatrix(const T m[MAXROWS][MAXCOLS])
 ________________________________________________
 *   This function copies the elements in the 2d array passed
 *   in to the matrix that called the function.
 ________________________________________________
 *   PRE-CONDITIONS
 *   same
 *   POST-CONDITIONS
 *   An matrix is created
*****************************************************/
template<class T>
void Matrix<T>::setMatrix(const T m[MAXROWS][MAXCOLS]){

    //PROCESSING - setting all elements in the matrix
    for (int i = 0; i < MAXROWS; i++) {
        for (int j = 0; j < MAXCOLS; j++) {
            array[i][j]=m[i][j];
        }
    }
}


/*****************************************************
 *
 *   Matrix<T> Matrix<T>::operator+(const Matrix &m)
 ________________________________________________
 *   This function adds the passed in matrix to the called matrix.
 ________________________________________________
 *   PRE-CONDITIONS
 *   same
 *   POST-CONDITIONS
 *   A third matrix is created by adding two matrices
*****************************************************/

template<class T>
Matrix<T> Matrix<T>::operator+(const Matrix &m) {
    Matrix<T> res;
    //PROCESSING adding two elements and put it into the new matrix
    for (int i = 0; i < MAXROWS; i++) {
        for (int j = 0; j < MAXCOLS; j++) {
            res.array[i][j]=array[i][j]+m.array[i][j] ;
        }
    }
    //OUT - return the new matrix
    return res;
}


template class Matrix<string>;
template class Matrix<int>;
template class Matrix<double>;








