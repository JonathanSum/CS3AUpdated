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
 /************************
 **      CONSTRUCTOR   **
 ************************/
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
    /**********************
        * * MUTATORS **
    **********************/

    void setup( const string &input_file );
    void login( );
    void run( );

private:
    string title;           //IN  - title of the board
    vector<User> user_list;         //IN - list of members
    User current_user;          //IN - current user
    vector<Message> message_list;       //IN/OUT    -   list of message
};


#endif //INC_3A_BBOARD_H
/*********************************************************************
   * BBoard Class
   * This class represents a BBoard object.
   * It manages 4 attributest,
   * title="";
        user_list,
        message_list,
        current_user;
*********************************************************************/

/*********************************************************************
 **      CONSTRUCTOR   **
*********************************************************************/

/*********************************************************************
 * BBoard();
 *  Constructor;    Initialize class attributes
 *  Parameter: none
 *  Return: none
*********************************************************************/

/*********************************************************************
 *     BBoard( const string &ttl );
 *  Constructor;     Setting the BBoard class attirbutes
 *  Parameter: string &ttl  //IN - title
 *  Return: none
*********************************************************************/

                    /**********************
                        * * MUTATORS **
                    **********************/

/*********************************************************************
 * void login( );
 * Mutators; This method ask the user to login by inputing
 * username and password, it failed it will repeatly ask
 * to login. Other wise, it will set the current user attirbutes
 * to the username which was input.
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void setup( const string &input_file );
 *
 * Mutators; This method set up the programming in the beginning
 * It reads the file, prints out the title, runs store the username
 * and password from the file it reads
 *--------------------------------------------------------------------
 * Parameter: input_file
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/
/*********************************************************************
 * void run(  );
 * Mutators; It dis play the menu, store message, or quit the program
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/