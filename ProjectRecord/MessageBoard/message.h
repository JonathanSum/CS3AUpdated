//
// Created by JonathanSum on 3/15/2019.
//

#ifndef INC_3A_MESSAGE_H
#define INC_3A_MESSAGE_H

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


//inclusion guards
//includes

class Message {


private:
    string author;              //IN - name of the username
    string subject;             //IN - name of the subject name
    string body;                //IN - name of the body

public:

    /************************
 **      CONSTRUCTOR   **
 ************************/

    Message() {             //CONSTRUCTOR
        author = "";
        subject = "";
        body = "";
    };


    Message(const string &athr,         //CONSTRUCTOR
            const string &sbjct,
            const string &body) {
        author=athr;
        subject=sbjct;
        this->body=body;
    }
    /**********************
        * * ACCESSORS **
    **********************/


    void display() const;
};

//end inc guards



#endif //INC_3A_MESSAGE_H
/*********************************************************************
   * Message Class
   * This class represents a Message object.
   * It manages 3 attributest,
   * author, subject, and body
*********************************************************************/

/*********************************************************************
 **      CONSTRUCTOR   **
*********************************************************************/

/*********************************************************************
 * Message();
 *  Constructor;    Initialize class attributes
 *  Parameter: none
 *  Return: none
*********************************************************************/

/*********************************************************************
 *     Message(const string &athr,
            const string &sbjct,
            const string &body);
 *  Constructor;     Setting the Message class attributes
 *  Parameter: const string &athr,      //IN  name of author
            const string &sbjct,      //IN  name of subject
            const string &body)      //IN  name of body
 *  Return: none
*********************************************************************/

                    /**********************
                        * * ACCESSORS **
                    **********************/

/*********************************************************************
 * void display() const;;
 *
 *      Accessor; This method displays the message in the given format. See output specs.
 *--------------------------------------------------------------------
 *      Parameter: none
 *--------------------------------------------------------------------
 *      Return: none
*********************************************************************/
