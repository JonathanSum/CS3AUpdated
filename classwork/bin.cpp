/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Lab 04  Bin project
 *   SECTION        : CS 003A
 *   Due Date       : 2/26/19
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

void addParts(vector<Part> &bin, int addAmount, int index);

void removeParts(vector<Part> &bin, int index, int amount);


char getWhatTheyWant();

char selectedMenu();

void addItem(vector<Part> &bin, string partTitle, int partAmount);

void displayInventory(vector<Part> bin);

int main() {


    string fileName;
    cout<<"Enter name of inventory file: ";
    cin>>fileName;
    vector<Part> bin;
    ifstream binFile;
    binFile.open("fileName");
    string title;
    string line;
    int n = 1;
    int m = 0;

    string itemName;
    int amount;
    bool notShow;

    while (getline(binFile, line)) {

        if (n % 2 == 1) {
            //There is a bug which need to be solved.
            //Somehow by using getLine to get each line from a file, the last index of the line has a null index or whatever it is.
            //As a result, the follow int, or possible true to other type of var, can not be output or sometimes is printed to the next line.
//            line[line.length() - 1] = 0;
            line.erase(line.length() - 1, 1);
            itemName = line;

        } else if (n % 2 == 0) {
            if (stoi(line) == 0) {
                notShow = true;
            }
            amount = stoi(line);


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


        int inputNumber;
        int inputIndex;
        string inputTitle;
        switch (whatTheyWant) {
            case 'a':
                cout << "Selection: " << (whatTheyWant) << endl;
                cout << "Please enter the title of the new item that you want to create" << endl;
                cin >> inputTitle;
                cout << "Please enter the amount of the new item that you want to create" << endl;
                cin >> inputNumber;
                addItem(bin, inputTitle, inputNumber);
                break;
            case 's':
                cout << "Selection: " << "s" << endl;
                cout << "Bin Selection: " << endl;
                cin >> inputTitle;

                vector<Part>::iterator it;
                vector<string> searchNames;

                //This part is for searching the element's index
                bool inside;
                int index;
                for (int i = 0; i < bin.size(); i++) {
                    if (bin[i].description == inputTitle) {
                        inside = true;
                        index = i;

                    } else {
                        inside = false;
                    }
                }
                char whatTheyWant2 = selectedMenu();
                if(whatTheyWant2=='a'){
                    int addAmount;
                    cout<<"Enter the amount that you want to add"<<endl;
                    cin>>addAmount;
                    addParts(bin,addAmount,index);
                } else if(whatTheyWant2=='r'){
                    int removeAmount;
                    cout<<"Enter the amount that you want to remove"<<endl;
                    cin>>removeAmount;
                    removeParts( bin, index,  amount);

                }



                break;
        }

        whatTheyWant = getWhatTheyWant();
    }


    if (whatTheyWant == 'q') {
        cout << endl << "Selection: " << whatTheyWant << endl;
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
//        bin[i].description[bin[i].description.length() - 1] = 0;
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
void addParts(vector<Part> &bin, int addAmount, int index) {

    if (addAmount > 0) {
        if (bin[index].partNum + addAmount > 30) {
            cout << "No bin can hold more than 30 parts" << endl;
        } else {
            cout<<"Debug adding parts: "<<bin[index].partNum<<" Now will be adding by: "<<addAmount<<endl;
            bin[index].partNum += addAmount;
        }
    } else {
        cout << "Please input a positive integer for an increase";
    }
}

void removeParts(vector<Part> &bin, int index, int amount) {
    if (bin[index].partNum - amount < 0) {
        cout << "The selected bin does not have enough amount to be removed." << endl;
    } else {
        cout<<"Debug removing: "<<bin[index].partNum<<" Now will be taken out by: "<<amount<<endl;
        bin[index].partNum -= amount;
    }

}

void addItem(vector<Part> &bin, string partTitle, int partAmount) {
    if (partAmount > 0 && partAmount <= 30) {
        cout << "adding" << endl;
        bin.push_back({partTitle, partAmount, false});

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

