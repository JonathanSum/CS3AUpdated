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
//    bool disappear;
};

void addParts(Part bin[], int addAmount, int index);

void removeParts(Part bin[], int index, int amount);

void addItem(Part bin[], string partTitle, int partAmount);

char getWhatTheyWant();

char selectedMenu();

void displayInventory(Part bin[]);

int main() {

//    int arr[99];
//    int capacity = sizeof(arr) / sizeof(arr[0]);
//    cout << to_string(capacity) << endl;
    string fileName;
//    cout<<"Enter name of inventory file: ";
//    cin>>fileName;
//    Part bin[10];
    vector<Part> bin;
    string name1 = "debug1";
    int amount = 1;
    Part myPart ={name1,amount};
    Part myPart1 ={"debug2",2};
    bin.push_back(myPart);
    bin.push_back(myPart1);
    for(int i=0;i<2;i++){
        cout<<bin[i].description<<endl;
        cout<<bin[i].partNum<<endl;
    }
    cout<<"For god sake where is my size of array: "<<bin.size()<<endl;

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
//            if (stoi(line) == 0) {
//                bin[m].disappear = false;
//            }
//            bin[m].partNum = stoi(line);
//            m++;
//        }
//        n++;
//
//    }
//    int sizeOfBin = 10;
//
//    for(int i=0;i<10;i++){
//        cout<<bin[i].description<<endl;
//        cout<<bin[i].partNum<<endl;
//    }
    char whatTheyWant;
//    do {
//        whatTheyWant = getWhatTheyWant();
//        string inputTitle;
//        int inputNumber;
//        int inputIndex;
//        if (whatTheyWant == 'a') {
//            cout << "Please enter the title of the new item that you want to create" << endl;
//            cin >> inputTitle;
//            cout << "Please enter the amount of the new item that you want to create" << endl;
//            cin >> inputNumber;
//            addItem(bin, inputTitle, inputNumber);
//        }else if(whatTheyWant='s'){
//            displayInventory(bin);
//        }
//
//
//    } while (!((whatTheyWant == 'Q') || (whatTheyWant == 'q')));


//    if (whatTheyWant == 'q') {
//        cout << endl << "Selection: " + (whatTheyWant) << endl;
//        cout << "Good Bye!!!" << endl;
//    }
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

char getWhatTheyWant() {
    char choice;
    cout << "Add a new item (a)" << endl;
    cout << "Select a bin (s)" << endl;
    cout << "Quit (q)" << endl;
    cin >> choice;
    return choice;
}

//This function can only add stuffs after the last element of the array
void addParts(Part (bin)[], int addAmount, int index) {

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

void removeParts(Part bin[], int index, int amount) {
    if (bin[index].partNum - amount < 0) {
        cout << "The selected bin does not have enough amount to be removed." << endl;
    } else {
        bin[index].partNum = bin[index].partNum - amount;
    }

}

void addItem(Part bin[], string partTitle, int partAmount) {

    if (partAmount > 0 && partAmount <= 30) {
        int capacity = *(&bin + 1) - bin; // or set this to ten since it is the size of the array
        cout << "size " << capacity << endl;
        Part newArray[capacity + 1];
        int capacity2 = capacity + 1;
        cout << "Updated size of array will be " << (capacity2) << endl;
        //debug forloop
        for (int i = 0; i <= capacity; i++) {

            newArray[i].description = bin[i].description;
            newArray[i].partNum = bin[i].partNum;

        }

        newArray[capacity2 - 1].description = partTitle;
        newArray[capacity2 - 1].partNum = partAmount;
        cout << "Debug name: " << bin[capacity2 - 1].description;
        cout << "Debug partNum: " << bin[capacity2 - 1].partNum;
        bin = newArray;

    }

}
//    else {
//        cout<< "Please input a part amount that is great than zero and no more than 30" <<endl;
//    }




char selectedMenu() {
    char choice;
    cout << "Menu:" << endl;
    cout << "Add parts (a)" << endl;
    cout << "Remove parts (r)" << endl;
    cin >> choice;
    return choice;
}

