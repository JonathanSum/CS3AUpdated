/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Lab 03 Specifications
 *   SECTION        : CS 003A
 *   Due Date       : 2/27/19
 *   ________________________________________________
 *   Write a program that simulates inventory bins in a warehouse. Each bin holds a number of the
 *   same type of parts. The program should use a structure that keeps the following data:
 *   Description of the part kept in the bin
 *   Number of parts in the bin
 *   The program should have an array of 30 bins, initialized with the following data:
***********************************************/
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
#include <vector>

using namespace std;
struct Part {
    string description; // Product description
    int partNum; // Part number
};

void addParts();

void removeParts();

void addItem();

string getWhatTheyWant();

void displayInventory(Part bin[]);

int main() {

    int arr[5]={1,2,3,4,5};
    int capacity = sizeof(arr) / sizeof(arr[0]);
    cout << to_string(capacity) << endl;
    string fileName;
    int temp[capacity+1];
    int capacity2 = sizeof(temp) / sizeof(temp[0]);
    int newItem=8;
    cout << to_string(capacity2) << endl;
    for(int i=0;i<=capacity+1;i++){
        if(i==(capacity+1)){
            cout<<"adding"<<endl;
            temp[i]=newItem;
        }else{
            cout<<"I am i: "<<i<<endl;
            temp[i]=arr[i];
        }


    }
    for(int i=0; i<=(capacity+1); i++){
        cout<<temp[i]<<endl;
    }
////    cout<<"Enter name of inventory file: ";
////    cin>>fileName;
//    Part bin[10];
//    ifstream binFile;
//    binFile.open("t3.txt");
//    string title;
//    string line;
//    int n = 1;
//    int m = 0;
//    while (getline(binFile, line)) {
//        if (n % 2 == 1) {
//
//            bin[m].description = line;
//
//        } else if (n % 2 == 0) {
//            bin[m].partNum = stoi(line);
//            m++;
//        }
//        n++;
//
//    }
//
//
//    string whatTheyWant;
//    whatTheyWant = getWhatTheyWant();
//    if (whatTheyWant == "q") {
//        cout << endl << "Selection: " + (whatTheyWant) << endl;
//        cout << "Good Bye!!!" << endl;
//    }
//    while (whatTheyWant != "q") {
//        cout << endl << "Selection: " + (whatTheyWant) << endl;
//
//
//        whatTheyWant = getWhatTheyWant();
//    }
//
//
//    displayInventory(bin);
//    binFile.close();
    return 0;
}

void displayInventory(Part bin[]) {
    cout << setw(36) << "Part Description" << setw(30) << "Number of Parts in the Bin" << endl;

    for (int i = 0; i < 10; i++) {
        //There is a bug which need to be solve.
        //Somehow by using getLine to get each line from a file, the last index of the line has a null index or whatever it is.
        //As a result, the follow int, or possible true to other type of var, can not be output or sometimes is printed to the next line.
        bin[i].description[bin[i].description.length() - 1] = 0;
        cout << setw(36) << bin[i].description << setw(30) << bin[i].partNum << endl;
    }
}

string getWhatTheyWant() {
    string choice;
    cout << "Add a new item (a)" << endl;
    cout << "Select a bin (s)" << endl;
    cout << "Quit (q)" << endl;
    cin >> choice;
    return choice;
}

void addParts(Part bin[], int addAmount, int index) {
    if (addAmount > 0) {
        if (bin[index].partNum + addAmount) {
            cout << "No bin can hold more than 30 parts" << endl;
        } else {
            bin[index].partNum += addAmount;
        }
    } else {
        cout << "Please input a positive integer for an increase";
    }
}

void removeParts(Part bin[], int index) {
    bin[index].partNum = 0;
}

void addItem(string title, int partNumber, Part bin[]) {
    int capacity = sizeof(bin) / sizeof(bin[0]);
    Part temp[capacity+1];
    for(int i; i<capacity;i++){
        temp[i].description=bin[i].description;
        temp[i].partNum=bin[i].partNum;

    }
}

string getWhatTheyWant2() {
    string choice;
    cout << "Menu:" << endl;
    cout << "Add parts (a)" << endl;
    cout << "Remove parts (r)" << endl;
    cin >> choice;
    return choice;
}

