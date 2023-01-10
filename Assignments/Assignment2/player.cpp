/*********************************
Filename: crazyeights.cpp
Author: Joseph Murche
Date: 4/22/2021
Description: Crazy 8's.
Input: int, char
Output: string, int
**********************************/

#include <iostream>
#include <string>
#include "player.h"
#include "game.h"
#include "card.h"
#include "hand.h"
#include "deck.h"
#include <cstdlib>

using namespace std;

//getters and setters

//Player::Player(){
  //  Player players[2];
//}


const string Player::get_name(){
    return name;
}

Hand Player::get_hand(){
    return hand;
    
}

void Player::set_name(string n){
  name = n;
}

void Player::set_hand(Deck &x){
    hand.set_cards(x);
}



//player turn/computer turn functions



void Player::turn(Deck &cardpile, Deck &drawstack){ //user turn
    Card c;

    int x, playagain = 0;

    cout <<"It is "<< get_name() << "'s turn."<< endl;
    cout <<"This is your current hand: "<< endl;

    do{
        hand.print_hand();
        do{
            cout << "Play card (1 - " << hand.getnumcards() << "): ";
            give_int(x);
            c = hand.get_card(x-1);
        } while(can_go(cardpile) == true);
    
        do{
             play_card(hand.get_card(x-1), cardpile, x-1);
             hand.draw(drawstack);
             playagain = 1;
        } while(rule_check(c, cardpile) == true);

        if(rule_check(c, cardpile) == false){
            cout << "Invalid move, please try again." << endl;
        }

        if(can_go(cardpile) == false && drawstack.getnumcards() > 0){
            cout << "There is no move to make, drawing a card..." << endl;
            //cout << "Your current hand: " << hand.draw(drawstack) << endl;
        }

        if(can_go(cardpile) == false){
            cout << "No moves to make and no cards to be drawn";
            cout << "Skipping turn" << endl;
            playagain = 1;
        }

    } while(playagain = 0);
}


void Player::cpu_turn(Deck &cardpile, Deck &drawstack){
    cout << "CPU's turn..." << endl;
    int playagain = 1;
    Card topcard = cardpile.get_cards(cardpile.getnumcards() - 1), tc;

    do{
        if(can_go(cardpile) == true){
        playagain = 0;
            for(int i = 0; i < hand.getnumcards(); i++){
                tc = hand.get_card(i);

                do{
                    play_card(hand.get_card(i), cardpile, i);
                    
                    if (drawstack.getnumcards() > 0) hand.draw(drawstack);
                    break;
                    } while(tc.get_suit() == topcard.get_suit());

                do{
                    play_card(hand.get_card(i), cardpile, i);
                    
                    if(drawstack.getnumcards() > 0) hand.draw(drawstack);
                    break;
                } while(tc.get_rank() == topcard.get_rank());

                do{
                    wild_card(hand.get_card(i), cardpile, i);

                    if(drawstack.getnumcards() > 0) hand.draw(drawstack);
                    break;
                } while(tc.get_rank() == 7);
            }    
        }

                    if(drawstack.getnumcards() > 0){
                        cout << "There are no moves to make, drawing a card..." << endl;
                        hand.draw(drawstack);
                    } else if(can_go(cardpile) == false && drawstack.getnumcards() == 0){
                        cout << "There is no move you can do and there is no card to draw";
                        cout << " skipping turn." << endl;

                        playagain = 0;
                    }

    } while(playagain = 1);
}

void Player::play_card(Card y, Deck &cardpile, int X){
    Card j = cardpile.get_cards(cardpile.getnumcards() - 1);
    int k, l, playagain = 1;

    if(y.get_rank() == 7){

        do{
            cout << endl;
            cout << "8's are wild in this game!" << endl;
            cout << "Please choose a suit (0 = Diamonds, 1 = Clubs, 2 = Spades, 3 = Hearts): ";
            give_int(k);
            y.set_suit(k);

            cout << "Please choose a rank (1 = Ace, 2-9, 10 = Jack, 11 = Queen, 12 = King): ";
            give_int(l);
            y.set_rank(l - 1);

             if (y.get_rank() == j.get_rank() || y.get_suit() == j.get_suit()) //valid input check
                playagain = 0;
      
             else cout << "\tError: either rank or suit must match top of pile, try again.\n";
    

        } while(playagain == 1);
    }

    cardpile.set_cards(cardpile.getnumcards(), y.get_rank(), y.get_suit());

    j = cardpile.get_cards(cardpile.getnumcards() - 1);  //making proper adjustments to the values of funtions here
    
    cardpile.setnumcards(cardpile.getnumcards() + 1);

    hand.remove(X);
}

void Player::wild_card(Card y , Deck &cardpile, int X){
   
    cout << "The CPU just played a wild card!" << endl;
    
    Card j = cardpile.get_cards(cardpile.getnumcards() - 1);

    do{
        srand(time(0));
        y.set_rank(rand() % 12 + 1); //random number between 1-12

        y.set_suit(j.get_suit());
    }while(y.get_rank() == 7);

    cardpile.set_cards(cardpile.getnumcards(), y.get_rank(), y.get_suit());
         
    j = cardpile.get_cards(cardpile.getnumcards() -1);

    cardpile.setnumcards(cardpile.getnumcards() + 1); //making adjustments just like above

    hand.remove(X);
}


bool Player::can_go(Deck d){
  
  Card t1, t2;
  
  t2 = d.get_cards(d.getnumcards()-1);
  
  for (int i = 0; i < hand.getnumcards(); i++){
    t1 = hand.get_card(i);
    
    if (t1.get_rank() == 7) 
    return true;
    
    if (t1.get_rank() == t2.get_rank() || t1.get_suit() == t2.get_suit()){
      return true;
    }
  }
  return false;
}




bool Player::empty_hand(){
    do{
        return true;
    } while (hand.getnumcards() == 0);

    return false;
}

int Player::numinhand(){
    int n = hand.getnumcards();
    return n;
}

bool rule_check(Card user, Deck &cardpile){
    Card topofpile = cardpile.get_cards(cardpile.getnumcards() - 1);

    while(user.get_rank() == topofpile.get_rank()){
        return true;
    }

    while(user.get_suit() == topofpile.get_suit()){
        return true;
    }

    if(user.get_rank() == 7){
        return true;
    }

    else return false;
}

void Player::give_int(int &n){
    int playagain = 1;
    cin >> n;

    do{
        if(cin.fail() == true){
            cin.clear();
            cin.ignore(100000000000000000, '\n');

            cout << "Error: Please enter an Integer: ";
            cin >> n;
        }
    } while(playagain == 1);

    if(cin.fail() == false){
        playagain = 0;
    }
}