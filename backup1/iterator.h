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
#ifndef INC_3A_ITERATOR_H
#define INC_3A_ITERATOR_H
#include <iostream>
#include "linkedList.h"



using namespace std;



template<class E> struct Node;
template<class E>
class Iterator {
private:
    Node<E> *current;
public:
    /**************************************
    **      CONSTRUCTOR  AND DESTRUCTOR  **
    ***************************************/
    Iterator();

    explicit Iterator(Node<E> *ptr);

/**********************
    * * MUTATORS **
**********************/
    int operator*();

    Iterator<E> operator++();
    Iterator<E> operator++(int);
/**********************
    * * ACCESSORS **
 **********************/
    bool operator==(const Iterator &right) const;

    bool operator!=(const Iterator &right) const;


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
 *  IntListIterator(Node *ptr);
 *  Constructor;    Initialize class current attributes
 *  Parameter: Node *ptr //IN pointer
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

template<class E>
Iterator<E>::Iterator() {
    current = nullptr;
}

template<class E>
Iterator<E>::Iterator(Node<E> *ptr) {
    current = ptr;
}

template<class E>
int Iterator<E>::operator*() {
    if(current!= nullptr){
        return current->data;
    };
}

template<class E>
Iterator<E> Iterator<E>::operator++() {
    if(current){
        current=current->next;
    }
    return *this;
}

template<class E>
Iterator<E> Iterator<E>::operator++(int) {
    Iterator<E> it = *this;
    ++*this;
    return it;
}

template<class E>
bool Iterator<E>::operator==(const Iterator &right) const {

    return current ==right.current;
}

template<class E>
bool Iterator<E>::operator!=(const Iterator &right) const {

    return current !=right.current;
}




#endif //INC_3A_ITERATOR_H