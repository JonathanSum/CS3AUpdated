//
// Created by JonathanSum on 3/15/2019.
//

#include "user.h"
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

/**************************************************************************
*   get_username()
*   This function returns true if the stored username/password matches with the
*   parameters. Otherwise returns false.
****************************************************************************/
string User::get_username() const {
    return username;
}

/**************************************************************************
*   check(const string &uname, const string &pass)
*   This function returns true if the stored username/password matches with the stored
*   password and user name

****************************************************************************/
bool User::check(const string &uname, const string &pass) const {

    //CALC and OUT, it returns true if the stored username/password matches with the
    if (uname.empty()&&pass.empty()) {
        return false;
    } else return uname == username && pass == password;
}


