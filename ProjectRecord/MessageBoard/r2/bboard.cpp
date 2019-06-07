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

/*************************************
 *      setup(const string &input_file)
 *      This method set up the programming in the beginning
 *      It reads the file, prints out the title, runs store the username
 *      and password from the file it reads
 **************************************/
void BBoard::setup(const string &input_file) {
    ifstream fin(input_file.c_str());
    string nameFile;
    string passwordFile;
    if (!fin.is_open()) {
        cout << "File did not opened" << endl;
    } else {
        while (fin >> nameFile >> passwordFile) {
            user_list.emplace_back(nameFile, passwordFile);
        }
        fin.close();
    }

    cout << "Welcome!" << endl;
    login();
    cout << "Bye" << endl;
}

/**************************************************************************
*      login()
*      this method ask the user to login by logining in
*      It asks the user to input the username and password, it failed it will repeatly ask
*      to login. Other wise, it will set the current user attirbutes
*      to the username which was input.
****************************************************************************/
void BBoard::login() {

    string name;
    string password;

    //IN/OUT - Login in Menu
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
/**************************************************************************
*      run()
*      It dis play the menu, store message, or quit the program
****************************************************************************/

void BBoard::run() {
    int n = 0;
    char choice;

//        CACL & OUT - if login() has not set a valid current_user, this function abort
//        without showing the menu
    while (!current_user.get_username().empty()) {
        if (n == 0) {
            cout << "Welcome back " << current_user.get_username() << "!\n" << endl;
            n++;
        }

//  OUT/IN - showing a menu for display and inputing message
        cout << "Menu\n";
        cout << "  - Display Messages ('D' or 'd')" << endl;
        cout << "  - Add New Message ('N' or 'n')" << endl;
        cout << "  - Quit ('Q' or 'q')" << endl;
        cout << "Choose an action: " << endl;
        cin >> choice;
        string subject, body;
        switch (choice) {
            case 'D':
            case 'd':
                if (message_list.empty()) {
                    cout << "Nothing to display\n";
                } else {
                    cout << "-----------------------------------------------\n";
                    int index = 1;
                    for (auto &i : message_list) {
                        cout << "Message #" << index << " : ";
                        i.display();
                        index++;
                        cout << "-----------------------------------------------\n";
                    }
                    cout << "\n";
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
                message_list.emplace_back(current_user.get_username(), subject, body);
                cout << "Message Recorded!\n" << endl;
                break;
            case 'Q':
            case 'q':
                cout << "Bye!" << endl;
                exit(0);
        }
    }

}


