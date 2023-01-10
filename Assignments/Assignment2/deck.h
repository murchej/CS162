/*********************************
Filename: crazyeights.cpp
Author: Joseph Murche
Date: 4/22/2021
Description: Crazy 8's.
Input: int, char
Output: string, int
**********************************/
#ifndef DECK_H
#define DECK_H
#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
#include "card.h"

using namespace std;

class Deck {
private:
Card cards[52];
int n_cards; //How many cards are still in the deck

public:
Deck();
Deck(int);
void create_deck(int);
void shuffle_deck(int);
void print_deck(int);
void wipe();
bool draw();
void printtopcard();
int getnumcards();
void setnumcards(int);

Card get_cards(int);
void set_cards(int, int, int);
void cardswap(Card &, Card &);

};

#endif