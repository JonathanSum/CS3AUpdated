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

#include "IntListIterator.h"
/***************************************************
 *
 *   Method IntListIterator():Class IntListIterator
 ________________________________________________
 *   This is a constructor
 *   for  *   Initialize the iterator.
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   created a constructor
*****************************************************/
IntListIterator::IntListIterator() {
    current = nullptr;
}

/***************************************************
 *
 *   Method IntList(const IntList &list):Class IntListIterator
 ________________________________________________
 *   This is a constructor
 *   for  *   Initialize the iterator by ptr.
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   created a constructor
*****************************************************/
IntListIterator::IntListIterator(IntNode *ptr) {
    current = ptr;
}
/***************************************************
 *
 *   Method operator*() : Class IntListIterator
 ________________________________________________
 *   It overrides the *
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   a current node's data is returned
*****************************************************/
int IntListIterator::operator*() {
    if(current!= nullptr){
        return current->data;
    }
}

/***************************************************
 *
 *   Method operator++() : Class IntListIterator
 ________________________________________________
 *   It overrides the ++
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   a current node's data is returned
*****************************************************/
IntListIterator IntListIterator:: operator++() {
    if(current){
        current=current->next;
    }
    return *this;
}
/***************************************************
 *
 *   Method operator++(int): Class IntListIterator
 ________________________________________________
 *   It overrides the ++
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   a current node's data is returned
*****************************************************/
IntListIterator IntListIterator:: operator++(int) {
    IntListIterator it = *this;
    ++*this;
    return it;
}
/***************************************************
 *
 *   operator==(const IntListIterator &right) const
 ________________________________________________
 *   It overrides the ==
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   a boolean is returned if two IntListIterator Objects
 *   are same
*****************************************************/
bool IntListIterator::operator==(const IntListIterator &right) const {
    return current ==right.current;
}
/***************************************************
 *
 *   operator!=(const IntListIterator &right) const
 ________________________________________________
 *   It overrides the !=
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   a boolean is returned if two IntListIterator Objects
 *   are not same
*****************************************************/
bool IntListIterator::operator!=(const IntListIterator &right) const {

    return current !=right.current;
}







