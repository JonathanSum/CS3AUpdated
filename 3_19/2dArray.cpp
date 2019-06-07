/*********************************************
 *   Author         : Jonathan Sum
 *   Assignment   #1: Lab 02 - CS 002 Review - Arrays
 *   SECTION        : CS 003A
 *   Due Date       : 2/23/19
 *   ________________________________________________
 *   The program should also be able to convert a Roman numeral such as MCMLXXVIII
 *   to its decimal number representation.
 *   Include a menu to select from the two options.
 *   Second, it can also convert digital number to roma number.
 *   ________________________________________________
 *   Input:
 *     input 1: input a seed value
 *     input 2: input total number of experiments.
 *   OUTPUT:
 *      output 1: a curve of how 21 different sum occurs
***********************************************/
#include <iostream>
#include <cstdlib>
#include <string>

using namespace std;

//-------------------------------------------------------------------
//  draw_card()
//      Uses rand() to draw a card then returns the numerical
//	value and card name
//-------------------------------------------------------------------

void passByR(string &s);
void draw_card(string *card,                 //IN - card name
               int *drawer_points             //IN - drawer's total points, reads current drawer's points to determine value of ace
);

int main() {

    cout << "You have $100. Enter bet:" << endl;
//    cout<<draw_card()<< endl;
    int playerTotal, dealerTotal,playerAmount;
    playerTotal=0;
    dealerTotal=0;
    int playerCard, dealerCard;
    string card;
    draw_card(&card,&playerTotal);
    cout<<card<<endl;
    cout<<"Hi"<<endl;
    passByR(card);
    cout<<card<<endl;
    cout<<playerTotal<<endl;
    return 0;
}
void passByR(string &s){
    
    s='It is change';
}
int draw_card() {
    srand(time(0));
    string dealerCard;
    string playerCard;
    string suit;


    //Suite: spades = 0, clubs = 1, diamonds = 2, and hearts = 3.
    int suite = 1 + (rand() % 4);
    int rank = 1 + (rand() % 13);
    int returnCardValue;
    return 0;
}

void draw_card(string *card,                 //IN - card name
               int *drawer_points             //IN - drawer's total points, reads current drawer's points to determine value of ace
) {               //IN - card name
    srand(333);
    string dealerCard;
    string playerCard;
//Suite: spades = 1, clubs = 2, diamonds = 3, and hearts = 4.
    int suite = 1 + (rand() % 4);
    int rank = 1 + (rand() % 13);
    cout<<suite<<" is suit"<<endl;
    cout<<rank<<" is rank"<<endl;

    int x, y;
    if(rank==1){
        int addRank;
        x = *drawer_points - 11;
        y = *drawer_points - 1;
        addRank= x > y && x < 21 ? 11 : 1;
        *drawer_points+=addRank;
    }else if(rank>=11){
        *drawer_points+=10;
    }else{
        *drawer_points+=rank;
    }
    if (rank == 1)
        if (suite == 1 && rank == 1) {
        } else if (suite == 1 && rank == 1) {
            *card = "Ace of Spades";
            *drawer_points+=rank;
        } else if (suite == 2 && rank == 1) {
            *card = "Two of Spades";
        } else if (suite == 3 && rank == 1) {
            *card = "Three of Spades";
        } else if (suite == 4 && rank == 1) {
            *card = "Four of Spades";
        } else if (suite == 5 && rank == 1) {
            *card = "Five of Spades";
        } else if (suite == 6 && rank == 1) {
            *card = "Six of Spades";
        } else if (suite == 7 && rank == 1) {
            *card = "Seven of Spades";
        } else if (suite == 8 && rank == 1) {
            *card = "Eight of Spades";
        } else if (suite == 9 && rank == 1) {
            *card = "Nine of Spades";
        } else if (suite == 10 && rank == 1) {
            *card = "Ten of Spades";
        } else if (suite == 11 && rank == 1) {
            *card = "Jack of Spades";
        } else if (suite == 12 && rank == 1) {
            *card = "Queen of Spades";
        } else if (suite == 13 && rank == 1) {
            *card = "King of Spades";
        } else if (suite == 1 && rank == 2) {
            *card = "Ace of Clubs";
        } else if (suite == 2 && rank == 2) {
            *card = "Two of Clubs";
        } else if (suite == 3 && rank == 2) {
            *card = "Three of Clubs";
        } else if (suite == 4 && rank == 2) {
            *card = "Four of Clubs";
        } else if (suite == 5 && rank == 2) {
            *card = "Five of Clubs";
        } else if (suite == 6 && rank == 2) {
            *card = "Six of Clubs";
        } else if (suite == 7 && rank == 2) {
            *card = "Seven of Clubs";
        } else if (suite == 8 && rank == 2) {
            *card = "Eight of Clubs";
        } else if (suite == 9 && rank == 2) {
            *card = "Nine of Clubs";
        } else if (suite == 10 && rank == 2) {
            *card = "Ten of Clubs";
        } else if (suite == 11 && rank == 2) {
            *card = "Jack of Clubs";
        } else if (suite == 12 && rank == 2) {
            *card = "Queen of Clubs";
        } else if (suite == 13 && rank == 2) {
            *card = "King of Clubs";
        } else if (suite == 1 && rank == 3) {
            *card = "Ace of Diamonds";
        } else if (suite == 2 && rank == 3) {
            *card = "Two of Diamonds";
        } else if (suite == 3 && rank == 3) {
            *card = "Three of Diamonds";
        } else if (suite == 4 && rank == 3) {
            *card = "Four of Diamonds";
        } else if (suite == 5 && rank == 3) {
            *card = "Five of Diamonds";
        } else if (suite == 6 && rank == 3) {
            *card = "Six of Diamonds";
        } else if (suite == 7 && rank == 3) {
            *card = "Seven of Diamonds";
        } else if (suite == 8 && rank == 3) {
            *card = "Eight of Diamonds";
        } else if (suite == 9 && rank == 3) {
            *card = "Nine of Diamonds";
        } else if (suite == 10 && rank == 3) {
            *card = "Ten of Diamonds";
        } else if (suite == 11 && rank == 3) {
            *card = "Jack of Diamonds";
        } else if (suite == 12 && rank == 3) {
            *card = "Queen of Diamonds";
        } else if (suite == 13 && rank == 3) {
            *card = "King of Diamonds";
        } else if (suite == 1 && rank == 4) {
            *card = "Ace of Hearts";
        } else if (suite == 2 && rank == 4) {
            *card = "Two of Hearts";
        } else if (suite == 3 && rank == 4) {
            *card = "Three of Hearts";
        } else if (suite == 4 && rank == 4) {
            *card = "Four of Hearts";
        } else if (suite == 5 && rank == 4) {
            *card = "Five of Hearts";
        } else if (suite == 6 && rank == 4) {
            *card = "Six of Hearts";
        } else if (suite == 7 && rank == 4) {
            *card = "Seven of Hearts";
        } else if (suite == 8 && rank == 4) {
            *card = "Eight of Hearts";
        } else if (suite == 9 && rank == 4) {
            *card = "Nine of Hearts";
        } else if (suite == 10 && rank == 4) {
            *card = "Ten of Hearts";
        } else if (suite == 11 && rank == 4) {
            *card = "Jack of Hearts";
        } else if (suite == 12 && rank == 4) {
            *card = "Queen of Hearts";
        } else if (suite == 13 && rank == 4) {
            *card = "King of Hearts";
        }

}



