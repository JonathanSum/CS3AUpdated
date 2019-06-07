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
void playGame(string &playerCard1,               //IN - card name
              string &playerCard2,
              string &playerCard3,
              int &playerTotal,         //IN - drawer's total points, reads current drawer's points to determine value of ace
              int &playerAmount,
              string &dealerCard1,          //IN - dealer's card name
              string &dealerCard2,          //IN - dealer's card name
              string &dealerCard3,         //IN - dealer's card name
              int    &dealerTotal
);
int factorial( int * n,int &m);
int main() {

//    int a1=5;
//    int *a2 = &a1;
//    factorial(&a1,a1);
    string playerCard1;               //IN - card name
    string playerCard2;
    string playerCard3;
    int playerTotal;         //IN - drawer's total points, reads current drawer's points to determine value of ace
    int playerAmount;
    string dealerCard1;          //IN - dealer's card name
    string dealerCard2;          //IN - dealer's card name
    string dealerCard3;         //IN - dealer's card name
    int    dealerTotal;
    playGame()
    return 0;
}

int factorial( int * n,int &m) {
    cout<<n<<endl;
}
void playGame(string &playerCard1,               //IN - card name
              string &playerCard2,
              string &playerCard3,
              int &playerTotal,         //IN - drawer's total points, reads current drawer's points to determine value of ace
              int &playerAmount,
              string &dealerCard1,          //IN - dealer's card name
              string &dealerCard2,          //IN - dealer's card name
              string &dealerCard3,         //IN - dealer's card name
              int    &dealerTotal
){
    cout<<playerCard1<<endl;
    cout<<playerCard2<<endl;
    cout<<playerCard3<<endl;
    cout<<playerTotal<<endl;
    cout<<playerAmount<<endl;
    cout<<dealerCard1<<endl;
    cout<<dealerCard2<<endl;
    cout<<dealerCard3<<endl;
    cout<<dealerTotal<<endl;
}
