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
void askingToQuitOrPlay(string &playerCard1,               //IN - card name
                        string &playerCard2,
                        string &playerCard3,
                        int &playerTotal,         //IN - drawer's total points, reads current drawer's points to determine value of ace
                        int &playerAmount,
                        string &dealerCard1,          //IN - dealer's card name
                        string &dealerCard2,          //IN - dealer's card name
                        string &dealerCard3,         //IN - dealer's card name
                        int &dealerTotal
);

void draw_card(string &card,                 //IN - card name
               int *drawer_points//IN - drawer's total points, reads current drawer's points to determine value of ace
);


void askingMoreCard(string &playerCard1,               //IN - card name
                    string &playerCard2,
                    string &playerCard3,
                    int &playerTotal,         //IN - drawer's total points, reads current drawer's points to determine value of ace
                    int &playerAmount,
                    string &dealerCard1,          //IN - dealer's card name
                    string &dealerCard2,          //IN - dealer's card name
                    string &dealerCard3,         //IN - dealer's card name
                    int &dealerTotal,
                    int &bet
);

void playGame(string &playerCard1,               //IN - card name
              string &playerCard2,
              string &playerCard3,
              int &playerTotal,         //IN - drawer's total points, reads current drawer's points to determine value of ace
              int &playerAmount,
              string &dealerCard1,          //IN - dealer's card name
              string &dealerCard2,          //IN - dealer's card name
              string &dealerCard3,         //IN - dealer's card name
              int &dealerTotal
);

int main() {
    cout<< "******************************************************************\n";
    cout<< "    Programmed by   : Jonathan Sum\n";
    cout<< "    Student ID      : 10239468\n";
    cout<< "    CS3A            : MTWTH -6a-8:25\n";
    cout<< "    Lab #1          : Roman Numerals\n";
    cout<< "******************************************************************\n";
    srand(333);
    //Player' card
    string playerCard1;
    //Dealer' card
    string dealerCard1;
    //Player' card1
    string playerCard2;
    //Dealer' card1
    string dealerCard2;
    //Player' card3
    string playerCard3;
    string dealerCard3;
    //asking to enter the bet
    int playerTotal, dealerTotal, playerAmount;
    playerAmount = 100;
    dealerTotal = 0;
    playGame(playerCard1,               //IN - card name
             playerCard2,
             playerCard3,
             playerTotal,         //IN - drawer's total points, reads current drawer's points to determine value of ace
             playerAmount,
             dealerCard1,          //IN - dealer's card name
             dealerCard2,          //IN - dealer's card name
             dealerCard3,         //IN - dealer's card name
             dealerTotal
    );


    return 0;
}


void playGame(string &playerCard1,               //IN - card name
              string &playerCard2,
              string &playerCard3,
              int &playerTotal,         //IN - drawer's total points, reads current drawer's points to determine value of ace
              int &playerAmount,
              string &dealerCard1,          //IN - dealer's card name
              string &dealerCard2,          //IN - dealer's card name
              string &dealerCard3,         //IN - dealer's card name
              int &dealerTotal
) {
    playerTotal = 0;
    dealerTotal = 0;
    int bet;
    bet = 500;
    while (bet > playerAmount) {
        cout << "You have $" << playerAmount << ". Enter bet:" << endl;
        cin >> bet;
    }


    playerTotal = 0;

    //dealer and player get their cards

    draw_card(playerCard1, &playerTotal);
    cout << "Your cards are:" << endl
         << "  " << playerCard1 << endl;
    draw_card(playerCard2, &playerTotal);
    cout << "  " << playerCard2 << endl;

    draw_card(dealerCard1, &dealerTotal);

    draw_card(dealerCard2, &dealerTotal);





    if (playerTotal == dealerTotal) {
        cout << "A draw! You get back your $" << bet << "." << endl;
        askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1, dealerCard2,
                           dealerCard3,
                           dealerTotal);
    } else if (playerTotal == 21 || dealerTotal > 21) {

        cout << "You win $" << bet << "." << endl;
        playerAmount += bet;
        askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1, dealerCard2,
                           dealerCard3, dealerTotal);

    } else if (playerTotal > 21 || dealerTotal == 21) {
        cout << "Your total is  " << playerTotal << ". You busted!" << endl;
        playerAmount -= bet;
        if (playerAmount > 0) {
            //asking to play more or not
            askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1,
                               dealerCard2, dealerCard3, dealerTotal);
        }
    } else if (playerTotal < 21 && dealerTotal < 21) {



        askingMoreCard(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1, dealerCard2,
                       dealerCard3, dealerTotal, bet);
    }

}

void draw_card(string &card,               //IN - card name
               int *drawer_points//IN - drawer's total points, reads current drawer's points to determine value of ace
) {

    string dealerCard;
    string playerCard;
    int suite = (rand() % 4);
    int rank = 1 + (rand() % 13);

    int x, y;  //x is the different between drawer's point to 11 and same with y which the point to 1.
    //In the following if statement is to determine whether or not to add
    if (rank == 1) {
        int addRank;
        x = *drawer_points - 11;
        y = *drawer_points - 1;
        addRank = x > y && x < 21 ? 11 : 1;
        *drawer_points += addRank;
    } else if (rank >= 11) {
        *drawer_points += 10;
    } else {
        *drawer_points += rank;
    }
    if (rank == 1 && suite == 0) {
        card = "Ace of Spades";
    } else if (rank == 2 && suite == 0) {
        card = "Two of Spades";
    } else if (rank == 3 && suite == 0) {
        card = "Three of Spades";
    } else if (rank == 4 && suite == 0) {
        card = "Four of Spades";
    } else if (rank == 5 && suite == 0) {
        card = "Five of Spades";
    } else if (rank == 6 && suite == 0) {
        card = "Six of Spades";
    } else if (rank == 7 && suite == 0) {
        card = "Seven of Spades";
    } else if (rank == 8 && suite == 0) {
        card = "Eight of Spades";
    } else if (rank == 9 && suite == 0) {
        card = "Nine of Spades";
    } else if (rank == 10 && suite == 0) {
        card = "Ten of Spades";
    } else if (rank == 11 && suite == 0) {
        card = "Jack of Spades";
    } else if (rank == 12 && suite == 0) {
        card = "Queen of Spades";
    } else if (rank == 13 && suite == 0) {
        card = "King of Spades";
    } else if (rank == 1 && suite == 1) {
        card = "Ace of Clubs";
    } else if (rank == 2 && suite == 1) {
        card = "Two of Clubs";
    } else if (rank == 3 && suite == 1) {
        card = "Three of Clubs";
    } else if (rank == 4 && suite == 1) {
        card = "Four of Clubs";
    } else if (rank == 5 && suite == 1) {
        card = "Five of Clubs";
    } else if (rank == 6 && suite == 1) {
        card = "Six of Clubs";
    } else if (rank == 7 && suite == 1) {
        card = "Seven of Clubs";
    } else if (rank == 8 && suite == 1) {
        card = "Eight of Clubs";
    } else if (rank == 9 && suite == 1) {
        card = "Nine of Clubs";
    } else if (rank == 10 && suite == 1) {
        card = "Ten of Clubs";
    } else if (rank == 11 && suite == 1) {
        card = "Jack of Clubs";
    } else if (rank == 12 && suite == 1) {
        card = "Queen of Clubs";
    } else if (rank == 13 && suite == 1) {
        card = "King of Clubs";
    } else if (rank == 1 && suite == 2) {
        card = "Ace of Diamonds";
    } else if (rank == 2 && suite == 2) {
        card = "Two of Diamonds";
    } else if (rank == 3 && suite == 2) {
        card = "Three of Diamonds";
    } else if (rank == 4 && suite == 2) {
        card = "Four of Diamonds";
    } else if (rank == 5 && suite == 2) {
        card = "Five of Diamonds";
    } else if (rank == 6 && suite == 2) {
        card = "Six of Diamonds";
    } else if (rank == 7 && suite == 2) {
        card = "Seven of Diamonds";
    } else if (rank == 8 && suite == 2) {
        card = "Eight of Diamonds";
    } else if (rank == 9 && suite == 2) {
        card = "Nine of Diamonds";
    } else if (rank == 10 && suite == 2) {
        card = "Ten of Diamonds";
    } else if (rank == 11 && suite == 2) {
        card = "Jack of Diamonds";
    } else if (rank == 12 && suite == 2) {
        card = "Queen of Diamonds";
    } else if (rank == 13 && suite == 2) {
        card = "King of Diamonds";
    } else if (rank == 1 && suite == 3) {
        card = "Ace of Hearts";
    } else if (rank == 2 && suite == 3) {
        card = "Two of Hearts";
    } else if (rank == 3 && suite == 3) {
        card = "Three of Hearts";
    } else if (rank == 4 && suite == 3) {
        card = "Four of Hearts";
    } else if (rank == 5 && suite == 3) {
        card = "Five of Hearts";
    } else if (rank == 6 && suite == 3) {
        card = "Six of Hearts";
    } else if (rank == 7 && suite == 3) {
        card = "Seven of Hearts";
    } else if (rank == 8 && suite == 3) {
        card = "Eight of Hearts";
    } else if (rank == 9 && suite == 3) {
        card = "Nine of Hearts";
    } else if (rank == 10 && suite == 3) {
        card = "Ten of Hearts";
    } else if (rank == 11 && suite == 3) {
        card = "Jack of Hearts";
    } else if (rank == 12 && suite == 3) {
        card = "Queen of Hearts";
    } else if (rank == 13 && suite == 3) {
        card = "King of Hearts";
    }

}


void askingMoreCard(string &playerCard1,               //IN - card name
                    string &playerCard2,
                    string &playerCard3,
                    int &playerTotal,         //IN - drawer's total points, reads current drawer's points to determine value of ace
                    int &playerAmount,
                    string &dealerCard1,          //IN - dealer's card name
                    string &dealerCard2,          //IN - dealer's card name
                    string &dealerCard3,         //IN - dealer's card name
                    int &dealerTotal,
                    int &bet
) {

    cout << "Your total is " << playerTotal << "." << " Do you want another card (y/n)" << endl;
    char input;


    cin >> input;
    if (input == 'y') {
        draw_card(playerCard3, &playerTotal);
        cout << "You draw a: " << endl;
        cout << "  " << playerCard3 << endl;
        char inputInside;
        //Keep asking player to give a card or not until no.
        while (inputInside != 'n' && playerTotal < 21) {
            cout << "Your total is " << playerTotal << "." << " Do you want another card (y/n)" << endl;
            cin >> inputInside;
            if (inputInside == 'y') {

                draw_card(playerCard3, &playerTotal);

                cout << "  " << playerCard3 << endl;
            }
        }
        //After the loop, check player's point excess 21 or not.
        if (playerTotal > 21) {
            cout << "Your total is " << playerTotal << ". You busted!" << endl;
            playerAmount -= bet;
            askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1,
                               dealerCard2, dealerCard3, dealerTotal);
        } else if (playerTotal == 21) {

            cout << "You win $" << bet << "." << endl;
            playerAmount += bet;

            askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1,
                               dealerCard2, dealerCard3, dealerTotal);
        }
    }
    //if player does not want more card and his or her point is less than 21.
    if (input == 'n' || playerTotal < 21) {
        cout << "The dealer's are:" << endl
             << "  " << dealerCard1 << endl;
        cout << "  " << dealerCard2 << endl;
        cout << "The dealer's total is " << dealerTotal << "." << endl;
        while (dealerTotal <= 16) {
            draw_card(dealerCard3, &dealerTotal);
            cout << "The dealer draw a card:" << endl;
            cout << "  " << dealerCard3 << endl;
        }
        cout << "The dealer's total is " << dealerTotal << "." << endl;
        //if dealer's point greater than 21, player won.
        if (dealerTotal > 21) {
            cout << "Dealer busted, and dealer's point is " << dealerTotal << endl;
            cout << "You win " << bet << "." << endl;
            playerAmount += bet;
            askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1,
                               dealerCard2, dealerCard3, dealerTotal);
        } else if (dealerTotal == 21) {
            cout << "Dealer win, and dealer's point is " << dealerTotal << endl;
            cout << "You busted, and you lose " << bet << "." << endl;
            playerAmount -= bet;
            askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1,
                               dealerCard2, dealerCard3, dealerTotal);
        }
            //then dealer's point is between less than 21 and greater than 16, so dealer's turn is ended.
            //Thus, the next turn is player's.
        else if (dealerTotal < 21) {
            if (dealerTotal < playerTotal) {
                cout << "Dealer's point is " << dealerTotal << endl;
                cout << "You win " << bet << "." << endl;
                playerAmount += bet;
                askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1,
                                   dealerCard2, dealerCard3, dealerTotal);
            }else if(dealerTotal > playerTotal){
                cout << "Dealer's point is " << dealerTotal << endl;
                cout << "Too bad.  You lose " << bet << "." << endl;
                playerAmount -= bet;
                askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1,
                                   dealerCard2, dealerCard3, dealerTotal);
            }else{
                cout << "Dealer's point is " << dealerTotal << endl;
                cout << "It is a draw. "<< endl;
                askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1,
                                   dealerCard2, dealerCard3, dealerTotal);
            }

        }
    }

}

void askingToQuitOrPlay(string &playerCard1,               //IN - card name
                        string &playerCard2,
                        string &playerCard3,
                        int &playerTotal,         //IN - drawer's total points, reads current drawer's points to determine value of ace
                        int &playerAmount,
                        string &dealerCard1,          //IN - dealer's card name
                        string &dealerCard2,          //IN - dealer's card name
                        string &dealerCard3,         //IN - dealer's card name
                        int &dealerTotal
) {
    //it is better to check player's amount is less than zero or equals to zero.
    if (playerAmount <= 0) {
        //Game over, amount is less than or equals to zero.
        cout << "You have $" << playerAmount << ". GAME OVER." << endl;
        exit(0);


    }
    cout << "Play again? (y/n): \n" << endl;
    char input;

    while (input != 'n' && input != 'y') {
        cin >> input;
        if (input == 'y') {
            //Play Game again
            playGame(playerCard1,               //IN - card name
                     playerCard2,
                     playerCard3,
                     playerTotal,         //IN - drawer's total points, reads current drawer's points to determine value of ace
                     playerAmount,
                     dealerCard1,          //IN - dealer's card name
                     dealerCard2,          //IN - dealer's card name
                     dealerCard3,         //IN - dealer's card name
                     dealerTotal
            );

        } else if (input == 'n') {
            cout << "You have $" << playerAmount << ". GAME OVER." << endl;
            exit(0);
        }
    }
}

