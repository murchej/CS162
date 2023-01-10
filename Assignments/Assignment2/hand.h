/*********************************
Filename: crazyeights.cpp
Author: Joseph Murche
Date: 4/22/2021
Description: Crazy 8's.
Input: int, char
Output: string, int
**********************************/
#ifndef HAND_H
#define HAND_H
#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
#include "card.h"
#include "deck.h"


using namespace std;
class Hand {
private:
    Card* cards;
    int n_cards; 
  
public:
    Hand();
    Hand(int);
    Hand(const Hand&);
    ~Hand();
    void print_hand();
    void draw(Deck &);
    void remove(int);
    void wipe();
    int getnumcards();
    void setnumcards(int);
    Card* get_cards(int);
    Card get_card(int);
    Card* set_cards(Deck &);
    const Hand& operator = (const Hand &);

 
};

#endif