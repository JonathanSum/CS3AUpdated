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

void multMenu1(int &rowA, int &colA, int &rowB, int &colB);




int main() {

    int m, n;           // m is number of row, and n is number of column
    cout << "Enter the number of rows and columns of the matrices to add: \n";
    cin >> m >> n;
    if (m <= n) {
        vector<vector<int>> vectA;
        vectA.resize(n, vector<int>(m));


        cout << "Enter matrix A: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> vectA[i][j];
            }
        }
        cout << "For matrix A you entered: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << vectA[i][j] << " ";
            }
            cout << endl;
        }
        vector<vector<int>> vectB;
        vectB.resize(n, vector<int>(m));


        cout << "Enter matrix B: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cin >> vectB[i][j];
            }
        }
        cout << "For matrix B you entered: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << vectB[i][j] << " ";
            }
            cout << endl;
        }
        cout << "sum of A and B is: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << vectA[i][j] + vectB[i][j] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
        cout << "Now for multiplication.\n";
        int rowA, colA, rowB, colB;
        multMenu1(rowA, colA, rowB, colB);

//here is input and calc part of sum of two matrices
        vector<vector<int>> vectA1;
        vectA1.resize(colA, vector<int>(rowA));
//    cout<<"rA: "<<rowA<<endl;
//    cout<<"cA: "<<colA<<endl;
//    cout<<"srA: "<< vectA1[0].size()<<endl;
//    cout<<"scA: "<< vectA1.size()<<endl;            //if number of vectors in the Matrix is 3, then col of Matrix A is 3.


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
        vector<vector<int>> vectB1;
        vectB1.resize(colB, vector<int>(rowB));
//    cout<<"rA: "<<rowB<<endl;
//    cout<<"cA: "<<colB<<endl;
//    cout<<"srA: "<< vectB1[0].size()<<endl;
//    cout<<"scA: "<< vectB1.size()<<endl;

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

        vector<vector<int>> vectC;

        vectC.resize(vectB1.size(), vector<int>(vectA1[0].size()));
//    cout<<"rA: "<<rowA<<endl;
//    cout<<"cA: "<<colB<<endl;
//    cout<<"srA: "<< vectC[0].size()<<endl;
//    cout<<"scA: "<< vectC.size()<<endl;
        for (int i = 0; i < vectC[0].size(); i++) {
            for (int j = 0; j < vectC.size(); j++) {
                int tempAmount = 0;

                for (int xi = 0; xi < vectC.size(); xi++) {
//                cout<<"Debug size: "<<xi<<" "<<vectA[0].size()<<endl;
                    tempAmount += vectA1[i][xi] * vectB1[xi][j];
                }
                vectC[i][j] = tempAmount;
//            cout<<tempAmount<<" ";
            }
//        cout<<endl;
        }

        cout << "product of A and B is: \n";
        for (int i = 0; i < vectC[0].size(); i++) {
            for (int j = 0; j < vectC.size(); j++) {
                cout << vectC[i][j] << " ";
            }
            cout << endl;
        }
//-------------------------------------------------------------
    } else if (m > n) {
        vector<vector<int>> vectA;
        vectA.resize(n, vector<int>(m));


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
        cout << "sum of A and B is: \n";
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                cout << vectA[j][i] + vectB[j][i] << " ";
            }
            cout << endl;
        }
        cout << endl << endl;
        cout << "Now for multiplication.\n";

        int rowA, colA, rowB, colB;

        multMenu1(rowA, colA, rowB, colB);


//here is input and calc part of sum of two matrices
        vector<vector<int>> vectA1;

        vectA1.resize(colA, vector<int>(rowA));

//    cout<<"rA: "<<rowA<<endl;
//    cout<<"cA: "<<colA<<endl;
//    cout<<"srA: "<< vectA1[0].size()<<endl;
//    cout<<"scA: "<< vectA1.size()<<endl;            //if number of vectors in the Matrix is 3, then col of Matrix A is 3.


        cout << "Enter matrix A: \n";
        for (int i = 0; i < rowA; i++) {
            for (int j = 0; j < colA; j++) {
                cin >> vectA1[j][i];
            }
        }
        cout<<"Debug Here"<<endl;
        cout << "For matrix A you entered: \n";
        for (int i = 0; i < vectA1[0].size(); i++) {
            for (int j = 0; j < vectA1.size(); j++) {
                cout << vectA1[j][i] << " ";
            }
            cout << endl;
        }
        vector<vector<int>> vectB1;
        vectB1.resize(colB, vector<int>(rowB));
//    cout<<"rA: "<<rowB<<endl;
//    cout<<"cA: "<<colB<<endl;
//    cout<<"srA: "<< vectB1[0].size()<<endl;
//    cout<<"scA: "<< vectB1.size()<<endl;

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

        vector<vector<int>> vectC;

        vectC.resize(vectB1.size(), vector<int>(vectA1[0].size()));
//    cout<<"rA: "<<rowA<<endl;
//    cout<<"cA: "<<colB<<endl;
//    cout<<"srA: "<< vectC[0].size()<<endl;
//    cout<<"scA: "<< vectC.size()<<endl;
        for (int i = 0; i < vectC[0].size(); i++) {
            for (int j = 0; j < vectC.size(); j++) {
                int tempAmount = 0;

                for (int xi = 0; xi < vectC.size(); xi++) {
//                cout<<"Debug size: "<<xi<<" "<<vectA[0].size()<<endl;
                    tempAmount += vectA1[xi][i] * vectB1[j][xi];
                }
                vectC[i][j] = tempAmount;
//            cout<<tempAmount<<" ";
            }
//        cout<<endl;
        }

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
