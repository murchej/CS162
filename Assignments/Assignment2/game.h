/*********************************
Filename: crazyeights.cpp
Author: Joseph Murche
Date: 4/22/2021
Description: Crazy 8's.
Input: int, char
Output: string, int
**********************************/
#ifndef GAME_H
#define GAME_H 
#include <iostream>
#include <string>
#include <ctime>
#include "deck.h"
#include "player.h"
#include "card.h"

using namespace std;

class Game {
private:
    Deck cards;
    Deck cardpile; //player's accumulated pile
    Player players[2];
  
public:
  Game();
  Player get_players(int);
  Player set_players();
  const Deck get_cards();
  Deck set_cards();
  bool check_winner();
  void play();
  bool rules(Card);
  string get_string();
  
};
bool rule_check(Card, Deck &);
string get_string();
#endif