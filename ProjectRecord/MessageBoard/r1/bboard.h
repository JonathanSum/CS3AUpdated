//
// Created by JonathanSum on 3/15/2019.
//

#ifndef INC_3A_BBOARD_H
#define INC_3A_BBOARD_H

#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <vector>
#include "user.h"
#include "message.h"
#include <cmath>

using namespace std;

class BBoard {
public:
    BBoard(){
        title="";
        user_list=vector<User>();
        message_list=vector<Message>();
        current_user= User();
    };
    BBoard( const string &ttl ){
        title = "Welcome!";
    }
    //imports all the authorized users from an input file, storing them as User objects in
    //the vector user_list
    //The name of the input file is passed in as a parameter to this function.
    //See below for file details.
    void setup( const string &input_file );

    //asks for and validates current User/password
    //This function asks for a username and password, and checks the user_list vector
    // for a matching User.
    void login( );
    void run( );

private:
    string title;           //title - string : title of the board; initialized via constructor
    vector<User> user_list;         //list of members; initially empty, then populated via setup()
    User current_user;
    vector<Message> message_list;
    void add_user(istream &infile, const string &name, const string &pass);
};


#endif //INC_3A_BBOARD_H
