//
// Created by JonathanSum on 3/13/2019.
//

#ifndef INC_3A_DISTANCE_H
#define INC_3A_DISTANCE_H

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

class Distance {
private:
    unsigned feet;
    double inches;
public:
    Distance() {
        inches = 0;
        feet = 0;
    };

    Distance(unsigned ft, double inch) {
        feet = ft, inches = inch;
        init();

    }

    Distance(double inch) {
        feet=0;
        inches = inch;
        init();
    }

    double convertToInches() const;

    const Distance operator+(const Distance &) const;

    const Distance operator-(const Distance &) const;

    void display() const;

private:
    void init();
};

#endif //INC_3A_DISTANCE_H
