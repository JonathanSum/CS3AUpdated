#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>

using namespace std;

int main() {
    char str[] = "John is from USA.";

    cout << "The lowercase version of \"" << str << "\" is " << endl;

    for (int i = 0; i < strlen(str); i++) {
    putchar(tolower(str[i]));
    str[i]=tolower(str[i]);
}
    cout<<"debug: "<<str<<endl;
    return 0;
}