/*********************************
Filename: crazyeights.cpp
Author: Joseph Murche
Date: 4/22/2021
Description: Crazy 8's.
Input: int, char
Output: string, int
**********************************/
#ifndef CARD_H
#define CARD_H
#include <iostream>
#include <string>
#include <ctime>
#include <cassert>

using namespace std;


class Card {
 
  public:
    Card();//ace of spades is the default card
    int get_rank();
    int get_suit();
    void set_rank(int);
    void set_suit(int);
    string suitname(); //returns the string of suits
    string rankname(); //returns the string of ranks

  private:
    int rank;  //range of 1-12
    int suit;  //range of 0-3

};


#endif