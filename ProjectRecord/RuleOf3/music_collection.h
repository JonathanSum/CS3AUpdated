/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Lab 12 - The Rule of 3
 *   SECTION        : CS 003A
 *   Due Date       : 4/11/19
 *   ________________________________________________
 *   Goals
 *   Use rule of 3.
***********************************************/

#include <iostream>
#ifndef INC_3A_1_MUSIC_COLLECTION_H
#define INC_3A_1_MUSIC_COLLECTION_H
using namespace std;

class Tune
{
private:
    string title;       //IN - title of the Tune

public:

    /**************************************
    **      CONSTRUCTOR  AND DESTRUCTOR  **
    ***************************************/

    Tune();

    Tune( const string &n );

        /****************
         * * ACCESSORS **
        ****************/
    const string & get_title() const;
};
/*********************************************************************
   * Tune Class
   * This class represents a Music_collection object.
   * It manages 1 attributest,
   * title of the Tune
*********************************************************************/
/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/
/*********************************************************************
 *  Tune();
 *  Constructor;    Initialize class attributes
 *  Parameter: none
 *  Return: none
*********************************************************************/
/*********************************************************************
 *  Tune( const string &n );
 *  Constructor;    Initialize class attributes and set the title
 *  with the value of n
 *  Parameter: const string &n    //IN - title of the Tune
 *  Return: none
*********************************************************************/
/*********************************************************************
                            * * ACCESSORS **
*********************************************************************/
/*********************************************************************
 *const string & get_title() const;
 * Accessors: returns true if add was successful,
            returns false if not enough room to add
 *--------------------------------------------------------------------
 * Parameter: const Tune &t     // a Tune object.
 *--------------------------------------------------------------------
 * Return: Boolean of index < number
*********************************************************************/
class Music_collection
{
private:
    int number;             // the number of tunes actually in the collection
    int max;                // the number of tunes the collection will ever be able to hold
    Tune *collection;        // a dynamic array of Tunes: "Music_collection has-many Tunes"

public:
    /**************************************
    **      CONSTRUCTOR  AND DESTRUCTOR  **
    ***************************************/

    Music_collection();

    ~Music_collection();

    Music_collection( int n );


    Music_collection( const Music_collection &m);


    /**********************
         * * MUTATORS **
    **********************/
    bool add_tune( const Tune &t );


    bool set_tune( int index, const Tune &t );


    Music_collection & operator=( const Music_collection &m );

    friend ostream & operator<<( ostream &out, const Music_collection &m );
};
/*********************************************************************
   * Music_collection Class
   * This class represents a Music_collection object.
   * It manages 3 attributest,
   * number of element
   * max element that the list can take
   * address of the list
*********************************************************************/

/*********************************************************************
                         **      CONSTRUCTOR   **
*********************************************************************/
/*********************************************************************
 *  Music_collection();
 *  Constructor;    Initialize class attributes
 *  Parameter: none
 *  Return: none
*********************************************************************/
/*********************************************************************
 *  Music_collection( int n);
 *  Constructor;    Initialize class attributes and Initialize the n
 *  to be max
 *  Parameter: int n       //set max by the value of n
 *  Return: none
*********************************************************************/
/*********************************************************************
 *  Music_collection( const Music_collection &m);
 *  Constructor;    // overloaded copy constructor
    Music_collection( const Music_collection &m);
 *  Parameter: const Music_collection &m        //Music_collection object
 *  Return: none
*********************************************************************/
/*********************************************************************
                         **    DESTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  ~IntList();
 *  Destructor;   deallocate all element in the linked list.
 *  After freeing all the element from the memory,
 *  set the head and tail to null pointer
 *  Parameter: none
 *  Return: none
*********************************************************************/


/*********************************************************************
                            * * MUTATORS **
*********************************************************************/
/*********************************************************************
 *bool add_tune( const Tune &t );
 * Mutator: returns true if add was successful,
            returns false if not enough room to add
 *--------------------------------------------------------------------
 * Parameter: const Tune &t     // a Tune object.
 *--------------------------------------------------------------------
 * Return: Boolean of index < number
*********************************************************************/
/*********************************************************************
 *bool set_tune( int index, const Tune &t );
 * Mutator: sets the Tune at position index in collection to t,
            returns true if index < number
 *--------------------------------------------------------------------
 * Parameter: const Tune &t      // a Tune object.
 *            int index     // index that wanting to insert.
 *--------------------------------------------------------------------
 * Return: Boolean of index < number
*********************************************************************/
/*********************************************************************
 *Music_collection & operator=( const Music_collection &m );
 * Mutator: overloaded assignment(=) operator
 *--------------------------------------------------------------------
 * Parameter: const Music_collection &m     //another object that
 *            to be assign
 *
 *--------------------------------------------------------------------
 * Return: Music_collection object
*********************************************************************/
/*********************************************************************
 *friend ostream & operator<<( ostream &out, const Music_collection &m );
 * Mutator: overloaded stream insertion operator
            outputs the title of each Tune in the collection on a separate line
 *--------------------------------------------------------------------
 * Parameter: ostream &out,             //ostream to be override
 *            const Music_collection &m         //      Music_collection object
 *
 *--------------------------------------------------------------------
 * Return: Music_collection object
*********************************************************************/




#endif //INC_3A_1_MUSIC_COLLECTION_H
