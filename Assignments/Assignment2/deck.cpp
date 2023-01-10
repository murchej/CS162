/*********************************
Filename: crazyeights.cpp
Author: Joseph Murche
Date: 4/22/2021
Description: Crazy 8's.
Input: int, char
Output: string, int
**********************************/

#include <iostream>
#include <ctime>
#include <cstdlib>
#include "deck.h"
#include "card.h"

using namespace std;

Deck::Deck(){
    cards[52];
}

Deck::Deck(int num){
  for (int i=1; i < num; i++){
    for (int j=1; j < 5;j++){
      cards[i].set_rank(0);
      cards[i].set_suit(0);
    }
  }

  n_cards = 52;
}

void Deck::create_deck(int num) {
  int x=0;
  
  for (int i=0; i < 4; i++){
    for (int j=0; j<13; j++){
      cards[x].set_suit(i+1); 
      cards[x].set_rank(j+1); 
      
      x++;
    }
  }
}

void Deck::shuffle_deck(int num){

    if(num == 0){
        return;
    }


  srand(time(0));
  
  int shuff;
  
  for (int i=0; i < num; i++){
    shuff = i + (rand() % (52-i));
    cardswap(cards[i], cards[shuff]);
  }
}

void Deck::print_deck(int num){
  
  for (int i=0;i<num;i++) {
    cout << cards[i].get_rank() << "\tof\t";
    cout << cards[i].get_suit() << endl;
  }
}



//getter and setter function section



Card Deck::get_cards(int i) {
  return cards[i];
}

int Deck::getnumcards(){
 return n_cards;
}

void Deck::set_cards(int index, int rank, int suit){
  cards[index].set_rank(rank);
  cards[index].set_suit(suit);
}

void Deck::setnumcards(int num){
  n_cards = num;
}



//misc function section



void Deck::cardswap(Card &one, Card &two){
  Card tcard;
  tcard = one;
  one = two;
  two = tcard;
}

void Deck::wipe(){
    for(int i = 0; i < n_cards; i++){
    do{
     cardswap(cards[i], cards[n_cards - 1]);
     setnumcards(getnumcards() - 1);
    } while(cards[i].get_rank() == -1);
    }

}

void Deck::printtopcard(){
    do{
         cout << cards[n_cards-1].rankname() << " of ";
         cout << cards[n_cards-1].suitname() << endl;
    } while(cards[n_cards-1].get_rank() != -1);
    
        if (cards[n_cards-1].get_rank() == -1){
    cout << "Invalid\n";
    }
}

bool Deck::draw(){
    if(cards[0].get_rank() != -1){
        return true;
    }
        else{
            return false;
        }
}