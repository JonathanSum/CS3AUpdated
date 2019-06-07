/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : Lab 12 - The Rule of 3
 *   SECTION        : CS 003A
 *   Due Date       : 4/11/19
 *   ________________________________________________
 *   Goals
 *   Use rule of 3.
***********************************************/

#include "music_collection.h"

/***************************************************
 *
 *   constructor Music_collection(): Class Music_collection
 ________________________________________________
 *   This constructor create a default
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   an object is created
*****************************************************/
Music_collection::Music_collection() {
    max=100;
    number =0;
    collection= new Tune[max];
}
/***************************************************
 *
 *   constructor Music_collection(int n): Class Music_collection
 ________________________________________________
 *   This constructor create a object
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   an object is created
*****************************************************/
Music_collection::Music_collection(int n) {
    max =n;
    number =0;
    collection= new Tune[max];
}
/***************************************************
 *
 *   constructor Music_collection(const Music_collection &m): Class Music_collection
 ________________________________________________
 *   This constructor create an object
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   an object is created
*****************************************************/
Music_collection::Music_collection(const Music_collection &m) {


    this->collection = new Tune[m.max];
    for(int i = 0; i<m.number; i++){
        collection[i]=m.collection[i];
    }
    max=m.max;
    number = m.number;
}
/***************************************************
 *
 *   Method add_tune(const Tune &t): Class Music_collection
 ________________________________________________
 *   It adds tune
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   Tune is added
*****************************************************/
bool Music_collection::add_tune(const Tune &t) {

    if(number+1>max){
        return false;
    }else{
        //add the tune here
        collection[number]=t;
        number++;
        return true;
    }

}

/***************************************************
 *
 *   Method add_tune(const Tune &t): Class Music_collection
 ________________________________________________
 *   It adds tune in to certain index
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   Tune is added
*****************************************************/
bool Music_collection::set_tune(int index, const Tune &t) {
    if(index < number ){
        collection[index]=t;
    }


}
/***************************************************
 *
 *   Method &Music_collection::operator=(const Music_collection &m)
 *   : Class Music_collection
 ________________________________________________
 *   It override assign operator(=)
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   assign operator(=) overrided
*****************************************************/
Music_collection &Music_collection::operator=(const Music_collection &m) {



    if(this==&m){
        return *this;
    }


    this->collection = new Tune[m.max];
    for(int i = 0; i<m.number; i++){
        collection[i]=m.collection[i];
    }
    max=m.max;
    number = m.number;

    return *this;
}
/***************************************************
 *
 *   Destructor :~Music_collection(): Class Music_collection
 ________________________________________________
 *   It clean the stored data of the object
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   clean the stored data of the object
*****************************************************/
Music_collection::~Music_collection() {
    delete[] collection;
    collection = nullptr;
}
/***************************************************
 *
 *   Method ostream &operator<<(ostream &out, const Music_collection &m)
 *   : Class Music_collection
 ________________________________________________
 *   It override ostream operator(<<)
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   ostream operator(<<) overrided
*****************************************************/
ostream &operator<<(ostream &out, const Music_collection &m) {
    for(int i =0; i<m.number; i++){
        out <<m.collection[i].get_title()<<endl;
    }

    return out;
}
/***************************************************
 *
 *   constructor Tune()
 ________________________________________________
 *   This constructor create a object
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   an object is created
*****************************************************/
Tune::Tune() {
    title="";
}
/***************************************************
 *
 *   constructor Tune(const string &n)
 ________________________________________________
 *   This constructor create a object
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   an object is created
*****************************************************/
Tune::Tune(const string &n) {
    title=n;
}
/***************************************************
 *
 *   Method &Tune::get_title() const : Class Tune
 ________________________________________________
 *   It return the title of the Tune
 ________________________________________________
 *   PRE-CONDITIONS
 *   Same
 *   POST-CONDITIONS
 *   Title of the Tune is returned
*****************************************************/
const string &Tune::get_title() const {
    return title;
}
