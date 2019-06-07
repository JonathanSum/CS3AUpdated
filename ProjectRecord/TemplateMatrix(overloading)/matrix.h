//
// Created by JonathanSum on 5/16/2019.
//

#ifndef INC_3A_MATRIX_H
#define INC_3A_MATRIX_H
#include <iostream>
#include <iomanip>
#include <sstream>

using namespace std;
template<class T>
class Matrix {
    private:
        const int static MAXROWS=2;     //IN&OUT - number of rows of the matrix
        const int static MAXCOLS=3;     //IN&OUT - number of column of the matrix
        T array[MAXROWS][MAXCOLS];          //IN&OUT - The matrix itsel
        int rows;              //IN&OUT - number of rows of the matrix
        int cols;              //IN&OUT - number of column of the matrix
    public:
    /**************************************
    **      CONSTRUCTOR  AND DESTRUCTOR  **
    ***************************************/
        Matrix();
        /**********************
            * * ACCESSORS **
        **********************/
        void printMatrix() const;
//        friend std::ostream& operator<<(std::ostream& , const Matrix<T>&);
        template <class U>
        friend std::ostream& operator<<( std::ostream&, const Matrix<U> m  );

        /**********************
             * * MUTATORS **
        **********************/
        void setElement(int row, int col,
                T value);
        void setMatrix(const T m[]);
        void setMatrix(const T m[][MAXCOLS]);
        Matrix<T> operator+(const Matrix& m);
};
/*********************************************************************
* DoublyLinkedList Class
* This class represents a DoublyLinkedList object.
* It manages 5 attributes,
        const int static MAXROWS=2;     //IN&OUT - number of rows of the matrix
        const int static MAXCOLS=3;     //IN&OUT - number of column of the matrix
        T array[MAXROWS][MAXCOLS];          //IN&OUT - The matrix itsel
        int rows;              //IN&OUT - number of rows of the matrix
        int cols;              //IN&OUT - number of column of the matrix
*********************************************************************/

/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  Matrix();
 *  Constructor;    Initialize class by setting an empty matrix
 *  Parameter: none
 *  Return: none
*********************************************************************/
/*********************************************************************
                            * * ACCESSORS **
*********************************************************************/

/*********************************************************************
 * void printMatrix() const;
 * Accessors: This function displays
 * all of the elements of the array row by row.
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * template <class U>
 * friend std::ostream& operator<<( std::ostream&, const Matrix<U> m  );
 * Accessors: This function displays
 * all of the elements of the array row by row, by overloading the ostream operator.
 *--------------------------------------------------------------------
 * Parameter: ostream&,         //IN - ostream object
 *    const Matrix<U> m  );     //IN - another Matrix to be added
 *--------------------------------------------------------------------
 * Return: ostream
*********************************************************************/
/*********************************************************************
                            * * MUTATORS **
*********************************************************************/
/*********************************************************************
 * void push_front(int value);
 * Mutator: Add a node with a integer value to the front the linked
 * list.
 *--------------------------------------------------------------------
 * Parameter: value // IN - the value of the new node that is
 * is going to be added to the front of the linked list.
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void setElement(int row, int col, T value);
 * Mutator: This function sets the appropriate element
 * in the Matrix to the value passed in.
 *--------------------------------------------------------------------
 * Parameter: int row,        //IN - number of row
                int col,        //IN - number of column
                T value;       //IN - the value to be changed
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void setMatrix(const T m[]);
 * Mutator: This function copies the elements in a 1d array and stores it into the 2d matrix.
 *--------------------------------------------------------------------
 * Parameter: const T m[]      //IN - the 1d matrix to be copied to the Matrix class
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void setMatrix(cconst T m[][MAXCOLS]);
 * Mutator: This function copies the elements in a 2d array and stores it into the 2d matrix.
 *--------------------------------------------------------------------
 * Parameter: const T m[][MAXCOLS]         //IN - the 2d matrix to be copied to the Matrix class
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/

/*********************************************************************
 * Matrix<T> operator+(const Matrix& m);
 * Mutator: This function adds the passed in matrix to the called matrix.
 *--------------------------------------------------------------------
 * Parameter: const Matrix& m         //IN - other matrix to be added
 *--------------------------------------------------------------------
 * Return: Matrix<T> object
*********************************************************************/


/*****************************************************
 *
 *   std::ostream& operator<<( std::ostream& out, const Matrix<T> m ): Class Matrix
 ________________________________________________
 *   This function displays all of the elements of the array row by row,
 *   by overloading the ostream operator.
 ________________________________________________
 *   PRE-CONDITIONS
 *   same
 *   POST-CONDITIONS
 *   A whole matrix is printed
*****************************************************/
template <typename T>
std::ostream& operator<<( std::ostream& out, const Matrix<T> m ) {
    for (int i = 0; i < m.MAXROWS; i++) {
        for (int j = 0; j < m.MAXCOLS; j++) {
            out << setprecision(2) <<m.array[i][j]<<"   ";     //IN - putting them
                                                               // into the ostream

        }
        out<<endl;
    }

//    out<<output;
    return out;
}



#endif //INC_3A_MATRIX_H
