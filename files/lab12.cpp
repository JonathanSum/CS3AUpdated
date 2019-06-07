#include <iostream>
#include <stdlib.h>     /* srand, rand */
#include <time.h>       /* time */
#include <cstring>
#include <vector>
/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Lab 13 - Recursion
 *   SECTION        : CS 003A
 *   Due Date       : 4/23/19
 *   ________________________________________________
 *   Goal: practice writing your own recursive functions
***********************************************/

using namespace std;

/***************************************************
 *
 *   FUNCTION int sum(int n)
 ________________________________________________
 *   This method computes the sum of all numbers
 *   from 1 to n
 ________________________________________________
 *   PRE-CONDITIONS
 *   input the number n in integer
 *   POST-CONDITIONS
 *   computes the sum of all numbers
*****************************************************/
int sum(int n           //IN - input number
);

/***************************************************
 *
 *   FUNCTION findmin
 ________________________________________________
 *   A recursive function that finds the minimum element
 *   and returns the minimum element in an array
 ________________________________________________
 *   PRE-CONDITIONS
 *   input an array and its size
 *   POST-CONDITIONS
 *   returns the minimum element in an array
*****************************************************/
int findmin(const int a[]           //IN - array to find the smallest number
                 , int n);           //IN - size of array

/***************************************************
 *
 *   FUNCTION findsum
 ________________________________________________
 *   A recursive function that computes and returns
 *   the sum of all elements in an array
 ________________________________________________
 *   PRE-CONDITIONS
 *   input an array and its size
 *   POST-CONDITIONS
 *   returns the sum of each element in the array
*****************************************************/
int findsum(const int a[]           //IN - array to find the sum of the array
            , int n);



/***************************************************
 *
 *   FUNCTION ispalindrome
 ________________________________________________
 *   A recursive function that determines whether
 *   an array is a palindrome array
 ________________________________________________
 *   PRE-CONDITIONS
 *   input the array and its size
 *   POST-CONDITIONS
 *   returns a boolean that if the array is
 *   palindrome it will return true.
*****************************************************/
bool ispalindrome(const char a[]            //IN - array to check ispalindrome
                    , int n);               //IN - size of the array

/***************************************************
 *
 *   FUNCTION generate_substrings
 ________________________________________________
 *   A function that generates all
 *   substrings of a string
 ________________________________________________
 *   PRE-CONDITIONS
 *   input a string
 *   POST-CONDITIONS
 *   return a vector array in string that has
 *   all the substrings
*****************************************************/
vector<string> generate_substrings(string s);

/***************************************************
 *
 *   FUNCTION drawPattern
 ________________________________________________
 *   A recursive function that takes as a parameter
 *   a nonnegative integer and generates
 *   the following pattern of stars.
 ________________________________________________
 *   PRE-CONDITIONS
 *   input a positive number
 *   POST-CONDITIONS
 *   print stars on screen
*****************************************************/
void drawPattern(int n          //IN - positive number for drawing a pattern
                    );
int main() {
/****
    int num = recureSum(10);
    cout<<num<<endl;
    int arr2[] = {5, 2, 3, 4, 5, 6, 7, 8};
    int arr[] = { 3, 20, 30, 40,5, 80, 50,1 };
    int num2;
    cout<<arr[7];
    cout<<endl;
    num2 = findsum(arr,8);
    cout<<num2;
    char a[7] = {'a', 'b', 'd','d', 'c', 'b', 'a'};
    if(ispalindrome(a, 7)){
        cout<<"Yes, It is\n";
    }else if(!ispalindrome(a,7)){
        cout<<"No,it isn't.";
    }
        string str = "rum";
    vector<string> list2= generate_substrings(str);
    cout<<"-------"<<endl;
    for(int i =0; i<list2.size();i++){
        cout<<list2[i]<<endl;
    }
    ****/



}

int sum(int n           //IN - input number
) {
    if (n == 1) {
        return 1;
    } else {
        return n + sum(n - 1);
    }
}

int findmin(const int a[]           //IN - array to find the smallest number
        , int n                       //IN - size of the array
) {
    //PROCESSING -  base cause to return the first element
    if (n == 0) {
        return a[0];
    }
    //PROCESSING -  if it is small, return the small number at last
    if (a[n - 1] < findmin(a, n - 1))
        return a[n - 1];
    //PROCESSING -  if it is small, return the small number in the array
    if (findmin(a, n - 1) < a[n - 1])
        return findmin(a, n - 1);
    else
        return a[n - 1];
}

int findsum(const int a[]           //IN - array to find the sum of the array
        , int n) {
    //PROCESSING -  Keep recursiving to calc the sum
    if (n == 0) {
        return 0;
    } else {
        return a[n - 1] + findsum(a, n - 1);

    }
}

bool ispalindrome(const char a[]            //IN - array to check ispalindrome
        , int n)               //IN - size of the array
  {
      //PROCESSING - base cause to return true if it is ispalindrome
    if (n == 0 || n == 1) {
        return true;

    }
      //PROCESSING - return true if two elements are same
    if (a[0] == a[n - 1]) {
        string str(a);
        str = str.substr(1, static_cast<unsigned long>(n - 1));
        char a2[n - 2];
        strcpy(a2, str.c_str());
        return ispalindrome(a2, n - 2);

        //PROCESSING - return false if two elements are not same
    } else {

        return false;
    }

}

vector<string> generate_substrings(string s         //IN - input string
) {
    vector<string> list;
    //PROCESSING - loop thru each element
    for (int i = 0; i < s.size(); i++) {
        string head = string(1, s[i]);
        cout <<"starting: "<< head << endl;
        list.push_back(head);

        //PROCESSING - add each element for substring
        for (int j = i+1; j < s.size(); j++) {
            list.push_back(list[(list.size()-1)]+s[j]);
            cout<<"j is: "<<j<<": ";
            cout<<s[j];
            cout<<endl;
        }
    }
    list.push_back("");
    //OUT - return the list
    return list;

}

void drawPattern(int n      //IN - input positive number for drawing the pattern
){

    //PROCESSING - base case if n is 1, then print nonthing
    if (n < 1)
        cout << "";
    else {
        //PROCESSING - print the upper part of pattern
        for(int i=0;i<n;i++){
            cout<<"*";
        }
        cout<<endl;

        //PROCESSING - recursive  the function
        drawPattern(n-1);

        //PROCESSING - print the lower part of pattern
        for(int i=0;i<n;i++){
            cout<<"*";
        }
        cout<<endl;
    }
}

















