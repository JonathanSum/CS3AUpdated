#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstring>


using namespace std;


int recureSum(int num) {
    if (num == 1) {
        return 1;
    } else {
        return num + recureSum(num - 1);
    }
}

int findmin(const int a[], int n) {
    int min;
    if (n == 0) {
        return a[0];
    }
    if (a[n - 1] < findmin(a, n - 1))
        return a[n - 1];
    if (findmin(a, n - 1) < a[n - 1])
        return findmin(a, n - 1);
    else
        return a[n - 1];
}

int findsum(const int a[], int n) {
    if (n == 0) {
        return 0;
    } else {
        return a[n - 1] + findsum(a, n - 1);

    }
}

bool ispalindrome(const char a[], int n) {
    int size = sizeof(a)/sizeof(a[0]);
    cout<<"Size: "<<size<<endl;
//    int midpoint=((size)/2);
//    cout<<"Midpoint: "<<midpoint<<endl;
//    if (midpoint >= n) {
//        return true;
//    }
//    if (a[size-n] == a[n-1])
//        return ispalindrome(a, n - 1);
//    else {
//        cout<<n<<endl;
//        return false;
//    }
return false;
}

int main() {


}
