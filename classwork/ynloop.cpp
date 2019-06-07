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
    srand(time(NULL));
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
//    void playGame(string &playerCard1,               //IN - card name
//                  string &playerCard2,
//                  string &playerCard3,
//                  int &playerTotal,         //IN - drawer's total points, reads current drawer's points to determine value of ace
//                  int &playerAmount,
//                  string &dealerCard1,          //IN - dealer's card name
//                  string &dealerCard2,          //IN - dealer's card name
//                  string &dealerCard3,         //IN - dealer's card name
//                  int    &dealerTotal
//    );


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
    playerTotal=0;
    dealerTotal=0;
    int bet;
    cout << playerTotal << endl;
    cout << "Debug bet " << bet << endl;
    bet = 500;
    cout<<"debug replay amount: "<<playerAmount<<endl;
    while (bet > playerAmount) {
        cout << "You have $"<<playerAmount<<". Enter bet:" << endl;
//        bet = 50;
        cin >> bet;
    }


    playerTotal = 0;
    cout << playerTotal;


    draw_card(playerCard1, &playerTotal);
    cout << "Your cards are:" << endl
         << "  " << playerCard1 << endl;
    draw_card(playerCard2, &playerTotal);
    cout << "  " << playerCard2 << endl;
    cout << "Debug: Your total is" << playerTotal << endl;
    cout << " d1 " << endl;
    draw_card(dealerCard1, &dealerTotal);
    cout << "The dealer's are:" << endl
         << "  " << dealerCard1 << endl;
    draw_card(dealerCard2, &dealerTotal);
    cout << "  " << dealerCard2 << endl;
    cout << "The dealer's total is " << dealerTotal << "." << endl;
    cout << " d2 " << endl;
    playerTotal = 10;
    dealerTotal = 5;


    if (playerTotal == dealerTotal) {
        cout << "A draw! You get back your $" << bet << "." << endl;
        askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1, dealerCard2,
                           dealerCard3,
                           dealerTotal);
    } else if (playerTotal == 21 || dealerTotal > 21) {
        cout << "Debug3 dealer's total is" << dealerTotal << endl;
        cout << "You win $" << bet << "." << endl;
        playerAmount += bet;
        askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1, dealerCard2,
                           dealerCard3, dealerTotal);

    } else if (playerTotal > 21 || dealerTotal == 21) {
        cout << "Your total is  " << playerTotal << ". You busted!" << endl;
        playerAmount-=bet;
        if (playerAmount > 0) {
            //asking to play more or not
            askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1,
                               dealerCard2, dealerCard3, dealerTotal);
        }
    } else if (playerTotal < 21 && dealerTotal < 21) {
        cout << " d4 " << endl;
        cout << "Debug both less than 21 Total is " << playerTotal << endl;

        askingMoreCard(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1, dealerCard2,
                       dealerCard3, dealerTotal, bet);
    }

}

void draw_card(string &card,               //IN - card name
               int *drawer_points//IN - drawer's total points, reads current drawer's points to determine value of ace
) {

    string dealerCard;
    string playerCard;
//Suite: spades = 1, clubs = 2, diamonds = 3, and hearts = 4.
    int suite = (rand() % 4);
    int rank = 1 + (rand() % 13);
//    cout << suite << " is suit" << endl;
//    cout << rank << " is rank" << endl;

    int x, y;

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
    if (rank == 1 && rank == 1) {
    } else if (rank == 1 && suite == 0) {
        cout << card << endl;
        card += "Ace of Spades";
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

// int &playerAmount
//cout<<"Debug dealer card2"<<dealerCard2<<endl;
    cout<<"debug loop forever starting "<<endl;
    cout << "Your total is " << playerTotal << "." << " Do you want another card (y/n)" << endl;
    char input;
    //Shouldn't here run a while loop for input y and n?

    cin >> input;
    if (input == 'y') {
        draw_card(playerCard3, &playerTotal);
        cout << "You draw a: " << endl;
        cout << "  " << playerCard3 << endl;
        char inputInside;
        //Keep asking player to give a card or not until no.
        while (inputInside != 'n' && playerTotal < 21) {
            cout<<"debug loop forever "<<inputInside<<endl;
            cout << "Your total is " << playerTotal << "." << " Do you want another card (y/n)" << endl;
            cin >> inputInside;
            if (inputInside == 'y') {
                cout << "Debug2 " << inputInside << playerTotal << endl;
                cout << "Debug2.5 player amount " << playerAmount << endl;

                draw_card(playerCard3, &playerTotal);
                cout << "Debug " << inputInside << " You draw a: " << endl;
                cout << "  " << playerCard3 << endl;
            }
        }
        //After the loop, check player's point excess 21 or not.
        if (playerTotal > 21) {
            cout << "Your total is " << playerTotal << ". You busted!" << endl;
            playerAmount-=bet;
            askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1,
                               dealerCard2, dealerCard3, dealerTotal);
        } else if(playerTotal==21) {
            cout<<"debug ??"<<endl;
            cout << "You win $" << bet << "." << endl;
            playerAmount += bet;
            cout<<"debug amount:"<<playerAmount<<endl;
            askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1,
                               dealerCard2, dealerCard3, dealerTotal);
        }
    }
    //if player does not want more card and his or her point is less than 21.
    if (input == 'n'||playerTotal<21) {
        while (dealerTotal <= 16) {
            cout << "The dealer's are:" << endl
                 << "  " << dealerCard1 << endl;
            cout << "  " << dealerCard2 << endl;
            cout << "The dealer's total is " << dealerTotal << "." << endl;
            draw_card(dealerCard3, &dealerTotal);
            cout << "The dealer draw a card:" << endl;
            cout << "  " << dealerCard3 << endl;
            cout << "The dealer's total is " << dealerTotal << "." << endl;
        }
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
            playerAmount-=bet;
            askingToQuitOrPlay(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1,
                               dealerCard2, dealerCard3, dealerTotal);
        }
            //then dealer's point is between less than 21 and greater than 16, so dealer's turn is ended.
            //Thus, the next turn is player's.
        else if(dealerTotal<21){
            cout<<"Possible loop?"<<endl;

            askingMoreCard(playerCard1, playerCard2, playerCard3, playerTotal, playerAmount, dealerCard1, dealerCard2,
                           dealerCard3, dealerTotal, bet);
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

