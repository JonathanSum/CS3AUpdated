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

string User::get_username() const {
    return username;
}

bool User::check(const string &uname, const string &pass) const {
    // returns true if the stored username/password matches with the
    // parameters. Otherwise returns false.
    // Note that, even though a User with empty name and password is
    // actually a valid User object (it is the default User), this
    // function must still return false if given a empty uname string.
    if (uname.empty()&&pass.empty()) {
        return false;
    } else return uname == username && pass == password;
}

void User::set_password(const string &newpass) {
    password=newpass;
}
