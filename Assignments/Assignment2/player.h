/*********************************
Filename: crazyeights.cpp
Author: Joseph Murche
Date: 4/22/2021
Description: Crazy 8's.
Input: int, char
Output: string, int
**********************************/
#ifndef PLAYER_H
#define PLAYER_H
#include <iostream>
#include <string>
#include <ctime>
#include <cassert>
#include "card.h"
#include "hand.h"


using namespace std;

class Player {
  private:
    Hand hand;
    string name;
  public:
   const string get_name();
    Hand get_hand();
   void set_name(string);
   void set_hand(Deck &);
   void gamestart();
   void turn(Deck &, Deck &);
   bool can_go(Deck);
   void cpu_turn(Deck &, Deck &);
   int numinhand();
   bool empty_hand();
   void play_card(Card, Deck &, int);
   void wild_card(Card, Deck &, int);
   void plus_hand();
   void give_int(int &);

};

#endif