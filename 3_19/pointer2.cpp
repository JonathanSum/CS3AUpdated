/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment     : CS 003A - Assignment 1: Blackjack
 *   SECTION        : CS 003A
 *   Due Date       : 2/28/19
 *   ________________________________________________
 *  Your assignment is to write a single-player version of the casino card game Blackjack, also known as
 *   21. The goal of the game Blackjack is to get cards whose total value comes closest to 21 without going
 *   over. Getting a card total over 21 is called "busting". The player will play against the dealer. There are
 *   3 possible outcomes.
 *   ________________________________________________
 *   Input:
 *     input 1:  Bet amount.
 *     input 2: y or n options.
 *   OUTPUT:
 *      win, lose, or asking for continue or end the game.
***********************************************/
#include <iostream>
#include <cstdlib>
#include <string>
#include <memory>
#include <ctime>

using namespace std;

//-------------------------------------------------------------------
//  draw_card()
//      Uses rand() to draw a card then returns the numerical
//	value and card name
//-------------------------------------------------------------------
void draw_card(string &card,                 //IN - card name
               int *drawer_points//IN - drawer's total points, reads current drawer's points to determine value of ace
);
void askingToQuitOrPlay(int &playerAmount,               //IN - card name
                        int *drawer_points//IN - drawer's total points, reads current drawer's points to determine value of ace
);
void askingMoreCard(string &card,               //IN - card name
                    int *drawer_points//IN - drawer's total points, reads current drawer's points to determine value of ace
        ,int &playerAmount
);
//int main() {
//    int a1=99;
//    int *a2 = &a1;
//    *a2=999;
//    cout<<a1<<endl;
//    return 0;
//}
void fac(int n);
void printing(int *p);
int main() {
    int a1=5;
    int *a2 = &a1;
    cout<<*a2<<endl;
//    fac(a1);
    cout<<*a2<<endl;
    printing(a2);
    cout<<*a2<<endl;
}


void printing(int *p){

//    cout<<p<<endl;
//    cout<<"I am p"<<p<<endl;
    int temp=*p;
    *p=temp-1;
//    cout<<"I am p"<<p<<endl;
if(temp==1){
    
}
//    (*p+1)=p;
//    printing(p);
}
void fac(int n){
    printing(&n);
//    if(n==1){
//
//    }
}
