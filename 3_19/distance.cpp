//
// Created by JonathanSum on 3/13/2019.
//

#include "distance.h"
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
#include <stdlib.h>
using namespace std;

double Distance::convertToInches() const {
    double returnInches=0;
    returnInches+=(feet*12)+inches;
    return returnInches;
}

const Distance Distance::operator+(const Distance &distanceObj) const {
    Distance returnObj;
    unsigned returnFeet;
    double returnInches;
    returnFeet=feet+distanceObj.feet;
    returnInches=inches+distanceObj.inches;

    returnInches = fabs(returnInches);
    if (returnInches >= 12) {
        double temp = returnInches / 12;
        returnInches = fmod(returnInches, 12);
        returnFeet+= temp;
    } else {
        returnInches = returnInches;
    }
    returnObj.feet=returnFeet;
    returnObj.inches=returnInches;

    return returnObj;
}

const Distance Distance::operator-(const Distance &distanceObj) const {
    Distance returnObj;
    unsigned returnFeet=0;
    double returnInches=0;
    bool ftN = false, inN = false;
        int tempFt=(feet-distanceObj.feet);
        if (tempFt<0){
            tempFt=tempFt*-1;
            ftN=true;
        }
        returnFeet=tempFt;


        returnInches=(inches-distanceObj.inches);
        if(returnInches<0){
            inN =true;
        }
        //case 2
        if(returnFeet!=0){
            if(ftN&&!inN){
                returnInches=12-returnInches;
                returnFeet--;
            }else if(!ftN&&inN){
                returnInches = 12+returnInches;
                returnFeet--;
            }
        }


    returnInches = fabs(returnInches);
    if (returnInches >= 12) {
        double temp = returnInches / 12;
        returnInches = fmod(returnInches, 12);
        returnFeet+= temp;
    } else if(returnFeet==0) {
        returnInches = returnInches;
    }
    returnObj.feet=returnFeet;
    returnObj.inches=returnInches;

    return returnObj;
}

void Distance::display() const {
    cout << feet << "\' " << inches << "\"";
}

void Distance::init() {
    inches = fabs(inches);
    if (inches >= 12) {
        double temp = inches / 12;
        inches = fmod(inches, 12);
        feet += temp;
    } else {
        inches = inches;
    }
}
