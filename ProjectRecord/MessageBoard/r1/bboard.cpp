//
// Created by JonathanSum on 3/15/2019.
//
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <string>
#include <iostream>
#include <vector>
#include <sstream>
#include "bboard.h"
#include <fstream>

void BBoard::setup(const string &input_file) {
    ifstream fin(input_file.c_str());
    string nameFile;
    string passwordFile;
    if(!fin.is_open()){
        cout<<"File did not opened"<<endl;
    }else{
        while (fin >> nameFile >> passwordFile) {
            user_list.emplace_back(nameFile, passwordFile);
        }
        fin.close();
    }

//    cout<<"Debuging user"<<endl;
//    for(int i=0; i<5; i++){
//        cout<<user_list[i].get_username()<<endl;
//    }
    cout << "Welcome!" << endl;
    login();
    cout << "Bye" << endl;
}

void BBoard::login() {

    string name;
    string password;
    //Login in Menu
    while (true) {
        cout << "Enter your username (\"Q\" or \"q\" to quit): \n";
        cin >> name;
        if (name == "Q" || name == "q") {
            cout << "Bye" << endl;
            exit(0);
        }
        if (name != "q" || name != "Q") {
            cout << "Enter your password: \n";
            cin >> password;
            for (int i = 0; i < user_list.size(); i++) {
                if (user_list[i].check(name, password)) {
                    current_user = User(name, password);
                    run();
                }
                if (i == user_list.size() - 1) {
                    cout << "Invalid Username or Password!" << endl;
                }
            }
        }

    }
}


void BBoard::run() {
    //Main Menu after valid login
    //     - Display Messages ('D' or 'd')
    //     - Add New Message ('N' or 'n')
    //     - Quit ('Q' or 'q')
//        ricq7   bjk1903
    int n=0;
    char choice;
    while (!current_user.get_username().empty()) {
        if(n==0){
            cout << "Welcome back " << current_user.get_username() <<"!\n"<< endl;
            n++;
        }
//        Note: if login() has not set a valid current_user, this function must abort
//        without showing the menu - i.e. there must be no way to get around
//        logging in!
        cout << "Menu\n";
        cout << "  - Display Messages ('D' or 'd')" << endl;
        cout << "  - Add New Message ('N' or 'n')" << endl;
        cout << "  - Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: "<<endl;
        cin>> choice;
        string subject, body;
        switch (choice) {
            case 'D':
            case 'd':
//                printf("     - Display Messages ('D' or 'd')");
                if (message_list.empty()) {
                    cout << "Nothing to display\n";
                } else {
                    cout<<"-----------------------------------------------\n";
                    int index =1;
                    for (auto &i : message_list) {
                        cout<<"Message #"<<index<< " : ";
                        i.display();
                        index++;
                        cout<<"-----------------------------------------------\n";
//                        if(index==1){
//                            cout<<"\n";
//                        }
                    }
                    cout<<"\n";
                }
                break;
            case 'N':
            case 'n':
                cin.clear();
                std::cin.ignore(256, '\n');
                cout << "Enter Subject: ";
                cout << "Enter Body: ";
                getline(cin, subject);
                getline(cin, body);
                message_list.emplace_back(current_user.get_username(),subject,body);
                cout<<"Message Recorded!\n"<<endl;
                break;
            case 'Q':
            case 'q':
                cout << "Bye!" << endl;
                exit(0);
        }
    }

}

void BBoard::add_user(istream &infile, const string &name, const string &pass) {

}
