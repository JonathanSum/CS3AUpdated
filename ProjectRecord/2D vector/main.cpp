/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Lab 06 - 2D Vector
 *   SECTION        : CS 003A
 *   Due Date       : 3/09/19
 *   ________________________________________________
 *   Goals
 *   By the end of this lab I should:
 *   be more familiar with 2d vectors

***********************************************/
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
//#include "Date.h"
#include <cctype>
#include <cstring>
#include <cstdio>
#include <vector>

using namespace std;

void multMenu1(int &rowA        //IN row the the matrix A
        , int &colA        //IN column the the matrix A
        , int &rowB,        //IN row the the matrix B
               int &colB        //IN column the the matrix B
);

int main() {

    int m, n;           //IN m is number of row, and n is number of column
    //IN ask the user to input row and column
    cout << "Enter the number of rows and columns of the matrices to add: \n";
    cin >> m >> n;
    // PROCESSING if numbers of row is greater than column, then run this part of if statement
    if (m <= n) {


        vector<vector<int>> vectA;              //CALC & OUT, it is a vector to store  Matrix A
        vectA.resize(n, vector<int>(m));                     //CALC resize the vector to be the matrix

        //IN ask the user to input Matrix A
        cout << "Enter matrix A: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> vectA[i][j];
            }
        }
        //OUT print out the matrix A
        cout << "For matrix A you entered: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << vectA[i][j] << " ";
            }
            cout << endl;
        }

        //IN ask the user to input Matrix B
        vector<vector<int>> vectB;
        vectB.resize(n, vector<int>(m));

        //IN ask the user to input Matrix B
        cout << "Enter matrix B: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> vectB[i][j];
            }
        }
        //OUT print out the matrix B
        cout << "For matrix B you entered: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << vectB[i][j] << " ";
            }
            cout << endl;
        }
        //PROCESS addition part of two matrix
        cout << "sum of A and B is: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << vectA[i][j] + vectB[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;

        //PROCESS multiplication part of two matrix
        cout << "Now for multiplication.\n";
        int rowA, colA, rowB, colB;                 //CALC & OUT row and column of matrix A and B
        multMenu1(rowA, colA, rowB,
                  colB);          //PROCESSING this function will ask the users to input row and column, if row and col are irrcorrect for multiplication, then it will ask again.

//INPUT  Here is input and calc part of sum of two matrices
        vector<vector<int>> vectA1;                 //CALC & OUT matrix A
        vectA1.resize(colA, vector<int>(rowA));

        // INPUT ask the user to input two matrix, A and B.
        cout << "Enter matrix A: \n";
        for (int i = 0; i < rowA; i++) {
            for (int j = 0; j < colA; j++) {
                cin >> vectA1[i][j];
            }
        }

        cout << "For matrix A you entered: \n";
        for (int i = 0; i < vectA1[0].size(); i++) {
            for (int j = 0; j < vectA1.size(); j++) {
                cout << vectA1[i][j] << " ";
            }
            cout << endl;
        }
        vector<vector<int>> vectB1;                 //CALC & OUT matrix B
        vectB1.resize(colB, vector<int>(rowB));


        cout << "Enter matrix B: \n";
        for (int i = 0; i < vectB1[0].size(); i++) {
            for (int j = 0; j < vectB1.size(); j++) {
                cin >> vectB1[i][j];
            }
        }
        cout << "For matrix B you entered: \n";
        for (int i = 0; i < rowB; i++) {
            for (int j = 0; j < colB; j++) {
                cout << vectB1[i][j] << " ";
            }
            cout << endl;
        }

        vector<vector<int>> vectC;          //CALC & PROCESSING this matrix C is the multi of matrix A and B (A][B]=[C])

        vectC.resize(vectB1.size(), vector<int>(vectA1[0].size()));

        //PROCESSING and OUT   calc  sum of two matrices ( [A][B]=[C])
        for (int i = 0; i < vectC[0].size(); i++) {
            for (int j = 0; j < vectC.size(); j++) {
                int tempAmount = 0;

                for (int xi = 0; xi < vectC.size(); xi++) {

                    tempAmount += vectA1[i][xi] *
                                  vectB1[xi][j];        //CALC & OUT this tempAmount is element of matrix C or the matrix of AB.
                }
                vectC[i][j] = tempAmount;

            }

        }
        // OUT Print out the result matrix ([A][B]=[C])
        cout << "product of A and B is: \n";
        for (int i = 0; i < vectC[0].size(); i++) {
            for (int j = 0; j < vectC.size(); j++) {
                cout << vectC[i][j] << " ";
            }
            cout << endl;
        }

        //------------------------------------
        // PROCESSING if numbers of row is less than column, then run this part of if statement
    } else if (m > n) {
        vector<vector<int>> vectA;                  //CALC & OUT, it is a vector to store  Matrix A
        vectA.resize(n, vector<int>(m));

        // INPUT & OUT ask the user to input two matrix A and B, and print them out
        cout << "Enter matrix A: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> vectA[j][i];
            }
        }
        cout << "For matrix A you entered: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << vectA[j][i] << " ";
            }
            cout << endl;
        }
        vector<vector<int>> vectB;
        vectB.resize(n, vector<int>(m));


        cout << "Enter matrix B: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> vectB[j][i];
            }
        }
        cout << "For matrix B you entered: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << vectB[j][i] << " ";
            }
            cout << endl;
        }

        //CALC & OUT print out the sum of two matrix
        cout << "sum of A and B is: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << vectA[j][i] + vectB[j][i] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;

        //CALC & OUT the following part is the part of the multiplication of two Matrices A and B
        cout << "Now for multiplication.\n";
        int rowA, colA, rowB, colB;             //IN these are row and column of Matrices A and B
        multMenu1(rowA, colA, rowB,
                  colB);      //PROCESSING this function will ask the users to input row and column, if row and col are irrcorrect for multiplication, then it will ask again.


        vector<vector<int>> vectA1;             //CALC & OUT matrix A
        vectA1.resize(colA, vector<int>(rowA));


        //INPUT & OUT ask the User to input Matrices A and B and print them out
        cout << "Enter matrix A: \n";
        for (int i = 0; i < rowA; i++) {
            for (int j = 0; j < colA; j++) {
                cin >> vectA1[j][i];
            }
        }

        cout << "For matrix A you entered: \n";
        for (int i = 0; i < vectA1[0].size(); i++) {
            for (int j = 0; j < vectA1.size(); j++) {
                cout << vectA1[j][i] << " ";
            }
            cout << endl;
        }

        vector<vector<int>> vectB1;                     //CALC & OUT matrix B
        vectB1.resize(colB, vector<int>(rowB));

        cout << "Enter matrix B: \n";
        for (int i = 0; i < vectB1[0].size(); i++) {
            for (int j = 0; j < vectB1.size(); j++) {
                cin >> vectB1[j][i];
            }
        }
        cout << "For matrix B you entered: \n";
        for (int i = 0; i < rowB; i++) {
            for (int j = 0; j < colB; j++) {
                cout << vectB1[j][i] << " ";
            }
            cout << endl;
        }

        vector<vector<int>> vectC;          //CALC & OUT matrix C, which is the matrix of ([A][B]=[C])

        vectC.resize(vectB1.size(), vector<int>(vectA1[0].size()));

        //PROCESSING processing the matrix C, which is the matrix of ([A][B]=[C])
        for (int i = 0; i < vectC[0].size(); i++) {
            for (int j = 0; j < vectC.size(); j++) {
                int tempAmount = 0;

                for (int xi = 0; xi < vectC.size(); xi++) {

                    tempAmount += vectA1[xi][i] * vectB1[j][xi];
                }
                vectC[i][j] = tempAmount;

            }

        }

        //OUT print out the result matrix C
        cout << "product of A and B is: \n";
        for (int i = 0; i < vectC[0].size(); i++) {
            for (int j = 0; j < vectC.size(); j++) {
                cout << vectC[i][j] << " ";
            }
            cout << endl;
        }
    }
    return 0;
}
// This function will ask the user to input row and column of two matrices. If column of A is not the same as row of B, it will ask the user to input again
void multMenu1(int &rowA, int &colA, int &rowB, int &colB) {
    while (colA != rowB) {
        cout << "Enter the number of rows and columns of matrix A: \n";
        cin >> rowA >> colA;
        cout << "Enter the number of rows and columns of matrix B: \n";
        cin >> rowB >> colB;
        if (colA != rowB) {
            cout << "The number of columns of matrix A must be the same as the number of rows of matrix B.\n";
        }
    }
}
