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
#include <cstdlib>
#include "card.h"

using namespace std;
/*******************************************************************
Function: Card()
Description: constructor for card class
********************************************************************/
Card::Card(){
    rank = -1;
    suit = -1;

}

int Card::get_rank(){
    return rank;
}

int Card::get_suit(){
    return suit;
}

void Card::set_suit(int num){
    suit = num;
}

void Card::set_rank(int num){
    rank = num;
}

string Card::rankname(){ //if else loop for ranks
    if(rank == 1){
        return "Ace";
    } else if(rank == 2){
        return "Two";
    } else if(rank == 3){
        return "Three";
    } else if(rank == 4){
        return "Four";
    } else if(rank == 5){
        return "Five";
    } else if(rank == 6){
        return "Six";
    } else if(rank == 7){
        return "Seven";
    } else if(rank == 8){
        return "Eight";
    } else if(rank == 9){
        return "Nine";
    } else if(rank == 10){
        return "Jack";
    } else if(rank == 11){
        return "Queen";
    } else if(rank == 12){
        return "King";
    }
}

string Card::suitname(){ //if else if loop for assigning card suits
    if (suit == 0){
        return "Diamonds";
    } else if(suit == 1){
        return "Clubs";
    } else if(suit == 2){
        return "Spades";
    } else if(suit == 3){
        return "Hearts";
    }
  
}

