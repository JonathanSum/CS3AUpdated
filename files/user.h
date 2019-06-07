//
// Created by JonathanSum on 3/15/2019.
//

#ifndef INC_3A_USER_H
#define INC_3A_USER_H
#include <string>
#include <iostream>
#include <cstdlib>
#include <iomanip>
#include <iostream>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

class User
{
private:
    string username;        //IN/OUT -- name of user
    string password;        //IN    --password of user

public:
    /************************
     **      CONSTRUCTOR   **
     ************************/
    //creates a User with empty name and password.
    User(){
        username="";        //IN/   -- name of user
        password="";        //IN    --password of user
    };

    // creates a User with given username and password.
    User(const string& uname, const string& pass){
        username=uname;
        password=pass;
    };


    /**********************
        * * ACCESSORS **
    **********************/

    string get_username() const;

    bool check(const string &uname, const string &pass) const;


    /**********************
        * * MUTATORS **
    **********************/

    void set_password(const string &newpass);
};

/*********************************************************************
   * User Class
   * This class represents a user object.
   * It manages 2 attributest,
   * user name, and user password
*********************************************************************/

/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/

/*********************************************************************
 * User();
 *  Constructor;    Initialize class attributes
 *  Parameter: none
 *  Return: none
*********************************************************************/

/*********************************************************************
 *  User(const string& uname, const string& pass)
 *  Constructor;   Setting the user class attributes
 *  Parameter: const string& uname,     //IN - name of user
 *  const string& pass          // - name of password
 *  Return: none
*********************************************************************/


/*********************************************************************
                            * * MUTATORS **
*********************************************************************/

/*********************************************************************
 * void set_password(const string &newpass);
 *
 * Mutators; This method will update the password attribute to the
 * parameter newpass value
 *--------------------------------------------------------------------
 * Parameter: newpass  (string)    //  IN  -   the password for the new attribute
 *--------------------------------------------------------------------
 * Return: none
*********************************************************************/


/*********************************************************************
                            * * ACCESSORS **
*********************************************************************/

/*********************************************************************
 * bool check(const string &uname, const string &pass) const;
 *
 * Accessor; This function returns true if the stored username/password matches with the
 * parameters. Otherwise returns false.
 *--------------------------------------------------------------------
 * Parameter: const string &uname      //  IN - name of user
 * const string &pass       //  IN  - password of user
 *--------------------------------------------------------------------
 * Return: bool
*********************************************************************/

/*********************************************************************
 * string get_username() const;
 *
 * Accessor; This function return the user name
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: user name in string
*********************************************************************/

#endif //INC_3A_USER_H
