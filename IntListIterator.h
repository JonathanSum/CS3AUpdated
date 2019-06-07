/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Assignment 7 - Linked List Recursion
 *   SECTION        : CS 003A
 *   Due Date       : 5/01/19
 *   ________________________________________________
 *   Goals
 *    Add some additional recursive functions to your
 *    IntList class as well as make sure the Big 3 are defined.
***********************************************/
#ifndef INC_3A_INTLISTITERATOR_H
#define INC_3A_INTLISTITERATOR_H

#include "IntList.h"
class IntNode;
class IntListIterator {

private:
    IntNode *current;
public:
    /**************************************
    **      CONSTRUCTOR  AND DESTRUCTOR  **
    ***************************************/
    IntListIterator();

    IntListIterator(IntNode *ptr);

    /**********************
        * * MUTATORS **
    **********************/
    int operator*();

    IntListIterator operator++();
    IntListIterator operator++(int);
    /**********************
        * * ACCESSORS **
     **********************/
    bool operator==(const IntListIterator &right) const;

    bool operator!=(const IntListIterator &right) const;
    //Constructors//


};
/*********************************************************************
   * IntListIterator  Class
   * This class represents a IntListIterator object.
   * It manages 1 attributest,
   * current pointer
*********************************************************************/
/*********************************************************************
                    **      CONSTRUCTOR   **
*********************************************************************/

/*********************************************************************
 *  IntListIterator();
 *  Constructor;    Initialize class current attributes
 *  Parameter: none
 *  Return: none
*********************************************************************/

/*********************************************************************
 *  IntListIterator(IntNode *ptr);
 *  Constructor;    Initialize class current attributes
 *  Parameter: IntNode *ptr //IN pointer
 *  Return: none
*********************************************************************/
/*********************************************************************
                            * * ACCESSORS **
*********************************************************************/

/*********************************************************************
 * bool operator==(const IntListIterator &right) const;
 * Accessors: override the operator==
 *--------------------------------------------------------------------
 * Parameter: const IntListIterator &right  //IN - another object
 *--------------------------------------------------------------------
 * Return: boolean
*********************************************************************/
/*********************************************************************
 * bool operato!=(const IntListIterator &right) const;
 * Accessors: override the operator==
 *--------------------------------------------------------------------
 * Parameter: const IntListIterator &right  //IN - another object
 *--------------------------------------------------------------------
 * Return: boolean
*********************************************************************/
/*********************************************************************
                            * * MUTATORS **
*********************************************************************/
/*********************************************************************
 *  int operator*();
 * Mutator: override the operator*
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: pointer
*********************************************************************/
/*********************************************************************
 *  IntListIterator operator++();
 * Mutator: override the operator++
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: IntListIterator
*********************************************************************/
/*********************************************************************
 *  IntListIterator operator++(int);
 * Mutator: override the operator++
 *--------------------------------------------------------------------
 * Parameter: none
 *--------------------------------------------------------------------
 * Return: IntListIterator
*********************************************************************/
#endif //INC_3A_INTLISTITERATOR_H