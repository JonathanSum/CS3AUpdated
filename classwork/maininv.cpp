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
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <iostream>
#include <fstream>
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




//    int arr[99];
//    int capacity = sizeof(arr) / sizeof(arr[0]);
//            cout<<to_string(capacity)<<endl;
    string fileName;
//    cout<<"Enter name of inventory file: ";
//    cin>>fileName;

    ifstream theFile("inventory.txt");
    string title;
    int amount;
    int index=0;
    Part bin[30];
//    while(theFile>>title){
//        cout<<title<<endl;
//        bin[index].description=title;
//        theFile>>amount;
//        cout<<amount<<endl;
//    }
int n=0;
theFile>>bin[n].description;
while(theFile){
    theFile>>bin[n].partNum;
    n++;
    theFile>>bin[n].description;
}


//    while (true) {
//        string x;
//        int y;
//        theFile >> x;
//        theFile >> y;
//
//
//        cout<<x<<endl;
//        cout<<"I am a line"<<endl;
//
//        if( theFile.eof() ) break;
//
//    }
//    string whatTheyWant;
//    whatTheyWant = getWhatTheyWant();
//    if(whatTheyWant=="q"){
//        cout<<endl<<"Selection: "+(whatTheyWant)<<endl;
//        cout<<"Good Bye!!!"<<endl;
//    }
//    while (whatTheyWant != "q") {
//        cout<<endl<<"Selection: "+(whatTheyWant)<<endl;
//
//
//
//
//        whatTheyWant = getWhatTheyWant();
//    }




//    for(int i=0; i<11;i++){
//        string description;
//        int partNum;
//        description=bin[i].description;
//        partNum=bin[i].partNum;
//        cout<<description+"\n";
//        cout<<to_string(partNum)+"\n";
//    }
    theFile.close();
//    displayInventory(bin);

    return 0;
}
//
void displayInventory(Part bin[]) {
    cout << setw(36) << "Part Description" << setw(30) << "Number of Parts in the Bin" << endl;

    for (int i = 0; i < 10; i++) {

        cout << setw(36) << bin[i].description << setw(30) << bin[i].partNum << endl;
    }
}

//string getWhatTheyWant() {
//    string choice;
//    cout << "Add a new item (a)" << endl;
//    cout << "Select a bin (s)" << endl;
//    cout << "Quit (q)" << endl;
//    cin >> choice;
//    return choice;
//}
//void addParts(){
//
//}
//void removeParts(){
//
//}
//void addItem(){
//
//}
//
//string getWhatTheyWant2() {
//    string choice;
//    cout<<"Menu:"<<endl;
//    cout << "Add parts (a)" << endl;
//    cout << "Remove parts (r)" << endl;
//    cin >> choice;
//    return choice;
//}








