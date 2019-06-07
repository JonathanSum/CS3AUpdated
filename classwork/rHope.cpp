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
    bool disappear;
};

void addParts(Part bin[], int addAmount, int index);

void removeParts(Part bin[], int index, int amount);


char getWhatTheyWant();

char selectedMenu();

void addItem(vector<Part> &bin, string partTitle, int partAmount);

void displayInventory(vector<Part> bin);

int main() {

//    int arr[99];
//    int capacity = sizeof(arr) / sizeof(arr[0]);
//    cout << to_string(capacity) << endl;
    string fileName;
//    cout<<"Enter name of inventory file: ";
//    cin>>fileName;
    vector<Part> bin;
    ifstream binFile;
    binFile.open("t3.txt");
    string title;
    string line;
    int n = 1;
    int m = 0;

    string itemName;
    int amount;
    bool notShow;

    while (getline(binFile, line)) {

        if (n % 2 == 1) {
            //There is a bug which need to be solve.
            //Somehow by using getLine to get each line from a file, the last index of the line has a null index or whatever it is.
            //As a result, the follow int, or possible true to other type of var, can not be output or sometimes is printed to the next line.
//            line[line.length() - 1] = 0;
            itemName = line;

        } else if (n % 2 == 0) {
            if (stoi(line) == 0) {
                notShow = true;
            }
            amount = stoi(line);
            cout<<n<<" and amount: "<<amount<<endl;

            //when the n is even, we finally add the item into the array.
            bin.push_back({itemName, amount, notShow});
            m++;
        }


        n++;

    }
    cout << "For god sake where is my size of array: " << bin.size() << endl;
    displayInventory(bin);


    int whatTheyWant;
    whatTheyWant = getWhatTheyWant();
    while (whatTheyWant != 'q') {

        string inputTitle;
        int inputNumber;
        int inputIndex;
        switch(whatTheyWant){
            case 'a':
                cout << "Please enter the title of the new item that you want to create" << endl;
                cin >> inputTitle;
                cout << "Please enter the amount of the new item that you want to create" << endl;
                cin >> inputNumber;
                addItem(bin, inputTitle, inputNumber);
                whatTheyWant = getWhatTheyWant();
                break;
            case 's':
                displayInventory(bin);
                break;
        }

        whatTheyWant = getWhatTheyWant();
    }


    if (whatTheyWant == 'q') {
        cout << endl << "Selection: " + (whatTheyWant) << endl;
        cout << "Good Bye!!!" << endl;

    }


    displayInventory(bin);
    binFile.close();
    return 0;
}

void displayInventory(vector<Part> bin) {
    cout << "my size of array: " << bin.size() << endl;
    cout << setw(36) << "Part Description" << setw(30) << "Number of Parts in the Bin" << endl;
    int sizeOfArray = bin.size();
    for (int i = 0; i < sizeOfArray; i++) {
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
void addParts(vector<Part> bin, int addAmount, int index) {

    if (addAmount > 0) {
        if (bin[index].partNum + addAmount > 30) {
            cout << "No bin can hold more than 30 parts" << endl;
        } else {
            bin[index].partNum += addAmount;
        }
    } else {
        cout << "Please input a positive integer for an increase";
    }
}

void removeParts(vector<Part> bin, int index, int amount) {
    if (bin[index].partNum - amount < 0) {
        cout << "The selected bin does not have enough amount to be removed." << endl;
    } else {
        bin[index].partNum = bin[index].partNum - amount;
    }

}

void addItem(vector<Part> &bin, string partTitle, int partAmount) {
    if (partAmount > 0 && partAmount <= 30) {
        cout << "For god sake where is my size of array: " << bin.size() << endl;
        cout << "adding" << endl;
        bin.push_back({partTitle, partAmount, false});
        cout << bin[10].description << endl;
        cout << bin[10].partNum << endl;
        cout << "2my size of array: " << bin.size() << endl;
    } else {
        cout << "Please input a part amount that is great than zero and no more than 30" << endl;
    }

}


char selectedMenu() {
    char choice;
    cout << "Menu:" << endl;
    cout << "Add parts (a)" << endl;
    cout << "Remove parts (r)" << endl;
    cin >> choice;
    return choice;
}

